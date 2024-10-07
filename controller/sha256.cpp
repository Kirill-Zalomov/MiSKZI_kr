#include "sha256.h"


constexpr quint32 Sha256::K[];


Sha256::Sha256(): lengthOfCurrentDataBlock(0), lengthOfInputData(0) {
    this->resultVariables[0] = 0x6a09e667;
    this->resultVariables[1] = 0xbb67ae85;
    this->resultVariables[2] = 0x3c6ef372;
    this->resultVariables[3] = 0xa54ff53a;
    this->resultVariables[4] = 0x510e527f;
    this->resultVariables[5] = 0x9b05688c;
    this->resultVariables[6] = 0x1f83d9ab;
    this->resultVariables[7] = 0x5be0cd19;
}


void Sha256::update(const QByteArray &data) {
    for (qsizetype i = 0 ; i < data.size(); i++) {
        this->currentDataBlock[this->lengthOfCurrentDataBlock++] = data[i];
        if (this->lengthOfCurrentDataBlock == 64) {
            this->transform();

            // End of the block
            this->lengthOfInputData += 512;
            this->lengthOfCurrentDataBlock = 0;
        }
    }
}


void Sha256::update(const QString &data) {
    this->update(data.toUtf8());
}


QByteArray Sha256::digest() {
    QByteArray hash;

    this->pad();
    this->revert(hash);

    return hash;
}


quint32 Sha256::rotr(quint32 x, quint32 n) {
    return (x >> n) | (x << (32 - n));
}


quint32 Sha256::choose(quint32 e, quint32 f, quint32 g) {
    return (e & f) ^ (~e & g);
}


quint32 Sha256::majority(quint32 a, quint32 b, quint32 c) {
    return (a & (b | c)) | (b & c);
}


quint32 Sha256::sig0(quint32 x) {
    return this->rotr(x, 7) ^ this->rotr(x, 18) ^ (x >> 3);
}


quint32 Sha256::sig1(quint32 x) {
    return this->rotr(x, 17) ^ this->rotr(x, 19) ^ (x >> 10);
}


void Sha256::transform() {
    quint32 maj, xorA, ch, xorE, sum, newA, newE, m[64];
    quint32 state[8];

    for (quint8 i = 0, j = 0; i < 16; i++, j += 4) { // Split data in 32 bit blocks for the 16 first words
        m[i] = (this->currentDataBlock[j] << 24) | (this->currentDataBlock[j + 1] << 16) | (this->currentDataBlock[j + 2] << 8) | (this->currentDataBlock[j + 3]);
    }

    for (quint8 k = 16 ; k < 64; k++) { // Remaining 48 blocks
        m[k] = this->sig1(m[k - 2]) + m[k - 7] + this->sig0(m[k - 15]) + m[k - 16];
    }

    for(quint8 i = 0 ; i < 8 ; i++) {
        state[i] = this->resultVariables[i];
    }

    for (quint8 i = 0; i < 64; i++) {
        maj   = this->majority(state[0], state[1], state[2]);
        xorA  = this->rotr(state[0], 2) ^ this->rotr(state[0], 13) ^ this->rotr(state[0], 22);

        ch = this->choose(state[4], state[5], state[6]);

        xorE  = this->rotr(state[4], 6) ^ this->rotr(state[4], 11) ^ this->rotr(state[4], 25);

        sum  = m[i] + K[i] + state[7] + ch + xorE;
        newA = xorA + maj + sum;
        newE = state[3] + sum;

        state[7] = state[6];
        state[6] = state[5];
        state[5] = state[4];
        state[4] = newE;
        state[3] = state[2];
        state[2] = state[1];
        state[1] = state[0];
        state[0] = newA;
    }

    for(quint8 i = 0 ; i < 8 ; i++) {
        this->resultVariables[i] += state[i];
    }
}

void Sha256::pad() {

    quint64 i = this->lengthOfCurrentDataBlock;
    quint8  end = this->lengthOfCurrentDataBlock < 56 ? 56 : 64;

    this->currentDataBlock[i++] = 0x80; // Append a bit 1
    while (i < end) {
        this->currentDataBlock[i++] = 0x00; // Pad with zeros
    }

    if(this->lengthOfCurrentDataBlock >= 56) {
        this->transform();
        memset(this->currentDataBlock, 0, 56);
    }

    // Append to the padding the total message's length in bits and transform.
    this->lengthOfInputData += this->lengthOfCurrentDataBlock * 8;
    this->currentDataBlock[63] = this->lengthOfInputData;
    this->currentDataBlock[62] = this->lengthOfInputData >> 8;
    this->currentDataBlock[61] = this->lengthOfInputData >> 16;
    this->currentDataBlock[60] = this->lengthOfInputData >> 24;
    this->currentDataBlock[59] = this->lengthOfInputData >> 32;
    this->currentDataBlock[58] = this->lengthOfInputData >> 40;
    this->currentDataBlock[57] = this->lengthOfInputData >> 48;
    this->currentDataBlock[56] = this->lengthOfInputData >> 56;
    this->transform();
}

void Sha256::revert(QByteArray &hash) {
    // SHA uses big endian byte ordering
    // Revert all bytes
    for (quint8 i = 0 ; i < 4 ; i++) {
        for(quint8 j = 0 ; j < 8 ; j++) {
            hash.remove((i + (j * 4)), 1);
            hash.insert((i + (j * 4)), (this->resultVariables[j] >> (24 - i * 8)) & 0x000000ff);
        }
    }
}

QString Sha256::toString() {
    QString hexString;
    for (quint8 byte : this->digest()) {
        hexString += QString("%1").arg(static_cast<quint8>(byte), 2, 16, QLatin1Char('0'));
    }
    return hexString;
}

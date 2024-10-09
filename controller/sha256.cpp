#include "sha256.h"


constexpr quint32 Sha256::K[];


Sha256::Sha256(): lengthOfCurrentDataBlock(0), lengthOfInputData(0) {
    this->setStartValuesToResultVariables();
    this->currentStep = {0};
}


void Sha256::calculateHashSum(const QByteArray &data) {
    for (qsizetype i = 0 ; i < data.size(); i++) {
        this->currentDataBlock[this->lengthOfCurrentDataBlock++] = data[i];
        if (this->lengthOfCurrentDataBlock == 64) {
            this->transformCurrentBlock();
            this->lengthOfInputData += 512;
            this->lengthOfCurrentDataBlock = 0;
        }
    }
}


void Sha256::determineOperation() {
    quint32 stepInIteration = this->currentStep % 114;
    if(stepInIteration == 0) {

    }
    if(stepInIteration == 1) {

    }
    if(stepInIteration >= 2 && stepInIteration <= 49) {

    }
    if(stepInIteration >= 50 && stepInIteration <= 112) {

    }
    if(stepInIteration == 113) {

    }
}


void Sha256::calculateHashSum(const QString &data) {
    this->calculateHashSum(data.toUtf8());
}


QByteArray Sha256::getHash() {
    QByteArray hash;
    this->pad();
    this->revert(hash);
    return hash;
}


// Циклический сдвиг вправо Rotr
quint32 Sha256::rotateRight(quint32 x, quint32 n) {
    return (x >> n) | (x << (32 - n));
}


// Реализация логической функции Ch
quint32 Sha256::choice(quint32 e, quint32 f, quint32 g) {
    return (e & f) ^ (~e & g);
}


// Реализация логической функции Maj
quint32 Sha256::majority(quint32 a, quint32 b, quint32 c) {
    return (a & (b | c)) | (b & c);
}


// Реализация логической функции Sigma0
quint32 Sha256::sigma0(quint32 x) {
    return this->rotateRight(x, 7) ^ this->rotateRight(x, 18) ^ (x >> 3);
}


// Реализация логической функции Sigma1
quint32 Sha256::sigma1(quint32 x) {
    return this->rotateRight(x, 17) ^ this->rotateRight(x, 19) ^ (x >> 10);
}


void Sha256::transformCurrentBlock() {
    // Разбиение блока данных на 16 слов длиной 32 бита (с порядком байтов от старшего к младшему внутри слова): w[0..15]
    this->prepareFirst16Words();

    // Генерация дополнительных 48 слов и вычисление их значений: w[16..63]
    for (quint8 k = 16 ; k < 64; k++) {
        this->generateLast48Words(k);
    }

    // Взятие хэш-суммы от обработки предыдущего бока в 512 бит
    this->takeHashFromPreviousBlockProcessing();

    // Вычисление контрольной суммы с использованием значений  w[0..63]
    for (quint8 i = 0; i < 64; i++) {
        this->makeIterationOfHashCalculating(i);
    }

    // Сохранение хэш-суммы для её использования в обработке следующих блоков по 512 бит
    this->saveHashValuesFromIteration();
}


void Sha256::prepareFirst16Words() {
    for (quint8 i = 0, j = 0; i < 16; i++, j += 4) {
        this->w[i] = (this->currentDataBlock[j] << 24) | (this->currentDataBlock[j + 1] << 16) | (this->currentDataBlock[j + 2] << 8) | (this->currentDataBlock[j + 3]);
    }
}


// k - индекс
void Sha256::generateLast48Words(const quint32 &k) {
    this->w[k] = this->sigma1(this->w[k - 2]) + this->w[k - 7] + this->sigma0(this->w[k - 15]) + this->w[k - 16];
}


// Вычисление контрольной суммы с использованием значений  w[0..63]
void Sha256::makeIterationOfHashCalculating(const quint32 &l) {
    this->maj   = this->majority(this->h[0], this->h[1], this->h[2]);
    this->sum0  = this->rotateRight(this->h[0], 2) ^ this->rotateRight(this->h[0], 13) ^ this->rotateRight(this->h[0], 22);

    this->ch = this->choice(this->h[4], this->h[5], this->h[6]);

    this->sum1  = this->rotateRight(this->h[4], 6) ^ this->rotateRight(this->h[4], 11) ^ this->rotateRight(this->h[4], 25);

    this->temp1  = this->w[l] + this->K[l] + this->h[7] + this->ch + this->sum1;
    this->updatedA = this->sum0 + this->maj + this->temp1;
    this->updatedE = this->h[3] + this->temp1;

    this->h[7] = this->h[6];
    this->h[6] = this->h[5];
    this->h[5] = this->h[4];
    this->h[4] = this->updatedE;
    this->h[3] = this->h[2];
    this->h[2] = this->h[1];
    this->h[1] = this->h[0];
    this->h[0] = this->updatedA;
}


// Взятие хэш-суммы от обработки предыдущего бока в 512 бит
void Sha256::takeHashFromPreviousBlockProcessing() {
    for(quint8 i = 0 ; i < 8 ; i++) {
        this->h[i] = this->resultVariables[i];
    }
}


// Сохранение хэш-суммы для её использования в обработке следующих блоков по 512 бит
void Sha256::saveHashValuesFromIteration() {
    for(quint8 i = 0 ; i < 8 ; i++) {
        this->resultVariables[i] += this->h[i];
    }
}


void Sha256::pad() {

    quint64 i = this->lengthOfCurrentDataBlock;
    quint8  end = this->lengthOfCurrentDataBlock < 56 ? 56 : 64;

    // Добавление одиночного бита (0x01) к текущему блоку данных на индекс i и дополнение нулями
    this->currentDataBlock[i++] = 0x80;
    while (i < end) {
        this->currentDataBlock[i++] = 0x00;
    }

    if(this->lengthOfCurrentDataBlock >= 56) {
        this->transformCurrentBlock();
        memset(this->currentDataBlock, 0, 56);
    }

    // Добавление к заполнению общую длину сообщения в битах и вычисление контрольной суммы по блоку
    this->lengthOfInputData += this->lengthOfCurrentDataBlock * 8;
    this->currentDataBlock[63] = this->lengthOfInputData;
    this->currentDataBlock[62] = this->lengthOfInputData >> 8;
    this->currentDataBlock[61] = this->lengthOfInputData >> 16;
    this->currentDataBlock[60] = this->lengthOfInputData >> 24;
    this->currentDataBlock[59] = this->lengthOfInputData >> 32;
    this->currentDataBlock[58] = this->lengthOfInputData >> 40;
    this->currentDataBlock[57] = this->lengthOfInputData >> 48;
    this->currentDataBlock[56] = this->lengthOfInputData >> 56;
    this->transformCurrentBlock();
}


// Преобразование внутреннего значения хеша в массив байтов в порядке big-endian
void Sha256::revert(QByteArray &hash) {
    for (quint8 i = 0 ; i < 4 ; i++) {
        for(quint8 j = 0 ; j < 8 ; j++) {
            hash.remove((i + (j * 4)), 1);
            hash.insert((i + (j * 4)), (this->resultVariables[j] >> (24 - i * 8)) & 0x000000ff);
        }
    }
}


// Получение значения хэша в виде строки
QString Sha256::getHashAsString() {
    QString hexString;
    for (quint8 byte : this->getHash()) {
        hexString += QString("%1").arg(static_cast<quint8>(byte), 2, 16, QLatin1Char('0'));
    }
    return hexString;
}


void Sha256::clearState() {
    this->currentDataBlock[64] = {0};
    this->lengthOfCurrentDataBlock = {0};
    this->lengthOfInputData = {0};
    this->maj = {0};
    this->sum0 = {0};
    this->ch = {0};
    this->sum1 = {0};
    this->temp1 = {0};
    this->updatedA = {0};
    this->updatedE = {0};
    this->w[64] = {0};
    this->h[8] = {0};
    this->currentStep = {0};

    this->setStartValuesToResultVariables();
}


void Sha256::setStartValuesToResultVariables() {
    this->resultVariables[0] = 0x6a09e667;
    this->resultVariables[1] = 0xbb67ae85;
    this->resultVariables[2] = 0x3c6ef372;
    this->resultVariables[3] = 0xa54ff53a;
    this->resultVariables[4] = 0x510e527f;
    this->resultVariables[5] = 0x9b05688c;
    this->resultVariables[6] = 0x1f83d9ab;
    this->resultVariables[7] = 0x5be0cd19;
}

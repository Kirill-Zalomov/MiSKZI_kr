#include "model.h"


Model::Model(QObject *parent) : QObject(parent) {}
Model::~Model() {}


QString Model::getInputText() const {
    return this->inputText;
}
void Model::setInputText(const QString &newInputText) {
    this->inputText = newInputText;
    emit inputTextHasBeenProcessed(this->inputText);
}


InputFormat Model::getInputFormat() const {
    return this->inputFormat;
}
void Model::setInputFormat(const InputFormat &newInputFormat) {
    this->inputFormat = newInputFormat;
}
void Model::setInputFormat(const quint32 &newInputFormat) {
    this->inputFormat = static_cast<InputFormat>(newInputFormat);
}

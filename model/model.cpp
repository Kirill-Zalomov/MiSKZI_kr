#include "model.h"


const QFont Model::mainFont = QFont("Monospace", 11);


Model::Model(QObject *parent) : QObject(parent) {}
Model::~Model() {}


QString Model::getInputText() const {
    return this->inputText;
}
void Model::setInputText(const QString &newInputText) {
    if(this->inputText.isEmpty() && !newInputText.isEmpty())   emit setEnableToControlButtons(true);
    if(!(this->inputText.isEmpty()) && newInputText.isEmpty()) emit setEnableToControlButtons(false);

    this->inputText = newInputText;
    emit inputTextHasBeenProcessed(this->inputText);
    emit setNewNumberOfCharactersInInput(this->inputText.size());
}


InputFormat Model::getInputFormat() const {
    return this->inputFormat;
}
void Model::setInputFormat(const InputFormat &newInputFormat) {
    this->inputFormat = newInputFormat;
}


bool Model::getVisualizationStarted() const {
    return this->visualizationStarted;
}
void Model::setVisualizationStarted(const bool &newValue) {
    this->visualizationStarted = newValue;
    emit changeButtonRunOrPauseState(this->visualizationStarted);
}

#include "controller.h"

Controller::Controller(Model *model, View *view, QObject *parent) : QObject(parent) {
    this->view  = view;
    this->model = model;
}


Controller::~Controller() {}


void Controller::onInputFormatChanged(const qint32 &index) {
    InputFormat oldInputFormat = this->model->getInputFormat();
    InputFormat newInputFormat = static_cast<InputFormat>(index);
    if(oldInputFormat == newInputFormat) return;

    this->model->setInputFormat(newInputFormat);
    emit clearInputText();
}


void Controller::onInputTextChanged(const QString &text) {
    InputFormat currentInputFormat = this->model->getInputFormat();
    QString filteredText = text;

    if(currentInputFormat == InputFormat::Hexadecimal) filteredText.remove(QRegularExpression("[^0-9A-Fa-f]"));
    else if(currentInputFormat == InputFormat::Binary) filteredText.remove(QRegularExpression("[^01]"));

    this->model->setInputText(filteredText);
}


void Controller::startControlling() {
    this->view->show();
}

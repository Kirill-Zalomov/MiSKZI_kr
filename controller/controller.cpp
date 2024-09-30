#include "controller.h"

Controller::Controller(Model *model, View *view, QObject *parent) : QObject(parent) {
    this->view  = view;
    this->model = model;
}


Controller::~Controller() {}


void Controller::onInputFormatChanged(const qint32 &index) {
    this->model->setInputFormat(index);
}


void Controller::onInputTextChanged(const QString &text) {
    this->model->setInputText(text + "!");
}


void Controller::startControlling() {
    this->view->show();
}

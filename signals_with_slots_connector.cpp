#include "signals_with_slots_connector.h"


SignalsWithSlotsConnector::SignalsWithSlotsConnector(QObject *parent) : QObject(parent) {}


void SignalsWithSlotsConnector::connectViewWithController(View* view, Controller* controller) {
    QObject::connect(view->comboBoxForInputFormat.data(), &QComboBox::currentIndexChanged, controller, &Controller::onInputFormatChanged, Qt::QueuedConnection);
    QObject::connect(view->lineEditForInput.data(), &QLineEdit::textEdited, controller, &Controller::onInputTextChanged, Qt::QueuedConnection);
    QObject::connect(view->buttonAutoRun.data(), &QPushButton::clicked, controller, &Controller::onButtonAutoRunClicked, Qt::QueuedConnection);
    QObject::connect(view->buttonForwardToTheFinish.data(), &QPushButton::clicked, controller, &Controller::calculateSha256, Qt::QueuedConnection);
    QObject::connect(controller, &Controller::clearInputText, view, &View::clearInputTextInLineEdit, Qt::QueuedConnection);
}


void SignalsWithSlotsConnector::connectControllerWithModel(const Controller* controller, const Model* model) {
    Q_UNUSED(controller);
    Q_UNUSED(model);
}


void SignalsWithSlotsConnector::connectModelWithView(const Model* model, const View* view) {
    QObject::connect(model, &Model::inputTextHasBeenProcessed, view, &View::setProcessedInputText, Qt::QueuedConnection);
    QObject::connect(model, &Model::setEnableToControlButtons, view, &View::setEnabledForControlButtons, Qt::QueuedConnection);
    QObject::connect(model, &Model::setNewNumberOfCharactersInInput, view, &View::setNewNumberOfCharactersInInput, Qt::QueuedConnection);
    QObject::connect(model, &Model::changeButtonRunOrPauseState, view, &View::changeButtonRunOrPauseState, Qt::QueuedConnection);
}

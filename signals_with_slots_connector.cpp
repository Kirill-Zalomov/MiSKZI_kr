#include "signals_with_slots_connector.h"


SignalsWithSlotsConnector::SignalsWithSlotsConnector(QObject *parent) : QObject(parent) {}


void SignalsWithSlotsConnector::connectViewWithController(View* view, Controller* controller) {
    QObject::connect(view->comboBoxForInputFormat.data(), &QComboBox::currentIndexChanged, controller, &Controller::onInputFormatChanged, Qt::QueuedConnection);
    QObject::connect(view->lineEditForInput.data(), &QLineEdit::textEdited, controller, &Controller::onInputTextChanged, Qt::QueuedConnection);
}


void SignalsWithSlotsConnector::connectControllerWithModel(const Controller* controller, const Model* model) {
    Q_UNUSED(controller);
    Q_UNUSED(model);
}


void SignalsWithSlotsConnector::connectModelWithView(const Model* model, const View* view) {
    QObject::connect(model, &Model::inputTextHasBeenProcessed, view, &View::setProcessedInputText, Qt::QueuedConnection);
}

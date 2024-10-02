#include "controller.h"
#include "model.h"
#include "view.h"
#include "signals_with_slots_connector.h"
#include <QApplication>
#include <QThread>


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    QScopedPointer<Model> model;
    QScopedPointer<View> view;
    QScopedPointer<Controller> controller;

    QThread threadForControllerAndModel;
    model.reset(new Model());
    view.reset(new View());
    controller.reset(new Controller(model.data(), view.data()));

    controller.data()->moveToThread(&threadForControllerAndModel);
    model.data()->moveToThread(&threadForControllerAndModel);
    threadForControllerAndModel.start();

    SignalsWithSlotsConnector signalsWithSlotsConnector;
    signalsWithSlotsConnector.connectViewWithController(view.data(), controller.data());
    signalsWithSlotsConnector.connectControllerWithModel(controller.data(), model.data());
    signalsWithSlotsConnector.connectModelWithView(model.data(), view.data());

    view.data()->show();
    qint32 result = application.exec();

    threadForControllerAndModel.quit();
    threadForControllerAndModel.wait();

    return result;
}

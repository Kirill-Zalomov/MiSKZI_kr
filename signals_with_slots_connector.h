#ifndef SIGNALSWITHSLOTSCONNECTOR_H
#define SIGNALSWITHSLOTSCONNECTOR_H


#include <QObject>
#include "model.h"
#include "view.h"
#include "controller.h"


class Model;
class View;
class Controller;


class SignalsWithSlotsConnector : public QObject {
    Q_OBJECT

public:
    explicit SignalsWithSlotsConnector(QObject *parent = nullptr);

    void connectViewWithController(View *view, Controller *controller);
    void connectControllerWithModel(const Controller *controller, const Model *model);
    void connectModelWithView(const Model *model, const View *view);
};


#endif // SIGNALSWITHSLOTSCONNECTOR_H

#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "view.h"
#include "model.h"


class View;
class Model;


class Controller : public QObject {
    Q_OBJECT

private:
    Model *model;
    View  *view;

public:
    explicit Controller(Model *model, View *view, QObject *parent = nullptr);
    ~Controller();
    void startControlling();

public slots:
    void onInputFormatChanged(const qint32 &index);
    void onInputTextChanged(const QString &text);

};


#endif  /* CONTROLLER_H */

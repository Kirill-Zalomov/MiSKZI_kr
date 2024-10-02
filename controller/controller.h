#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include "view.h"
#include "model.h"
#include "sha256.h"


#include <iostream>
#include <cstdint>


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

signals:
    void clearInputText();
    void setEnableToControlButtons(const bool &newState);

public slots:
    void onInputFormatChanged(const qint32 &index);
    void onInputTextChanged(const QString &text);
    void onButtonAutoRunClicked();
    void calculateSha256();

};


#endif  /* CONTROLLER_H */

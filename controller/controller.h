#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "view.h"
#include "model.h"


class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
};


#endif  /* CONTROLLER_H */

#ifndef COFIGURATOROFCONTROLBUTTONSBLOCK_H
#define COFIGURATOROFCONTROLBUTTONSBLOCK_H


#include <QPushButton>


class ConfiguratorOfControlButtonsBlock {
public:
    ConfiguratorOfControlButtonsBlock();

    void configureButtonBacwardToTheStart(QPushButton *buttonBacwardToTheStart);
    void configureButtonTenStepsBacward(QPushButton *buttonTenStepsBacward);
    void configureButtonOneStepBacward(QPushButton *buttonOneStepBacward);
    void configureButtonOneStepForward(QPushButton *buttonOneStepForward);
    void configureButtonTenStepsForward(QPushButton *buttonTenStepsForward);
    void configureButtonForwardToTheEnd(QPushButton *buttonForwardToTheEnd);
    void configureButtonAutoRun(QPushButton *buttonAutoRun);
};

#endif // COFIGURATOROFCONTROLBUTTONSBLOCK_H

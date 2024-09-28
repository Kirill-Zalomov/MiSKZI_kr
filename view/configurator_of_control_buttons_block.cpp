#include "configurator_of_control_buttons_block.h"


const QSize ConfiguratorOfControlButtonsBlock::controlButtonSize = QSize(50, 30);
const QSize ConfiguratorOfControlButtonsBlock::iconSize = QSize(20, 20);


ConfiguratorOfControlButtonsBlock::ConfiguratorOfControlButtonsBlock() {}


void ConfiguratorOfControlButtonsBlock::controlButtonGeneralConfiguration(QPushButton *controlButton) {
    controlButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    controlButton->setBaseSize(ConfiguratorOfControlButtonsBlock::controlButtonSize);
    controlButton->setMinimumSize(ConfiguratorOfControlButtonsBlock::controlButtonSize);
    controlButton->setMaximumSize(ConfiguratorOfControlButtonsBlock::controlButtonSize);
    controlButton->setIconSize(ConfiguratorOfControlButtonsBlock::iconSize);
    controlButton->setEnabled(false);
    controlButton->setStyleSheet(QString("background-color: %1;").arg(GREY_BUTTON_INACTIVE_COLOR));
}


void ConfiguratorOfControlButtonsBlock::configureButtonBacwardToStart(QPushButton *buttonBacwardToTheStart) {
    this->controlButtonGeneralConfiguration(buttonBacwardToTheStart);
    buttonBacwardToTheStart->setIcon(QIcon(ICONPATH_TO_START));
}


void ConfiguratorOfControlButtonsBlock::configureButtonTenStepsBacward(QPushButton *buttonTenStepsBacward) {
    this->controlButtonGeneralConfiguration(buttonTenStepsBacward);
    buttonTenStepsBacward->setIcon(QIcon(ICONPATH_BACKWARD_TEN_STEPS));
}


void ConfiguratorOfControlButtonsBlock::configureButtonOneStepBacward(QPushButton *buttonOneStepBacward) {
    this->controlButtonGeneralConfiguration(buttonOneStepBacward);
    buttonOneStepBacward->setIcon(QIcon(ICONPATH_BACKWARD_ONE_STEP));
}


void ConfiguratorOfControlButtonsBlock::configureButtonOneStepForward(QPushButton *buttonOneStepForward) {
    this->controlButtonGeneralConfiguration(buttonOneStepForward);
    buttonOneStepForward->setIcon(QIcon(ICONPATH_FORWARD_ONE_STEP));
}


void ConfiguratorOfControlButtonsBlock::configureButtonTenStepsForward(QPushButton *buttonTenStepsForward) {
    this->controlButtonGeneralConfiguration(buttonTenStepsForward);
    buttonTenStepsForward->setIcon(QIcon(ICONPATH_FORWARD_TEN_STEPS));
}


void ConfiguratorOfControlButtonsBlock::configureButtonForwardToFinish(QPushButton *buttonForwardToTheFinish) {
    this->controlButtonGeneralConfiguration(buttonForwardToTheFinish);
    buttonForwardToTheFinish->setIcon(QIcon(ICONPATH_TO_FINISH));
}


void ConfiguratorOfControlButtonsBlock::configureButtonAutoRun(QPushButton *buttonAutoRun) {
    this->controlButtonGeneralConfiguration(buttonAutoRun);
    buttonAutoRun->setIcon(QIcon(ICONPATH_START));
    buttonAutoRun->setStyleSheet(QString("background-color: %1;").arg(GREEN_BUTTON_INACTIVE_COLOR));
}

#ifndef COFIGURATOR_OF_CONTROL_BUTTONS_BLOCK_H
#define COFIGURATOR_OF_CONTROL_BUTTONS_BLOCK_H


#include <QPushButton>


#define  ICONPATH_START               (R"(:/resources/images/start.png)")
#define  ICONPATH_PAUSE               (R"(:/resources/images/pause.png)")
#define  ICONPATH_FORWARD_ONE_STEP    (R"(:/resources/images/forward1.png)")
#define  ICONPATH_FORWARD_TEN_STEPS   (R"(:/resources/images/forward10.png)")
#define  ICONPATH_TO_FINISH           (R"(:/resources/images/tofinish.png)")
#define  ICONPATH_BACKWARD_ONE_STEP   (R"(:/resources/images/backward1.png)")
#define  ICONPATH_BACKWARD_TEN_STEPS  (R"(:/resources/images/backward10.png)")
#define  ICONPATH_TO_START            (R"(:/resources/images/tostart.png)")


#define GREY_BUTTON_ACTIVE_COLOR      ("#333333")
#define GREY_BUTTON_INACTIVE_COLOR    ("#555555")
#define GREEN_BUTTON_ACTIVE_COLOR     ("#108B10")
#define GREEN_BUTTON_INACTIVE_COLOR   ("#105B10")


class ConfiguratorOfControlButtonsBlock {
private:
    static constexpr QSize controlButtonSize {50, 30};
    static constexpr QSize iconSize {20, 20};

    void controlButtonGeneralConfiguration(QPushButton *controlButton);

public:
    ConfiguratorOfControlButtonsBlock();

    void configureButtonBacwardToStart(QPushButton *buttonBacwardToTheStart);
    void configureButtonTenStepsBacward(QPushButton *buttonTenStepsBacward);
    void configureButtonOneStepBacward(QPushButton *buttonOneStepBacward);
    void configureButtonOneStepForward(QPushButton *buttonOneStepForward);
    void configureButtonTenStepsForward(QPushButton *buttonTenStepsForward);
    void configureButtonForwardToFinish(QPushButton *buttonForwardToTheEnd);
    void configureButtonAutoRun(QPushButton *buttonAutoRun);
};


#endif // COFIGURATOR_OF_CONTROL_BUTTONS_BLOCK_H

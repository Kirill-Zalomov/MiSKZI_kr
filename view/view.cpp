#include "view.h"


View::View(QWidget *parent) : QMainWindow{parent} {

    //
    // Вынести данный код в отдельную функцию
    //
    this->mainContainer.reset(new QWidget(this));
    this->mainContainer->setMinimumSize(QSize(480, 320));

    this->mainContainerLayout.reset(new QVBoxLayout(this->mainContainer.data()));
    this->mainContainer.data()->setLayout(this->mainContainerLayout.data());
    this->setCentralWidget(this->mainContainer.data());

    // Инициализация и настройка блока для ввода исходных данных
    this->initInputBlock();
    this->cofigureInputBlock();
    this->addChildWidgetsToInputBlock();

    // Инициализация и настройка блока кнопок, управляющих ходом визуализации алгоритма
    this->initControlButtonsBlock();
}


View::~View() {}


void View::initInputBlock() {
    this->containerForInput.reset(new QHBoxLayout(this));
    this->labelForInputFormat.reset(new QLabel(this));
    this->comboBoxForInputFormat.reset(new QComboBox(this));
    this->lineEditForInput.reset(new QLineEdit(this));

    /// todo: Перенести эту строку в другую функцию
    qobject_cast<QVBoxLayout*>(this->mainContainer.data()->layout())->addLayout(this->containerForInput.data());
}


void View::cofigureInputBlock() {
    ConfiguratorOfInputBlock configuratorOfInputBlock;
    configuratorOfInputBlock.configureLabelForInputFormat(this->labelForInputFormat.data());
    configuratorOfInputBlock.configureComboBoxForInputFormat(this->comboBoxForInputFormat.data());
    configuratorOfInputBlock.configureLineEditFotInput(this->lineEditForInput.data());
}


void View::addChildWidgetsToInputBlock() {
    this->containerForInput->addWidget(this->labelForInputFormat.data());
    this->containerForInput->addWidget(this->comboBoxForInputFormat.data());
    this->containerForInput->addWidget(this->lineEditForInput.data());
}


void View::initControlButtonsBlock() {
    this->containerForControlButtons.reset(new QHBoxLayout(this));
    this->buttonBacwardToTheStart.reset(new QPushButton(this));
    this->buttonTenStepsBacward.reset(new QPushButton(this));
    this->buttonOneStepBacward.reset(new QPushButton(this));
    this->buttonOneStepForward.reset(new QPushButton(this));
    this->buttonTenStepsForward.reset(new QPushButton(this));
    this->buttonForwardToTheEnd.reset(new QPushButton(this));
    this->buttonAutoRun.reset(new QPushButton(this));

    /// todo: Перенести эту строку в другую функцию
    qobject_cast<QVBoxLayout*>(this->mainContainer.data()->layout())->addLayout(this->containerForControlButtons.data());
}


void View::cofigureControlButtonsBlock() {

}


void View::addChildWidgetsToControlButtonsBlock() {
    this->containerForControlButtons->addWidget(this->buttonBacwardToTheStart.data());
    this->containerForControlButtons->addWidget(this->buttonTenStepsBacward.data());
    this->containerForControlButtons->addWidget(this->buttonOneStepBacward.data());
    this->containerForControlButtons->addWidget(this->buttonOneStepForward.data());
    this->containerForControlButtons->addWidget(this->buttonTenStepsForward.data());
    this->containerForControlButtons->addWidget(this->buttonForwardToTheEnd.data());
    this->containerForControlButtons->addWidget(this->buttonAutoRun.data());
}


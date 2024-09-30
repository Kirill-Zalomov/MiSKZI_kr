#include "view.h"


View::View(QWidget *parent) : QMainWindow{parent} {
    // Инициализация и настройка главного окна
    this->initMainWindow();
    this->configureMainWindow();

    // Инициализация и настройка блока для ввода исходных данных
    this->initInputBlock();
    this->configureInputBlock();
    this->addChildWidgetsToInputBlock();

    // Инициализация и настройка блока кнопок, управляющих ходом визуализации алгоритма
    this->initControlButtonsBlock();
    this->configureControlButtonsBlock();
    this->addChildWidgetsToControlButtonsBlock();

    // Инициализация и настройка блока для визуализации работы алгоритма
    this->initVisualisingBlock();
    this->configureVisualisingBlock();
    this->addChildWidgetsToVisualisingBlock();

    // Добавление настроенных блоков на главное окно
    this->addBlocksToMainWindow();
}


View::~View() {}


void View::initMainWindow() {
    this->mainContainer.reset(new QWidget(this));
    this->mainContainerLayout.reset(new QVBoxLayout(this->mainContainer.data()));
}


void View::configureMainWindow() {
    this->mainContainer->setMinimumSize(QSize(720, 480));
    this->mainContainer.data()->setLayout(this->mainContainerLayout.data());
    this->mainContainerLayout->setSpacing(10);
    this->setCentralWidget(this->mainContainer.data());
}


void View::addBlocksToMainWindow() {
    this->mainContainerLayout->addLayout(this->containerForInput.data());
    this->mainContainerLayout->addLayout(this->containerForControlButtons.data());
    this->mainContainerLayout->addWidget(this->containerForVisualisingBlock.data());
}


void View::initInputBlock() {
    this->containerForInput.reset(new QHBoxLayout(this));
    this->labelForInputFormat.reset(new QLabel(this));
    this->comboBoxForInputFormat.reset(new QComboBox(this));
    this->lineEditForInput.reset(new QLineEdit(this));
}


void View::configureInputBlock() {
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
    this->buttonForwardToTheFinish.reset(new QPushButton(this));
    this->buttonAutoRun.reset(new QPushButton(this));
}


void View::configureControlButtonsBlock() {
    ConfiguratorOfControlButtonsBlock configuratorOfControlButtonsBlock;
    configuratorOfControlButtonsBlock.configureButtonBacwardToStart(this->buttonBacwardToTheStart.data());
    configuratorOfControlButtonsBlock.configureButtonTenStepsBacward(this->buttonTenStepsBacward.data());
    configuratorOfControlButtonsBlock.configureButtonOneStepBacward(this->buttonOneStepBacward.data());
    configuratorOfControlButtonsBlock.configureButtonOneStepForward(this->buttonOneStepForward.data());
    configuratorOfControlButtonsBlock.configureButtonTenStepsForward(this->buttonTenStepsForward.data());
    configuratorOfControlButtonsBlock.configureButtonForwardToFinish(this->buttonForwardToTheFinish.data());
    configuratorOfControlButtonsBlock.configureButtonAutoRun(this->buttonAutoRun.data());
}


void View::addChildWidgetsToControlButtonsBlock() {
    this->containerForControlButtons->addWidget(this->buttonBacwardToTheStart.data());
    this->containerForControlButtons->addWidget(this->buttonTenStepsBacward.data());
    this->containerForControlButtons->addWidget(this->buttonOneStepBacward.data());
    this->containerForControlButtons->addWidget(this->buttonOneStepForward.data());
    this->containerForControlButtons->addWidget(this->buttonTenStepsForward.data());
    this->containerForControlButtons->addWidget(this->buttonForwardToTheFinish.data());
    this->containerForControlButtons->addWidget(this->buttonAutoRun.data());
    this->containerForControlButtons->addStretch();
}


void View::initVisualisingBlock() {
    this->containerForVisualisingBlock.reset(new QScrollArea(this));
    this->containerForVisualisingBlockLayout.reset(new QHBoxLayout(this));
    this->containerForVisualisingBlockCentralWidget.reset(new QWidget(this));
    this->labelDescription.reset(new QLabel(this));
    this->labelWords.reset(new QLabel(this));
    this->labelCalculations.reset(new QLabel(this));
    this->labelKeys.reset(new QLabel(this));
}


void View::configureVisualisingBlock() {
    ConfiguratorOfVisualisingBlock configuratorOfVisualisingBlock;
    configuratorOfVisualisingBlock.configureLabelDescription(this->labelDescription.data());
    configuratorOfVisualisingBlock.configureLabelWords(this->labelWords.data());
    configuratorOfVisualisingBlock.configureLabelCalculations(this->labelCalculations.data());
    configuratorOfVisualisingBlock.configureLabelKeys(this->labelKeys.data());
    configuratorOfVisualisingBlock.configureScrollAreaForVisualizing(this->containerForVisualisingBlock.data());
}


void View::addChildWidgetsToVisualisingBlock() {
    this->containerForVisualisingBlockLayout->addWidget(this->labelDescription.data());
    this->containerForVisualisingBlockLayout->addWidget(this->labelWords.data());
    this->containerForVisualisingBlockLayout->addWidget(this->labelCalculations.data());
    this->containerForVisualisingBlockLayout->addWidget(this->labelKeys.data());
    this->containerForVisualisingBlockCentralWidget->setLayout(this->containerForVisualisingBlockLayout.data());
    this->containerForVisualisingBlockCentralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    this->containerForVisualisingBlock->setWidget(this->containerForVisualisingBlockCentralWidget.data());
}


void View::setProcessedInputText(const QString& text) {
    this->lineEditForInput->setText(text);
}

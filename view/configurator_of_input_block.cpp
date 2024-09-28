#include "configurator_of_input_block.h"


ConfiguratorOfInputBlock::ConfiguratorOfInputBlock() {}


void ConfiguratorOfInputBlock::configureLabelForInputFormat(QLabel *labelForInputFormat) {
    QSize size = QSize(120, 25);
    labelForInputFormat->setText("Формат данных:");
    labelForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    labelForInputFormat->setBaseSize(size);
    labelForInputFormat->setMinimumSize(size);
    labelForInputFormat->setMaximumSize(size);
}


void ConfiguratorOfInputBlock::configureComboBoxForInputFormat(QComboBox *comboBoxForInputFormat) {
    QSize size = QSize(120, 25);
    comboBoxForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    comboBoxForInputFormat->setBaseSize(size);
    comboBoxForInputFormat->setMinimumSize(size);
    comboBoxForInputFormat->setMaximumSize(size);

    comboBoxForInputFormat->addItem("Текстовый");
    comboBoxForInputFormat->addItem("Двоичный");
    comboBoxForInputFormat->addItem("Шестнадцатеричный");
}


void ConfiguratorOfInputBlock::configureLineEditFotInput(QLineEdit *lineEditForInput) {
    lineEditForInput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineEditForInput->setPlaceholderText(R"(Введите входные данные...)");
}

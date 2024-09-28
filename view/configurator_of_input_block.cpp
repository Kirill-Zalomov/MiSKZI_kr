#include "configurator_of_input_block.h"


const QSize ConfiguratorOfInputBlock::labelForInputFormatSize = QSize(100, 25);
const QSize ConfiguratorOfInputBlock::comboBoxForInputFormatSize = QSize(180, 25);


ConfiguratorOfInputBlock::ConfiguratorOfInputBlock() {}


void ConfiguratorOfInputBlock::configureLabelForInputFormat(QLabel *labelForInputFormat) {
    labelForInputFormat->setText("Формат данных:");
    labelForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    labelForInputFormat->setBaseSize(ConfiguratorOfInputBlock::labelForInputFormatSize);
    labelForInputFormat->setMinimumSize(ConfiguratorOfInputBlock::labelForInputFormatSize);
    labelForInputFormat->setMaximumSize(ConfiguratorOfInputBlock::labelForInputFormatSize);
}


void ConfiguratorOfInputBlock::configureComboBoxForInputFormat(QComboBox *comboBoxForInputFormat) {
    comboBoxForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    comboBoxForInputFormat->setBaseSize(ConfiguratorOfInputBlock::comboBoxForInputFormatSize);
    comboBoxForInputFormat->setMinimumSize(ConfiguratorOfInputBlock::comboBoxForInputFormatSize);
    comboBoxForInputFormat->setMaximumSize(ConfiguratorOfInputBlock::comboBoxForInputFormatSize);

    comboBoxForInputFormat->addItem("Текстовый");
    comboBoxForInputFormat->addItem("Двоичный");
    comboBoxForInputFormat->addItem("Шестнадцатеричный");
}


void ConfiguratorOfInputBlock::configureLineEditFotInput(QLineEdit *lineEditForInput) {
    lineEditForInput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineEditForInput->setPlaceholderText(R"(Введите входные данные...)");
}

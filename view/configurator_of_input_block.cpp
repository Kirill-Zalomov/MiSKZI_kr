#include "configurator_of_input_block.h"


const QSize ConfiguratorOfInputBlock::labelForInputFormatFixedSize = QSize(120, 30);
const QSize ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize = QSize(180, 30);
const QSize ConfiguratorOfInputBlock::lineEditForInputMinSize = QSize(300, 30);


ConfiguratorOfInputBlock::ConfiguratorOfInputBlock() {}


void ConfiguratorOfInputBlock::configureLabelForInputFormat(QLabel *labelForInputFormat) {
    labelForInputFormat->setText("Формат данных:");
    labelForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    labelForInputFormat->setBaseSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputFormat->setMinimumSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputFormat->setMaximumSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
}


void ConfiguratorOfInputBlock::configureComboBoxForInputFormat(QComboBox *comboBoxForInputFormat) {
    comboBoxForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    comboBoxForInputFormat->setBaseSize(ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize);
    comboBoxForInputFormat->setMinimumSize(ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize);
    comboBoxForInputFormat->setMaximumSize(ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize);

    comboBoxForInputFormat->addItem("Текстовый");
    comboBoxForInputFormat->addItem("Двоичный");
    comboBoxForInputFormat->addItem("Шестнадцатеричный");
}


void ConfiguratorOfInputBlock::configureLineEditFotInput(QLineEdit *lineEditForInput) {
    lineEditForInput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineEditForInput->setMinimumSize(ConfiguratorOfInputBlock::lineEditForInputMinSize);
    lineEditForInput->setPlaceholderText(R"(Введите входные данные...)");
}

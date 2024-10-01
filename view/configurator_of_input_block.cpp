#include "configurator_of_input_block.h"


const QSize ConfiguratorOfInputBlock::labelForInputFormatFixedSize = QSize(130, 30);
const QSize ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize = QSize(190, 30);
const QSize ConfiguratorOfInputBlock::lineEditForInputMinSize = QSize(300, 30);


ConfiguratorOfInputBlock::ConfiguratorOfInputBlock() {}


void ConfiguratorOfInputBlock::configureLabelForInputFormat(QLabel *labelForInputFormat) {
    labelForInputFormat->setText("Формат данных:");
    labelForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    labelForInputFormat->setBaseSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputFormat->setMinimumSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputFormat->setMaximumSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputFormat->setFont(Model::mainFont);
}


void ConfiguratorOfInputBlock::configureLabelForInputCounter(QLabel *labelForInputCount) {
    labelForInputCount->setText(QString("%1 / %2").arg(labelForInputCount->text().size()).arg(Model::maxCharactersNumber));
    labelForInputCount->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    labelForInputCount->setBaseSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputCount->setMinimumSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputCount->setMaximumSize(ConfiguratorOfInputBlock::labelForInputFormatFixedSize);
    labelForInputCount->setFont(Model::mainFont);
    labelForInputCount->setAlignment(Qt::AlignCenter);
}


void ConfiguratorOfInputBlock::configureComboBoxForInputFormat(QComboBox *comboBoxForInputFormat) {
    comboBoxForInputFormat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    comboBoxForInputFormat->setBaseSize(ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize);
    comboBoxForInputFormat->setMinimumSize(ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize);
    comboBoxForInputFormat->setMaximumSize(ConfiguratorOfInputBlock::comboBoxForInputFormatFixedSize);
    comboBoxForInputFormat->setFont(Model::mainFont);

    comboBoxForInputFormat->addItem("Текстовый");
    comboBoxForInputFormat->addItem("Двоичный");
    comboBoxForInputFormat->addItem("Шестнадцатеричный");
}


void ConfiguratorOfInputBlock::configureLineEditFotInput(QLineEdit *lineEditForInput) {
    lineEditForInput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineEditForInput->setMinimumSize(ConfiguratorOfInputBlock::lineEditForInputMinSize);
    lineEditForInput->setPlaceholderText(R"(Введите входные данные...)");
    lineEditForInput->setMaxLength(Model::maxCharactersNumber);
    lineEditForInput->setFont(Model::mainFont);
}

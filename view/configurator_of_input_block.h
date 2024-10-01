#ifndef CONFIGURATOR_OF_INPUT_BLOCK_H
#define CONFIGURATOR_OF_INPUT_BLOCK_H


#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include "model.h"


class ConfiguratorOfInputBlock {

private:
    static const QSize labelForInputFormatFixedSize;
    static const QSize comboBoxForInputFormatFixedSize;
    static const QSize lineEditForInputMinSize;

public:
    ConfiguratorOfInputBlock();

    void configureLabelForInputFormat(QLabel *labelForInputFormat);
    void configureLabelForInputCounter(QLabel *labelForInputCount);
    void configureComboBoxForInputFormat(QComboBox *comboBoxForInputFormat);
    void configureLineEditFotInput(QLineEdit *lineEditForInput);

};


#endif // CONFIGURATOR_OF_INPUT_BLOCK_H

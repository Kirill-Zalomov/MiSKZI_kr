#ifndef CONFIGURATOR_OF_INPUT_BLOCK_H
#define CONFIGURATOR_OF_INPUT_BLOCK_H


#include <QLabel>
#include <QComboBox>
#include <QLineEdit>


class ConfiguratorOfInputBlock {

public:
    ConfiguratorOfInputBlock();

    void configureLabelForInputFormat(QLabel *labelForInputFormat);
    void configureComboBoxForInputFormat(QComboBox *comboBoxForInputFormat);
    void configureLineEditFotInput(QLineEdit *lineEditForInput);
};


#endif // CONFIGURATOR_OF_INPUT_BLOCK_H

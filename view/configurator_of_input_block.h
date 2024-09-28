#ifndef INITIALIZEROFINPUTBLOCK_H
#define INITIALIZEROFINPUTBLOCK_H


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


#endif // INITIALIZEROFINPUTBLOCK_H

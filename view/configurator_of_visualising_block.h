#ifndef CONFIGURATOR_OF_VISUALISING_BLOCK_H
#define CONFIGURATOR_OF_VISUALISING_BLOCK_H


#include <QLabel>
#include <QFont>


class ConfiguratorOfVisualisingBlock {

private:
    static const QSize labelSize;
    static const QFont labelFont;

    void labelGeneralConfiguration(QLabel *label);

public:
    ConfiguratorOfVisualisingBlock();

    void configureLabelDescription(QLabel *labelDescription);
    void configureLabelWords(QLabel *labelWords);
    void configureLabelCalculations(QLabel *labelCalculations);
    void configureLabelKeys(QLabel *labelKeys);
};


#endif // CONFIGURATOR_OF_VISUALISING_BLOCK_H

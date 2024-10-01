#ifndef CONFIGURATOR_OF_VISUALISING_BLOCK_H
#define CONFIGURATOR_OF_VISUALISING_BLOCK_H


#include <QScrollArea>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>
#include "model.h"


class ConfiguratorOfVisualisingBlock {

private:
    static const QSize labelSize;

    void labelGeneralConfiguration(QLabel *label);

public:
    ConfiguratorOfVisualisingBlock();

    void configureLabelDescription(QLabel *labelDescription);
    void configureLabelWords(QLabel *labelWords);
    void configureLabelCalculations(QLabel *labelCalculations);
    void configureLabelKeys(QLabel *labelKeys);
    void configureScrollAreaForVisualizing(QScrollArea *scrollArea);
};


#endif // CONFIGURATOR_OF_VISUALISING_BLOCK_H

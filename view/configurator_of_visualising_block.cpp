#include "configurator_of_visualising_block.h"


const QSize ConfiguratorOfVisualisingBlock::labelSize = QSize(250, 1000);


ConfiguratorOfVisualisingBlock::ConfiguratorOfVisualisingBlock() {}


void ConfiguratorOfVisualisingBlock::labelGeneralConfiguration(QLabel *label) {
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    label->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    label->setBaseSize(ConfiguratorOfVisualisingBlock::labelSize);
    label->setMinimumSize(ConfiguratorOfVisualisingBlock::labelSize);
    label->setFont(Model::mainFont);
}


void ConfiguratorOfVisualisingBlock::configureLabelDescription(QLabel *labelDescription) {
    this->labelGeneralConfiguration(labelDescription);
    labelDescription->setText("#1");
}


void ConfiguratorOfVisualisingBlock::configureLabelWords(QLabel *labelWords) {
    this->labelGeneralConfiguration(labelWords);
    labelWords->setText("#2");
}


void ConfiguratorOfVisualisingBlock::configureLabelCalculations(QLabel *labelCalculations) {
    this->labelGeneralConfiguration(labelCalculations);
    labelCalculations->setText("#3");
}


void ConfiguratorOfVisualisingBlock::configureLabelKeys(QLabel *labelKeys) {
    this->labelGeneralConfiguration(labelKeys);
    labelKeys->setText("#4");
}


void ConfiguratorOfVisualisingBlock::configureScrollAreaForVisualizing(QScrollArea *scrollArea) {
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setAlignment(Qt::AlignCenter);
}

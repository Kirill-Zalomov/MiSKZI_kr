#ifndef VIEW_H
#define VIEW_H


#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "configurator_of_input_block.h"
#include "configurator_of_control_buttons_block.h"
#include "configurator_of_visualising_block.h"


class View : public QMainWindow {
    Q_OBJECT

private:
    QScopedPointer<QWidget> mainContainer;
    QScopedPointer<QVBoxLayout> mainContainerLayout;

    // Элементы пользовательского интерфейса для блока ввода исходных данных
    QScopedPointer<QHBoxLayout> containerForInput;
    QScopedPointer<QLabel> labelForInputFormat;
    QScopedPointer<QComboBox> comboBoxForInputFormat;
    QScopedPointer<QLineEdit> lineEditForInput;

    // Элементы пользовательского интерфейса для блока управляющих кнопок
    QScopedPointer<QHBoxLayout> containerForControlButtons;
    QScopedPointer<QPushButton> buttonBacwardToTheStart;
    QScopedPointer<QPushButton> buttonTenStepsBacward;
    QScopedPointer<QPushButton> buttonOneStepBacward;
    QScopedPointer<QPushButton> buttonOneStepForward;
    QScopedPointer<QPushButton> buttonTenStepsForward;
    QScopedPointer<QPushButton> buttonForwardToTheFinish;
    QScopedPointer<QPushButton> buttonAutoRun;

    // Элементы пользовательского интерфейса для блока визуализации работы алгоритма
    QScopedPointer<QScrollArea> containerForVisualisingBlock;
    QScopedPointer<QHBoxLayout> containerForVisualisingBlockLayout;
    QScopedPointer<QLabel> labelDescription;
    QScopedPointer<QLabel> labelWords;
    QScopedPointer<QLabel> labelCalculations;
    QScopedPointer<QLabel> labelKeys;


    void initMainWindow();
    void configureMainWindow();
    void addBlocksToMainWindow();

    void initInputBlock();
    void configureInputBlock();
    void addChildWidgetsToInputBlock();

    void initControlButtonsBlock();
    void configureControlButtonsBlock();
    void addChildWidgetsToControlButtonsBlock();

    void initVisualisingBlock();
    void configureVisualisingBlock();
    void addChildWidgetsToVisualisingBlock();

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

signals:

};


#endif /* VIEW_H */

#ifndef MODEL_H
#define MODEL_H


#include <QObject>
#include <QRegularExpressionValidator>
#include <QFont>
#include "input_format_enum.h"


class Model : public QObject {
    Q_OBJECT

private:
    QString inputText;
    InputFormat inputFormat;
    bool visualizationStarted;

public:
    static constexpr qsizetype maxCharactersNumber { 1000 };
    static const QFont mainFont;

    explicit Model(QObject *parent = nullptr);
    ~Model();

    QString getInputText() const;
    void setInputText(const QString &newInputText);

    InputFormat getInputFormat() const;
    void setInputFormat(const InputFormat &newInputFormat);

    bool getVisualizationStarted() const;
    void setVisualizationStarted(const bool &newValue);

signals:
    void inputTextHasBeenProcessed(const QString& text);
    void setEnableToControlButtons(const bool &newState);
    void setNewNumberOfCharactersInInput(const qsizetype &newNumber);
    void changeButtonRunOrPauseState(const bool &run);

};


#endif /* MODEL_H */

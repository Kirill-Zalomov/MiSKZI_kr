#ifndef MODEL_H
#define MODEL_H


#include <QObject>
#include "input_format_enum.h"


class Model : public QObject {
    Q_OBJECT

private:
    QString inputText;
    InputFormat inputFormat;

public:
    explicit Model(QObject *parent = nullptr);
    ~Model();

    QString getInputText() const;
    void setInputText(const QString &newInputText);

    InputFormat getInputFormat() const;
    void setInputFormat(const InputFormat &newInputFormat);
    void setInputFormat(const quint32 &newInputFormat);

signals:
    void inputTextHasBeenProcessed(const QString& text);

};


#endif /* MODEL_H */

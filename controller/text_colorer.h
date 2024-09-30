#ifndef TEXTCOLORER_H
#define TEXTCOLORER_H


#include <QString>


class TextColorer {

    static const QString colorValues[];

public:
    TextColorer();

    enum TextColor {
        grey,
        red,
        green,
        yellow,
        blue,
        magenta,
        orange,
        cyan,
        white
    };

    QString colorText(const QString &text, const TextColor &color);
};


#endif // TEXTCOLORER_H

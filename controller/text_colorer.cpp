#include "text_colorer.h"


const QString TextColorer::colorValues[] = {
    "grey"
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "orange",
    "cyan",
    "white"
};


TextColorer::TextColorer() {}


QString TextColorer::colorText(const QString &text, const TextColor &color) {
    return QString("<p style=\"line-height:20%; background-color: %1;\">%2</p>")
        .arg(TextColorer::colorValues[color])
        .arg(text);
}

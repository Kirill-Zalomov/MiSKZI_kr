#include "controller.h"
#include "view.h"
#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    View view;
    view.show();
    return application.exec();
}

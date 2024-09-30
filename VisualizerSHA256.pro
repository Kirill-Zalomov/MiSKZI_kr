QT += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


RESOURCES += resources.qrc


SOURCES += \
    controller/text_colorer.cpp \
    main.cpp \
    model/model.cpp \
    signals_with_slots_connector.cpp \
    view/configurator_of_control_buttons_block.cpp \
    view/configurator_of_input_block.cpp \
    view/configurator_of_visualising_block.cpp \
    view/view.cpp \
    controller/controller.cpp


HEADERS += \
    controller/text_colorer.h \
    model/input_format_enum.h \
    model/model.h \
    controller/controller.h \
    signals_with_slots_connector.h \
    view/configurator_of_control_buttons_block.h \
    view/configurator_of_input_block.h \
    view/configurator_of_visualising_block.h \
    view/view.h


INCLUDEPATH += \
    model \
    view \
    controller


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES +=

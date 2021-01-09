QT += quick sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        appcore.cpp \
        database/connection.cpp \
        database/statistic.cpp \
        lesson/getlesson.cpp \
        lesson/lesson.cpp \
        lesson/listmodel_course.cpp \
        lesson/task.cpp \
        lesson/task2.cpp \
        lesson/task3.cpp \
        main.cpp \
        statistics/rebuildsentencestatcombinations.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    appcore.h \
    database/connection.h \
    database/statistic.h \
    lesson/getlesson.h \
    lesson/lesson.h \
    lesson/listmodel_course.h \
    lesson/task.h \
    lesson/task2.h \
    lesson/task3.h \
    statistics/rebuildsentencestatcombinations.h

QT += quick sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        appcore.cpp \
        auth/accesscodegenerate.cpp \
        auth/accesscoderead.cpp \
        auth/accesscodewrite.cpp \
        auth/checkifuserexists.cpp \
        auth/createaccount.cpp \
        auth/createemptyaccount.cpp \
        auth/emailvalidate.cpp \
        auth/generaterandomusername.cpp \
        auth/loginvalidate.cpp \
        auth/passwordvalidate.cpp \
        auth/sourceandencriptedstringscompare.cpp \
        auth/stringtomd5.cpp \
        auth/userlogin.cpp \
        auth/userregisterdata.cpp \
        database/connection.cpp \
        database/statistic.cpp \
        lesson/lesson.cpp \
        lesson/listmodel_course.cpp \
        lesson/task.cpp \
        lesson/task2.cpp \
        lesson/task3.cpp \
        main.cpp \
        statistics/rebuildsentencestatcombinations.cpp \
        unittests/unittest.cpp \
        usefulclasses/randomlettersandnumbers.cpp

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
    auth/accesscodegenerate.h \
    auth/accesscoderead.h \
    auth/accesscodewrite.h \
    auth/checkifuserexists.h \
    auth/createaccount.h \
    auth/createemptyaccount.h \
    auth/emailvalidate.h \
    auth/generaterandomusername.h \
    auth/loginvalidate.h \
    auth/passwordvalidate.h \
    auth/sourceandencriptedstringscompare.h \
    auth/stringtomd5.h \
    auth/userlogin.h \
    auth/userregisterdata.h \
    database/connection.h \
    database/statistic.h \
    lesson/lesson.h \
    lesson/listmodel_course.h \
    lesson/task.h \
    lesson/task2.h \
    lesson/task3.h \
    statistics/rebuildsentencestatcombinations.h \
    unittests/unittest.h \
    usefulclasses/randomlettersandnumbers.h

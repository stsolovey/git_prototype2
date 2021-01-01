import QtQuick 2.0
import QtQuick.Controls 2.12
import Util 1.0
Item {
    Connections { // устанавливаем соединение
        target: appCore // целевой объект для соединения
    }
    width: Util.appWidth
    height: Util.appHeight



    Button
    {
        id: btn1
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 5
        text: "To Class"
        onClicked: {

            appCore.askForClass("hello i'm sql query i want to get the class"); // DELETEME
            appCore.askForExercise()
            loader.source = Util.linkPath
        }
    }
    Button
    {
        id: closedEgg
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 5
        text: "Another Class"
        onClicked: {
            //loader.source = "/exercises/ex1.qml"

        }
        enabled: false
    }


}

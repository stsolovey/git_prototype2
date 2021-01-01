import QtQuick 2.0
import QtQuick.Controls 2.12
import Util 1.0
Item {
    Component.onCompleted: {
        appCore.askActualDirection()
    }
    Connections { // устанавливаем соединение
        target: appCore // целевой объект для соединения

        function onSendActualDirection(direction) {
            textid.text = direction
        }
    }
    Loader {
        id: loader
        anchors.fill: parent
    }
    Text {
        id: textid
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        text: "placeholder"
    }

    Button
    {
        id: btn1
        //anchors.top: parent.top
        anchors.centerIn: parent
        text: "To Categories"
        onClicked: {
            loader.source = "/categories/cat1.qml"
            btn1.visible = false
            btn1.enabled = false
            textid.visible = false
        }
    }


}

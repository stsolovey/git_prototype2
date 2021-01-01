import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: itemID
    anchors.centerIn: parent
Text {
    id: textid
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter
    text: Util.userName
}

Button
{
    id: btn1
    //anchors.top: parent.top
    anchors.centerIn: parent
    text: "To Course 1"
    onClicked: {
        loader.source = "/courses/course1.qml"
    }
}
Button
{
    id: btn2
    anchors.top: btn1.bottom
    anchors.horizontalCenter: btn1.horizontalCenter
    anchors.topMargin: 15
    text: "To Course 2"
    onClicked: {
        loader.source = "/courses/course2.qml"
    }
}
}

import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick 2.12

Item {
    id: itemId
    width: 640
    height: 480
    Text {
        id: textId
        text: qsTr("Name of the exercise 2.")
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }
    TextArea {
        id: textareaID
        placeholderText: "Type in English"
        width: 350
        height: 100
        anchors.top: textId.bottom
        anchors.horizontalCenter: textId.horizontalCenter
        anchors.topMargin: 15
        background: Rectangle {
                    radius: 10
                    border.color: "#e5e5e5"
                    border.width: 2
                }
    }

    Button
    {
        id: checkButtonId
        anchors.top: textareaID.bottom
        anchors.horizontalCenter: textareaID.horizontalCenter
        anchors.topMargin: 15
        text: "Check"
        onClicked: {
            loader.source = "/exercises/ex3.qml"
        }
    }
}

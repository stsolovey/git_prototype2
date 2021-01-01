import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick 2.12
import Util 1.0

Item {
    id: itemId
    width: 640
    height: 480
    Loader {
        id: loader2
        anchors.fill: itm
    }
    Component.onCompleted: {

    }

    Text {
        id: textId
        text: qsTr(Util.textOfTheExcercise)
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
            appCore.checkAnswer(textareaID.text)
            loader2.source = "/review/answer_review.qml"
        }
    }
    Item {
        id: itm
        anchors.top: checkButtonId.bottom
        anchors.horizontalCenter: checkButtonId.horizontalCenter
    }
}

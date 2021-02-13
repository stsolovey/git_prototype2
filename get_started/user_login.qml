import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Item {

    id: itemID
    anchors.centerIn: parent
    property int textFieldWidth: 200
    Text {
        id: textid
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 25
        text: "Создайте профиль"
        font.bold: true

    }

    TextField  {
        id: textInputAgeId
        anchors.top: textid.bottom
        anchors.topMargin: 15
        anchors.horizontalCenter: parent.horizontalCenter
        width: textFieldWidth
        background: Rectangle {

            radius: 3
            border {
                width: 1
                color: "lightgray"
            }

        }
        placeholderText: qsTr("Возраст")
    }
    TextField  {
        id: textInputNameId
        anchors.top: textInputAgeId.bottom
        anchors.topMargin: 15
        anchors.horizontalCenter: parent.horizontalCenter
        width: textFieldWidth
        background: Rectangle {
        //anchors.horizontalCenter: parent.horizontalCenter

            radius: 3
            border {
                width: 1
                color: "lightgray"
            }

        }
        placeholderText: qsTr("Имя")
    }
    TextField  {
        id: textInputMailId
        anchors.top: textInputNameId.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: textFieldWidth
        background: Rectangle {
            radius: 3
            border {
                width: 1
                color: "lightgray"
            }
        }
        placeholderText: qsTr("Электронная почта")
    }
    TextField  {
        id: textInputPasswordId
        anchors.top: textInputMailId.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: textFieldWidth
        background: Rectangle {
            radius: 3
            border {
                width: 1
                color: "lightgray"
            }
        }
        placeholderText: qsTr("Пароль")
    }
    Button {
        id: createAccountButtonId
        anchors.top: textInputPasswordId.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Создать аккаунт"
        width: textFieldWidth

        contentItem: Text {
                    text: parent.text
                    color: parent.pressed ? "black" : "#BFBFBF"
                    font.bold: true
                    font.italic: true
                }
        background: Rectangle {
            radius: 3
            color: "#F2F2F2"
            border.width: 1
            border.color: parent.pressed ? "#F2F2F2" : "#E6E6E6"

        }
        onClicked: {
            loader.source = "/mainPageContent.qml"
        }

    }

    Button {
        id: backButtonId
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 30
        text: "<< Back"
        onClicked: {
            loader.source = "/mainPageContent.qml"
        }
    }
}

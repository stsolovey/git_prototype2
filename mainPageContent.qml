import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: itemID
    anchors.centerIn: parent
    Text {
        id: textid
        anchors.bottom: btn1.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: windowid.height/4
        text: "Learn a language. Forever."

    }

    Button
    {
        id: btn1
        width: btn2.width
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: btn2.top
        anchors.bottomMargin: 15
        text: "GET STARTED"
        onClicked: {
            loader.source = "/get_started/registration.qml"
        }
    }
    Button
    {
        id: btn2
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: btn1.horizontalCenter
        anchors.bottomMargin: windowid.height/4
        text: "I ALREADY HAVE AN ACCOUNT"
        onClicked: {
            loader.source = "/login_form.qml"
        }
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick 2.12
import Util 1.0

Item {
    id: itemId
    width: 640
    height: 480
    Text {
        id: textId
        text: qsTr(Util.textOfTheReview)
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button
    {
        id: checkButtonId
        anchors.top: textId.bottom
        anchors.horizontalCenter: textId.horizontalCenter
        anchors.topMargin: 15
        text: "End"
        onClicked: {
            //appCore.askForExercise()
            loader.source = "/courses/course1.qml"
        }
    }
}

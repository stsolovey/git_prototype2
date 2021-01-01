import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick 2.12
import Util 1.0

Item {

    Text {
        id: textId
        text: Util.textOfTheReview
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 5
    }

    Button
    {
        id: rightAnswer
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 5
        text: "NEXT >>"
        //signal checkButtonClicked()
        onClicked: {
            itemId.nextButtonClicked()
        }
    }
}

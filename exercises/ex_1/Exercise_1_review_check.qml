import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick 2.12
import Util 1.0


    Button
    {
        id: checkButtonId
        enabled: Util.isTheCheckButtonActive
        //anchors.top: taskItem.bottom
        //anchors.horizontalCenter: taskItem.horizontalCenter
        //anchors.topMargin: 15
        text: "Check"

        onClicked: {

            itemId.checkButtonClicked()
            //appCore.checkAnswer("textareaID.text")
            //loader2.source = "/review/answer_review.qml"
        }
    }


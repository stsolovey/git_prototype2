import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick 2.12
import Util 1.0

Item {
    id: lessonReviewItemId
    width: 640
    height: 480
    focus: true
    signal endOfTheLesson_Clicked()
    Text {
        id: textId
        text: qsTr(Util.textOfTheLessonReview)
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    onEndOfTheLesson_Clicked: {
        Util.setDefaultSettings()
        loader.source = "/mainPageContent.qml"
    }

    Keys.onPressed: {
        console.log("lesson_review.qml item key pressed:", event.key)
        if ((event.key === Qt.Key_Return) || (event.key === Qt.Key_Enter)) {
                            event.accepted = true;
                            lessonReviewItemId.endOfTheLesson_Clicked()
                        }
    }

    Button
    {
        id: checkButtonId
        anchors.top: textId.bottom
        anchors.horizontalCenter: textId.horizontalCenter
        anchors.topMargin: 15
        text: "End"
        onClicked: {
            lessonReviewItemId.endOfTheLesson_Clicked()
        }
    }
}

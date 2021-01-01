import QtQuick.Controls 2.12
import QtQuick 2.12
import Util 1.0
import "../../exercises/ex_1/"

Item {
    id: itemId
    width: 640
    height: 480
    //focus: true
    signal checkButtonClicked()
    signal nextButtonClicked()
    Keys.onPressed: {
        console.log(" Ex_1.qml item key pressed:", event.key)
        if ((event.key === Qt.Key_Return) || (event.key === Qt.Key_Enter)) {
                            event.accepted = true;
                            itemId.nextButtonClicked()
                        }
    }

    Loader {
        id: taskLoader
        anchors.fill: taskItem
        function show(str1) {source = str1;}
        function hide()
        {
            sourceComponent = undefined;
        }
    }
    Loader {
        id: underTaskLoader
        anchors.centerIn: underTaskItem
        function show(str1) {source = str1;}
        function hide()
        {
            sourceComponent = undefined;
        }
    }
    Component.onCompleted: {
        taskLoader.show("Exercise_1_task_text_area.qml")
        underTaskLoader.show("Exercise_1_review_check.qml")
    }
    onCheckButtonClicked:
    {
        appCore.checkAnswer(Util.ex1_task_answer)
        Util.textAreaEnabled = false
        underTaskLoader.hide()
        underTaskLoader.show( Util.valueReview ? "Exercise_1_review_right_answer.qml" : "Exercise_1_review_wrong_answer.qml" )
    }
    onNextButtonClicked:
    {
        if (Util.endOftheLesson) {
            taskLoader.hide()
            underTaskLoader.hide()
            loader.source = "/review/lesson_review.qml"
            //console.log("onNextButtonClicked, expected true:", Util.endOftheLesson)
        } else {
            //console.log("onNextButtonClicked, expected false:", Util.endOftheLesson)
            appCore.askForExercise()
            taskLoader.hide()
            Util.textAreaEnabled = true
            Util.ex1_task_answer = ""
            taskLoader.show("Exercise_1_task_text_area.qml")
            underTaskLoader.hide()
            underTaskLoader.show("Exercise_1_review_check.qml")
        }

    }

    ProgressBar {
        id: progbar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        value: Util.progressBar_value
        from: 0
        to: Util.lesson_lenght
    }

    Text {
        id: textId
        text: qsTr(Util.textOfTheExcercise)
        anchors.top: progbar.top
        anchors.horizontalCenter: progbar.horizontalCenter
        anchors.topMargin: 15
    }

    Item {
        id: taskItem
        anchors.top: textId.bottom
        anchors.horizontalCenter: textId.horizontalCenter
        anchors.topMargin: 15
        width: 350
        height: 100
    }

    Item {
        id: underTaskItem
        anchors.top: taskItem.bottom
        anchors.horizontalCenter: taskItem.horizontalCenter
        anchors.topMargin: 15
        width: 350
        height: 100
    }
}

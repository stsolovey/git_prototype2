pragma Singleton // Указываем, что этот QML Тип является синглетоном
import QtQuick 2.0

Item {

    property int appWidth: 640
    property int appHeight: 480
    property int typeOfTheExercise: 0
    property int points: 0
    property int lesson_lenght: 0
    property int progressBar_value: 0
    property bool valueReview: false
    property bool isTheCheckButtonActive: false
    property bool isTheCheckLoaderActive: true
    property bool textAreaEnabled: true
    property bool endOftheLesson: false
    property string textOfTheExcercise: "textOfTheExcercise"
    property string textOfTheReview: "textOfTheReview"
    property string textOfTheLessonReview: "textOfTheLessonReview"
    property string taskText: "taskText"
    property string rightAnswerText: "rightAnswer"
    property string linkPath: "main.qml"
    property string userName: ""
    property string currentCourse: "ru_en_categories"
    property string ex1_task_answer: ""
    property string title: "Type in translation to English"
    property string placeholder: "Type in English"
    function getPathToTheExercisePage(type)
    {
        switch(type)
        {
        case -1:
            linkPath = "/review/lesson_review.qml"
            return
        case 1:
            linkPath = "/exercises/ex_1/Exercise_1.qml"
            return
        case 2:
            linkPath = "/exercises/ex2.qml"
            return
        case 3:
            linkPath = "/exercises/ex3.qml"
            return
        default:
            linkPath = "main.qml"
            return
        }
    }

    Connections { // устанавливаем соединение
        target: appCore // целевой объект для соединения
        function onSendLessonInfo (lenght){
            lesson_lenght = lenght
        }

        function onSendExercise(exType, exText) {
            typeOfTheExercise = exType
            textOfTheExcercise = exText
            getPathToTheExercisePage(exType)
            //console.log("onSendExercis", typeOfTheExercise)
            //console.log("linkPath", linkPath)
        }
        function onSendProgressBarValue (pbv) {
            progressBar_value = pbv
        }

        function onSendReview(boolReturn, reviewMessage) {
  //          console.log("boolReturn is ", boolReturn, "reviewMessage is ", reviewMessage);
            valueReview = boolReturn
            textOfTheReview = reviewMessage
        }
        function onEndOfTheLesson(review) {
            endOftheLesson = true
            linkPath = "/review/lesson_review.qml"
            console.log("onEndOfTheLesson review", endOftheLesson, review)
            textOfTheLessonReview = review
        }
        function onSendUserName(name) {
            userName = name
        }
    }

    onEx1_task_answerChanged: {
        //console.log("ex1_task_answer is", ex1_task_answer)
        if (ex1_task_answer=="") {
            isTheCheckButtonActive = false
        } else {
            isTheCheckButtonActive = true
        }
    }
    function swithchCheckToReview(type){

    }

    function setDefaultSettings() {

        typeOfTheExercise = 0
        points =  0
        lesson_lenght =  0
        progressBar_value =  0
        valueReview =  false
        isTheCheckButtonActive =  false
        isTheCheckLoaderActive =  true
        textAreaEnabled =  true
        endOftheLesson =  false
        textOfTheExcercise =  "textOfTheExcercise"
        textOfTheReview =  "textOfTheReview"
        textOfTheLessonReview =  "textOfTheLessonReview"
        taskText = "taskText"
        rightAnswerText =  "rightAnswer"
        linkPath = "main.qml"
        userName = ""
        currentCourse = "ru_en_categories"
        ex1_task_answer = ""
        title = "Type in translation to English"
        placeholder = "Type in English"

    }
}

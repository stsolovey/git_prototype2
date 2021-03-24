import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import Util 1.0

Item {
    id: itemID
    anchors.centerIn: parent
    property int textFieldWidth: 200
    property int age;
    property string login;
    property string email;
    property string pass;
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
        validator: IntValidator {bottom: 1; top: 99}
    }
    TextField  {
        id: textInputNameId
        anchors.top: textInputAgeId.bottom
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
        placeholderText: qsTr("Логин")
        onTextChanged: {
            appCore.checkLogin(textInputNameId.text)
        }
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
        onTextChanged: {
            appCore.checkEmail(textInputMailId.text)

            //appCore.checkIfLoginExists(textInputMailId.text)
            //validation(text);
        }
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

        onTextChanged: {
                        appCore.checkPassword(textInputPasswordId.text)
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
        enabled: !Util.loginExists &
                 Util.loginIsValid &
                 !Util.emailExists &
                 Util.emailIsValid &
                 Util.passwordIsValid

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
            age = parseInt(textInputAgeId.text)
            login = textInputNameId.text
            email = textInputMailId.text
            pass = textInputPasswordId.text
            appCore.userRegistration(age, login, email, pass)
            //loader.source = "/mainPageContent.qml"
            console.log("hhhhm: ", !Util.loginExists &
                        Util.loginIsValid &
                        !Util.emailExists &
                        Util.emailIsValid &
                        Util.passwordIsValid)
            textInputAgeId.text = ""
            textInputNameId.text = ""
            textInputMailId.text = ""
            textInputPasswordId.text = ""
        }

    }
//*************************************//

    Text {
        id: textid2
        anchors.top: createAccountButtonId.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 50
        text: "Уже есть аккаунт?"
        font.bold: true

    }

    TextField  {
        id: textFieldLoginId
        anchors.top: textid2.bottom
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
        placeholderText: qsTr("Логин")
    }
    TextField  {
        id: textFieldPasswordId
        anchors.top: textFieldLoginId.bottom
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
        placeholderText: qsTr("Пароль")
    }

    Button {
        id: loginButtonId
        anchors.top: textFieldPasswordId.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Войти"
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
            //loader.source = "/mainPageContent.qml"
            appCore.authentification(textFieldLoginId.text, textFieldPasswordId.text)
            if (Util.resultOfAuthentification){

            appCore.compareAccessCodeFromFileAndFromDataBaseSlot()
            }
            if (Util.resultOfAccessCodeComparision) {

                loader.source = "/courses/course1.qml"
            }
            console.log("Util.resultOfAccessCodeComparision from registration.qml", Util.resultOfAccessCodeComparision)
            console.log("login", textFieldLoginId.text, "password", textFieldPasswordId.text)
        }

    }

    Button {
        id: justStartButtonId
        anchors.top: loginButtonId.bottom
        anchors.topMargin: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Просто начать заниматься"
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
            //appCore.createDefaultAccount()
            //loader.source = "/mainPageContent.qml"

        }

    }




}

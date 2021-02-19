import QtQuick.Controls 2.12
import QtQuick 2.0

Item {
    id: unitTestItem

    Button {
        id: unitTest1Button
        anchors.bottom: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        text: "accessCodeGenerate"


        onClicked:
        {
            //unitTest.accessCodeGenerate
            unitTest.accessCodeGenerate()
            //unitTest.accessCodeRead()
            //unitTest.accessCodeWrite()
        }
    }
    Button {
        id: unitTest2Button
        anchors.top: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        text: "accessCodeWrite"


        onClicked:
        {
            //unitTest.accessCodeGenerate
            //unitTest.accessCodeGenerate()
            //unitTest.accessCodeRead()
            unitTest.accessCodeWrite()
        }
    }
    Button {
        id: unitTest3Button
        anchors.top: unitTest2Button.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "accessCodeWrite"


        onClicked:
        {
            //unitTest.accessCodeGenerate
            //unitTest.accessCodeGenerate()
            //unitTest.accessCodeRead()
            unitTest.stringToMd5()
        }
    }
    Button {
        id: unitTest4Button
        anchors.top: unitTest3Button.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "accessCodeWriteToDataBase"


        onClicked:
        {
            unitTest.accessCodeWriteToDataBase("slusla", "helloiamslusla")
        }
    }
}

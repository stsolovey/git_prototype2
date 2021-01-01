/*import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import Util 1.0

Window  {
    property bool visiblity: true
    width: Util.appWidth
    height: Util.appHeight
    visible: true
    title: qsTr("Hello World")
    Component.onCompleted: {
        appCore.askUserName()
        loader.source = "mainPageContent.qml"
    }

    Loader {
        id: loader
        anchors.fill: parent
    }


import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.12
}*/
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window {
    id: windowid
    visible: true
    width: 640
    height: 480
    title: qsTr("Atom.")
    /*Item {
        id: headerId
        Text {
            id: leftHeaderText
            anchors.left: parent.left
            text: "currentCourse"
        }
        Text {
            id: rightHeaderText
            anchors.right: parent.right
            text: "slusla"
        }
    }*/

    Component.onCompleted: {
        appCore.askUserName()
        loader.source = "mainPageContent.qml"
    }

    Loader {
        id: loader
        anchors.fill: parent
    }



}

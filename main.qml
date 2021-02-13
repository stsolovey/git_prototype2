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

//import Util 1.0
Window {
    id: windowid
    visible: true
    width: 480
    height: 640
    title: qsTr("Atom.")

    Component.onCompleted: {
        //appCore.userLogin()
        loader.hide();
        loader.source =  Util.linkPath ;
    }

    Loader {
        id: loader
        anchors.fill: parent
        function show(string_source) {source = string_source;}
        function hide()
        {
            source = "";
            sourceComponent = undefined;
        }
    }
}

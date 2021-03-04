import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import Util 1

Window {
    id: windowid
    visible: true
    width: 480
    height: 640
    title: qsTr("Atom.")
    Component.onCompleted: {
        //appCore.compareAccessCodeFromFileAndFromDataBaseSlot()
        console.log("Util.resultOfAccessCodeComparision", Util.resultOfAccessCodeComparision)
        if (Util.resultOfAccessCodeComparision) {
            loader.source = "/courses/course1.qml"
        }
        else {
            loader.source =  "mainPageContent.qml"
        }
        console.log("Util.resultOfAccessCodeComparision", Util.resultOfAccessCodeComparision)

    }
    Loader {
        id: loader
        anchors.fill: parent
    }
}

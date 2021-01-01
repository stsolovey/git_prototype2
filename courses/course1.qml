import QtQuick 2.0
import QtQuick.Controls 2.12
import Util 1.0
Item {

    Connections { // устанавливаем соединение
        target: appCore // целевой объект для соединения
    }

property string query: ""
    ListView {
        id: tableView
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        boundsBehavior: Flickable.StopAtBounds
        anchors.margins: 5
        spacing: 10
        ScrollBar.vertical: ScrollBar {}
        delegate: Rectangle {
            property int btnID: id_cat
            property string textid: "txt" + id_cat
            property string rectid: "rect" + id_cat
            id: rectid
            anchors.horizontalCenter: parent.horizontalCenter
            width: 250
            height: 50
            color: "#F8F9F9"
            radius: 15

                Text {
                    id: textid
                    anchors.leftMargin: 10
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    text: id_cat + ": " + name
                }

                Button {
                    id: btbID
                    anchors.rightMargin: 10
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    text:"To Class >>"
                    onClicked: {
                        //console.log("id category: ", id_cat)
                        appCore.askForClass(id_cat);
                        appCore.askForExercise();
                        loader.source = Util.linkPath
                    }
                }
        }

        model: myModel

    }

}

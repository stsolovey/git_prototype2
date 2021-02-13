import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: itemID
    Component.onCompleted: {


        appCore.userLogin()
        loader.hide();
        loader.source =  Util.linkPath ;


    }
}

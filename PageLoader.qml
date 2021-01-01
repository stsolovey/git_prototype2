pragma Singleton // Указываем, что этот QML Тип является синглетоном
import QtQuick 2.0

Item {
    property int appWidth: 640
    property int appHeight: 480
    function getPage(pageNumber)
    {
        switch(pageNumber)
        {
        case 1:
            return "/direction/dir1.qml"
        case 2:
            return "/categories/cat1.qml"
        case 3:
            return "/exercises/ex2.qml"
        default:
            return "Nothing found"
        }
    }
}

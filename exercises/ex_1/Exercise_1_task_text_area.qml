import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick 2.12
import Util 1.0

TextArea {
id: textareaID
placeholderText: Util.placeholder
focus:Util.textAreaEnabled
width: 350
height: 100
text: ""
enabled: Util.textAreaEnabled


Keys.onPressed: {
            if (((event.key === Qt.Key_Return) || (event.key === Qt.Key_Enter)) && text==="") {

                    event.accepted = true;

                } else if ((event.key === Qt.Key_Return) || (event.key === Qt.Key_Enter)) {
                    event.accepted = true;
                    if (Util.textAreaEnabled)
                        {
                            itemId.checkButtonClicked()
                            console.log("itemId.checkButtonClicked():")
                        }
                }
            }

/*Keys.onReleased: {
    if (event.key===16777220) {
        text = text2
    } else text2 = text
}*/

onTextChanged: {
    console.log("underTaskLoader.source:", underTaskLoader.source)
    Util.ex1_task_answer = text
    /*console.log("Text has changed to:", text)
    if (text == "")
    {
        console.log("text is empty")
    }*/
}

background: Rectangle {
            radius: 10
            border.color: "#e5e5e5"
            border.width: 2
        }
}

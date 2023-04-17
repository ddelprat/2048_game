import QtQuick 2.15

Item {
    id: carre
    property alias item1Width: carre.width
    property alias item1Height: carre.height
    width: 50
    height: 50
    property alias text1: text1
    property alias rectangleColor: rectangle.color
    property alias text1FontpixelSize: text1.font.pixelSize
    property alias text1Text: text1.text
    focus: true

    Rectangle {
        id: rectangle
        color: valueToColor(text1.text)
        border.color: "black"
        border.width: 1
        anchors.fill: parent
        radius: 5


        Text {
            id: text1
            text: ""
            anchors.centerIn: parent
            font.pixelSize: Math.min(parent.width, parent.height) * 0.8
            maximumLineCount: 1
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Arial"
            font.bold: true
            clip: true
            visible: (text1.text !== "0")
        }

        function valueToColor(value) {
            switch (value) {
                case "0": return "#7A7A7A";
                case "2": return "#ffff55";
                case "4": return "#ff5555";
                case "8": return "#5555ff";
                case "16": return "#ffaa55";
                case "32": return "#55ff55";
                case "64": return "#aa5500";
                case "128": return "#ff55ff";
                case "256": return "#5500aa";
                case "512": return "#aaaa55";
                case "1024": return "#550000";
                case "2048": return "#ff55aa";
            }
            return "#ff55aa"
        }
    }
}

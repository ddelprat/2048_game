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
            maximumLineCount: 1
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: Math.min(parent.width, parent.height) * Math.pow(0.8,text.length)
            font.family: "Arial"
            font.bold: true
            clip: true
            visible: (text1.text !== "0")
        }

        function valueToColor(value) {
            switch (value) {
                case "0": return "#CCC1B2";
                case "2": return "#EDE5DB";
                case "4": return "#ede0c8";
                case "8": return "#f2b178";
                case "16": return "#f59562";
                case "32": return "#f67c5e";
                case "64": return "#f65e3c";
                case "128": return "#eed072";
                case "256": return "#edcc5f";
                case "512": return "#ecc84f";
                case "1024": return "#550000";
                case "2048": return "#edc22e";
                default: return "#edc22e";
            }
        }
    }
}

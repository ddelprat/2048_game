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
        color: (text1.text === "0") ? "#ff0000" : "#f5f5f5"
        border.color: "black"
        border.width: 1
        anchors.fill: parent

        Text {
            id: text1
            text: qsTr("")
            anchors.centerIn: parent
            font.pixelSize: Math.min(parent.width, parent.height) * 0.8
            maximumLineCount: 1
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Arial"
            font.bold: true
            clip: true
        }
    }
}

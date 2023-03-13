import QtQuick 2.15

Item {
    id: carre
    property alias item1Width: carre.width
    property alias item1Height: carre.height
    width: 400
    height: 400
    property alias rectangleColor: rectangle.color
    property alias text1FontpixelSize: text1.font.pixelSize
    property alias text1Text: text1.text
    focus: true

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        Text {
            id: text1
            text: qsTr("2")
            anchors.fill: parent
            font.pixelSize: 200
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Arial"
            font.bold: true
        }
    }

}

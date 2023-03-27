import QtQuick 2.15

GridView {
    id: grid
    anchors.fill: parent
    model: GridModel {}

    cellWidth: Math.min(parent.width, parent.height) / 4
    cellHeight: cellWidth

    delegate: Rectangle {
        width: grid.cellWidth
        height: grid.cellHeight
        color: "#cccccc"
        margin: 10
        radius: Math.min(width, height) / 4

        Text {
            text: model.display
            font.pixelSize: grid.cellHeight / 2
            anchors.centerIn: parent
        }
    }
}

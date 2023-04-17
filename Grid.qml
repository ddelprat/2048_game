import QtQuick 2.15
import QtQuick.Controls 2.15

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
        radius: 5

        Text {
            text: model.display
            font.pixelSize: grid.cellHeight / 2
            anchors.centerIn: parent
            visible: (model.value !== 0)
        }
    }
}

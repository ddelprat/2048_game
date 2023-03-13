import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 450
    height: 800
    visible: true
    color: "#f4f0c9"
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 14
        y: 15
        width: 156
        height: 124
        color: "#ffe7aa"
        radius: 10
    }

    Rectangle {
        id: score
        x: 191
        y: 15
        width: 112
        height: 56
        color: "#ffffff"
        radius: 10
    }

    Rectangle {
        id: new_game
        x: 191
        y: 83
        width: 112
        height: 56
        color: "#ffffff"
        radius: 10
    }

    Rectangle {
        id: best_score
        x: 318
        y: 15
        width: 112
        height: 56
        color: "#ffffff"
        radius: 10
    }

    Rectangle {
        id: undo
        x: 318
        y: 83
        width: 112
        height: 56
        color: "#ffffff"
        radius: 10
    }

    Rectangle {
        id: rectangle1
        x: 15
        y: 190
        width: 420
        height: 420
        color: "#5f4444"
        radius: 10
    }
}

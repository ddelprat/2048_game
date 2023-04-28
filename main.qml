import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.3


Window {


    width: 450
    height: 800
    visible: true
    color: "#ffe7aa"
    title: qsTr("2048")



    property int score: vueObjetBoardGame.score
    property int best: vueObjetBoardGame.best
    property int loose: vueObjetBoardGame.loose


    property variant board : vueObjetBoardGame.getBoardAsQvector()



    Rectangle {
        id: scoreWindow
        x: 191
        y: 15
        width: 112
        height: 56
        color: "#bcac9e"
        radius: 10
        Text {
            width: 113
            height: 25
                color: "#ffffff"
                text:  score
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 14
                font.styleName: "Gras"
                font.family: "Tahoma"
                anchors.verticalCenterOffset: 12
                anchors.horizontalCenterOffset: 0
                anchors.centerIn: parent
        }

        Text {
            id: text1
            x: 14
            y: 0
            width: 84
            height: 24
            color: "#ffffff"
            text: qsTr("SCORE")
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            font.family: "Tahoma"
            font.styleName: "Gras"
        }

    }

    Rectangle {
        id: new_game
        x: 191
        y: 83
        width: 112
        height: 56
        color: "#8f7a65"
        radius: 10
        Text{
            x: 0
            y: 0
            width: 112
            height: 56
            visible: true
            text: "RESTART"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.styleName: "Gras"
            font.family: "Tahoma"
            font.pointSize: 16
            color: "white" // définit la couleur du texte
        }
        Button {
            id: restart
            x: 0
            y: 0
            width: 112
            height: 56
            opacity: 0
            visible: true
            text: qsTr("RESTART")
            focusPolicy: Qt.NoFocus
            font.preferShaping: true
            clip: false
            font.styleName: "Gras"
            font.bold: false
            font.pointSize: 16
            font.family: "Tahoma"
            icon.color: "#689967"
            flat: false
            onClicked: {
                vueObjetBoardGame.restart();
                board = vueObjetBoardGame.getBoardAsQvector();
                //console.log(vueObjetBoardGame.score)
            }
            focus : false
        }
    }


    Rectangle {
        id: best_score
        x: 318
        y: 15
        width: 112
        height: 56
        color: "#bcac9e"
        radius: 10
        Text {
            width: 113
            height: 25
                color: "#ffffff"
                text:  best
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 14
                font.styleName: "Gras"
                font.family: "Tahoma"
                anchors.verticalCenterOffset: 12
                anchors.horizontalCenterOffset: 0
                anchors.centerIn: parent
        }

        Text {
            id: text2
            x: 14
            y: 0
            width: 84
            height: 24
            color: "#ffffff"
            text: qsTr("BEST")
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            font.family: "Tahoma"
            font.styleName: "Gras"
        }
    }

    Rectangle {
        id: rectangle1
        x: 15
        y: 190
        width: 420
        height: 420
        color: "#bbada0"
        radius: 10
        //focus: true
        GridView {
                focus: true
                id: grid
                anchors.fill: parent
                x: 15
                y: 190
                width: 420
                height: 420
                cellWidth: (grid.width) / 4
                cellHeight: (grid.height) / 4
                //spacing: 5
                model: vueObjetBoardGame.getBoardAsQvector().length * vueObjetBoardGame.getBoardAsQvector()[0].length
               // model : 16
                delegate: Case {
                    id: myCase
                    item1Width: grid.cellWidth
                    item1Height: grid.cellHeight
                    text1Text: board[Math.floor(index / 4)][index % 4]
                    //text1Text: modelData[index]
                    Keys.onPressed: function(event){
                      switch (event.key) {
                        case Qt.Key_Up:
                            vueObjetBoardGame.play_up();
                            board = vueObjetBoardGame.getBoardAsQvector();
                            //console.log(vueObjetBoardGame.score)
                          break;
                        case Qt.Key_Down:
                            vueObjetBoardGame.play_down();
                            board = vueObjetBoardGame.getBoardAsQvector();
                          break;
                        case Qt.Key_Right:
                            vueObjetBoardGame.play_right();
                            board = vueObjetBoardGame.getBoardAsQvector();
                            break;
                        case Qt.Key_Left:
                            vueObjetBoardGame.play_left();
                            board = vueObjetBoardGame.getBoardAsQvector();
                            break;
                        case Qt.Key_Space:
                            vueObjetBoardGame.restart();
                            board = vueObjetBoardGame.getBoardAsQvector();
                            break;
                      }
                    }
                }
        }

    }

    Rectangle {
        id: rectangle_joli
        x: 15
        y: 15
        width: 124
        height: 124
        color: "#edc22e"
        radius: 10

        Text {
            id: text3
            x: 0
            y: 0
            width: 124
            height: 124
            color: "#ffffff"
            text: qsTr("2048")
            font.pixelSize: 45
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.styleName: "Gras"
            font.family: "Arial"
        }
    }

    Text {
        id: texte_fin
        x: 48
        y: 611
        width: 354
        height: 86
        text: qsTr("Game Over !")
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Tahoma"
        visible: if(loose==0){
                     false}
                else{
                     true}
    }
}

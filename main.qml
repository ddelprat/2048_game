import QtQuick 2.15
import QtQuick.Window 2.15


Window {


    width: 450
    height: 800
    visible: true
    color: "#f4f0c9"
    title: qsTr("2048")



    property int score: vueObjetBoardGame.score


    property variant board : vueObjetBoardGame.getBoardAsQvector()


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
        id: scoreWindow
        x: 191
        y: 15
        width: 112
        height: 56
        color: "#ffffff"
        radius: 10
        Text {
                text: "Score: " + score
                anchors.centerIn: parent
            }
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
                            console.log(vueObjetBoardGame.score)
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
                      }
                    }
                }
            }

    }
}

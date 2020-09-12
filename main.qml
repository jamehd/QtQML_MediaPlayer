import QtQuick 2.6
import QtQuick.Controls 2.4

ApplicationWindow {
    visible: true
    width: 1920
    height: 1080
//    visibility: "FullScreen"
    title: qsTr("Media Player")
    Item {
        anchors.fill: parent
//        transform: Scale { origin.x: 0; origin.y: 0; xScale: 0.5; yScale: 0.5}

        //Backgroud of Application
        Image {
            id: backgroud
            anchors.fill: parent
            source: "qrc:/Image/background.png"
        }
        //Header
        AppHeader{
            id: headerItem
            width: parent.width
            height: 141
            playlistButtonStatus: 0
            onClickPlaylistButton: {
                playlistButtonStatus ? playlist.open() : playlist.close()
            }
        }

        //Playlist
        PlaylistView{
            id: playlist
            y: headerItem.height
            width: 675
            height: parent.height - headerItem.height
        }

        //Media Info
        MediaInfoControl{
            id: mediaInfoControl
            anchors.top: headerItem.bottom
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.leftMargin: playlist.width*playlist.position
            anchors.bottom: parent.bottom
        }
    }
}

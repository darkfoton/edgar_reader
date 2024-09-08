import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import EDGARReader

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("EDGAR Reader")

    color: "#eeeeee"

    CoreViewModel {
        id: coreViewModelID
    }

    Loader {
        id: popupLoaderID
        anchors.fill: parent

        onLoaded: {
            item.visible = true
        }
    }

    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            Layout.fillWidth: true
            height: 40

            color: "#dddddd"

            RowLayout {
                anchors.fill: parent
                anchors.margins: 5

                Button {
                    Layout.fillHeight: true
                    implicitWidth: 70

                    text: "Download"

                    onClicked: {
                        coreViewModelID.startDownloading()
                    }
                }

                Item {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Button {
                    Layout.fillHeight: true
                    implicitWidth: 70

                    text: "Properties"

                    onClicked: {
                        popupLoaderID.source = "AppPropertiesView.qml"
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        ListView {
            id: downloadsListID
            Layout.fillWidth: true

            model: coreViewModelID.downloadsList

            implicitHeight: 80// * downloadsListID.model.count

            delegate: Rectangle {
                width: parent.width
                height: 40

                color: "#dddddd"

                RowLayout {
                    anchors.fill: parent

                    Item {
                        Layout.fillHeight: true
                        implicitWidth: 200

                        Label {
                            anchors.centerIn: parent
                            text: "Downloading " + object.name
                        }
                    }

                    Item {
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: 5

                            color: "white"

                            Rectangle {
                                x: 0
                                y: 0
                                width: parent.width * object.progress
                                height: parent.height

                                color: object.failed
                                       ? "red"
                                       : object.finished
                                            ? "grey"
                                            : "green"
                            }
                        }
                    }

                    Button {
                        Layout.fillHeight: true
                        Layout.margins: 5
                        implicitWidth: height

                        text: "X"

                        onClicked: {
                            coreViewModelID.deleteDownload(index)
                        }
                    }
                }
            }
        }
    }
}

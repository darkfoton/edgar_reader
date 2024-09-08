import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Windows
import QtQuick.Layouts
import QtQuick.Dialogs

import EDGARReader

Popup {
    width: 640
    height: 480

    anchors.centerIn: parent

    ApplicationPropertiesViewModel {
        id: propertiesViewModelID
    }

    FolderDialog {
        id: folderDialogID

        visible: false

        onAccepted: {
            if (title === "Downloads folder")
            {
                propertiesViewModelID.setDownloadsFolderLocation(selectedFolder)
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        spacing: 0

        Item {
            Layout.fillWidth: true
            implicitHeight: 40

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10

                Item {
                    Layout.fillHeight: true
                    implicitWidth: 100

                    Label {
                        anchors.centerIn: parent

                        text: "Submissions url:"
                    }
                }

                TextField {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    text: propertiesViewModelID.submissionsUrl

                    onTextChanged: {
                        propertiesViewModelID.submissionsUrl = text
                    }
                }

                Button {
                    Layout.fillHeight: true
                    implicitWidth: 50

                    text: "Open"

                    onClicked: {
                        Qt.openUrlExternally(propertiesViewModelID.submissionsUrl)
                    }
                }
            }
        }

        Item {
            Layout.fillWidth: true
            implicitHeight: 40

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10

                Item {
                    Layout.fillHeight: true
                    implicitWidth: 100

                    Label {
                        anchors.centerIn: parent

                        text: "Company facts url:"
                    }
                }

                TextField {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    text: propertiesViewModelID.companyfactsUrl

                    onTextChanged: {
                        propertiesViewModelID.companyfactsUrl = text
                    }
                }

                Button {
                    Layout.fillHeight: true
                    implicitWidth: 50

                    text: "Open"

                    onClicked: {
                        Qt.openUrlExternally(propertiesViewModelID.companyfactsUrl)
                    }
                }
            }
        }

        Item {
            Layout.fillWidth: true
            implicitHeight: 40

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10

                Item {
                    Layout.fillHeight: true
                    implicitWidth: 100

                    Label {
                        anchors.centerIn: parent

                        text: "Downloads folder:"
                    }
                }

                TextField {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    text: propertiesViewModelID.downloadsFolderLocation

                    onTextChanged: {
                        propertiesViewModelID.downloadsFolderLocation = text
                    }
                }

                Button {
                    Layout.fillHeight: true
                    implicitWidth: 50

                    text: "Browse"

                    onClicked: {
                        folderDialogID.title = "Downloads folder"
                        folderDialogID.currentFolder = propertiesViewModelID.downloadsFolderLocation
                        folderDialogID.open()
                    }
                }
            }
        }

        Item {
            Layout.fillWidth: true
            implicitHeight: 40

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10

                Item {
                    Layout.fillHeight: true
                    implicitWidth: 100

                    Label {
                        anchors.centerIn: parent

                        text: "Company emeil:"
                    }
                }

                TextField {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    text: propertiesViewModelID.companyEmeil

                    onTextChanged: {
                        propertiesViewModelID.companyEmeil = text
                    }
                }

                Item {
                    Layout.fillHeight: true
                    implicitWidth: 50
                }
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    onClosed: {
        parent.source = ""
    }
}

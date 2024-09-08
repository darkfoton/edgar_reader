#ifndef COREVIEWMODEL_H
#define COREVIEWMODEL_H

#include <QQuickItem>
#include <QNetworkAccessManager>
#include "downloadslistmodel.h"

class CoreViewModel : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* downloadsList READ downloadsList NOTIFY downloadsListChanged FINAL)
    QML_ELEMENT
public:
    CoreViewModel();

    QAbstractListModel* downloadsList();

    Q_INVOKABLE void startDownloading();
    Q_INVOKABLE void deleteDownload(int index);

signals:
    void downloadsListChanged();

private:
    QNetworkAccessManager m_networkManager;
    DownloadsListModel m_downloadList;
};

#endif // COREVIEWMODEL_H

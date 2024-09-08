#ifndef DOWNLOADSLISTMODEL_H
#define DOWNLOADSLISTMODEL_H

#include <QAbstractListModel>

class DownloadViewModel;
class QNetworkReply;

enum DownloadsListModel_e {
    DownloadsListModel_object = Qt::UserRole + 1
};

class DownloadsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DownloadsListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addDownload(const QString& folder, const QString& name, QNetworkReply* reply);
    void removeDownload(int index);

    QHash<int,QByteArray> roleNames() const override;

private:
    QList<std::shared_ptr<DownloadViewModel>> m_list;
};

#endif // DOWNLOADSLISTMODEL_H

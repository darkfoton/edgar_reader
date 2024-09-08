#include "downloadslistmodel.h"
#include "downloadviewmodel.h"

DownloadsListModel::DownloadsListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int DownloadsListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_list.size();
}

QVariant DownloadsListModel::data(const QModelIndex &index, int role) const
{
    QVariant result;

    if (!index.isValid())
        return result;

    if (role == DownloadsListModel_object)
    {
        result = QVariant::fromValue(m_list.at(index.row()).get());
    }

    return result;
}

void DownloadsListModel::addDownload(const QString& folder, const QString& name, QNetworkReply* reply)
{
    beginInsertRows(QModelIndex(), m_list.size(), m_list.size());
    m_list.push_back(std::make_shared<DownloadViewModel>(folder, name, reply));
    endInsertRows();
}

void DownloadsListModel::removeDownload(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_list.at(index)->cancel();
    m_list.removeAt(index);
    endRemoveRows();
}

QHash<int,QByteArray> DownloadsListModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[DownloadsListModel_object] = "object";
    return roles;
}

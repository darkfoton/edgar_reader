#include "downloadviewmodel.h"
#include <QFile>

DownloadViewModel::DownloadViewModel()
    : QQuickItem()
    , m_name("")
    , m_reply(nullptr)
    , m_progress(0.0)
    , m_finished(false)
    , m_failed(false)
    , m_folder("")
{

}

DownloadViewModel::DownloadViewModel(const QString &folder, const QString& name, QNetworkReply* reply)
    : QQuickItem()
    , m_name(name)
    , m_reply(reply)
    , m_progress(0.0)
    , m_finished(false)
    , m_failed(false)
    , m_folder(folder)
{
    connect(reply, &QNetworkReply::finished, this, &DownloadViewModel::onFileDownloaded);
    connect(reply, &QNetworkReply::errorOccurred, this, &DownloadViewModel::onError);
    connect(reply, &QNetworkReply::downloadProgress, this, &DownloadViewModel::onDownloadProgress);
}

QString DownloadViewModel::name() const
{
    return m_name;
}

double DownloadViewModel::progress() const
{
    return m_progress;
}

bool DownloadViewModel::finished() const
{
    return m_finished;
}

bool DownloadViewModel::failed() const
{
    return m_failed;
}

void DownloadViewModel::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    double progress = bytesReceived * 1.0 / bytesTotal;
    if (m_progress != progress)
    {
        m_progress = progress;
        emit progressChanged();
    }
}

void DownloadViewModel::onFileDownloaded()
{
    m_finished = true;
    emit finishedChanged();

    auto buffer = m_reply->readAll();

    QFile file(m_folder + "/" + m_name + ".zip");
    file.open(QFile::WriteOnly);
    file.write(buffer);
    file.close();
}

void DownloadViewModel::onError(QNetworkReply::NetworkError error)
{
    m_failed = true;
    emit failedChanged();
}

void DownloadViewModel::cancel()
{
    if (m_reply->isRunning())
    {
        m_reply->abort();
    }
}

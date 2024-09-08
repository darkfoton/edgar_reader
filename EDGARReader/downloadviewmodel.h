#ifndef DOWNLOADVIEWMODEL_H
#define DOWNLOADVIEWMODEL_H

#include <QQuickItem>
#include <QNetworkReply>

class DownloadViewModel : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT FINAL)
    Q_PROPERTY(double progress READ progress NOTIFY progressChanged FINAL)
    Q_PROPERTY(bool finished READ finished NOTIFY finishedChanged FINAL)
    Q_PROPERTY(bool failed READ failed NOTIFY failedChanged FINAL)
    QML_ELEMENT
public:
    DownloadViewModel();
    DownloadViewModel(const QString& folder, const QString& name, QNetworkReply* reply);

    QString name() const;
    double progress() const;
    bool finished() const;
    bool failed() const;

    void cancel();

private slots:
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onFileDownloaded();
    void onError(QNetworkReply::NetworkError error);

signals:
    void progressChanged();
    void finishedChanged();
    void failedChanged();

private:
    QString m_name;
    QString m_folder;
    double m_progress;
    bool m_finished;
    bool m_failed;
    QNetworkReply* m_reply;
};

#endif // DOWNLOADVIEWMODEL_H

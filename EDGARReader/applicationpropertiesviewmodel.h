#ifndef APPLICATIONPROPERTIESVIEWMODEL_H
#define APPLICATIONPROPERTIESVIEWMODEL_H

#include <QQuickItem>
#include <QSettings>

class ApplicationPropertiesViewModel : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString submissionsUrl READ submissionsUrl WRITE setSubmissionsUrl NOTIFY submissionsUrlChanged FINAL)
    Q_PROPERTY(QString companyfactsUrl READ companyfactsUrl WRITE setCompanyfactsUrl NOTIFY companyfactsUrlChanged FINAL)
    Q_PROPERTY(QString downloadsFolderLocation READ downloadsFolderLocation WRITE setDownloadsFolderLocation NOTIFY downloadsFolderLocationChanged FINAL)
    Q_PROPERTY(QString companyEmeil READ companyEmeil WRITE setCompanyEmeil NOTIFY companyEmeilChanged FINAL)
    QML_ELEMENT
public:
    ApplicationPropertiesViewModel();
    virtual ~ApplicationPropertiesViewModel();

    QString submissionsUrl() const;
    QString companyfactsUrl() const;
    QString downloadsFolderLocation() const;
    QString companyEmeil() const;

    void setSubmissionsUrl(const QString& value);
    void setCompanyfactsUrl(const QString& value);
    void setDownloadsFolderLocation(const QString& value);
    void setCompanyEmeil(const QString& value);

    Q_INVOKABLE void setSubmissionsUrl(const QUrl& value);
    Q_INVOKABLE void setCompanyfactsUrl(const QUrl& value);
    Q_INVOKABLE void setDownloadsFolderLocation(const QUrl& value);

signals:
    void submissionsUrlChanged();
    void companyfactsUrlChanged();
    void downloadsFolderLocationChanged();
    void companyEmeilChanged();

private:
    QSettings m_settings;

    QString m_submissionsUrlKey;
    QString m_companyfactsUrlKey;
    QString m_downloadsFolderLocationKey;
    QString m_companyEmeilKey;

    QString m_submissionsUrl;
    QString m_companyfactsUrl;
    QString m_downloadsFolderLocation;
    QString m_companyEmeil;
};

#endif // APPLICATIONPROPERTIESVIEWMODEL_H

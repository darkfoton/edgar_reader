#include "applicationpropertiesviewmodel.h"

ApplicationPropertiesViewModel::ApplicationPropertiesViewModel()
    : QQuickItem()
    , m_settings("darkfoton", "EDGAR Reader")
    , m_submissionsUrlKey("submissions_url")
    , m_companyfactsUrlKey("companyfacts_url")
    , m_downloadsFolderLocationKey("downloads_folder_location")
    , m_companyEmeilKey("company_emeil")
{
    m_submissionsUrl = m_settings.value(m_submissionsUrlKey, "https://www.sec.gov/Archives/edgar/daily-index/bulkdata/submissions.zip").toString();
    m_companyfactsUrl = m_settings.value(m_companyfactsUrlKey, "https://www.sec.gov/Archives/edgar/daily-index/xbrl/companyfacts.zip").toString();
    m_downloadsFolderLocation = m_settings.value(m_downloadsFolderLocationKey).toString();
    m_companyEmeil = m_settings.value(m_companyEmeilKey).toString();
}

ApplicationPropertiesViewModel::~ApplicationPropertiesViewModel()
{
    m_settings.setValue(m_submissionsUrlKey, m_submissionsUrl);
    m_settings.setValue(m_companyfactsUrlKey, m_companyfactsUrl);
    m_settings.setValue(m_downloadsFolderLocationKey, m_downloadsFolderLocation);
    m_settings.setValue(m_companyEmeilKey, m_companyEmeil);
}

QString ApplicationPropertiesViewModel::submissionsUrl() const
{
    return m_submissionsUrl;
}

QString ApplicationPropertiesViewModel::companyfactsUrl() const
{
    return m_companyfactsUrl;
}

QString ApplicationPropertiesViewModel::downloadsFolderLocation() const
{
    return m_downloadsFolderLocation;
}

QString ApplicationPropertiesViewModel::companyEmeil() const
{
    return m_companyEmeil;
}

void ApplicationPropertiesViewModel::setSubmissionsUrl(const QString& value)
{
    if (m_submissionsUrl != value)
    {
        m_submissionsUrl = value;
        emit submissionsUrlChanged();
    }
}

void ApplicationPropertiesViewModel::setCompanyfactsUrl(const QString& value)
{
    if (m_companyfactsUrl != value)
    {
        m_companyfactsUrl = value;
        emit companyfactsUrlChanged();
    }
}

void ApplicationPropertiesViewModel::setDownloadsFolderLocation(const QString& value)
{
    if (m_downloadsFolderLocation != value)
    {
        m_downloadsFolderLocation = value;
        emit downloadsFolderLocationChanged();
    }
}

void ApplicationPropertiesViewModel::setCompanyEmeil(const QString& value)
{
    if (m_companyEmeil != value)
    {
        m_companyEmeil = value;
        emit companyEmeilChanged();
    }
}

void ApplicationPropertiesViewModel::setSubmissionsUrl(const QUrl& value)
{
    auto path = value.toLocalFile();
    if (m_submissionsUrl != path)
    {
        m_submissionsUrl = path;
        emit submissionsUrlChanged();
    }
}

void ApplicationPropertiesViewModel::setCompanyfactsUrl(const QUrl& value)
{
    auto path = value.toLocalFile();
    if (m_companyfactsUrl != path)
    {
        m_companyfactsUrl = path;
        emit companyfactsUrlChanged();
    }
}

void ApplicationPropertiesViewModel::setDownloadsFolderLocation(const QUrl& value)
{
    auto path = value.toLocalFile();
    if (m_downloadsFolderLocation != path)
    {
        m_downloadsFolderLocation = path;
        emit downloadsFolderLocationChanged();
    }
}

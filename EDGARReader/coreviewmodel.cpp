#include "coreviewmodel.h"
#include <QSettings>
#include <QNetworkReply>

CoreViewModel::CoreViewModel()
{

}

QAbstractListModel* CoreViewModel::downloadsList()
{
    return &m_downloadList;
}

void CoreViewModel::startDownloading()
{
    QSettings settings("darkfoton", "EDGAR Reader");
    auto folder_location = settings.value("downloads_folder_location").toString();
    auto submissions_url = settings.value("submissions_url").toUrl();
    auto companyfacts_url = settings.value("companyfacts_url").toUrl();
    auto company_emeil = settings.value("company_emeil").toString();

    QNetworkRequest submissions_request(submissions_url);
    submissions_request.setRawHeader("User-Agent", company_emeil.toUtf8());
    submissions_request.setRawHeader("Accept-Encoding", "gzip, deflate");
    submissions_request.setRawHeader("Host", "www.sec.gov");
    m_downloadList.addDownload(folder_location, "submissions", m_networkManager.get(submissions_request));

    QNetworkRequest companyfacts_request(companyfacts_url);
    companyfacts_request.setRawHeader("User-Agent", company_emeil.toUtf8());
    companyfacts_request.setRawHeader("Accept-Encoding", "gzip, deflate");
    companyfacts_request.setRawHeader("Host", "www.sec.gov");
    m_downloadList.addDownload(folder_location, "companyfacts", m_networkManager.get(companyfacts_request));
}

void CoreViewModel::deleteDownload(int index)
{
    m_downloadList.removeDownload(index);
}

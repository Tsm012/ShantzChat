#include "httpclient.h"
#include <QDebug>
#include <QSslConfiguration>

HttpClient::HttpClient(QObject* parent) : QObject(parent)
{
    // Initialize QNetworkAccessManager
    manager = new QNetworkAccessManager(this);

    // Connect the finished signal of QNetworkAccessManager to the onRequestFinished slot
    connect(manager, &QNetworkAccessManager::finished, this, &HttpClient::onRequestFinished);
}

void HttpClient::sendGetRequest(const QUrl& url)
{
    QNetworkRequest request(url);

    // Send the GET request
    manager->get(request);
}

void HttpClient::onRequestFinished(QNetworkReply* reply)
{
    if (reply->error()) {
        // If there is an error, emit an empty result or error message
        emit requestFinished("Error: " + reply->errorString());
        qDebug() << reply->errorString();
        reply->deleteLater();
        return;
    }

    // If the request was successful, read the response
    QString answer = reply->readAll();
    emit requestFinished(answer);  // Emit the result via a signal

    // Clean up
    reply->deleteLater();
}

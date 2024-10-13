#pragma once

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class HttpClient : public QObject
{
    Q_OBJECT

public:
    explicit HttpClient(QObject* parent = nullptr);
    void sendGetRequest(const QUrl& url);

signals:
    void requestFinished(QString result);  // Signal to emit the result of the request

private slots:
    void onRequestFinished(QNetworkReply* reply);

private:
    QNetworkAccessManager* manager;
};

#endif // HTTPCLIENT_H


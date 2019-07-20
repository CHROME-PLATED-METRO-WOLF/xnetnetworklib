#include "xnetnetworklib.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QIODevice>
#include <QPixmap>

Xnetnetworklib::Xnetnetworklib()
{
}

QImage Xnetnetworklib::getNetworkImage(QUrl imgUrl)
{
    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(imgUrl);
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply->readAll();
    QImage img(20, 20, QImage::Format_Indexed8);
    img.loadFromData(bytes);
    bytes.clear();
    return img;
}

QImage Xnetnetworklib::getNetworkImage(QString imgUrl)
{
    QUrl url = imgUrl;
    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(url);
    url = NULL;
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply->readAll();
    QImage img(20, 20, QImage::Format_Indexed8);
    img.loadFromData(bytes);
    bytes.clear();
    return img;
}

void Xnetnetworklib::getNetworkFile(QByteArray &dataArray, QUrl url)
{
    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(url);
    url = NULL;
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    dataArray = reply->readAll();

}

void Xnetnetworklib::getNetworkFile(QByteArray &dataArray, QString url)
{
    QUrl dataUrl = url;
    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(dataUrl);
    dataUrl = NULL;
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    dataArray = reply->readAll();

}

void Xnetnetworklib::obsoleteDownloadfile(QFile &path, QUrl url)
{
    if ( path.open(QIODevice::ReadWrite) )
    {
        QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
        QNetworkRequest request(url);
        url = NULL;
        QNetworkReply *reply = netAccManager->get(request);
        reply->ignoreSslErrors();
        QEventLoop loop;
        QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
        loop.exec();
        path.write(reply->readAll());
        path.flush();

    }
}

void Xnetnetworklib::obsoleteDownloadfile(QFile &path, QString url)
{

    if ( path.open(QIODevice::ReadWrite) )
    {
        QUrl dataUrl = url;
        QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
        QNetworkRequest request(dataUrl);
        dataUrl = NULL;
        QNetworkReply *reply = netAccManager->get(request);
        reply->ignoreSslErrors();
        QEventLoop loop;
        QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));

        loop.exec();
        path.write(reply->readAll());
        path.flush();
    }
}

void Xnetnetworklib::dowloadfile(QFile &path, QUrl url)
{
    QNetworkAccessManager nam;

    if(!path.open(QIODevice::ReadWrite))
        ;
    QNetworkRequest request(url);
    QNetworkReply* reply = nam.get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::readyRead, [&]{
        //this will be called every time a chunk of data is received
        QByteArray data= reply->readAll();
        //qDebug() << "received data of size: " << data.size();
        path.write(data);
    });

    //use the finished signal from the reply object to close the file
    //and delete the reply object
    QObject::connect(reply, &QNetworkReply::finished, [&]{
        qDebug() << "finished downloading";
        QByteArray data= reply->readAll();
        path.write(data);
        reply->deleteLater();

    });
    loop.exec();

}

void Xnetnetworklib::dowloadfile(QFile &path, QString url)
{
    QNetworkAccessManager nam;
    QUrl dataurl = url;
    if(!path.open(QIODevice::ReadWrite))
        ;
    QNetworkRequest request(dataurl);
    QNetworkReply* reply = nam.get(request);
    reply->ignoreSslErrors();
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::readyRead, [&]{
        //this will be called every time a chunk of data is received
        QByteArray data= reply->readAll();
        //qDebug() << "received data of size: " << data.size();
        path.write(data);
    });

    //use the finished signal from the reply object to close the file
    //and delete the reply object
    QObject::connect(reply, &QNetworkReply::finished, [&]{
        qDebug() << "finished downloading";
        QByteArray data= reply->readAll();
        path.write(data);
        path.flush();
        reply->deleteLater();
        loop.exit();
    });
    loop.exec();

}



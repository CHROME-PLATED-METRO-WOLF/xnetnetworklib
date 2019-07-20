#ifndef XNETNETWORKLIB_H
#define XNETNETWORKLIB_H

#include <QImage>
#include <QFile>
#include "xnetnetworklib_global.h"
class XNETNETWORKLIBSHARED_EXPORT Xnetnetworklib
{

public:
    Xnetnetworklib();
    QImage getNetworkImage(QUrl imgUrl);
        QImage getNetworkImage(QString imgUrl);
        int getNetworkFile(QByteArray &dataArray, QUrl url);
        int getNetworkFile(QByteArray &dataArray, QString url);
        int obsoleteDownloadfile(QFile &path, QUrl url);
        int obsoleteDownloadfile(QFile &path, QString url);
        int dowloadfile(QFile &path, QUrl url);
        int dowloadfile(QFile &path, QString url);
};

#endif // XNETNETWORKLIB_H

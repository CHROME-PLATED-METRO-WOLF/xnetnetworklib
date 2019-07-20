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
        void getNetworkFile(QByteArray &dataArray, QUrl url);
        void getNetworkFile(QByteArray &dataArray, QString url);
        void obsoleteDownloadfile(QFile &path, QUrl url);
        void obsoleteDownloadfile(QFile &path, QString url);
        void dowloadfile(QFile &path, QUrl url);
        void dowloadfile(QFile &path, QString url);
};

#endif // XNETNETWORKLIB_H

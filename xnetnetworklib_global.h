#ifndef XNETNETWORKLIB_GLOBAL_H
#define XNETNETWORKLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XNETNETWORKLIB_LIBRARY)
#  define XNETNETWORKLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define XNETNETWORKLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XNETNETWORKLIB_GLOBAL_H
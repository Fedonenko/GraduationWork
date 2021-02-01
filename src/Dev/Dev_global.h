#ifndef DEV_GLOBAL_H
#define DEV_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DEV_LIBRARY)
#  define DEV_EXPORT Q_DECL_EXPORT
#else
#  define DEV_EXPORT Q_DECL_IMPORT
#endif

#endif // DEV_GLOBAL_H

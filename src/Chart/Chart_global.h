#ifndef CHART_GLOBAL_H
#define CHART_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CHART_LIBRARY)
#  define CHART_EXPORT Q_DECL_EXPORT
#else
#  define CHART_EXPORT Q_DECL_IMPORT
#endif

#endif // CHART_GLOBAL_H

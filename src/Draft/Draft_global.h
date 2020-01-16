#ifndef DRAFT_GLOBAL_H
#define DRAFT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DRAFT_LIBRARY)
#  define DRAFT_EXPORT Q_DECL_EXPORT
#else
#  define DRAFT_EXPORT Q_DECL_IMPORT
#endif

#endif // DRAFT_GLOBAL_H

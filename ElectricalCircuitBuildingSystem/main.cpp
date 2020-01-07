#include <QDebug>

#include "application.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);

    Application app(argc, argv);

#ifdef DEBUG
    qDebug() << "Hello Main!";
#endif

    return app.exec();
}

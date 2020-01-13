#include <QDebug>

#include "application.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);

    Application app(argc, argv);

    qDebug() << Application::applicationDirPath();


#ifdef DEBUG
    qDebug() << "Hello Main!";
#endif

    return app.exec();
}

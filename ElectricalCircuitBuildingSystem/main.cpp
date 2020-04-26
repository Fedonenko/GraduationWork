#include <QDebug>
#include <QSplashScreen>

#include "application.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    qDebug() << Application::applicationDirPath();


#ifdef DEBUG
    qDebug() << "Hello Main in DEBUG !";
#endif

    return app.exec();
}

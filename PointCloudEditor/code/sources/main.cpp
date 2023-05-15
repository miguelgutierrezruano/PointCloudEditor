#include "PointCloudEditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PointCloudEditor w;
    w.show();

    QObject::connect(w.quitAction, &QAction::triggered, &a, &QApplication::quit);

    return a.exec();
}

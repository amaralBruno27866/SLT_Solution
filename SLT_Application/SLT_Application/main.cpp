#include "SLT_Application.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SLT_Application w;
    w.show();
    return a.exec();
}

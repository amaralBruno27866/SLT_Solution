#include "SLT_W11.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SLT_W11 w;
    w.show();
    return a.exec();
}

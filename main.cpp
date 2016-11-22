#include "ig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IG w;
    w.show();

    return a.exec();
}

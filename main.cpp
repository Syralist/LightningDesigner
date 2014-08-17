#include "lightningdesigner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LightningDesigner w;
    w.show();

    return a.exec();
}

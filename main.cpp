#include <QtGui/QApplication>
#include <ui/clip.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clip w;
    w.show();

    return a.exec();
}



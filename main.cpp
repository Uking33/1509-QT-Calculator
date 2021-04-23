#include <QApplication>
#include "base.h"
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Base base;
    base.show();
    return app.exec();
}

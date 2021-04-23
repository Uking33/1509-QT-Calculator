#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QGridLayout>
#include "base.h"

class Button:public QPushButton
{
    Q_OBJECT
public:
    Button(const QString &text, const QString & shortcut, int width, int height, QGridLayout *parent, int x, int y);
    ~Button();
};

#endif // BUTTON_H

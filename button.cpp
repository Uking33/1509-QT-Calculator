#include "button.h"

Button::Button(const QString & text, const QString & shortcut, int width, int height,  QGridLayout* parent=0, int x=0, int y=0)
    :QPushButton(text)
{
    setFixedSize(width,height);//设置长宽
    setShortcut(QKeySequence(shortcut));//设置快捷键
    setFont(QFont("幼圆", 13, QFont::Normal));//设置字体
    parent->addWidget(this, x, y);//布局
}
Button::~Button(){}

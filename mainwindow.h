#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);
    ~Calculator();
};

#endif // MAINWINDOW_H

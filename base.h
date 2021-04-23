#ifndef BASE
#define BASE

#define BUTTONWIDTH 50  //按键宽度
#define BUTTONHEIGHT 40  //按键高度
#define MARGIN 15  //内边距
#define SPACING 5  //组件间距

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLineEdit>
#include <QKeyEvent>
#include <math.h>
#include "treenode.h"
#include "button.h"

class Base:public QWidget
{
    Q_OBJECT
public:
    Base();
    ~Base();
    //布局
    QGridLayout *_mainLayout;
    QGridLayout *_oneLayout;
    QFrame *_editFrame;
    QVBoxLayout *_editLayout;
    //组件
    QPushButton *_buttonone[6][5];
    QLineEdit *_edit1;
    QLineEdit *_edit2;

public slots://按键响应槽函数
    //数字按键
    void zeroButtonPress();
    void oneButtonPress();
    void twoButtonPress();
    void threeButtonPress();
    void fourButtonPress();
    void fiveButtonPress();
    void sixButtonPress();
    void sevenButtonPress();
    void eightButtonPress();
    void nineButtonPress();
    void pointButtonPress();
    //符号按键
    void addButtonPress();
    void subButtonPress();
    void mulButtonPress();
    void divButtonPress();
    void equButtonPress();
    //修饰符按键
    void plusminusButtonPress();
    void sqrtButtonPress();
    void pencentButtonPress();
    void fractionButtonPress();
    //清除按键
    void clearButtonPress();
    void delButtonPress();
    void clearnumberButtonPress();
    //储存按键
    void MCButtonPress();
    void MRButtonPress();
    void MSButtonPress();
    void MsaveButtonPress();
    void MdelButtonPress();

protected:
    //键盘响应
    void keyPressEvent(QKeyEvent*);
    //计算数据
    TreeNode *_nownode;//现在的节点
    TreeNode *_head;//头节点
    TreeNode *_numnode;//临时储存数字的节点
    TreeNode *_father;//临时储存父亲节点
    bool _end;//等号结束
    double _result;//计算结果
    double _valueM;//储存的值
    QString sumInput;//计算器运算的总式
    enum Error    //错误枚举
    {
        No_Error=0,
        Error_Div=1,
        Error_XSF=2
    }_error;
    //计算函数
    void initTree();  //创建二叉树
    double calu(TreeNode *now);  //计算
    unsigned short youxian(QString ysf);    //计算优先级
    //按键详细处理函数
    void numberButton(int n);  //数字处理函数
    void fuhaoButton(QString str);  //符号处理函数
    typedef double (*MATH)(double);    //函数指针
    double out();   //提数
    void xiushifuButton(QString str1, QString str2, MATH p, bool xiushi, bool right);  //修饰符处理函数
    //布局函数
    void initBase();
    void initedit(int width);
    void pr(QString up,QString down);
    //错误判断函数
    void reset();
    void ysfreset();
    void fuhaoreset();
};

#endif // BASE

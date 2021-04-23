#include "base.h"

Base::Base()
{
    //设置窗口
    setWindowTitle("计算器-基本型");
    setFixedSize(MARGIN*2+BUTTONWIDTH*5+SPACING*4,50+SPACING*6+MARGIN*2+BUTTONHEIGHT*6);
    //布局
    initedit(BUTTONWIDTH*5+20);
    initBase();
    _mainLayout=new QGridLayout;
    _mainLayout->addWidget(_editFrame, 0, 0);
    _mainLayout->addLayout(_oneLayout, 1, 0);
    _mainLayout->setMargin(MARGIN);
    this->setLayout(_mainLayout);
    //计算初始化
    MCButtonPress();
    clearButtonPress();
}
Base::~Base(){}

/*创建*/
void Base::initedit(int width)//创建基本型组建
{
    //背景色
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::darkBlue);
    //第一行
    _edit1 = new QLineEdit();//初始化显示框
    _edit1->setFixedSize(width-2,20);//文本框大小
    _edit1->setAlignment(Qt::AlignRight);//右对齐
    _edit1->setFrame(false);   // 设置有没有边框
    _edit1->setStyleSheet("font-size : 15px");//字体大小
    _edit1->setEnabled (false);//不可选
    _edit1->setPalette(palette);//颜色
    //第二行
    _edit2 = new QLineEdit();
    _edit2->setFixedSize(width-2,30);
    _edit2->setAlignment(Qt::AlignRight);
    _edit2->setFrame(false);
    _edit2->setStyleSheet("font-size : 25px");
    _edit2->setEnabled (false);
    _edit2->setPalette(palette);
    //无间距垂直布局
    _editLayout = new QVBoxLayout();
    _editLayout->addWidget(_edit1);
    _editLayout->addWidget(_edit2);
    _editLayout->setSpacing(0);
    _editLayout->setMargin(0);
    //边框
    _editFrame=new QFrame();
    _editFrame->setLayout(_editLayout);
    _editFrame->setFrameStyle(QFrame::StyledPanel);
}
void Base::initBase()//创建基本型组建
{
    _valueM=0;
    _oneLayout = new QGridLayout();
    //创建按钮。text为显示的内容，shortcut为快捷键
    QString text[6][5] = {{"MC","MR","MS","M+","M-"},{"←","CE","C","±","√"},{"7","8","9","/","%"},{"4","5","6","*","1/x"},{"1","2","3","-","="},{"0","",".","+",""}};
    QString shortcut[6][5] = {{"Ctrl+L","Ctrl+R","Ctrl+M","Ctrl+P","Ctrl+O"},{"Backspace","Delete","Esc","F9","@"},{"7","8","9","/","%"},{"4","5","6","*","R"},{"1","2","3","-","="},{"0","",".","+",""}};
    for(int i=0;i<6;i++)
        for(int j=0;j<5;j++)
        {
            if ((i!=5||j!=1)&&(i!=5||j!=4))
            {
                if (i==5&&j==0)
                    _buttonone[i][j] = new Button(text[i][j],shortcut[i][j],BUTTONWIDTH*2+5,BUTTONHEIGHT,_oneLayout,i,j);
                else if (i==4&&j==4) _buttonone[i][j] = new Button(text[i][j],shortcut[i][j],BUTTONWIDTH,BUTTONHEIGHT*2+4,_oneLayout,i,j);
                else _buttonone[i][j] = new Button(text[i][j],shortcut[i][j],BUTTONWIDTH,BUTTONHEIGHT,_oneLayout,i,j);
            }
        }
    //连接按钮(可缩减)
    connect(_buttonone[0][0],SIGNAL(clicked()),this,SLOT(MCButtonPress()));
    connect(_buttonone[0][1],SIGNAL(clicked()),this,SLOT(MRButtonPress()));
    connect(_buttonone[0][2],SIGNAL(clicked()),this,SLOT(MSButtonPress()));
    connect(_buttonone[0][3],SIGNAL(clicked()),this,SLOT(MsaveButtonPress()));
    connect(_buttonone[0][4],SIGNAL(clicked()),this,SLOT(MdelButtonPress()));
    connect(_buttonone[1][0],SIGNAL(clicked()),this,SLOT(delButtonPress()));
    connect(_buttonone[1][1],SIGNAL(clicked()),this,SLOT(clearButtonPress()));
    connect(_buttonone[1][2],SIGNAL(clicked()),this,SLOT(clearnumberButtonPress()));
    connect(_buttonone[1][3],SIGNAL(clicked()),this,SLOT(plusminusButtonPress()));
    connect(_buttonone[1][4],SIGNAL(clicked()),this,SLOT(sqrtButtonPress()));
    connect(_buttonone[2][0],SIGNAL(clicked()),this,SLOT(sevenButtonPress()));
    connect(_buttonone[2][1],SIGNAL(clicked()),this,SLOT(eightButtonPress()));
    connect(_buttonone[2][2],SIGNAL(clicked()),this,SLOT(nineButtonPress()));
    connect(_buttonone[2][3],SIGNAL(clicked()),this,SLOT(divButtonPress()));
    connect(_buttonone[2][4],SIGNAL(clicked()),this,SLOT(pencentButtonPress()));
    connect(_buttonone[3][0],SIGNAL(clicked()),this,SLOT(fourButtonPress()));
    connect(_buttonone[3][1],SIGNAL(clicked()),this,SLOT(fiveButtonPress()));
    connect(_buttonone[3][2],SIGNAL(clicked()),this,SLOT(sixButtonPress()));
    connect(_buttonone[3][3],SIGNAL(clicked()),this,SLOT(mulButtonPress()));
    connect(_buttonone[3][4],SIGNAL(clicked()),this,SLOT(fractionButtonPress()));
    connect(_buttonone[4][0],SIGNAL(clicked()),this,SLOT(oneButtonPress()));
    connect(_buttonone[4][1],SIGNAL(clicked()),this,SLOT(twoButtonPress()));
    connect(_buttonone[4][2],SIGNAL(clicked()),this,SLOT(threeButtonPress()));
    connect(_buttonone[4][3],SIGNAL(clicked()),this,SLOT(subButtonPress()));
    connect(_buttonone[4][4],SIGNAL(clicked()),this,SLOT(equButtonPress()));
    connect(_buttonone[5][0],SIGNAL(clicked()),this,SLOT(zeroButtonPress()));
    connect(_buttonone[5][2],SIGNAL(clicked()),this,SLOT(pointButtonPress()));
    connect(_buttonone[5][3],SIGNAL(clicked()),this,SLOT(addButtonPress()));
}

void Base::keyPressEvent(QKeyEvent* event)//键盘响应
{
    if (event->key()==Qt::Key_0||event->key()==16777222) zeroButtonPress();
    if (event->key()==Qt::Key_1||event->key()==16777233) oneButtonPress();
    if ((event->key()==Qt::Key_2||event->key()==16777237)) twoButtonPress();
    if ((event->key()==Qt::Key_3||event->key()==16777239)) threeButtonPress();
    if ((event->key()==Qt::Key_4||event->key()==16777234)) fourButtonPress();
    if ((event->key()==Qt::Key_5||event->key()==16777227)) fiveButtonPress();
    if ((event->key()==Qt::Key_6||event->key()==16777236)) sixButtonPress();
    if ((event->key()==Qt::Key_7)) sevenButtonPress();
    if ((event->key()==Qt::Key_8)) eightButtonPress();
    if ((event->key()==Qt::Key_9)) nineButtonPress();
    if (event->key()==Qt::Key_Enter||event->key()==Qt::Key_Return) equButtonPress();
}
void Base::pr(QString up,QString down)//输出框显示
{
    _edit1->setText(up);
    _edit1->setAlignment(Qt::AlignRight);
    _edit2->setText(down);
    _edit2->setAlignment(Qt::AlignRight);
}


/*清除操作响应函数*/
void Base::clearButtonPress()//全部清除
{
    //数据初始化
    _head=new TreeNode();
    _head->data="head";
    _father=new TreeNode();
    _nownode=new TreeNode();
    _error=No_Error;
    _end=false;
    _result=0;
    sumInput="";
    //输出框初始化
    pr(sumInput,QString::number(_nownode->num));
}
void Base::clearnumberButtonPress()//清除数字
{
    if (!_error&&_nownode->fuhao==false)//不为符号清除节点数据
    {
        if(_nownode->xiushifu)sumInput.remove(sumInput.length()-_nownode->data.length(),_nownode->data.length());//清除总式
        _nownode->data="";
        _nownode->num=0;
        _nownode->data="0";
        _nownode->point=false;
        _nownode->afterPoint=false;
        _nownode->xiushifu=false;
        pr(sumInput,_nownode->data);
    }
    if(_error) clearButtonPress();//错误清除
}
void Base::delButtonPress()//回删数字
{
    if(!_error&&!_nownode->xiushifu&&_nownode->data.length()>0&&!_nownode->fuhao&&!_end)//不出错、没修饰、有长度、非符号、没结束
    {
        if(_nownode->data.endsWith(".")) //小数点结尾
            _nownode->point=false;//减去小数点
        if(_nownode->point) //小数结尾
            _nownode->afterPoint--;//减去小数位
        //减一个字符
        _nownode->data=_nownode->data.left(_nownode->data.length()-1);
        _nownode->num=_nownode->data.toDouble();
        if(_nownode->num==0&&_nownode->data=="") //最后一位时变为0
            _nownode->data="0";
        pr(sumInput,_nownode->data);
    }
}


/*按键前判断函数*/
void Base::reset()
{
    if(!_error&&_end)//等号之后按键。清除所有数据和显示，但结果数据没清除
        clearButtonPress();
    if(_nownode->M&&!_nownode->fuhao)//M之后按键，清除数字
    {
        clearnumberButtonPress();
        _nownode->M=false;
    }
}
void Base::ysfreset()//修饰符之后按数字键。清除当前数字
{
    if(_nownode->xiushifu)
        clearnumberButtonPress();
}
void Base::fuhaoreset()//前面因符号计算出错
{
    if(_nownode->_father!=NULL&&_nownode->_father->data=="/"&&_nownode->data=="0")
    {
        _error=Error_Div;
        pr(sumInput,"除数不能为零");
    }
}


/*储存函数*/
void Base::MCButtonPress()
{
    if(!_error)//判断是否出错
    {
        _valueM=0;
    }
}
void Base::MRButtonPress()
{
    reset();//判断是否等号后
    if(!_error)//判断是否出错
    {
        if(_nownode->xiushifu)sumInput.remove(sumInput.length()-_nownode->data.length(),_nownode->data.length());
        _nownode->num=_valueM;
        _nownode->data=QString::number(_nownode->num);
        pr(sumInput,_nownode->data);
        _nownode->M=true;
    }
}
void Base::MSButtonPress()
{
    if(!_error)//判断是否出错
    {
        //等号提数
        if(_end){_valueM= _result;}
        //运算符后提数
        else if(_nownode->_father!=NULL&&_nownode->_father->fuhao&&_nownode->data.length()==0)
        {
            QString ff=_nownode->_father->data;
            _nownode->_father->data="+";
            _nownode->num=0;
            _nownode->num=calu(_head->ancestor()->RChild);
            _valueM=_valueM+_nownode->num;
            _nownode->data= QString::number(_nownode->num);
            _nownode->_father->data=ff;
        }
        else if(_nownode->fuhao==false&&_nownode->data.length()!=0)//普通数字
        {
            _valueM=_nownode->num;
        }
        _nownode->M=true;
    }
}
void Base::MsaveButtonPress()
{
    if(!_error)//判断是否出错
    {
        //等号提数
        if(_end){_valueM= _valueM+_result;}
        //运算符后提数
        else if(_nownode->_father!=NULL&&_nownode->_father->fuhao&&_nownode->data.length()==0)
        {
            QString ff=_nownode->_father->data;
            _nownode->_father->data="+";
            _nownode->num=0;
            _nownode->num=calu(_head->ancestor()->RChild);
            _valueM=_valueM+_nownode->num;
            _nownode->data= QString::number(_nownode->num);
            _nownode->_father->data=ff;
        }
        else if(_nownode->fuhao==false&&_nownode->data.length()!=0)//普通数字
        {
            _valueM=_valueM+_nownode->num;
        }
        _nownode->M=true;
    }
}
void Base::MdelButtonPress()
{
    if(!_error)//判断是否出错
    {
        //等号提数
        if(_end){_valueM= _valueM-_result;}
        //运算符后提数
        else if(_nownode->_father!=NULL&&_nownode->_father->fuhao&&_nownode->data.length()==0)
        {
            QString ff=_nownode->_father->data;
            _nownode->_father->data="+";
            _nownode->num=0;
            _nownode->num=calu(_head->ancestor()->RChild);
            _valueM=_valueM+_nownode->num;
            _nownode->data= QString::number(_nownode->num);
            _nownode->_father->data=ff;
        }
        else if(_nownode->fuhao==false&&_nownode->data.length()!=0)//普通数字
        {
            _valueM=_valueM-_nownode->num;
        }
        _nownode->M=true;
    }
}


/*修饰符操作响应函数*/
//修饰符函数计算
double pencent(double _X){return 0.01*_X;}
double plusminus(double _X){return -_X;}
double fraction(double _X){return 1/_X;}
//修饰函数
double Base::out()//提数
{
    //等号提数
    if(_end)
    {
        double temp=_result;
        clearButtonPress();
        _nownode->num=temp;
        _nownode->data=QString::number(temp);
    }
    //运算符后提数
    if(_nownode->_father!=NULL&&_nownode->_father->fuhao&&_nownode->data.length()==0)
    {
        QString ff=_nownode->_father->data;
        _nownode->_father->data="+";
        _nownode->num=0;
        _nownode->num=calu(_head->ancestor()->RChild);
        _valueM=_nownode->num;
         _nownode->data= QString::number(_nownode->num);
        _nownode->_father->data=ff;
    }
    return _nownode->num;
}
void Base::xiushifuButton(QString str1, QString str2, MATH p, bool xiushi=true, bool right=true)
//str1为修饰符前修饰、str2为修饰符后修饰、p为函数指针、xiushi true为修饰false为清空计算、right是是否有效
{

    if(!right)//判断错误
    {
        _error=Error_XSF;
        _nownode->data="无效输入";
        pr(sumInput,_nownode->data);
    }
    if(!_error)
    {
        if(xiushi&&!_nownode->xiushifu)//未修饰过
            sumInput.append(_nownode->data);
        //小数点后无数字处理小数点
        if(_nownode->point&&((_nownode->num/1-(int)(_nownode->num)/1)==0))
        {
            sumInput.remove(sumInput.length()-_nownode->data.length(),_nownode->data.length());
            _nownode->data.remove(_nownode->data.length()-_nownode->afterPoint-1,_nownode->afterPoint+1);
            _nownode->afterPoint=0;
            _nownode->point=false;
        }
        //普通数字修饰计算
        if(xiushi&&_nownode->data.length()>=1)
        {
            sumInput.remove(sumInput.length()-_nownode->data.length(),_nownode->data.length());
            _nownode->data.insert(0,str1);
            _nownode->data.append(str2);
            sumInput.append(_nownode->data);
            _nownode->xiushifu=true;
            _nownode->num=p(_nownode->num);
        }
        //普通数字不修饰清空计算
        if(!xiushi)
        {
            if(_nownode->xiushifu) sumInput.remove(sumInput.length()-_nownode->data.length(),_nownode->data.length());
            _nownode->num=p(_nownode->num);
            _nownode->data=QString::number(_nownode->num);
            _nownode->xiushifu=true;
        }
        //更新显示框中的显示信息
        pr(sumInput,QString::number(calu(_nownode)));
    }
}
void Base::plusminusButtonPress()
{
    if(_nownode->xiushifu)
        xiushifuButton("negate(",")",plusminus,true,out()==_nownode->num);
    else
        xiushifuButton("","",plusminus,false,out()==_nownode->num);
}
void Base::sqrtButtonPress(){xiushifuButton("sqrt(",")",sqrt,true,out()>=0);}
void Base::pencentButtonPress(){xiushifuButton("","",pencent,false,out()!=0);}
void Base::fractionButtonPress(){xiushifuButton("reciproc(",")",fraction,true,out()==_nownode->num);}


/*数字输入操作响应函数*/
void Base::numberButton(int n)
{
    if(!_error)//判断是否出错
    {
        reset();//判断是否等号后
        ysfreset();//判断是否修饰过
        QString str=QString::number(n);
        if((_nownode->data=="0"&&_nownode->num==0)||_nownode->data=="head")//当数字为0时或head
        {
            _nownode->num=n;
            _nownode->data=str;
        }
        else//当数字大于0时
        {
            if(_nownode->point)//有小数点
                _nownode->num=_nownode->num+n*pow(10,-(++_nownode->afterPoint));
            else if(_nownode->num<0)
                    _nownode->num=_nownode->num*10-n;
                 else
                    _nownode->num=_nownode->num*10+n;
            _nownode->data.append(str);
        }
        pr(sumInput,QString::number(_nownode->num));
     }
}
void Base::zeroButtonPress()
{
    if(!_error)//判断是否出错
    {
        reset();//判断是否等号后,M后
        ysfreset();//判断是否修饰过，清除当前数字
        if((_nownode->data!="0"&&_nownode->num!=0)||_nownode->point)//数字非0后或小数点后
        {
            if(_nownode->point)//有小数点
                ++_nownode->afterPoint;
            else _nownode->num=_nownode->num*10;
            _nownode->data.append("0");
        }
        if(_nownode->data==""||_nownode->data=="head")//空数字或head
        {
            _nownode->num=0;
            _nownode->data="0";
        }
        pr(sumInput,_nownode->data);
    }
}
void Base::oneButtonPress(){numberButton(1);}
void Base::twoButtonPress(){numberButton(2);}
void Base::threeButtonPress(){numberButton(3);}
void Base::fourButtonPress(){numberButton(4);}
void Base::fiveButtonPress(){numberButton(5);}
void Base::sixButtonPress(){numberButton(6);}
void Base::sevenButtonPress(){numberButton(7);}
void Base::eightButtonPress(){numberButton(8);}
void Base::nineButtonPress(){numberButton(9);}
void Base::pointButtonPress()
{
    if(!_error)//判断是否出错
    {
        reset();//判断是否等号后,M后
        ysfreset();//判断是否修饰过，清除当前数字
        if(_nownode->point==false)
        {
            if(_nownode->data=="")
                _nownode->data.append(tr("0"));
            _nownode->data.append(tr("."));
            _nownode->point=true;
            _nownode->afterPoint=0;
        }
        pr(sumInput,_nownode->data);
    }
}



/*符号输入操作响应函数*/
void Base::fuhaoButton(QString str)
{
    if(!_error)
    {
        if(_end)//等号后提数
        {
            double temp=_result;
            clearButtonPress();
            _nownode->num=temp;
            _nownode->data=QString::number(temp);
        }
        if(_nownode->_father!=NULL&&_nownode->_father->fuhao&&_nownode->data=="")//符号后重复处理
        {
            //删掉下一个数
            _nownode=_nownode->_father;
            delete _nownode->RChild;
            _nownode->RChild=NULL;
            //移动父亲清除符号
            sumInput.remove(sumInput.length()-_nownode->data.length()-2,_nownode->data.length()+2);
            if(_nownode->_father->data=="head"&&_nownode->LChild->RChild==NULL&&_nownode->LChild->LChild==NULL)//第一个符号
            {
                _nownode=_nownode->LChild;
                sumInput.remove(sumInput.length()-_nownode->data.length(),_nownode->data.length());
                _nownode->_father->_father->RChild=NULL;
                _nownode->_father=NULL;
            }
            else
            {
                _nownode=_nownode->LChild;
                sumInput.remove(sumInput.length()-_nownode->data.length(),_nownode->data.length());
                _nownode->_father->_father->RChild=_nownode;
                _nownode->_father=_nownode->_father->_father;
            }
            //清除显示
            _nownode=_nownode->maxRChild();
        }
        if(_nownode->data!="") //判断上一个计算是否出错
            fuhaoreset();
        if(!_error)//数字后添加符号
        {
            //前一个数处理
            if(!_nownode->xiushifu&&_nownode->data!="head")//非修饰符后
            {
                if(_nownode->point&&((_nownode->num/1-(int)(_nownode->num)/1)==0)) //小数点后无数字
                {
                    _nownode->data.remove(_nownode->data.length()-_nownode->afterPoint-1,_nownode->afterPoint+1);
                    _nownode->afterPoint=0;_nownode->point=false;
                }
                if(_nownode->data=="") _nownode->data="0";//开始数字为空
                sumInput.append(_nownode->data);
            }
            _numnode=new TreeNode();
            _numnode=_nownode;
            //符号处理
            _nownode=new TreeNode();
            _nownode->data = str;
            _nownode->fuhao = true;
            _father=_nownode;
            initTree();//把节点添加进二叉树
            sumInput.append(" "+str+" ");
            pr(sumInput,QString::number(calu(_numnode)));
            //后一个数添加
            _nownode=new TreeNode(_father);
        }
    }
}
void Base::addButtonPress(){fuhaoButton("+");}
void Base::subButtonPress(){fuhaoButton("-");}
void Base::mulButtonPress(){fuhaoButton("*");}
void Base::divButtonPress(){fuhaoButton("/");}

/*计算函数*/
short unsigned int Base::youxian(QString ysf)//优先级返回（数字越小月高）
{
    unsigned int back;  //返回的优先级
    const char *p = ysf.toLocal8Bit().data();//QString转换成const char
    char c=*p;
    switch(c)
    {
        case'*':back=2;break;//乘
        case'/':back=2;break;//除
        case'+':back=4;break;//加
        case'-':back=4;break;//减
    }
    return back;
}
void Base::initTree()//构建二叉树
{
    if(_numnode->_father!=NULL&&youxian(_numnode->_father->data)>youxian(_nownode->data))//高优先级
    {
        _nownode->_father =_numnode->_father;
        _numnode->_father->RChild=_nownode;
        _nownode->LChild =_numnode;
        _numnode->_father =_nownode;
    }
    else if(_numnode->_father!=NULL&&youxian(_numnode->_father->data)==youxian(_nownode->data))//等优先级
    {
        _nownode->_father =_numnode->_father->_father;
        _numnode->_father->_father->RChild=_nownode;
        _nownode->LChild =_numnode->_father;
        _numnode->_father->_father=_nownode;
    }
    else if(_numnode->_father!=NULL&&youxian(_numnode->_father->data)<youxian(_nownode->data))//低优先级
    {
        TreeNode *tempnode=new TreeNode();
        tempnode=_numnode->_father;
        while(!(tempnode->_father->data=="head")&&(youxian(tempnode->data)>=youxian(_nownode->data)))
            tempnode=tempnode->_father;
        _nownode->_father =tempnode->_father;
        tempnode->_father->RChild=_nownode;
        _nownode->LChild=tempnode;
        tempnode->_father=_nownode;
    }
    else if(_numnode->_father==NULL)//第一个符号
    {
        _nownode->LChild=_numnode;
        _numnode->_father=_nownode;
        _nownode->_father=_head;
        _head->RChild=_nownode;
    }
}
double Base::calu(TreeNode* now)//计算
{
    double sum,first,second;//sum储存结果、first、second储存左右节点的值
    if((now->LChild==NULL)&&(now->RChild==NULL))//树的底层返回值
    {
        sum=now->num;
    }
    else if(now->data=="head")//树的head返回
    {
        sum=(calu(now->RChild));
    }
    else//符号计算返回
    {
        const char *p = now->data.toLocal8Bit().data();
        char c=*p;
        first = calu(now->LChild);
        second = calu(now->RChild);
        switch(c)
        {
            case'+':sum = first+second;break;
            case'-':sum = first-second;break;
            case'*':sum = first*second;break;
            case'/':if(second==0) _error=Error_Div;
                        else sum = first/second;
                    break;
        }
    }
    return sum;
}

void Base::equButtonPress()//等号输入响应函数
{
    if(!_error)//是否出错
    {
        if(_nownode->data!="") fuhaoreset();//是否符号出错
        if(!_error)
        {
            _head=_head->ancestor();
            if(_nownode->_father==NULL)//无符号后，获取树的根
            {
                _head->RChild=_nownode;
                _nownode->_father=_head;
            }
            if(!_end)//是否按过等号
            {
                _end=true;
                if(_nownode->data=="") //符号后
                    _nownode->_father->data="+";
                _result = calu(_head->RChild);
                sumInput="";
                pr(sumInput,QString::number(_result));
             }
        }
    }
}

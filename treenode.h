#ifndef TREENODE_H
#define TREENODE_H

#include <QString>
#include <QDebug>

class TreeNode
{
public:
    TreeNode(TreeNode *);
    TreeNode();
    ~TreeNode();
    //函数
    TreeNode*ancestor();    //返回祖先
    TreeNode* maxRChild();//返回最右边的孩子
    TreeNode& operator=(const TreeNode &);  //等号重载运算符
    //数据
    QString data;//显示的字符
    double num;//值
    bool point;//是否带小数点
    short unsigned int afterPoint;//几位小数点
    bool fuhao;//是否为符号
    bool xiushifu;//是否有修饰符
    bool M;//是否刚按过M类函数
    //连接
    TreeNode *LChild;
    TreeNode *RChild;
    TreeNode *_father;
};


#endif // TREENODE_H

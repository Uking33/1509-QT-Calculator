#include "treenode.h"

TreeNode::TreeNode(TreeNode *father):_father(father)
{
    data="";//data,num为"0",0时才为0
    num=0;
    afterPoint=false;
    point=false;
    xiushifu=false;
    fuhao=false;
    M=false;
    LChild=NULL;
    RChild=NULL;
    _father->RChild=this;
}
TreeNode::TreeNode()
{
    data="";//data,num为"0",0时才为0
    num=0;
    afterPoint=false;
    point=false;
    xiushifu=false;
    fuhao=false;
    M=false;
    LChild=NULL;
    RChild=NULL;
    _father=NULL;
}
TreeNode::~TreeNode(){}
TreeNode * TreeNode::maxRChild()//返回最右边的孩子
{
    if(RChild==NULL) return this;
    return RChild->maxRChild();
}
TreeNode * TreeNode::ancestor()//返回祖先
{
    if(_father==NULL) return this;
    return _father->ancestor();
}
TreeNode & TreeNode::operator=(const TreeNode & n)//等号重载运算符
{
    data=n.data;
    num=n.num;
    afterPoint=n.afterPoint;
    point=n.point;
    xiushifu=n.xiushifu;
    fuhao=n.fuhao;
    M=n.M;
    LChild=n.LChild;
    RChild=n.RChild;
    _father=n._father;
    return *this;
}

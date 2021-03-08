//定义二叉树类相关函数的头文件
#ifndef PREMIDSEQUENCEBUILDBINARYTREE_H_
#define PREMIDSEQUENCEBUILDBINARYTREE_H_

struct BinTreeNode                                            //二叉树信息结点 
{
	char data;
	BinTreeNode* leftchild,* rightchild;
	BinTreeNode():leftchild(nullptr),rightchild(nullptr){}    //构造函数 
 };

class BinaryTree                                              //二叉树类定义 
{
public:
    BinTreeNode* CreateBinaryTree1(char* vlr,char* lvr,int n);//利用前、中序序列建立二叉树
    BinTreeNode* CreateBinaryTree2(char* lrv,char* lvr,int n);//利用后、中序序列建立二叉树
    void PrintTree(BinTreeNode* subTree,int n);               //凹入法输出二叉树
	void PreOrder(BinTreeNode* subTree);                      //前序遍历
	void InOrder(BinTreeNode* subTree);                       //中序遍历
	void PostOrder(BinTreeNode* subTree);                     //后序遍历
 };

#endif

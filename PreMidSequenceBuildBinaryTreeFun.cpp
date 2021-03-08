//二叉树类里面的函数功能的代码实现
#include <iostream>
#include <cstring>
#include "PreMidSequenceBuildBinaryTree.h"
using namespace std;


BinTreeNode* BinaryTree::CreateBinaryTree1(char* vlr,char* lvr,int n)//利用前、中序序列建立二叉树
{
	if(n==0) return nullptr;
	int k=0;
	while(vlr[0]!=lvr[k]) k++;                                      //在中序中寻找根 
	BinTreeNode* tree=new BinTreeNode;                             
	tree->data=*vlr;                                                //初始化根结点
	tree->leftchild=CreateBinaryTree1(vlr+1,lvr,k);
	//从前序vlr+1开始对中序的0~k-1左子序列的k个元素递归建立左子树
	tree->rightchild=CreateBinaryTree1(vlr+k+1,lvr+k+1,n-k-1);
	//从前序vlr+k+1开始对中序的k+1~n-1右子序列的n-k-1个元素递归建立右子树 
	return tree;
}


BinTreeNode* BinaryTree::CreateBinaryTree2(char* lrv,char* lvr,int n)//利用后、中序序列建立二叉树
{
	if(n==0) return nullptr;
	int k=0;
	while(lrv[n-1]!=lvr[k]) k++;                                     //在中序中寻找根 
	BinTreeNode* tree=new BinTreeNode;                             
	tree->data=lrv[n-1];                                             //初始化根结点
	tree->leftchild=CreateBinaryTree2(lrv,lvr,k);
	//从后序lrv-1开始对中序的0~k-1左子序列的k个元素递归建立左子树
    tree->rightchild=CreateBinaryTree2(lrv+k,lvr+k+1,n-k-1);
	//从后序lrv+k-1开始对中序的k+1~n-1右子序列的n-k-1个元素递归建立右子树 
	return tree;
}


void BinaryTree::PreOrder(BinTreeNode* subTree)                     //前序遍历
{
	if(subTree!=nullptr)
	{
		cout<<subTree->data;
        PreOrder(subTree->leftchild);
        PreOrder(subTree->rightchild);
	}
}


void BinaryTree::InOrder(BinTreeNode* subTree)                     //中序遍历
{
	if(subTree!=nullptr)
	{
        InOrder(subTree->leftchild);
        cout<<subTree->data;
        InOrder(subTree->rightchild);
	}
}


void BinaryTree::PostOrder(BinTreeNode* subTree)                  //后序遍历
{
	if(subTree!=nullptr)
	{
        PostOrder(subTree->leftchild);
        PostOrder(subTree->rightchild);
        cout<<subTree->data;
	}
}


void BinaryTree::PrintTree(BinTreeNode* subTree,int n)           //凹入法输出二叉树
{
	//逆时针旋转90°打印二叉树，n为打印的层数，初始值为0 
	int i;
	if(subTree==nullptr)
	    return;
	PrintTree(subTree->rightchild,n+1);                          //遍历打印右子树 
	for(i=0;i<n;i++)
	    cout<<"   ";
	if(n>=0)
	{
		cout<<"---";
		cout<<subTree->data<<endl;
	}
	PrintTree(subTree->leftchild,n+1);                          //遍历打印左子树 
}

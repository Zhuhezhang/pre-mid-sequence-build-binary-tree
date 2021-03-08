//������������ĺ������ܵĴ���ʵ��
#include <iostream>
#include <cstring>
#include "PreMidSequenceBuildBinaryTree.h"
using namespace std;


BinTreeNode* BinaryTree::CreateBinaryTree1(char* vlr,char* lvr,int n)//����ǰ���������н���������
{
	if(n==0) return nullptr;
	int k=0;
	while(vlr[0]!=lvr[k]) k++;                                      //��������Ѱ�Ҹ� 
	BinTreeNode* tree=new BinTreeNode;                             
	tree->data=*vlr;                                                //��ʼ�������
	tree->leftchild=CreateBinaryTree1(vlr+1,lvr,k);
	//��ǰ��vlr+1��ʼ�������0~k-1�������е�k��Ԫ�صݹ齨��������
	tree->rightchild=CreateBinaryTree1(vlr+k+1,lvr+k+1,n-k-1);
	//��ǰ��vlr+k+1��ʼ�������k+1~n-1�������е�n-k-1��Ԫ�صݹ齨�������� 
	return tree;
}


BinTreeNode* BinaryTree::CreateBinaryTree2(char* lrv,char* lvr,int n)//���ú��������н���������
{
	if(n==0) return nullptr;
	int k=0;
	while(lrv[n-1]!=lvr[k]) k++;                                     //��������Ѱ�Ҹ� 
	BinTreeNode* tree=new BinTreeNode;                             
	tree->data=lrv[n-1];                                             //��ʼ�������
	tree->leftchild=CreateBinaryTree2(lrv,lvr,k);
	//�Ӻ���lrv-1��ʼ�������0~k-1�������е�k��Ԫ�صݹ齨��������
    tree->rightchild=CreateBinaryTree2(lrv+k,lvr+k+1,n-k-1);
	//�Ӻ���lrv+k-1��ʼ�������k+1~n-1�������е�n-k-1��Ԫ�صݹ齨�������� 
	return tree;
}


void BinaryTree::PreOrder(BinTreeNode* subTree)                     //ǰ�����
{
	if(subTree!=nullptr)
	{
		cout<<subTree->data;
        PreOrder(subTree->leftchild);
        PreOrder(subTree->rightchild);
	}
}


void BinaryTree::InOrder(BinTreeNode* subTree)                     //�������
{
	if(subTree!=nullptr)
	{
        InOrder(subTree->leftchild);
        cout<<subTree->data;
        InOrder(subTree->rightchild);
	}
}


void BinaryTree::PostOrder(BinTreeNode* subTree)                  //�������
{
	if(subTree!=nullptr)
	{
        PostOrder(subTree->leftchild);
        PostOrder(subTree->rightchild);
        cout<<subTree->data;
	}
}


void BinaryTree::PrintTree(BinTreeNode* subTree,int n)           //���뷨���������
{
	//��ʱ����ת90���ӡ��������nΪ��ӡ�Ĳ�������ʼֵΪ0 
	int i;
	if(subTree==nullptr)
	    return;
	PrintTree(subTree->rightchild,n+1);                          //������ӡ������ 
	for(i=0;i<n;i++)
	    cout<<"   ";
	if(n>=0)
	{
		cout<<"---";
		cout<<subTree->data<<endl;
	}
	PrintTree(subTree->leftchild,n+1);                          //������ӡ������ 
}

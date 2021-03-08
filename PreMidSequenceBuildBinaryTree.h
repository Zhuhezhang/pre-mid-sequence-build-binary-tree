//�������������غ�����ͷ�ļ�
#ifndef PREMIDSEQUENCEBUILDBINARYTREE_H_
#define PREMIDSEQUENCEBUILDBINARYTREE_H_

struct BinTreeNode                                            //��������Ϣ��� 
{
	char data;
	BinTreeNode* leftchild,* rightchild;
	BinTreeNode():leftchild(nullptr),rightchild(nullptr){}    //���캯�� 
 };

class BinaryTree                                              //�������ඨ�� 
{
public:
    BinTreeNode* CreateBinaryTree1(char* vlr,char* lvr,int n);//����ǰ���������н���������
    BinTreeNode* CreateBinaryTree2(char* lrv,char* lvr,int n);//���ú��������н���������
    void PrintTree(BinTreeNode* subTree,int n);               //���뷨���������
	void PreOrder(BinTreeNode* subTree);                      //ǰ�����
	void InOrder(BinTreeNode* subTree);                       //�������
	void PostOrder(BinTreeNode* subTree);                     //�������
 };

#endif

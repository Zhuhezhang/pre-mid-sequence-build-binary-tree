//利用前、中序序列或者后、中序序列唯一确定一棵二叉树之主函数部分 
#include <iostream>
#include <cstring> 
#include "PreMidSequenceBuildBinaryTree.h"
using namespace std; 

int main(void)
{
	while(1)
	{
		int flag; 
		cout<<"您想如何建立二叉树(1：前、中序序列   2：后、中序序列)：";
		cin>>flag;
		BinTreeNode* root;  BinaryTree b;
		
		if(flag==1)//利用前、中序序列建立二叉树
		{
			char VLR[100],LVR[100];
			cout<<"请输入前序序列：";
	        cin>>VLR;
	        cout<<"请输入中序序列：";
	        cin>>LVR;
	        cout<<endl;
	        root=b.CreateBinaryTree1(VLR,LVR,strlen(VLR));
		}
        else      //利用后、中序序列建立二叉树
        {
        	char LRV[100],LVR[100];
			cout<<"请输入后序序列：";
	        cin>>LRV;
	        cout<<"请输入中序序列：";
	        cin>>LVR;
	        cout<<endl;
	        root=b.CreateBinaryTree2(LRV,LVR,strlen(LRV));
		}
        
    	cout<<"前序遍历：";
    	b.PreOrder(root);
	    cout<<endl;

	    cout<<"中序遍历：";
	    b.InOrder(root);
	    cout<<endl;

	    cout<<"后序遍历：";
	    b.PostOrder(root);
	    cout<<endl;

	    cout<<"\n凹入法输出该二叉树(逆时针旋转90°输出)：\n";
	    b.PrintTree(root,0);
	    cout<<endl;

	    char flag2;
	    cout<<"是否继续运算(Y/N): ";
	    cin>>flag2;
	    cout<<endl;
	    if(flag2=='n'||flag2=='N')
	    {
	    	cout<<endl;
	    	cout<<"感谢使用！\n";
	    	system("pause");
	    	break;
		}
	}
	return 0;
}

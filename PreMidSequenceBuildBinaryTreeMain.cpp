//����ǰ���������л��ߺ���������Ψһȷ��һ�ö�����֮���������� 
#include <iostream>
#include <cstring> 
#include "PreMidSequenceBuildBinaryTree.h"
using namespace std; 

int main(void)
{
	while(1)
	{
		int flag; 
		cout<<"������ν���������(1��ǰ����������   2������������)��";
		cin>>flag;
		BinTreeNode* root;  BinaryTree b;
		
		if(flag==1)//����ǰ���������н���������
		{
			char VLR[100],LVR[100];
			cout<<"������ǰ�����У�";
	        cin>>VLR;
	        cout<<"�������������У�";
	        cin>>LVR;
	        cout<<endl;
	        root=b.CreateBinaryTree1(VLR,LVR,strlen(VLR));
		}
        else      //���ú��������н���������
        {
        	char LRV[100],LVR[100];
			cout<<"������������У�";
	        cin>>LRV;
	        cout<<"�������������У�";
	        cin>>LVR;
	        cout<<endl;
	        root=b.CreateBinaryTree2(LRV,LVR,strlen(LRV));
		}
        
    	cout<<"ǰ�������";
    	b.PreOrder(root);
	    cout<<endl;

	    cout<<"���������";
	    b.InOrder(root);
	    cout<<endl;

	    cout<<"���������";
	    b.PostOrder(root);
	    cout<<endl;

	    cout<<"\n���뷨����ö�����(��ʱ����ת90�����)��\n";
	    b.PrintTree(root,0);
	    cout<<endl;

	    char flag2;
	    cout<<"�Ƿ��������(Y/N): ";
	    cin>>flag2;
	    cout<<endl;
	    if(flag2=='n'||flag2=='N')
	    {
	    	cout<<endl;
	    	cout<<"��лʹ�ã�\n";
	    	system("pause");
	    	break;
		}
	}
	return 0;
}

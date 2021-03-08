@[TOC](目录)
# 1.题目
【问题描述】
     如果给出了遍历二叉树的前序序列和中序序列，则可以构造出唯一的一棵二叉树。试编写实现上述功能的程序。    
【基本要求】
     已知一棵二叉树的前序和中序遍历序列，试设计完成下列任务的一个算法：
    （1）构造一棵二叉树；
    （2）证明构造正确（即分别以前序和中序遍历该树，将得到的结果与给出的序列进行比较）；
    （3）对该二叉树进行后序遍历，输出后序遍历序列；
    （4）用凹入法输出该二叉树。
【测试数据】
    （1）前序序列为 ABDEGCFHIJ
         中序序列为 DBGEAHFIJC 
    （2）前序序列为 -×+abc/de
         中序序列为 a+b×c-d/e
【拓展内容】
     已知后序和中序遍历序列构造二叉树。
# 2.程序设计
程序分三个文件，第一个是定义二叉树类相关函数的头文件，第二个是二叉树类里面的函数功能的代码实现，第三个是主函数部分。
第一个函数声明文件里面首先定义的是一个二叉树结点的结构体BinTreeNode，里面含有数据变量、左指针、右指针以及一个对左右指针的初始化的构造函数。接下来就是一个二叉树类BinaryTree，里面含有对二叉树操作的一些函数，包括利用前、中序序列建立二叉树(BinTreeNode* CreateBinaryTree1(char* vlr,char* lvr,int n);)、利用后、中序序列建立二叉树(BinTreeNode* CreateBinaryTree2(char* lrv,char* lvr,int n);)、凹入法输出二叉树(void PrintTree(BinTreeNode* subTree,int n);)、前序遍历(void PreOrder(BinTreeNode* subTree);)、中序遍历(void InOrder(BinTreeNode* subTree);)以及后序遍历(void PostOrder(BinTreeNode* subTree);)。
第二个函数定义文件里首先是构造二叉树函数（由于利用后、中序序列建立二叉树与利用前、中序序列建立二叉树基本一致，所以这里只介绍后者），若结点数n=0则返回nullptr，否则首先在中序序列中找出头根结点所在位置，然后利用new申请一个BinTreeNode类型的内存并将其用于对根结点的初始化，紧接着是利用、tree->leftchild=CreateBinaryTree(vlr+1,lvr,k)从前序vlr+1开始对中序的0~k-1左子序列的k个元素递归建立左子树，然后再利用tree->rightchild=CreateBinaryTree(vlr+k+1,lvr+k+1,n-k-1)从前序vlr+k+1开始对中序的k+1-n-1右子序列的n-k-1个元素递归建立右子树，最后返回二叉树的根结点。
然后是前序遍历二叉树算法：若二叉树根结点指针不为空，则首先输出其数据，然后再利用递归依次输出左孩子和右孩子，中序和后序遍历思路和前序遍历也差不多，就不再说明。最后就是利用凹入法打印二叉树，也即输出逆时针旋转90°的二叉树，函数参数除了根结点以外还有一个打印的层数n，初值为0。然后就是if(subTree==nullptr)则return，否则利用递归打印右子树，然后根据层数输出“   ”及“---”，最后也是一个遍历函数用来打印左子树。
第三个文件是主函数部分，语句包含在while循环里面，首先是确定要如何建立二叉树（输入1代表以前中序序列建立或者2以后中序序列建立），然后定义二叉树的根指针、用来存储前、中序序列/后、中序序列的数组，然后利用定义的BinaryTree类对象来调用构造二叉树函数，并分别以前、中、后序序列遍历输出该二叉树，以便验证建立的二叉树是否正确，最后就是简单的判断语句，判断是否执行下一次二叉树的建立输出。至此，整个程序设计说明结束。
# 3.使用说明
首先输入您想如何建立二叉树，利用前、中序序列或者后、中序序列，然后依次从键盘输入前序/后序序列（直接输入即可，不用输入一个字符按一次回车或空格），输入完前序/后序序列之后按回车，再按照同样方法输入中序序列，然后再按回车运行即可，当该二叉树操作完成之后会显示是否执行下一次计算，输入Y/N选择继续或退出，若选择继续则按照同样方法输入结点即可。
# 4.测试结果
测试结果如下
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210308214206284.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210308214214175.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210308214222661.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)

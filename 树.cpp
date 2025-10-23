#include<iostream>
using namespace std; 
//树经常被用来表示层次化的数据 
定义树为一个逻辑模型 ，树并非线性结构，是一个层次结构
 内容：根，孩子，父母，兄弟
 树中没有任何孩子的节点叫做叶节点
 树可以被称为递归的数据结构
 在有N个节点的树中，一定有N-1个链
 从根节点到某个节点要经过几条边，其深度就是几
  最常用的树的类型：二叉树，使用动态结构，
  结构中有左右孩子两个指针 
  而可以有多个孩子的，就要用别的结构
  
  二叉树： 最多两个孩子
  完全二叉树：除了叶子，都得是2个孩子 
  还有完美二叉树，所有节点的高度差为0
  尽量降低高度，高度越低，检索效率越高
  对于完美二叉树一个节点索引为i(从0开始)
  其左孩子 2i+1   右孩子 2i+2 
  
  二叉搜索树： 
  插入的话数组和链表更快，但链表和数组的
  search时间都是0(n) 此时就要用二叉搜索树(有了排序的基础)
  二分查找是主要原理 
  数组进行二分查找的话，查找时间是log n
  但是移动删除时间是n，二叉搜索树可以
  使得查找，插入，删除均为log n
  其要求左侧的树<=根节点，右侧的树>根节点
  但在插入和删除时得改变树的结构以保证重新平衡 
  因此要有保持平衡的方法 
  构建方法：每个节点
  struct BstNode{
  	    int data;
		  BstNode* left;
		  BstNode* right;                
} ;
BstNode* root;
root=nullptr;//初始状态 
BstNode* p=new BstNode(value/data);//这些得通过指针访问，并且元素本身的内存储存在堆里 
对链表，我们总保留的信息是头节点的地址
 对树，保留根节点的地址 
 BstNode* GeyNewNode(int data){
 	BstNode* newNode = new BstNode();
 	newNode->data=data;
	 newNode->left=newNode->right=nullptr;
	 reutrn newNode;
 } 
 BstNode* Insert(BstNode* root,int data){
 	if(root==nullptr){
 		root=GetNewNode(data);
 		return root;
	 }//这样是将root作为全局变量
	 else if(data<=root->data){
	 	root->eft=Insert(root->left,data);
	 } 
	 else{
	 	root->right=Insert(root->right,data);
	 	
	 }
	 return root;
 }
 
 bool Search(BstNode* root,int data){
 	if(root==nillptr) return false;
 	else if(data==root->data) return true;
 	else if(data<=root->data) return Search(root->left,data);
 	else if(data>root->data) return Search(root->right,data);
 }
 
 应用程序在运行时，会在栈和堆中处理转换内存
 堆中，我们可以控制任何东西的生命周期
 
 question： 如何利用二叉搜索树找最小和最大值
 小：法一：使用循环
 int FindMin(BstNode* root) {
 	BstNode* current =root;
 	while(current->left!=nullptr){
 		current=current->left;
	 }
	 return current->data;	 
 }  
 法二：递归 
 int FindMin(BstNode* root){
 	if(root==nullptr) return -1
 	else if(root->left==nullptr){
 		return root->next;
	 }
	 return FindMin(root->left);
 }
 
 查看树的高度； 考虑到树的高度应该是最大的
 根节点到叶节点的边数 
 逻辑是：如果我们知道其在左右子树的高度，只需比较这两个高度即可，取大,然后注意要有递归出口 
  FindHeight(root){
  	if(root==nullptr) return -1 ;
  	leftheight=FindHeight(root->left);
	 rightheight=FindHeight(root->right);
	 return max(leftheight,rightheight)+1;   
	  } 
 
 树的遍历算法： 分为深搜和广搜  
广搜：层序遍历
void levelOrder(){
	if(root == nullptr) return;
	queue<TreeNode*> q;
	q.push(root);
	vector<int> res;
	while(!q.empty()){
		TreeNode* current =q.front;
		res.add(q);
		q.pop();
		if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
	}
} 
深搜：  可以递归前中后
void preorder(TreeNode* root){
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);  
} 
其时间复杂度为0(n)   空间复杂度从O（log n）到 O（n） 
//中序遍历会得到二叉搜索树排序后的元素 
检查是否为二叉搜索树： 法一：多次递归 
bool IsSubtreeLesser(Node* root,int value){
	if(root==nullptr) return true;
	if(root->data<=value&&IsSubtreeLesser(root->left,data)&&IsSubtreeLesser(root->right,data)) 
      return true;
    else
    return false;
} 
bool IsSubtreeGreater(Node* rot,int value){
}
boolIsBinarySearchTree(Node* root){
	if(root==nullptr) return true;
	if(IsSubtreeLesser(root->left,root->data)&& IsSubtreeGreater(root->right,root->data) &&IsSubtreeGreater(root->left) &&IsSubtreeGreater(root->right))
      return true;
    else
        return false;
}   //O(n^2)

一种优化方法是：每次标记一个能取的范围
bool IsBinarySearchTree(Node* root,int minValue,int maxValue){
	if(root==nullptr) return true;
	if(root->data<minValue &&root->data>maxValue
	&&IsBinarySearchTree(root->left,minvalue,root->data)
	&&IsBinarySearchTree(root->right,root->data,maxValue))
	    return true;
	else
	    return false;
} //O(n)


从二叉搜索树中删除一个节点
删除时不要忘记回收内存，并且考虑仍保证二叉搜索树
 有三种情况：0，1，2个孩子 
 有两个孩子的情况下，删除后，将其右孩子接到原来的位置
Node* Delete(Node* root,int data){
	if(root==nullptr) return root;
	else if(data<root->data) root->left=Delete(root->left,data);
	else if(data>root->data) root->right=Delete(root->right,data);
	else{
		//case:1 no child
		if(root->left==nullptr&& root->right==nullptr){
			delete root;
			root==nullptr;
			return root;
		}else if(root->left==nullptr) 
		//case 2:one child
		Node* temp=root;
		root=root->right;
		delete temp;
		return root;
	}    else{
		//case 3 :2 children  这样可以变为简单情况 
		Node* temp=FindMin(root->right);
		root->data=temp->data;
		root->right=Delete(root->right,temp->data);
		return root;  
	}
	
	
	找到给定的一个节点的中序遍历的后继节点
	法一：中序遍历一遍，再找 
	但在树中最好的操作是O（h）=O（log n） 
case 1:node has right subtree 后继为其右子树的左子树的最左的节点
case2: no right subtree 后继应去往最近的、没遍历过的祖先

Node* Getsuccessor(Node* root,int data) {
	Node* current=Find(root,data);
	if(current==null) return null;
	//case1:node has right subtree O(h)
	if(current->right!=null){
		return FindMin(current->right);
	}else{ //case2 : no right subtree O(h)
		Node* successor=nullptr;
		Node* ancestor=root;
		while(ancestor!=current){
			if(current->data < ancestor->data){
				successor=ancestor;
				ancestor=ancestor->left;
			}else{
				ancestor=ancesstor->right;
			}
		}
	}
	return successor;
}

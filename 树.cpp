#include<iostream>
using namespace std; 
//��������������ʾ��λ������� 
������Ϊһ���߼�ģ�� �����������Խṹ����һ����νṹ
 ���ݣ��������ӣ���ĸ���ֵ�
 ����û���κκ��ӵĽڵ����Ҷ�ڵ�
 �����Ա���Ϊ�ݹ�����ݽṹ
 ����N���ڵ�����У�һ����N-1����
 �Ӹ��ڵ㵽ĳ���ڵ�Ҫ���������ߣ�����Ⱦ��Ǽ�
  ��õ��������ͣ���������ʹ�ö�̬�ṹ��
  �ṹ�������Һ�������ָ�� 
  �������ж�����ӵģ���Ҫ�ñ�Ľṹ
  
  �������� �����������
  ��ȫ������������Ҷ�ӣ�������2������ 
  �������������������нڵ�ĸ߶Ȳ�Ϊ0
  �������͸߶ȣ��߶�Խ�ͣ�����Ч��Խ��
  ��������������һ���ڵ�����Ϊi(��0��ʼ)
  ������ 2i+1   �Һ��� 2i+2 
  
  ������������ 
  ����Ļ������������죬������������
  searchʱ�䶼��0(n) ��ʱ��Ҫ�ö���������(��������Ļ���)
  ���ֲ�������Ҫԭ�� 
  ������ж��ֲ��ҵĻ�������ʱ����log n
  �����ƶ�ɾ��ʱ����n����������������
  ʹ�ò��ң����룬ɾ����Ϊlog n
  ��Ҫ��������<=���ڵ㣬�Ҳ����>���ڵ�
  ���ڲ����ɾ��ʱ�øı����Ľṹ�Ա�֤����ƽ�� 
  ���Ҫ�б���ƽ��ķ��� 
  ����������ÿ���ڵ�
  struct BstNode{
  	    int data;
		  BstNode* left;
		  BstNode* right;                
} ;
BstNode* root;
root=nullptr;//��ʼ״̬ 
BstNode* p=new BstNode(value/data);//��Щ��ͨ��ָ����ʣ�����Ԫ�ر�����ڴ洢���ڶ��� 
�����������ܱ�������Ϣ��ͷ�ڵ�ĵ�ַ
 �������������ڵ�ĵ�ַ 
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
	 }//�����ǽ�root��Ϊȫ�ֱ���
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
 
 Ӧ�ó���������ʱ������ջ�Ͷ��д���ת���ڴ�
 ���У����ǿ��Կ����κζ�������������
 
 question�� ������ö�������������С�����ֵ
 С����һ��ʹ��ѭ��
 int FindMin(BstNode* root) {
 	BstNode* current =root;
 	while(current->left!=nullptr){
 		current=current->left;
	 }
	 return current->data;	 
 }  
 �������ݹ� 
 int FindMin(BstNode* root){
 	if(root==nullptr) return -1
 	else if(root->left==nullptr){
 		return root->next;
	 }
	 return FindMin(root->left);
 }
 
 �鿴���ĸ߶ȣ� ���ǵ����ĸ߶�Ӧ��������
 ���ڵ㵽Ҷ�ڵ�ı��� 
 �߼��ǣ��������֪���������������ĸ߶ȣ�ֻ��Ƚ��������߶ȼ��ɣ�ȡ��,Ȼ��ע��Ҫ�еݹ���� 
  FindHeight(root){
  	if(root==nullptr) return -1 ;
  	leftheight=FindHeight(root->left);
	 rightheight=FindHeight(root->right);
	 return max(leftheight,rightheight)+1;   
	  } 
 
 ���ı����㷨�� ��Ϊ���Ѻ͹���  
���ѣ��������
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
���ѣ�  ���Եݹ�ǰ�к�
void preorder(TreeNode* root){
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);  
} 
��ʱ�临�Ӷ�Ϊ0(n)   �ռ临�Ӷȴ�O��log n���� O��n�� 
//���������õ�����������������Ԫ�� 
����Ƿ�Ϊ������������ ��һ����εݹ� 
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

һ���Ż������ǣ�ÿ�α��һ����ȡ�ķ�Χ
bool IsBinarySearchTree(Node* root,int minValue,int maxValue){
	if(root==nullptr) return true;
	if(root->data<minValue &&root->data>maxValue
	&&IsBinarySearchTree(root->left,minvalue,root->data)
	&&IsBinarySearchTree(root->right,root->data,maxValue))
	    return true;
	else
	    return false;
} //O(n)


�Ӷ�����������ɾ��һ���ڵ�
ɾ��ʱ��Ҫ���ǻ����ڴ棬���ҿ����Ա�֤����������
 �����������0��1��2������ 
 ���������ӵ�����£�ɾ���󣬽����Һ��ӽӵ�ԭ����λ��
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
		//case 3 :2 children  �������Ա�Ϊ����� 
		Node* temp=FindMin(root->right);
		root->data=temp->data;
		root->right=Delete(root->right,temp->data);
		return root;  
	}
	
	
	�ҵ�������һ���ڵ����������ĺ�̽ڵ�
	��һ���������һ�飬���� 
	����������õĲ�����O��h��=O��log n�� 
case 1:node has right subtree ���Ϊ����������������������Ľڵ�
case2: no right subtree ���Ӧȥ������ġ�û������������

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

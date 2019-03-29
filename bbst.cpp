//including library
#include<iostream>
using namespace std;
//declaring class for the connections
class Node{
public:
//declaring pointers for connections
	Node * left;
	Node* right;
	Node * parent;
//declaring data for storage
	int data;
	Node(int value){
	data=value;
	left=NULL;
	right=NULL;
	parent=NULL;
	}
};
class BST{
public:
	Node * root;
	BST(){
	root=NULL;
	}
int count=0;
//for insertion
void insert(int value){
	insertA(root,value);
	count++;
}
//for insertion at a particular position
void insertA(Node * curr,int value){
//if node = null
if(root==NULL){
root= new Node(value);
}
else if(value<curr->data){
	    if(curr->left==NULL){
		          curr->left=new Node(value);
		          curr->left->parent=curr;
		                 }
	   else insertA(curr->left,value);
}
else{
	 if(curr->right==NULL){
	 curr->right=new Node(value);
	 curr->right->parent=curr;
     }
	 else insertA(curr->right,value);
}
//if value<curr->data
//if value>curr-> data
}
Node * search(int value){
	searchA(root,value);
}
Node * searchA(Node * curr,int value){
//if the value matches
if(curr==NULL ||curr->data==value ){
	 return curr;
	}
//if value<curr->data
else if(value<curr->data) return searchA(curr->left,value);
//if value>curr->data
else return searchA(curr->right,value);
}
void DisplayA(){
display(root);
}
//display function
void display(Node * curr){
         if(curr==NULL) return;
         display(curr->left);
         //printing
         cout<<curr->data<<" ";
         display(curr->right);
           }
Node * findMinA(){
	     findMin(root);
          }
Node * findMin(Node * curr){
         while(curr->left!=NULL){
		              curr=curr->left;
	      }
	     return curr;
}
//for replacement
void replaceAtparent(Node * A,Node * B){
                         Node * p=A->parent;
                         Node * p1=B->parent;
                         A->parent=NULL;
                         B->parent=NULL;
                         if(A->parent->left==A){
	                                  p->left=B;
                                      B->parent=p;
}
else{
	p->right=B;
	B->parent=p;
}
if(p1->left==B){
	      p1->left=NULL;
}
else{
	p1->right=NULL;
}
}
void deleteN(int value){
	    deleteA(root,value);
}
//for deletion at a particular position
void deleteA(Node * curr,int value){
	                  if(root==NULL)return ;
	                  else if(value<curr->data){
		              deleteA(curr->left,value);
	                           }
	                  else if(value>curr->data){
		              deleteA(curr->right,value);
	                        }
	else{
		Node * temp=new Node(value);
		Node *p=curr->parent;
		if(curr->left==NULL and curr->right==NULL){
			                                  temp=curr;
			                                  curr=NULL;
			                                  delete temp;
		                                        }
		else if(curr->left==NULL and curr->right!=NULL){
			                                  if(p->left=curr){
				                                           temp=curr;
				                                           p->left=NULL;
				                                           p->left=curr->right;
				                                           curr->right->parent=p;
				                                           curr->parent=NULL;
			                                                   }
			                                   else{
			                                        temp=curr;
				                                    p->right=NULL;
				                                    p->right=curr->right;
				                                    curr->right->parent=p;
				                                    curr->parent=NULL;
			                                          }
		                        }
		   else if(curr->left!=NULL and curr->right==NULL){
			                                     if(p->left=curr){
				                                             temp=curr;
				                                              p->left=NULL;
				                                             p->left=curr->left;
				                                            curr->left->parent=p;
				                                             curr->parent=NULL;
			                                                     }
                                                 else{
                                                     temp=curr;
				                                     p->right=NULL;
				                                     p->right=curr->left;
				                                     curr->left->parent=p;
				                                     curr->parent=NULL;
			                                             }
		                                            }
		else{
			if(p->left=curr){
				       p->left=findMin(p->left->right);
                       curr->parent=NULL;
				       if(findMin(p->left->right)->parent->left=findMin(p->left->right)){
					                                        findMin(p->left->right)->parent->left=NULL;
					                                        findMin(p->left->right)->parent=NULL;
				                }
				      else{
                           findMin(p->left->right)->parent->right=NULL;
					       findMin(p->left->right)->parent=NULL;
				       }
			}
			else{
				p->right=findMin(p->right->right);
				curr->parent=NULL;
				if(findMin(p->right->right)->parent->left=findMin(p->right->right)){
					                                       findMin(p->right->right)->parent->left=NULL;
					                                       findMin(p->right->right)->parent=NULL;
				                                             }
                else{
					findMin(p->right->right)->parent->right=NULL;
					findMin(p->right->right)->parent=NULL;
				}
			}
}
}
}
void add(){
	cout<<endl;
	cout<<"The no of elements are "<<count<<endl;
}
//for rangesearch
int rangeSearch(int i,int j){
	                Node * curr=root;
	                while(i<curr->data){
 	                curr=curr->left;
}
//looping
while(i>curr->data){
	          curr=curr->right;
}
display(curr->left);
cout<<curr->data<<" ";
display(curr->right);
}
};
//declaring main functionj
int main(){
        BST b1;
        b1.insert(12);
        b1.insert(10);
        b1.insert(15);
        b1.insert(2);
        b1.insert(4);
        b1.insert(6);
        b1.DisplayA();
       //b1.deleteN(12);
       b1.add();
       //b1.replaceAtparent(b1.root->left,b1.root->right);
       b1.DisplayA();
        cout<<endl;
       cout<<"The least element is "<<b1.findMinA()->data<<endl;
//closing the main function
return 0;
}

#include <iostream>
using namespace std;

template <class T>
class BinaryTree
{

	struct node{
		T value;
		struct node* right;
		struct node* left;
	};

public:
	BinaryTree();
	~BinaryTree();
    void insert(T val);
	void printPreOrder();//wrapper function
	void printInOrder();//wrapper function
	void printPostOrder();//wrapper function
	int size();//wrapper function
	bool lookup(T val);//wrapper function
    int height(void);//wrapper function
    int counts(void);//wrapper function
    void destroyTree(void);


private:
	struct node*root=NULL;
	int treeSize;
    int calculateHeight(struct node*rootNode);
	 void insert(struct node** node, T val);
	bool lookup(struct node* node, T val);
	void printPreOrder(struct node* node);
	void printInOrder(struct node* node);
	void printPostOrder(struct node* node);
	void deleteTree(struct node* node);
    int nodeCounts(struct node* rootNode);
    void destroySubTree(struct node* &);
    
};

template <class T>
BinaryTree<T>::BinaryTree(){
	this->root = NULL;
	this->treeSize = 0;
    
    
}

template <class T>
BinaryTree<T>::~BinaryTree(){
	this->destroyTree();
}

template <class T>
int BinaryTree<T>::size(){
	return this->treeSize;
}

template <class T>
void BinaryTree<T>::insert(T val){
    insert(&(this->root), val);
	
} //insert


template <class T>
void BinaryTree<T>::insert(struct node** node, T val){

	if(*node == NULL)	{
		struct node* tmp = new struct node;
		tmp->value = val;
		tmp->left=NULL;
		tmp->right = NULL;
		*node = tmp;

		this->treeSize++;
	}else{
		if(val > (*node)->value){
			insert(&(*node)->right, val);
		}else{
			insert(&(*node)->left, val);
		}
	}//else
    
}

template <class T>
void BinaryTree<T>::printInOrder(){
	printInOrder(this->root);
	cout<<endl;
}

template <class T>
void BinaryTree<T>::printInOrder(struct node* node){
	if(node != NULL){
		printInOrder(node->left);
		cout << node->value << ", ";
		printInOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::printPreOrder(){
	printPreOrder(this->root);
	cout << endl;
}


template <class T>
void BinaryTree<T>::printPreOrder(struct node* node){
	if(node != NULL)	{
		cout << node->value << ", ";
		printPreOrder(node->left);
		printPreOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::printPostOrder(){
	printPostOrder(this->root);
	cout << endl;
}

template <class T>
void BinaryTree<T>::printPostOrder(struct node* node){
	if(node != NULL){
		printPostOrder(node->left);
		printPostOrder(node->right);
		cout << node->value << ", ";
	}
}



template <class T>
void BinaryTree<T>::deleteTree(struct node* node){
	if(node != NULL){
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <class T>
bool BinaryTree<T>::lookup(T val){
	return lookup(this->root, val);
}

template <class T>
bool BinaryTree<T>::lookup(struct node* node, T val){
	if(node == NULL){
		return false;
	}//if
    else{
		if(val == node->value){
			return true;
		}//if

		if(val > node->value){
			return lookup(node->right, val);
		}//if
        else{
			return lookup(node->left, val);
		}//else
	}//else

}
template <class T>
int BinaryTree<T>::height(void){
	calculateHeight(this->root);
}

template<class T>
int BinaryTree<T>::calculateHeight(struct node*rootNode){

     int leftHeight=0;
    int rightHeight=0;

if(rootNode == NULL) {

		return 0;

	}//if

	else{
        leftHeight=calculateHeight(rootNode->left);
        rightHeight=calculateHeight(rootNode->right);
        if(rightHeight > leftHeight){

            return ++rightHeight;
        }//if

        else{
            return ++leftHeight;
        }//else

	}//else


}//end

template <class T>
int BinaryTree<T>::counts(void){
	nodeCounts(this->root);
}

template <class T>
int BinaryTree<T>::nodeCounts(struct node*rootNode){
    
    if (rootNode== NULL)
    {
        return 0;
    }
   // int countForThisNode = rootNode->right != NULL and rootNode->left!= NULL;
    //return countForThisNode + nodeCounts(rootNode->right) + nodeCounts(rootNode->left);
    return 1+nodeCounts(rootNode->left)+nodeCounts(rootNode->right);
}//end NodeCount
template <class T>
void BinaryTree<T>::destroyTree(void) {
	destroySubTree(this->root);
} //clear
template <class T>
void BinaryTree<T>::destroySubTree(struct node* &rootNode) {

	if (rootNode != NULL) {
		destroySubTree(rootNode->left);
		destroySubTree(rootNode->right);
		delete rootNode;
	}//if
}		

int main(){

	BinaryTree<int> myIntTree;

    cout<<"Before inserting total tree height : "<<myIntTree.height()<<endl;
    cout<<"Before inserting total tree Nodes : "<<myIntTree.counts()<<endl;
    int n1=5;
    int n2=6;
    int n3=10;
    int n4=1;
    int n5=13;
    int n6=2;
   
	cout<<"Now inserting number: "<<n1<<endl;
    myIntTree.insert(n1);
	cout<<"Now inserting number: "<<n2<<endl;
    myIntTree.insert(n2);
    cout<<"Now inserting number: "<<n3<<endl;
    myIntTree.insert(n3);
    cout<<"Now inserting number: "<<n4<<endl;
    myIntTree.insert(n4);
    cout<<"Now inserting number: "<<n5<<endl;
    myIntTree.insert(n5);
    cout<<"Now inserting number: "<<n6<<endl;
    myIntTree.insert(n6);

    
    cout<<"Total tree height : "<<myIntTree.height()<<endl;
    cout<<"Total node counts : "<<myIntTree.counts()<<endl;

	cout<<"Here is Post-order print "<<endl;
    myIntTree.printPostOrder();
    cout<<"Here is In-order print "<<endl;
	myIntTree.printInOrder();
     cout<<"Here is Pre-Order print "<<endl;
	myIntTree.printPreOrder();

cout << "Tree size: " << myIntTree.size()<<endl;

	
	
}


#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


class Node
{
 public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node();
    void setData(int value);
    ~Node();
};

Node::Node(){
    left = NULL;
   	right = NULL;
    parent = NULL;
}
void Node::setData(int data){
    this->data=data;
}

Node::~Node(){

}

class AvlTrees
 {
 public:
 	Node *root;
 	AvlTrees();
 	
 	int high(Node *node);
 	int balance(Node *node);

 	void pre(Node *node);
 	void in(Node *node);
 	void post(Node *node);

	void insert(int value);
 	void reBalance(Node *v, string a);
 	void rightRotaion(Node *v);
 	void leftRotaion(Node *v);
 	void RitLefRotaion(Node *v);
 	void LefRitRotaion(Node *v);
 	void checkIsNull(Node *v, Node *w ,Node *x , string a);

 	void deLete(int value);
 	void deLeteRightRotaion(Node *v);
 	void deLeteLeftRotaion(Node *v);
 	void deLeteRitLefRotaion(Node *v);
	void deLeteLefRitRotaion(Node *v);


	void checkParent(Node *v,Node *x);
 	void printAvl(string order);
 	~AvlTrees();
 }; 


 AvlTrees::AvlTrees(){
	root = NULL;
}
int AvlTrees::high(Node *node){
	int right = 0 ;
	int left = 0;
	if(node == NULL){
		return -1;
	}
	right = this->high(node->right) + 1;
	left = this->high(node->left) + 1;

	if(right > left){
		return right;
	}
	else{
		return left;
	}
	return 0;

}
int AvlTrees::balance(Node *node){
	int right = 0;
	int left = 0;
	int result = 0;

	right = this->high(node->right);
	left = this->high(node->left);
	result = left - right;
	return result;
}
//reBalance string a== "in" insert value to tree else remove 
void AvlTrees::reBalance(Node *node, string a){
		Node *temp = node;
		while(temp !=NULL){
			if(this->balance(temp) == -2){
				if(this->balance(temp->right) ==-1){
					if(a == "in"){
						rightRotaion(temp);
					}else{
						deLeteLeftRotaion(temp);
					}

				}else if(this->balance(temp->right) == 0){
					deLeteLeftRotaion(temp);
				}
				else if(this->balance(temp->right) == 1){
					if(a == "in"){
						RitLefRotaion(temp);
					}else{
						deLeteRitLefRotaion(temp);
					}
				}
			} 
			else if(this->balance(temp) == 2){
				if(this->balance(temp->left) ==1){
					if(a == "in"){
						leftRotaion(temp);
					}else{
						deLeteRightRotaion(temp);
					}

				}else if(this->balance(temp->left) == 0){
					deLeteRightRotaion(temp);
				}
				else if(this->balance(temp->left) == -1){
					if(a == "in"){
						LefRitRotaion(temp);
					}else{
						deLeteLefRitRotaion(temp);
					}
				}
			} 
			temp  = temp->parent;
		}
}
//check the v node is on the right or left on v's parent
void  AvlTrees::checkParent(Node *v, Node *x){
	if(v->parent == NULL){
		x->parent =NULL;
		root = x;
	}
	else{
		if(v->parent->left->data == v->data){
			v->parent->left = x;
		}else if(v->parent->right->data == v->data){
			v->parent->right = x;
		}
		x->parent = v->parent;
	}
}
//check the right or left value is not null 
void AvlTrees::checkIsNull(Node *v, Node *w ,Node *x , string a){
	if(a == "LefRitRotaion"){
		if(w->left ==NULL){
			x->right =NULL;
		}else{
			x->right = w->left;
			x->right->parent = x;
		}
		if(w->right == NULL){
			v->left =NULL;
		}else{
			v->left = w->right;
			v->left->parent = v;
		}
	}
	else {
		if(w->left ==NULL){
			v->right =NULL;
		}else{
			v->right = w->left;
			v->right->parent = v;
		}
		if(w->right == NULL){
			x->left =NULL;
		}else{
			x->left = w->right;
			x->left->parent = x;
		}

	}
}
void AvlTrees::rightRotaion(Node *v){
	Node *x = v->right;

	checkParent(v,x);
	if(x->left !=NULL){
		v->right = x->left;
		x->left->parent = v;
	}else{
		v->right = NULL;
	}
	x->left = v;
	v->parent = x;
}

void AvlTrees::leftRotaion(Node *v){
	Node *x = v->left;

	checkParent(v,x);
	
	if(x->right !=NULL){
			v->left = x->right;
			x->right->parent = v;
		}else{
			v->left = NULL;
		}
		x->right = v;
		v->parent = x;
}
void AvlTrees::RitLefRotaion(Node *v){
		Node *x = v->right;
		Node *w =  x->left;

		checkParent(v,w);
		checkIsNull(v, w , x , "RitLefRotaion");
		w->left =v;
		v->parent = w;
		w->right =x;
		x->parent =w;
}
void AvlTrees::LefRitRotaion(Node *v){
		Node *x = v->left;
		Node *w = x->right;

		checkParent(v,w);
		checkIsNull(v, w , x , "LefRitRotaion");
		w->left =x;
		x->parent = w;
		w->right =v;
		v->parent =w;
}


void AvlTrees:: insert(int value){
	Node *node = new Node();
	node->setData(value);
	if(root == NULL){
		root = node;
		return;
	}
	Node *temp = root;
		while(temp !=NULL){
			if(temp->data == value){
				return;
			}
			else if(temp->data > value){
				if(temp->left == NULL){
					node->parent = temp;
					temp->left = node;
					this->reBalance(node, "in");
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
					if(temp->right == NULL){
					node->parent = temp;
					temp->right= node;
					this->reBalance(node, "in");
					return;
				}else {
					temp = temp->right;
					}
			}
		}
	}
void AvlTrees::pre(Node *node){
	if(node == NULL){
		return;
	}
	cout << node->data << " ";
	pre(node->left);
	pre(node->right);
}
void AvlTrees::in(Node *node){
	if(node == NULL){

		return;
	}
	in(node->left);
	cout << node->data << " ";
	in(node->right);
}
void AvlTrees::post(Node *node){
	if(node == NULL){
		return;
	}
	post(node->left);
	post(node->right);
	cout << node->data << " ";
}


void AvlTrees::printAvl(string order){
	if(root == NULL){
		cout << "EMPTY" << endl;
		return;
	}
	else{
		 if(order == "PRE"){
			this->pre(root);
		}else if(order == "IN"){
			this->in(root);
		}else if(order == "POST"){
			this->post(root);
		}
	}
	cout << endl;
}

void AvlTrees::deLete(int value){
	Node *temp = root;
		while(temp !=NULL){
			if(temp->data == value){
				if(temp->left == NULL){
					if(temp->right ==NULL){
						if(temp->parent ==NULL){
							root =NULL;
						}
						else{ //Right ! NULL ;
							Node *p = temp->parent;
							if(temp->parent->right != NULL && temp->parent->right->data == temp->data){
								temp->parent->right =NULL;
							}else if (temp->parent->left != NULL && temp->parent->left->data == temp->data){
								temp->parent->left =NULL;
							}
							if(p != NULL){
							reBalance(p, "rm");
							return;

							}
						}
					
					}
					else { 
						Node *nRight = temp->right;
						if(temp->parent ==NULL){
							root =temp->right;
							root->parent =NULL;
						}else{
							if( temp->parent->left != NULL && temp->parent->left->data == temp->data){
								temp->parent->left = temp ->right;
							}else if ( temp->parent->right != NULL && temp->parent->right->data == temp->data){
								temp->parent->right =temp->right;
							}
							temp->right->parent =temp->parent;
						}
						if(nRight != NULL){
							reBalance(nRight, "rm");
							return;
						}

					}
				}else{
					Node *node = temp->left;
					while(node->right != NULL){
						node = node->right;
					}
					Node *nodeP = node; 
					if(node->left !=NULL){
						if( node->parent->left != NULL && node->parent->left->data == node->data){
							node->parent->left = node->left;
						}else if(node->parent->right != NULL && node->parent->right->data == node->data){
							node->parent->right = node->left;
						}
						node->left->parent = node->parent;
					}
					else{
						if( node->parent->left != NULL && node->parent->left->data == node->data){
							node->parent->left =NULL;
						}else if( node->parent->right != NULL && node->parent->right->data == node->data){
							node->parent->right =NULL;
						}
					}
					if(temp->parent ==NULL){
						root = node;
						root->parent =NULL;
					}else{
						if(temp->parent->left != NULL && temp->parent->left->data == temp->data){
							temp->parent->left=node;
							temp->parent->left->parent = temp->parent;
						}
						else if( temp->parent->right != NULL && temp->parent->right->data == temp->data){
							temp->parent->right = node;
							temp->parent->right->parent=temp->parent;
						}
					}
					node->left= temp->left;
					node->right = temp->right;
					if(node->left != NULL){
						node->left->parent =node;
					}
					if(node->right != NULL){
						node->right->parent =node;
					}
					if(nodeP != NULL){
						reBalance(nodeP, "rm");
						return;
					}

				}
				delete temp;
				return;
			}else if(temp->data > value){
				if(temp->left == NULL){
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
					if(temp->right == NULL){
					return;
				}else {
					temp = temp->right;
					}
			}
		}
}
void AvlTrees::deLeteLeftRotaion(Node *v){
	Node *x = v->right;
	Node *b = x->left;

	checkParent(v,x);
	v->parent =x;
	x->left = v;

	v->right = b;
	if(b != NULL){
		b->parent =v;
	}
}

void AvlTrees::deLeteRightRotaion(Node *v){
	Node *x = v->left;
	Node *b;
	if(x->right !=NULL){
		b = x->right;
	}else{
		b=NULL;
	}

	checkParent(v,x);
	v->parent =x;
	x->right = v;

	v->left = b;
	if(b != NULL){
		b->parent =v;
	}
}
void AvlTrees::deLeteRitLefRotaion(Node *v){
	Node *x = v->right;
	Node *w = x->left;
	Node *b = w->left;
	Node *c = w->right;

	checkParent(v,w);
	v->parent = w;
	w->left = v;
	x->parent = w;
	w->right = x;

	v->right = b;
	if(b != NULL){
		b->parent =v;
	}
	x->left = c;
	if(c != NULL){
		c->parent =x;
	}

}
void AvlTrees::deLeteLefRitRotaion(Node *v){
	Node *x = v->left;
	Node *w = x->right;
	Node *b = w->right;
	Node *c = w->left;

	checkParent(v,w);
	v->parent = w;
	w->right = v;
	x->parent = w;
	w->left = x;

	v->left = b;
	if(b != NULL){
		b->parent =v;
	}
	x->right = c;
	if(c != NULL){
		c->parent =x;
	}
}

AvlTrees::~AvlTrees(){


}



int main(){
	string temp= "";
	vector<int> nums;

	string order = "";
	int temNum = 0;
	string instuct = "";

	getline(cin, temp);
	vector<string> tree;
	string result = "";

	stringstream input(temp);
	while(input >> result){
		tree.push_back(result);
	}

	for(int i = 0 ; i < tree.size(); i ++){
		if(tree[i][0] == 'A' || tree[i][0] == 'D' ){
			order += tree[i][0];
			temNum = stoi(tree[i].substr(1,tree[i].size()));
			nums.push_back(temNum);

		}else{
			instuct = tree[i];
		}
	}
	AvlTrees avl;

	for(int i = 0 ; i < nums.size(); i++){
		if(order[i] == 'A'){
			avl.insert(nums[i]);
		}
		else if(order[i] == 'D'){
			avl.deLete(nums[i]);
		}
	}
	avl.printAvl(instuct);
	return 0;
}

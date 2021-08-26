#include<bits/stdc++.h>
using namespace std;

struct node
{
	int roll;
	node *left, *right;
	node() //initialize the node using null
	{
		left=NULL;
		right=NULL;
	}
};
node *root;

void Insert(int roll)
{
	if(root==NULL) //first node in tree
	{
		root=new node();
		root->roll=roll;
	}
	else
	{
		node *current=root,*parent;
		while(current!=NULL)
		{
				if(roll<current->roll)
				{
					parent=current; //keep track of parent node
					current=current->left;
				}
				else
				{
					parent=current;
					current=current->right;
				}
		}
		node *newnode=new node();
		newnode->roll=roll;
		if(newnode->roll<parent->roll) parent->left=newnode;
		else parent->right=newnode;
	}
}

void print_preorder(node *current)
{
	if(current==NULL) return;
	cout<<current->roll<<endl;
	print_preorder(current->left);
	print_preorder(current->right);

}

int main()
{
    Insert(10);
    Insert(1);
    Insert(5);
    Insert(9);
    Insert(4);
    Insert(0);

    print_preorder(root);
}

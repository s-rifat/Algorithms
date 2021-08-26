
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int roll;
	node *next, *prev;
};
node *root, *tail;
void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=new node();
		root->roll=roll;
		root->next=NULL;
		tail=root;
	}
	else
	{
		node *newnode=new node();
		newnode->roll=roll;
		newnode->next=NULL;
		tail->next=newnode; //add the new node after tail node
		tail=tail->next; //move tail pointer forward
	}
}

int main()
{
    return 0;
}

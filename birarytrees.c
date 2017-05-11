#include <stdio.h>


typedef struct node node;

struct node {
int value;
node *left;
node *right;
};

int compare(int a,int b)
{
	return (a > b) - (a < b);
}

node node_from_value(int value)
{
	node n;
	n.value = value;
	n.right = NULL;
	n.left = NULL;
	return n;
}

void attatch_left(node* parent,node* child)
{
    printf("1");
	parent->left = child;
}

void attatch_right(node* parent,node* child)
{
    printf("2");
	parent->right = child;
}

void insert_node(node* parent, node* new)
{
	printf("0");
	switch(compare(parent->value,new->value))
	{
		case 1:
		if(parent->left==NULL)attatch_left(parent, new);
		else insert_node(parent->left,new);
		break;
		
		case -1:
		if(parent->right==NULL)attatch_right(parent, new);
		else insert_node(parent->right,new);
		break;
			
		default:
			break;
					
	}

}

	
	int sum(node* root)
	{
	    int suma = root->value;
	    if(root->left  != NULL) suma += sum(root->left);
	    if(root->right != NULL) suma += sum(root->right);
	    return suma;
	}


int main(int argc, const char* argv[])
{
node N = node_from_value(3);
node A = node_from_value(2);
node K = node_from_value(1);
insert_node(&N,&A);
printf("SUMA: %d",sum(&N));
insert_node(&N,&K);
printf("N:%d\n",N.value);
printf("N left:%d\n",N.left->value);
printf("N left left:%d\n",N.left->left->value);





return 0;
}
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
};

typedef struct Node node;


node* create_node(int value)
{
	
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = value;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

node* insert(node *root,int value)
{
	if (root == NULL)
	{
		return create_node(value);
	}
	else if (value < root->data)
	{
		root -> left = insert(root->left, value);
	}
	else
	{
		root -> right =  insert(root -> right, value);
	}	
	return root;
}

void search(node *root)  
{  
	int val;
	printf("\nEnter the value to be searched :");
	scanf("%d", &val);
	printf("\n");

	node *temp = root;

    while (temp != NULL)  
    {  
    	if (temp -> data == val)
    	break;
    	
        if (val < temp -> data)  
        {
            temp = temp -> left;  
    	}
        else
		{  
            temp = temp -> right;  
    	}
    } 
    if (temp == NULL)
    {
    	printf("!!NOT FOUND\n");
	}
	else
	{
		printf("The element %d is in the tree\n", temp -> data);
	}
} 

void display(node *root)  
{  
    if (root != NULL)
    {
    display(root->left);  
   	printf("%d\n", root -> data);
    display(root->right);
	}
}   

node* delete_node(node *root, int value)
{
	node *parent_node = NULL;
	node *temp = root;
	while (temp != NULL && temp -> data != value)  
    {  
    	parent_node = temp;
    	
        if (value < temp -> data)  
        {
            temp = temp -> left;  
    	}
        else
		{  
            temp = temp -> right;  
    	}
    } 
    if (temp == NULL)  
    printf("NO SUCH ELEMENT IN THE TREE");  
  
    else if (temp -> left == NULL && temp -> right == NULL)  
    {  
    	//printf("%d\n",temp -> code);
        if (temp != root)  
        {  
            if (parent_node -> left == temp)  
                parent_node -> left = NULL;  
            else  
                parent_node -> right = NULL;  
        }  
        else  
        {
        	root = NULL;
		}
        free(temp);       
    }  
    else if (temp -> left != NULL && temp -> right != NULL)  
    {  
    	node *temp2 = temp -> right;
    	
    	while(temp2 -> left != NULL) 
		{  
        	temp2 = temp -> left;  
    	}  
  
        int temp_val_holder = temp2 -> data;  
  
        delete_node(root, temp2 -> data);  
  
        temp -> data = temp_val_holder;  
    }  
  
    else  
    {  
    	node* child_node = NULL;
    	if (temp -> left != NULL)
    	child_node = temp -> left;
    	else
    	child_node = temp -> right;
  
        if (temp != root)  
        {  
            if (temp ==  parent_node -> left)  
                parent_node -> left = child_node;  
            else  
                parent_node -> right = child_node;  
        }  
        else  
            root = child_node;  
        free(temp);  
    }  
	
}

void main()
{
	node *root = NULL;
	int element;
	int del_val;
	int i=0;
	int ch;
	while (i != 1)
	{
		printf("\n\n_________________________\n\nPlease Choose an option\n_________________________\n\n 1.INSERT ELEMENT\n 2.SEARCH ELEMENT\n 3.DISPALY ELEMENTS IN TREE\n 4.DELETE A ELEMENT\n 5.EXIT\n");
		printf("Enter your choice :");
		scanf("%d", &ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				
				printf("Enter the value:");
				scanf("%d",&element);
				printf("\n");
				
				root = insert(root, element);
				break;
				
			case 2:
				search(root);
				break;
			case 3:
				display(root);
				break;
			case 4:
				printf("Enter the Element to deleted :");
				scanf("%d", &del_val);
				delete_node(root, del_val);
				break;
			case 5:
				i =1;
		}
	} 	
}



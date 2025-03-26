//SET B
/*  a) Write a C program which uses Binary search tree library
	 and implements following function with recursion:
			T copy(T) - create another BST which is exact copy of BST 
			which is passed as parameter. 
			int compare(T1, T2) - compares two binary search trees 
			and returns I if they are equal and�0�otherwise.      */
			
#include<stdio.h>
#include<stdlib.h>
#include "btree.h"
BSTnode *treecopy(BSTnode *root)
{
	BSTnode *newnode;
	if(root!=NULL)
	{
		newnode=(BSTnode*)malloc(sizeof(BSTnode));
		newnode->data=root->data;
		newnode->left=treecopy(root->left);
		newnode->right=treecopy(root->right);
		return newnode;
		
	}
	else
		return NULL;
}

int compare(BSTnode *root1,BSTnode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	else
		if(root1!=NULL && root2!=NULL)
				if(compare(root1->left,root2->left))
					return compare(root1->right,root2->right);
	return 0;
}


int compare1(BSTnode *root1, BSTnode *root2) 
{
    if (root1 == NULL && root2 == NULL) 
	{
        return 1;
    }
    if (root1 == NULL || root2 == NULL) 
	{
        return 0;
    }
    if (root1->data != root2->data)
	 {

        return 0;
    }
    return compare1(root1->left, root2->left) && compare1(root1->right, root2->right);
}
int main()
{
	int choice,key,ans;
	BSTnode *root=NULL,*root1=NULL;
	printf("1) Copy Tree\n");
	printf("2) Compare Tree\n");
	printf("3) Exit\n");
	printf("Enter Your Choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n");
			root=create(root);
			root1=treecopy(root);
			printf(" 1st Tree is : \n");
			inorder(root);
			printf("\nCopy Tree IS : \n");
			inorder(root1);
			free(root);
			free(root1);
			break;
			
		case 2:
			printf("\n");
			printf("1) Compare two Tree Structure\n");
			printf("2) Compare two Tree With Node Data\n");
			printf("3) Exit\n");
			printf("Enter Your Choice : ");
			scanf("%d",&key);
			switch(key)
			{
				case 1:
					printf("Enter The First Tree : \n");
					root=create(root);
					printf("\nEnter The Second Tree : \n");
					root1=create(root1);
	
					ans=compare(root,root1);
					if(ans!=0)
						printf("\nBoth tree are same");
					else
						printf("\nBoth Tree Are not same");
					free(root);
					free(root1);
					break;
					
				case 2:
					printf("Enter The First Tree : \n");
					root=create(root);
					printf("\nEnter The Second Tree : \n");
					root1=create(root1);
					ans=compare1(root,root1);
					if(ans!=0)
						printf("\nBoth tree are same");
					else
						printf("\nBoth Tree Are not same");
					free(root);
					free(root1);
					break;
			}
		
		case 3:
			exit(0);
		}

	return 0;
}


#include<stdio.h>
#include "btree.h"
 int main()
{
	BSTnode *root=NULL;
	int choice,ele,nodes;
	do
	{
	printf("\n\n");
	printf("1) create\n");
	printf("2) insert\n");
	printf("3) search\n");
	printf("4) Display\n");
	printf("5) Exit\n");
	printf("Enter The Choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			root=create(root);
			break;
			
		case 2:
			printf("Enter the Elements To Insert : ");
			scanf("%d",&ele);
			insert(root,ele);
			break;
			
		case 3:
			printf("Enter The Elements To Search : ");
			scanf("%d",&ele);
			if(search(root,ele)!=NULL)
			{
				printf("Element Is Present In Tree.\n");
			}
			else
			{
				printf("Element Is Not Present In Tree.\n");
			}
			break;
			
		
		case 4:
			printf("Tree Is : \n");
			printf("\nInorder : ");
			inorder(root);
			printf("\npreorder : ");
			preorder(root);
			printf("\npostorder : ");
			postorder(root);
			break;
			
	
		case 5:
			exit(0);
	}
	}while(choice!=5);
	
	return 0;
}


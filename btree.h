#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *left,*right;
};
typedef struct node BSTnode;
BSTnode *create(BSTnode *root)
{
        BSTnode *newnode,*temp,*parent;
        int i,n,num;
        printf("How Many Nodes : ");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
                newnode=(BSTnode*)malloc(sizeof(BSTnode));
                scanf("%d",&num);
                newnode->data=num;
                newnode->left=newnode->right=NULL;
                if(root==NULL)
                {
                        root=newnode;
                        continue;
                }
                temp=root;
                while(temp!=NULL)
                {
                        parent=temp;
                        if(num<temp->data)
                        {
                                temp=temp->left;
                        }
                        else
                        {
                                temp=temp->right;
                        }

                }
                if(num<parent->data)
                {
                        parent->left=newnode;

                }
                else
                {
                        parent->right=newnode;
                }
        }
        return(root);
}

//search
BSTnode *search(BSTnode *root,int key)
{
        BSTnode *temp=root;
        while(temp!=NULL)
        {
                if(key==temp->data)
                        return(temp);
                if(key<temp->data)
                        temp=temp->left;
                else
                        temp=temp->right;

        }
        return NULL;
}

//insert
BSTnode *insert(BSTnode *root,int ele)
{
        BSTnode *newnode,*temp=root,*parent;
        newnode=(BSTnode*)malloc(sizeof(BSTnode));
        newnode->data=ele;
        newnode->right=newnode->left=NULL;
        if(root==NULL)
        {
                root=newnode;
                return(root);
        }
        while(temp!=NULL)
        {
                parent=temp;
                if(ele<temp->data)
                {
                        temp=temp->left;
                }
                else
                {
                        temp=temp->right;
                }
        }
        if(ele<parent->data)
        {
                parent->left=newnode;
        }
        else
        {
                parent->right=newnode;
        }
        return(root);
}

//display
void preorder(BSTnode *root)
{
        BSTnode *temp=root;
        if(temp!=NULL)
        {
                preorder(temp->left);
                printf("%d\t",temp->data);
                preorder(temp->right);
        }
}

void inorder(BSTnode *root)
{
        BSTnode *temp=root;
        if(temp!=NULL)
        {
                inorder(temp->left);
                printf("%d\t",temp->data);
                inorder(temp->right);
        }
}

void postorder(BSTnode *root)
{
        BSTnode *temp=root;
        if(temp!=NULL)
        {
                printf("%d\t",temp->data);
                postorder(temp->left);
                postorder(temp->right);

        }
}

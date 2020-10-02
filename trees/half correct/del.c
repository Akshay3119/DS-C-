#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node{
    struct node *left;
    struct node *right;
    int info;
};
typedef struct node NODE;

NODE *createnode(int n)
{
  NODE *nn;
  nn=(NODE*)malloc(sizeof(NODE));
  nn->left=nn->right=NULL;
  nn->info=n;
  return nn;  
}


NODE *createtree(NODE *root)
{
    NODE *p,*c;
    int z=1,n,x;
    printf("enter info part of root\n");
    scanf("%d",&x);
    root=createnode(x);
    while(z!=0)
    {
        printf("enter info part of next node\n");
        scanf("%d",&n);
        p=c=root;
        while(c!=NULL)
        {
            p=c;
            if(n>p->info)
                c=p->right;
            else
                c=p->left;

        }
        if(n>p->info)
            p->right=createnode(n);
        else
            p->left=createnode(n);
        printf("do you want to continue?\n");
        scanf("%d",&z);
    }
    return root;
}

NODE *searchp(NODE *root,int x)
{
    NODE *p,*c;
    p=c=root;
    
    while(x!=c->info)
    {
        p=c;
        if(x>p->info)
            c=p->right;
        else
            c=p->left;
    }
    return p;
}

void trv(NODE *root)
{   
    if(root!=NULL)
    {
        trv(root->left);
        printf("%d\t",root->info);
        trv(root->right);
    }
}

NODE *search(NODE *root,int val)
{
    while(root!=NULL&&root->info!=val)
    {
        if(val>root->info)
            root=root->right;
        else
            root=root->left;
    }
    return root;

}


NODE *inorderSuccessor(NODE *root, NODE *node)
{
  
    NODE *successor = NULL;
    NODE *current  = root;
  
    while(current->info != node->info)
    {    
        if(current->info > node->info)
        {
            successor = current;
            current= current->left;
        }
        
        else
            current = current->right;
    }
    
    if(current!=NULL && current->right!=NULL)
    {
        successor=current->right;
        while(successor->left!=NULL)
            successor=successor->left;
    }
  
    return successor;
}

void swap(NODE *a,NODE *b)
{
    NODE *c;
    c=createnode(0);
    c->info=b->info;
    b->info=a->info;
    a->info=c->info;
}


NODE *del(NODE *root,NODE *adr)
{
    NODE *q,*p;
    if(adr==NULL)
        return;
    if(adr->right==NULL&&adr->left==NULL)
    {
        p=searchp(root,adr->info);
        if(p->left==adr)
            p->left=NULL;
        else
            p->right=NULL;
        free(adr);
        return root;
    }
    else if(adr->right!=NULL&&adr->left!=NULL)
    {
        q=inorderSuccessor(root,adr);
        swap(adr,q);
        root=del(root,q);
        return root;
    }
    else
    {
        if(adr->left!=NULL)
        {
            swap(adr,adr->left);
            free(adr->left);
            adr->left=NULL;
            return root;
        }
        else
        {
            swap(adr,adr->right);
            free(adr->right);
            adr->right=NULL;
            return root;
        }


    }
}


void main()
{
    int x,z=1;
    NODE *root,*adr;
    root=adr=NULL;
    root=createtree(root);
    do{
        printf("enter info to be deleted : ");
        scanf("%d",&x);
        adr=search(root,x);
        if(adr==NULL)
            printf("info not found\n");
        root=del(root,adr);
        trv(root);
        printf("\n");
        printf("do you want to delete again? : ");
        scanf("%d",&z);
    }while(z!=0);

    trv(root);
}
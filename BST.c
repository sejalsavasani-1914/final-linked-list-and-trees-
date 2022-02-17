#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *l;
    struct node *r;
};

struct node *newnode(int);
struct node inorder(struct node *);
struct node *insert(int,struct node *);
struct node* deletenode(struct node *, int);

int main()
{
    int x,n;
    struct node *t,*temp;
    t = (struct node *)malloc(sizeof(struct node));

    printf("how many nodes you want in tree?\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the value of tree node\n");
        scanf("%d",&x);
        insert(x,t);
        
    }
    printf("inorder value is:\n");
    inorder(t);
    t = deletenode(t,20);
    printf("\nInorder traversal of the tree after deleting node: \n");
    inorder(t);
    printf("\n");
return 0;   
}

struct node* newnode(int item)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->info=item;
    t->l=t->r=NULL;
    return t;
}

struct node inorder(struct node *t)
{
        if(t!=NULL)
        {
            inorder(t->l);
            printf("%d,",t->info);
            inorder(t->r);
        }
}

struct node *insert(int info,struct node *t) 
{
    if(t==NULL)
    {
        return newnode(info);
    }
    if(info < t->info) 
    {
    t->l=insert(info,t->l);
    } 
    else if(info > t->info) 
    {
    t->r=insert(info,t->r);
    }
    return t;
}

struct node* minvaluenode(struct node *t)
{
    struct node *current = t;
    while (current && current->l != NULL)
    {
        current = current->l;
    }
    return current;
}

struct node* deletenode(struct node *t, int info)
{
    if(t==NULL)
    {
        return t;
    }
    if(info < t->info)
    {
        t->l=deletenode(t->l,info);
    }
    else if(info > t->info)
    {
        t->r=deletenode(t->r,info);
    }
    else
    {
        if(t->l==NULL)
        {
            struct node *temp = t->r;
            free(t);
            return temp;
        }
        else if(t->r == NULL)
        {
            struct node *temp = t->l;
            free(t);
            return temp;
        }
        struct node *temp = minvaluenode(t->r);
        t->info = temp->info;
        t->r = deletenode(t->r, temp->info);
    }
    return t;
}
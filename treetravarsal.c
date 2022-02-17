#include<stdio.h>
#include<stdlib.h>

struct node
{
    char info;
    struct node *l;
    struct node *r;
};

void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

void main()
{
    struct node *a,*b,*c,*d,*e,*f,*g,*t;
    a=(struct node *)malloc(sizeof(struct node));
    b=(struct node *)malloc(sizeof(struct node));
    c=(struct node *)malloc(sizeof(struct node));
    d=(struct node *)malloc(sizeof(struct node));
    e=(struct node *)malloc(sizeof(struct node));
    f=(struct node *)malloc(sizeof(struct node));
    g=(struct node *)malloc(sizeof(struct node));

    t=a;
    a->info='A';
    a->l=b;
    a->r=d;
    b->info='B';
    b->l=c;
    b->r=NULL;
    c->info='C';
    c->l=NULL;
    c->r=NULL;
    d->info='D';
    d->l=e;
    d->r=g;
    e->info='E';
    e->l=NULL;
    e->r=f;
    f->info='F';
    f->l=NULL;
    f->r=NULL;
    g->info='G';
    g->l=NULL;
    g->r=NULL;

    printf("preorder value is:\n");
    preorder(t);
    printf("\ninorder value is:\n");
    inorder(t);
    printf("\npostorder value is:\n");
    postorder(t);
    printf("\nThanks!\n");
}

void preorder(struct node *t)
{
    if(t==NULL)
    {
        printf("Empty Tree");
    }
    else
    {
        printf("%c",t->info);
    }
    if(t->l!=NULL)
        {
            preorder(t->l);
        }
    if(t->r!=NULL)
    {
        preorder(t->r);
    }
}

void inorder(struct node *t)
{
    if(t==NULL)
    {
        printf("Empty Tree");
    }
    else
    {
        if(t->l!=NULL)
        {
            inorder(t->l);
        }
        printf("%c",t->info);
        if(t->r!=NULL)
        {
            inorder(t->r);
        }
    }
}

void postorder(struct node *t)
{
    if(t==NULL)
    {
        printf("Empty Tree");
    }
    else
    {
        if(t->l!=NULL)
        {
            postorder(t->l);
        }
        if(t->r!=NULL)
        {
            postorder(t->r);
        }
        printf("%c",t->info);
    }
}
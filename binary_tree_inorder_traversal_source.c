//Source: http://programmingearth.com/post.php?pageid=74&title=C%20program%20for%20inorder%20traversal%20in%20binary%20tree.

#include<stdio.h>
#include<conio.h>
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);

    if(x==-1)
	return NULL;

    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

void inorder(node *t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("  %d",t->data);
    inorder(t->right);
  }
}


void main()
{
  node *root;
  clrscr();
  root=create();

  printf("\nThe inorder traversal of tree is: ");
  inorder(root);

  getch();
}


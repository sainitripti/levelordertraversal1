#include<iostream>

using namespace std;

struct node
{ int data;
  struct node* right;
  struct node* left;
};

struct node* newnode(int data);
int height(struct node * node);
void printlevel(struct node* root,int d);
void printlevelorder(struct node* root);

int main(void)
{ struct node* root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
  root->left->left=newnode(4);
  root->left->right=newnode(5);
  printlevelorder(root);
  return 0;
}

struct node* newnode(int data)
{ struct node* node=new(struct node);
  node->data=data;
  node->left=NULL;
  node->right=NULL;
}

int height(struct node * node)
{ if(node==NULL)
   return 0;
  else
 {
  int lheight=height(node->left);
  int rheight=height(node->right);
  if(lheight>=rheight)
   return (1+lheight);
  else
   return (1+rheight);
 }
}

void printlevel(struct node* root,int d)
{ if(root==NULL)
   return;
  if(d==1)
   cout<<root->data<<" ";
  else if(d>1)
  { printlevel(root->left,d-1);
    printlevel(root->right,d-1);
  }
}

void printlevelorder(struct node* root)
{ int h=height(root);
  for(int i=1;i<=h;i++)
   { printlevel(root,i);
     cout<<"\n";
   }
}

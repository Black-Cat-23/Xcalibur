#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
} tree;
 
tree *root=NULL;
int insert(int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->data=val;
    printf("Enter Left child of %d:(Enter -1 to return)", val);
    if(val==-1){
        return 0;
    }
    newnode->left=insert(val);
    printf("Enter Right child of %d:(Enter -1 to return)", val);
    if(val==-1){
        return 0;
    }
    newnode->right= insert(val);
    return newnode;
}

void inorder(tree *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void preorder(tree *root){
    if(root==NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelorder(tree *root){
    if(root==NULL){
        return;
    }
    queue *q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = -1;
    enqueue(q, root);
    while(!isEmpty(q)){
        tree *temp = dequeue(q);
        printf("%d ", temp->data);
        if(temp->left!=NULL){
            enqueue(q, temp->left);
        }
        if(temp->right!=NULL){
            enqueue(q, temp->right);
        }
    }
}
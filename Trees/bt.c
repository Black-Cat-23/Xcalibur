#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
    int data;
    struct tree *left;
    struct tree * right;
} tree ;
tree * root= NULL;

tree * create(int val){
    tree* newnode= malloc(sizeof(tree));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right= NULL;
    return newnode;
}

tree * insert( tree * root, int val){
    if (root==NULL){
        root=create(val);
    }
    else if ( root->data > val){
        root->left=insert(root->left, val);
    }
    else if ( root->data < val){
        root->right=insert(root->right, val);
    }
    return root;
}
tree  * minvalue(tree * root){
    if(root!= NULL || root->right!=NULL){

        return minvalue(root->right);
    }
    else{
        return root;
    }
}

void delete(tree * root, int val){
    if ( root ==NULL){
        printf("Tree is empty");
    }
    else if( root->data > val){
        delete(root->left, val);
    }
    else if ( root->data< val){
        delete(root->right, val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
        }
        else if (root->left==NULL){
            tree * temp=root;
            root=root->right;
            free(temp);
        }
        else if (root->right==NULL){
            tree * temp= root;
            root=root->left;
            free(temp);
        }
        else{
            tree * temp= minvalue(root->right);
            root->data=temp->data;
            delete(root->right, temp->data);
        }
    }
}

void inorder( tree * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder( tree * root){
    if(root!=NULL){

        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder( tree * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main(){

    root=create(10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    delete(root, 20);
    inorder(root);
} 
// Implement recursive and non-recursive tree traversing methods inorder, preorder and post-order traversal.
#include<stdio.h>
#include<stdlib.h>

struct BinaryTree{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

int AddChild(struct BinaryTree *root,int data){
    struct BinaryTree *NewNode = malloc(sizeof(struct BinaryTree));
    NewNode->data = data;
    if(root->data == data){
        return 0;
    }
    if(data < root->data){
        if(root->left){
            AddChild(root->left,data);
        }
        else{
            root->left =NewNode;
        }
    }
    else{
        if(root->right){
            AddChild(root->right,data);
        }
        else{
            root->right = NewNode;
        }
    }
}

struct BinaryTree* MakeTree(int arr[],int size){
    struct BinaryTree *root = malloc(sizeof(struct BinaryTree));
    root->data = arr[0];
    for(int i=0;i<size;i++){
        AddChild(root,arr[i]);
    }
    return root;
}

int InOrderTraversal(struct BinaryTree *root){    
        if(root->left){
            InOrderTraversal(root->left);
        }
        printf("%d  ",root->data);
        if(root->right){
            InOrderTraversal(root->right);
        }    
}

int PreOrderTraversal(struct BinaryTree *root){
    printf("%d  ",root->data);
    if(root->left){
        PreOrderTraversal(root->left);
    }
    if(root->right){
        PreOrderTraversal(root->right);
    }
}

int PostOrderTraversal(struct BinaryTree *root){
    if(root->left){
        PreOrderTraversal(root->left);
    }
    if(root->right){
        PreOrderTraversal(root->right);
    }
    printf("%d  ",root->data);
}

int main(){
    int arr[]={15,12,7,14,27,20,29,88,23};    
    struct BinaryTree *root;
    int size = sizeof(arr) / 4;
    root = MakeTree(arr,size);
    printf("Root is %d\n",root->data);
    InOrderTraversal(root);
    printf("\n");
    PreOrderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);
}




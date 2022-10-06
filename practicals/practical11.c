// Write a program which create binary search tree.
#include<stdio.h>
#include<stdlib.h>

struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

int AddChild(struct BinaryTreeNode *root,int Data){
    struct BinaryTreeNode *NewNode =malloc(sizeof(struct BinaryTreeNode));    
    NewNode->data = Data;
    if(root->data == Data){
        return 0;
    }
    if (Data < root->data){
        if(root->left){
            AddChild(root->left,Data);
        }
        else{
            root->left = NewNode;
        }
    }
    else{
        if(root->right){
            AddChild(root->right,Data);
        }
        else{
            root->right = NewNode;
        }
    }

}

void InOrderTraversal(struct BinaryTreeNode *root){
    if (root->left){
        InOrderTraversal(root->left);
    }
    printf("%d  ",root->data);
    if (root->right){
        InOrderTraversal(root->right);
    }

}
struct BinaryTreeNode* MakeTree(int arr[],int size){    
    struct BinaryTreeNode *root = malloc(sizeof(struct BinaryTreeNode));
    root->data = arr[0];
    for(int i=0;i<size;i++){
        // printf("%d  ",i);
        AddChild(root,arr[i]);
    }
    return root;
}
int main(){
    int arr[]={15,12,7,14,27,20,29,88,23};
    struct BinaryTreeNode *root;
    int size = sizeof(arr) / 4;
    root = MakeTree(arr,size);
    printf("Root is %d\n",root->data);
    InOrderTraversal(root);
}

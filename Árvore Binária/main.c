#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
  int key;
  struct TreeNode *left;
  struct TreeNode *right;
};

void preOrderWay(struct TreeNode **rootNode){
  printf("-> %d ", (*rootNode)->key);

  if((*rootNode)->left != NULL){
    preOrderWay(&(*rootNode)->left);
  }
  if((*rootNode)->right != NULL){
    preOrderWay(&(*rootNode)->right);
  }
}

void searchTree(int x, struct TreeNode **ptr, int *feedback){
  if((*ptr) == NULL){
    *feedback = 0;
  } else if(x == (*ptr)->key){
    *feedback = 1;
  } else if(x < (*ptr)->key) {
    if((*ptr)->left == NULL){
      *feedback = 2;
    } else {
      (*ptr) = (*ptr)->left;
      searchTree(x, ptr, feedback);
    }
  } else if((*ptr)->right == NULL){
    *feedback = 3;
  } else {
    (*ptr) = (*ptr)->right;
    searchTree(x, ptr, feedback);
  }
}

void insertTree(int x, struct TreeNode **rootNode){
  struct TreeNode *ptr = (*rootNode);
  int feedback;
  searchTree(x, &ptr, &feedback);
  if(feedback == 1){
    printf("Insercao invalida\n");
    return;
  }
  struct TreeNode *pt1 = (struct TreeNode*) malloc(sizeof(struct TreeNode));
  pt1->key = x;
  pt1->left = NULL;
  pt1->right = NULL;
  if(feedback == 0){
    (*rootNode) = pt1;
  } else if(feedback == 2){
    ptr->left = pt1;
  } else {
    ptr->right = pt1;
  }
}

int main(){
  struct TreeNode *ptr = NULL;

  insertTree(1, &ptr);
  insertTree(5, &ptr);
  insertTree(4, &ptr);
  insertTree(-8, &ptr);
  insertTree(-4, &ptr);
  
  struct TreeNode *temp = ptr;

  if(temp != NULL){
    preOrderWay(&temp);
  }

  return 0;
}
#include<iostream>
using namespace std;
struct BinaryTreeNode{
  int value;
  BinaryTreeNode* pLeft;
  BinaryTreeNode* pRight;
};
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
  if(pRoot2==NULL){
    return true;
  }
  if(pRoot1==NULL){
    return false;
  }
  if(pRoot1->value!=pRoot2->value){
    return false;
  }
  return (DoesTree1HaveTree2(pRoot1->pLeft, pRoot2->pLeft) &&
  DoesTree1HaveTree2(pRoot1->pRight,pRoot2->pRight));
}
bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
  bool result=false;
  if(pRoot1&&pRoot2){
    if (pRoot1->value==pRoot2->value) {
      result = DoesTree1HaveTree2(pRoot1, pRoot2);
    }
    if(!result){
      result = hasSubTree(pRoot1->pLeft, pRoot2);
    }
    if(!result){
      result = hasSubTree(pRoot1->pRight, pRoot2);
    }
  }
  return result;
}

#include<iostream>
using namespace std;
#define GET_ARRAY_LENGTH(array,len){len=(sizeof(array)/sizeof(array[0]));}
struct BinaryTreeNode{
  int m_nValue;
  BinaryTreeNode* m_pLeft;
  BinaryTreeNode* m_pRight;
};
BinaryTreeNode* ConstructCore(int* startPreOrder, int* endPreOrder,
  int* startInOrder, int* endInOrder){
    // 前序遍历的第一个数是根节点的值
    int rootValue = startPreOrder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    if(startPreOrder == endPreOrder){
      if(startInOrder==endInOrder && *startPreOrder == *startInOrder)
        return root;
      else
        throw exception();
    }
    // 中序遍历中找到根节点的值
    int* rootInOrder = startInOrder;
    while(rootInOrder<=endInOrder && *rootInOrder!=rootValue)
      ++rootInOrder;
    if(rootInOrder==endInOrder && *rootInOrder!=rootValue)
      throw exception();
    int LeftLength = rootInOrder - startInOrder;
    int* leftPreOrderEnd = startPreOrder+LeftLength;
    if(LeftLength>0){
      //构建左树
      root->m_pLeft = ConstructCore(startPreOrder+1, leftPreOrderEnd,
      startInOrder, rootInOrder-1);
    }
    if(LeftLength<endPreOrder-startPreOrder){
      //构建右树
      root->m_pRight = ConstructCore(leftPreOrderEnd+1, endPreOrder,
      rootInOrder+1, endInOrder);
    }
    return root;
  }
BinaryTreeNode* Construct(int* preOder, int* inOrder, int length){
  if(preOder==NULL || inOrder==NULL || length<0){
    return NULL;
  }
  return ConstructCore(preOder,preOder+length-1,inOrder,inOrder+length-1);
}
void DispBinaryTreeByPreOrder(BinaryTreeNode* root){
  // 前序遍历
  if(root){
    cout <<root->m_nValue;
    DispBinaryTreeByPreOrder(root->m_pLeft);
    DispBinaryTreeByPreOrder(root->m_pRight);
  }
}
void DispBinaryTreeByInOrder(BinaryTreeNode* root){
  // 中序遍历
  if(root){
    DispBinaryTreeByInOrder(root->m_pLeft);
    cout <<root->m_nValue;
    DispBinaryTreeByInOrder(root->m_pRight);
  }
}
// 层级遍历
//TO-DO:利用队列实现二叉树层级遍历
int main(int argc, char const *argv[]) {
  int preOder[]={1,2,4,7,3,5,6,8};
  int inOrder[]={4,7,2,1,5,3,8,6};
  int length;
  GET_ARRAY_LENGTH(preOder,length);
  BinaryTreeNode* root;
  root = Construct(preOder, inOrder, length);
  printf("%s\n", "print the BinaryTree by preOder");
  DispBinaryTreeByPreOrder(root);
  printf("\n");
  printf("%s\n", "print the BinaryTree by inOrder");
  DispBinaryTreeByInOrder(root);
  printf("\n");
  return 0;
}

#include<iostream>
#include<stack>
using namespace std;
#define GET_ARRAY_LENGTH(array,len){len=(sizeof(array)/sizeof(array[0]));}
struct ListNode{
  int m_nValue;
  ListNode* m_pNext;
};
// 双重指针 和 指针的引用 两种方法构建链表
void AddtoTail(ListNode** pHead, int value){
  ListNode* pNew = new ListNode();
  pNew->m_nValue = value;
  pNew->m_pNext = NULL;
  if(*pHead==NULL) {
    *pHead = pNew;
  }
  else{
    ListNode* pNode = *pHead;
    while (pNode->m_pNext!=NULL) {
      pNode = pNode->m_pNext;
    }
    pNode->m_pNext = pNew;
  }
}
void AddtoTail1(ListNode *&pHead, int value){
  ListNode* pNew = new ListNode();
  pNew->m_nValue = value;
  pNew->m_pNext = NULL;
  if(pHead==NULL) {
    pHead = pNew;
  }
  else{
    ListNode* pNode = pHead;
    while (pNode->m_pNext!=NULL) {
      pNode = pNode->m_pNext;
    }
    pNode->m_pNext = pNew;
  }
}
void RemoveNode(ListNode** pHead, int value){
  if (pHead == NULL || *pHead==NULL)
    return;
  ListNode* pToBeRemoved = NULL;
  if ((*pHead)->m_nValue==value){
    pToBeRemoved = *pHead;
    *pHead = (*pHead)->m_pNext;
  }
  else
  { ListNode* pNode = (*pHead)->m_pNext;
    while(pNode->m_nValue == value && pNode->m_pNext != NULL){
      pNode = pNode->m_pNext;
    }
    if(pNode->m_pNext!=NULL && pNode->m_pNext->m_nValue==value){
      pToBeRemoved = pNode->m_pNext;
      pNode->m_pNext = pNode->m_pNext->m_pNext;
    }
  }
  if(pToBeRemoved!=NULL){
    delete pToBeRemoved;
    pToBeRemoved = NULL;
  }
}
void DispList(ListNode* pHead){
  if (pHead==NULL)  return;
  ListNode* pNode = NULL;
  pNode = pHead;
  while(pNode->m_pNext!=NULL){
    cout<<pNode->m_nValue;
    pNode = pNode->m_pNext;
  }
  cout<<pNode->m_nValue<<"\n";
}
void PrintListFromTailToHeadByStack(ListNode* pHead){
  stack<ListNode*> nodes;    // 使用stack来实现：要使用stack需要在开头添加 #include <stack>
  ListNode* pNode = pHead;
  while(pNode!=NULL){
    nodes.push(pNode);
    pNode=pNode->m_pNext;
  }
  while(!nodes.empty()){
    pNode = nodes.top();
    cout<<pNode->m_nValue;
    nodes.pop();
  }
  cout<<"\n";
}
void PrintListFromTailToHeadByRecursively(ListNode* pHead){
  if(pHead!=NULL)
  {
    if(pHead->m_pNext!=NULL){
      PrintListFromTailToHeadByRecursively(pHead->m_pNext);
    }
    cout<<pHead->m_nValue;
  }
}
int main(int argc, char const *argv[]) {
  ListNode *pHead = NULL;
  int a[]={1,2,3,4,5};
  int len;
  GET_ARRAY_LENGTH(a,len);
  for(int i=0;i<len;i++){
    AddtoTail1(pHead, a[i]);
  }
  DispList(pHead);
  PrintListFromTailToHeadByRecursively(pHead);
  return 0;
}

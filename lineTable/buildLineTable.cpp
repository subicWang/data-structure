#include<iostream>
#define MaxSize 50
using namespace std;
typedef int ElemType;
typedef struct{
  ElemType data[MaxSize];
  int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n) { //由a中的个元素建立顺序表l
  int i=0, k=0;                                     // K表示L中的元素个数,初始值为0
  L=(SqList *)malloc(sizeof(SqList));               // 分配存放线性表的空间
  while(i<n){
    L->data[i] = a[i];                              // 将元素a[i]存放到l中
    k++;
    i++;
  }
  L->length = k;
}
void InitList(SqList *&L){
  L=(SqList *)malloc(sizeof(SqList));
  L->length = 0;
}
void DestroyList(SqList *&L){
   free(L);
}
bool IsEmpty(SqList *L){
  return(L->length==0);
}
int ListLength(SqList *L){
  return(L->length);
}
void DispList(SqList *L){
  for(int i=0; i<L->length; i++){
        printf("%d", L->data[i]);
  }
  printf("\n");
}
bool GetElem(SqList *L, int i, ElemType &e){
  if(i<1 || i>L->length)
    return false;
  e=L->data[i-1];
  return true;
}
int LocateElem(SqList *L, ElemType e){
  int i=0;
  while (i<L->length && L->data[i]!=e)
    i++;
  if(i>=L->length)
    return 0;
  return i+1;
}
bool InsertElem(SqList *&L, int i, ElemType e){
  int j;
  if(i<1 || i>L->length+1)
    return false;
  i--;
  for(j=L->length; j>i; j--){
    L->data[j] = L->data[j-1];
  }
  L->data[i] = e;
  L->length++;
  return true;
}
bool DeleteElem(SqList *&L, int i, ElemType &e){
  int j;
  if(i<1 || i>L->length)
    return false;
  i--;
  e=L->data[i];
  for(j=i; j<L->length-1;j++){
    L->data[j]=L->data[j+1];
  }
  L->length--;
  return true;
}
int AdjustArray(SqList *&L){
  ElemType Pivot = L->data[0];
  int i=0;
  int j=L->length-1;
  while(i<j){
    while(j>i && L->data[j]>Pivot)
      j--;
    L->data[i]=L->data[j];
    DispList(L);
    while(i<j && L->data[i]>Pivot)
      i++;
    L->data[j]=L->data[i];
    DispList(L);
  }
  L->data[i] = Pivot;
  DispList(L);
  return i;
}
void QuickSort(SqList *&L, int start, int end){
  if(start<end){
    int i = AdjustArray(L);
    QuickSort(L, start, i);
    QuickSort(L, i+1, end);
  }
}
// void Swap(ElemType *&x, ElemType *&y){
//   ElemType *tmp;
//   tmp=&x; &x=&y; &y=tmp;
// }

int main(int argc, char const *argv[]) {
  ElemType x=2, y=6;
  // Swap(x,y);
  printf("%d,%d\n",*&x,*&y);
  ElemType a[6]={3,2,3,4,5,3};
  // ElemType insert_num=9;
  // ElemType delete_num=0;
  SqList *L;
  CreateList(L, a, 6);

  DispList(L);
  // // bool isInsert=InsertElem(L, 3, insert_num);
  // // DispList(L);
  // // bool isDelet=DeleteElem(L, 5, delete_num);
  // // DispList(L);
  // // printf("%d\n", delete_num);
  // // QuickSort(L,0,L->length-1);
  // int i = AdjustArray(L);
  // DispList(L);
  // printf("%d\n", i);
  return 0;
}

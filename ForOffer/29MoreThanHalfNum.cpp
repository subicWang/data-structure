#include<iostream>
using namespace std;

bool g_bInputInvalid = false;
bool checkInvalidArray(int* numbers, int length){
  g_bInputInvalid = false;
  if(numbers==NULL||length==0){
    g_bInputInvalid = true;
  }
  return g_bInputInvalid;
}

int moreThanHalfNum(int* numbers, int length){
  if(checkInvalidArray(numbers, length)){
    return 0;
  }
  int middle = length - 1;

}

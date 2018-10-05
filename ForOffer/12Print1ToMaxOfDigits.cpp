#include<iostream>
#include<string.h>
using namespace std;
//坑： 需要考虑n为大数的情况
void memset(char *number, char x, int n){
  for(int i=0;i<n;i++){
    number[i] = x;
  }
}
void PrintNumber(char* number){
  bool isBeginning=true;
  int nLength = strlen(number);
  for(int i=0; i<nLength; ++i){
    if(isBeginning && number[i] !='0'){
      isBeginning=false;
    }
    if(!isBeginning){
      printf("%c", number[i]);
    }
    printf("\n");
  }

}
bool Increment(char* number){
  bool isOverflow=false;
  int nTakeOver=0;
  int nLength=strlen(number);
  for(int i=nLength-1; i>=0; i--){
    int nSum = number[i]-'0'+nTakeOver;
    if(i==nLength-1){
      nSum++;
    }
    if(nSum>=10){
      if(i==0){
        isOverflow=true;
      }
      else{
        nSum-=10;
        nTakeOver=1;
        number[i]='0'+nSum;
      }
    }
    else{
      number[i]='0'+nSum;
      break;
    }
  }
  cout<<number<<endl;
  return isOverflow;
}
void print1ToMaxOfDigitsRecursively(char* number,int length,int index){
  if(index==length-1){
    PrintNumber(number);
    return;
  for(int i=0;i<10;++i){
    number[index+1]=i+'0';
    print1ToMaxOfDigitsRecursively(number, length, index+1);
    }
  }
}
void print1ToMaxOfDigit(int n){
  if(n<0){
    return;
  }
  char *number= new char [n+1];
  // memset(number, '0', n);
  number[n] = '\0';
  // while(!Increment(number)){
  //   PrintNumber(number);
  // }
  for(int i=0;i<10;i++){
    number[0]=i+'0';
    print1ToMaxOfDigitsRecursively(number, n, 0);
  }
  delete []number;
}

int main(int argc, char const *argv[]) {
  print1ToMaxOfDigit(3);
  return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int n=0;
int SUM=0;
int MUL=1;
int x[1001]={0};
int c=0;
void ojbk(int index){
  for(int i=index;i<n;i++){
    SUM+=x[i];
    MUL*=x[i];
    if(SUM>MUL){
      ojbk(i+1);
      c++;
      cout<<"count:"<<c<<endl;
    }else if(x[i]==1){
      ojbk(i+1);
    }else{
      SUM-=x[i];
      MUL/=x[i];
      break;
    }
    SUM-=x[i];
    MUL/=x[i];
    for(;i<n&&x[i]==x[i+1];i++);
  }
}
int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i=0;i<n;i++){
    int xi;
    cin>>xi;
    x[i]=xi;
  }
  sort(x,x+n);
  ojbk(0);
  cout<<c;
  return 0;
}

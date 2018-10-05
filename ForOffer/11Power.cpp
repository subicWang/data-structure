#include<iostream>
using namespace std;
bool equal(double num1, double num2){
  if((num1-num2 > -0.0000001) && (num1-num2)<0.0000001){
    return true;
  }
  else{
    return false;
  }
}
double PowerWithUnsignedExponent(double base, unsigned int exponent){
  double result=1.0;
  for(unsigned int i=1;i<=exponent;i++){
    result *= base;
  }
  return result;
}
double PowerWithUnsignedExponentAdvanced(double base, unsigned int exponent){
  if(exponent==0){
    return 1.0;
  }
  if(exponent==1){
    return base;
  }
  double result=PowerWithUnsignedExponentAdvanced(base, exponent>>1);
  result *=result;
  if((exponent & 0x1)==1){
    result*=base;
  }
  return result;
}
double Power(double base, int exponent){
  if(equal(base, 0.0) && exponent<0){
    return 0.0;
  }
  unsigned int absExponet = (unsigned int) exponent;
  if(exponent<0){
    absExponet = (unsigned int) (-exponent);
  }
  double result = PowerWithUnsignedExponent(base, absExponet);
  if(exponent<0){
    result = 1.0/result;
  }
  return result;
}
int main(int argc, char const *argv[]) {
  cout<<"请输入底:";
  double base;
  cin>>base;
  cout<<"请输入指数：";
  int exponent;
  cin>>exponent;
  double result;
  result = Power(base, exponent);
  cout<<base<<"的"<<exponent<<"次方是："<<result<<endl;
  return 0;
}

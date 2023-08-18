#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

double calPow(double base,int64_t exp){
      if(exp==0){
            return 1;
      }else if(exp==2){
            return base*base;
      }else{
            auto _base = calPow(base,exp/2);
            if(exp%2==0)
                  return _base* _base;
            else
                  return _base*_base*base;
      }
}

class Solution {
public:
    double myPow(double base, int exp) {
      int64_t n = exp;
      bool neg = false; 
      if(n<0){
            n = (0-n);
            neg = true;
      }
      auto ans = calPow(base,n);
      return (neg)?(1.0/ans):ans;
    } 
};

int main(int argc, char const *argv[])
{
      Solution s;
      for(int i=0;i<10;i++){
            std::cout<<s.myPow(2,-i)<<std::endl;
            std::cout<<calPow(2,i)<<std::endl;}
      //       std::cout<<(3<<i)<<std::endl;
return 0;
}
/*
Source: https://en.wikipedia.org/wiki/Trailing_zero
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

#define lli long long int

int main(int argc, char const *argv[])
{
      lli  n=0;
      std::cin>>n;

      lli  k=(lli)(log(n)/log(5));
      lli ans=0;
      for(int i=1;i<=k;i++){
            lli temp = n/pow(5,i);
            ans+=(lli)(temp);
      }
      std::cout<<ans<<std::endl;
return 0;
}
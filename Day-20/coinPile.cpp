#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

#define lli long long int


int main(int argc, char const *argv[])
{
      int t=0;
      std::cin>>t;

      while(t--){
            lli a,b;
            std::cin>>a>>b;
            double x = ((double)(2*a-b))/3;
            double y = ((double)(2*b-a))/3;
            if(y<0 or x<0){
                  std::cout<<"NO"<<std::endl;
                  continue;
            }else{
                  double intPart, fracPart;
                  fracPart = modf(y,&intPart);
                  if(fracPart==0)
                        std::cout<<"YES"<<std::endl;
                  else
                        std::cout<<"NO"<<std::endl;
            }
      }
      // std::cout<<t%2<<std::endl;

return 0;
}
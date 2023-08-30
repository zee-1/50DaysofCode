#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;


int main(int argc, char const *argv[])
{
      int n=0;
      std::cin>>n;
      unsigned long long ans;
      long long s2;
      for(size_t k=1; k<=n;k++){
            ans = (k*k)*((k*k)-1)/2;
            s2 = 4*(size_t(k)-1)*(size_t(k)-2);
            std::cout<<ans-s2<<std::endl;
      }
      
return 0;
}
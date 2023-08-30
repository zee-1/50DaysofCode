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
      int k=0;
      std::cin>>k;
      for(int i=1; i<=k;i++){
            int64_t ans = k*k*((k-1)*(k-1)-1)/2 - 4*(k-1)*(k-2);
            std::cout<<ans<<std::endl;
      }
      
return 0;
}
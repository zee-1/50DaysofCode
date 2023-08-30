#include <vector>
#include <iostream>
#include <algorithm>

#define lli long long int
#define modulo (1000000000+7)

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;


int main(int argc, char const *argv[])
{
lli ans=1;

int n;
std::cin >>n;
int m = n%30;
int o = n/30;
lli temp = ((1<<30)%(modulo));
for(int i=0; i<o;i++){
      ans= (ans*temp)%(modulo);
}
ans = ans%(modulo);
lli residual = (lli)(1<<m)%(modulo);
std::cout<<(ans*residual)%(modulo)<<std::endl;
return 0;
}
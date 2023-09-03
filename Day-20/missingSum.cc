#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

#define lli long long int

int main(int argc, char const *argv[])
{
      unsigned int n;
      std::cin>>n;
      vector<int> elements;
      lli max_sum=0;
      for(int i=0;i<n;i++){
            lli temp=0; std::cin>>temp;
            max_sum+=temp;
            elements.push_back(temp);
      }
      std::cout<<max_sum<<std::endl;
      vector<lli> dp(max_sum+2,0);

      dp[0]=1;
      for(int i=0;i<elements.size();i++){
            dp[elements[i]]=-1;
      }
      dp[elements[0]]=-1;
      for(size_t i=0; i<elements.size();i++){
            int val=elements[i];
            int j=0;
            for(; j<max_sum;j++){
                  if(dp[j]!=0 and dp[j]!=i){
                        dp[j+elements[i]]=i;
                  }
            }
            dp[elements[i]]=i;
      }
      for(int i=0; i<max_sum+2;i++){
            if(!dp[i]){
                  std::cout<<i<<std::endl;
                  break;
            }
      };
return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#define MAX_SUM (int)(1e+3)

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;
using std::array;
bool sumSubset(vector<int> &v, int k){
    vector<int> dp(MAX_SUM,-1);

    for(int i=0; i<v.size(); i++){
         for(int j=0; j<MAX_SUM+1; j++){
            if(dp[j]!=-1 and dp[j]!=i){
                if(dp[j+v[i]]==-1)
                    dp[j+v[i]]=i;
            }
        }
        if(dp[v[i]]==-1)
            dp[v[i]]=i;
    }

    return dp[k]!=-1;
}
/*
4 5
4 3 2 1
*/
int main(int argc, char const *argv[])
{
    vector<int> vec = {4,3,2,1};
    std::cout<<sumSubset(vec,12)<<std::endl;
return 0;
}
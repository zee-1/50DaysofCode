#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
            auto count = prices.size();
            vector<int> maxArr(count,0);

            for(int i=count-2; i>=0; i--){
            maxArr[i] = max(maxArr[i+1],prices[i+1]);

            
        }
        int maxProfit =0;
        for(size_t i=0; i<count;i++){
            maxProfit = max(maxProfit,(maxArr[i] - prices[i]));
        }
            return maxProfit;
    }
};

int main(int argc, char const *argv[])
{
      vector<int> v = {7,1,5,3,6,4};

      Solution s;
      std::cout<<s.maxProfit(v);
return 0;
}
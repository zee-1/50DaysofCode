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
    void sortColors(vector<int>& nums) {
        vector<int> buckets(3);
        for(auto i:nums){
            buckets[i]++;
        };
        size_t start=0;
        auto end =buckets[0];
        for( auto i =start;i<buckets[0];i++){
            nums[i]=0;
        }
        start = end,end=end+buckets[1];
        for(auto i = start;i<end;i++){
            nums[i]=1;
        }
        start = end,end=end+buckets[2];
        for( auto i=start;i<end;i++){
            nums[i]=2;
        }
    }
};

int main(int argc, char const *argv[])
{
      vector<int> v= {2,0,1};
      Solution s;
      s.sortColors(v);
      for(auto i:v){
            std::cout<<i<<" ";
      };
return 0;
}
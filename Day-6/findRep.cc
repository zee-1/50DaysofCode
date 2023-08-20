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
    int findDuplicate(vector<int>& nums) {
        vector<int> hash(1e+5+1,0);
        int ans=0;
        int count = nums.size();
        for(int i=0; i<count;i++){
            hash[nums[i]]++;
        }
        for(int i=0; i<int(1e+5+1);i++){
            if(hash[i]>1)
                ans=i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
      Solution s;
      vector<int> vec ={1,3,4,2,2};
      s.findDuplicate(vec);
return 0;
}
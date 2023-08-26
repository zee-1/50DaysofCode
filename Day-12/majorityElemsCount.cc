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
    int majorityElement(vector<int>& nums) {
      int count = 0,
           elem = 0;
      
      
      auto size = nums.size();
      for(int i=0; i<size; i++){
            if(count==0){
                  elem=nums[i];
            }
            if(nums[i]==elem) count+=1;
            else count-=1;
      }
      return elem;
    }
};

int main(int argc, char const *argv[])
{
return 0;
}
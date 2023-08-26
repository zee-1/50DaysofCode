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
    vector<int> majorityElement(vector<int>& nums) {
      int elem1=0,
          elem2=0,
          count1=0,
          count2=0;
      
      if(nums.size()==1){
            return nums;
      }

      for(auto num: nums){
            if(count1==0 || elem1==0){
                  count1+=1;
                  elem1=num;
            }else if(count2==0||elem2==0){
                  count2+=1;
                  elem2=num;
            }else{
                  count1--;
                  count2--;
            }
      }

      vector<int> ans = {elem1,elem2};
      return ans;
    }
};

int main(int argc, char const *argv[])
{
      Solution s;
      vector<int> vec={1}; 
      auto ans=s.majorityElement(vec);
      for(auto i:ans){
            std::cout<<i<<std::endl;
      };
return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>

#define lli long long int

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> ans;
      if(nums.size()<4) return ans;
      sort(nums.begin(),nums.end());
      int count =nums.size();
      for(int i=0; i<count;i++){
            if(i!=0 and nums[i]==nums[i-1]){
                  while(i<count and nums[i]==nums[i-1])i++;
            }
            for(int j=i+1; j<count;j++){
                  if(j!=i+1 and nums[j]==nums[j-1]){
                        while(j<count  and nums[j]==nums[j-1])j++;
                  }
                  int k=j+1,
                      l=count-1;
                  while(k<l){
                        lli sum = nums[i];
                        sum += nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if(sum == target){
                              vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                              ans.push_back(temp);
                              k++;
                              l--;
                              while(k<l and nums[k]==nums[k-1]) k++;
                              while(k<l and nums[l]==nums[l+1]) l--;
                        }else if(sum<target)k++;
                        else l--;
                  }
            }
      }
      return ans;
    }
};

int foo(int &a);


int main(int argc, char const *argv[])
{
      Solution s;
      vector<int> v={0,0,0,0};
      auto out = s.fourSum(v,0);
      std::cout<<out.size()<<std::endl;
      for(auto i:out){
            for(auto j:i){
                  std::cout<<j<<" ";
            };
            std::cout<<std::endl;
      };
return 0;
}
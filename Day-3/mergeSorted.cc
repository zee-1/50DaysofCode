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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        auto lastOfNums1 = m-1;
        int i = lastOfNums1,j = n-1,k=m+n-1;

        while(i>=0 and j>=0 and k>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }else{
                nums1[k--]=nums2[j--];
            }
        }while(i>=0){
            nums1[k--]=nums1[i--];
        }while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};

int main(int argc, char const *argv[])
{
      vector<int>nums1 = {0};
      vector<int>nums2 = {2};
      Solution s;
      s.merge(nums1,0,nums2,1);
      for(auto i:nums1){
        std::cout<<i<<" ";
      };
return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;
using std::lower_bound;
using std::upper_bound;
using std::type_info;
// using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    auto temp = lower_bound(matrix.begin(),matrix.end(),target, [](auto & vec, int value) { return vec[0] <= value; });
    std::cout<<(*temp)[0]<<std::endl;
    return 0;
    }
};

int main(int argc, char const *argv[])
{
      vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60},{71,72,74,76}};
      Solution s;
      std::cout<<s.searchMatrix(mat,11)<<std::endl;;      
return 0;
}
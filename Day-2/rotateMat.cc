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
    void rotate(vector<vector<int>>& matrix) {
      auto m = matrix.size();
      auto n = matrix.size();
      for(auto i =0; i<m; i++){
            for(auto j=i;j<n;j++){
                  swap(matrix[i][j],matrix[j][i]);
            }
      }
      for(auto i =0; i<m; i++){
            for(auto j=0;j<n/2;j++){
                  swap(matrix[i][j],matrix[i][m-1-j]);
            }
      }        

      // for(auto i:matrix){
      //       for(auto j:i){
      //             std::cout<<j<<" ";
      //       };
      //       std::cout<<std::endl;
      // };
    }
};

int main(int argc, char const *argv[])
{
      vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
      Solution s;
      s.rotate(mat);
return 0;
}
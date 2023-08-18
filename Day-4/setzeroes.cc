#include <vector>
#include <iostream>

using std::vector;

void fillrow(vector<vector<int>> &mat,int row,int fill=0){
      int n = mat[0].size();
      for(size_t col=0; col<n;col++){
            if(mat[row][col])
                  mat[row][col]=fill;
      }
}

void fillcol(vector<vector<int>> &mat,int col,int fill=0){
      int m = mat.size();
      for(size_t row=0; row<m;row++){
            if(mat[row][col])
                  mat[row][col]=fill;
      }
}
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fill = random();
        int m = matrix.size();
        int n = matrix[0].size();
        for(size_t i=0;i<m; i++){
            for(size_t j =0; j<n; j++){
                if(!matrix[i][j]){
                  fillrow(matrix,i,fill);
                  fillcol(matrix,j,fill);
                }
            }
        } 
        for(size_t i=0; i<m; i++){
            for(size_t j=0; j<n; j++){
                  if(matrix[i][j]==fill)
                        matrix[i][j]=0;
            }
        }    
    }

};

int main(int argc, char const *argv[])
{
      Solution s;
      vector<vector<int>> vec = {{0,2,2,0},{1,1,2,3},{3,1,2,3}};
      s.setZeroes(vec);

      for(auto i:vec){
            for(auto j:i){
                  std::cout<<j<<" ";
            };
            std::cout<<std::endl;
      };
      return 0;
}

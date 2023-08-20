#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* repeatedNumber(const int* A, int n1, int *len1) {
      len1 = new int[2];
      vector<int> hash(n1+1,0);
      int64_t sum =0;
      int64_t repNum = -1;
      for (size_t i = 0; i < n1; i++)
      {
            hash[A[i]]++;
            sum+=int64_t(A[i]);
            if(hash[A[i]]>1){
                  repNum=A[i];
                  break;
            }
      }
      int64_t trueSum = (n1*(n1+1))/2;
      len1[0] = repNum;
      len1[1] = trueSum-sum+repNum;
      return len1;
}

int main(int argc, char const *argv[])
{
      int *len1=0,n1=5;
      int arr[]={1,3,4,5,3};
      auto ans = repeatedNumber(arr,n1,len1);
      std::cout<<ans[0]<<std::endl;
      std::cout<<ans[1]<<std::endl;
return 0;
}
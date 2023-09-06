#include <iostream>
#include <vector>

using namespace std;

long long paintTheCeiling(int s0, int n, int k, int b,int m, long long a){
      long long result = 0;
      vector<long long> s(n,0);

      s[0] = 0;

      for (int i=1; i<n; i++){
            s[i] = ((k*s[i-1]+b)%m)+1 +s[i-1];
      }

      int start =0 , end= n-1;

      while(start<=end){
            if(s[start]*s[end]>a){
                  end--;
            }else{
                  result += 2*(end- start)+1;
                  start++;
            }
      }
      return result;

}
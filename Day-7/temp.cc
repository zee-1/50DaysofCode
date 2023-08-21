#include <iostream>
#include<set>
#include <map>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
      map<int,int> m;
      int sum=5;
      vector<int> vec= {1,3,2,5,4,0};
      for(int i=0; i<5;i++)
            if(m[sum-vec[i]]>0){
                  int temp = m[sum-vec[i]];
                  if(i>(temp-1))
                        std::cout<<i<<','<<temp-1<<std::endl;
            }else
                  m[vec[i]]=(i+1);
      return 0;
}

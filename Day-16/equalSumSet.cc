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
/*
Your task is to divide the numbers 1,2,…,n
into two sets of equal sum.

Input
The only input line contains an integer n.

Output
Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to create the sets. 
First, print the number of elements in the first set followed by the elements themselves 
in a separate line, and then, print the second set in a similar way.
*/


int main(int argc, char const *argv[])
{
int n=0;
std::cin>>n;
vector<bool> visited(n);

lli max_sum = (n*(n+1))/2;

if(max_sum%2!=0 or max_sum==0){
      std::cout<<"NO"<<std::endl;
      return 0;
}
std::cout<<"YES"<<std::endl;


max_sum=max_sum/2;

int **arr = new int*[n+1];
for(int i=0; i<n+1;i++){
      arr[i] = new int[max_sum+1];
      for(int j=0; j<max_sum+1; j++){
            arr[i][j] = 0;
      }
}
arr[0][0]=1;

for(int i=0;i<n+1;i++){
      int j;
      for(j=1;j+i<max_sum+1;j++){
            if(i>j)arr[i][j]=arr[i-1][j];
            arr[i][j+i]=i;
      }
      arr[i][i]=i;
}
vector<int> v1,v2;
int i=n,j=n;

while(max_sum!=0 and i!=0 and j!=0){
      int node = arr[i][j];
      if(!visited[node]){
            visited[node]=1;
            max_sum-=node;
            j=max_sum;
            v1.push_back(node);
      }else{
            i--;
      }
}
for(int i=0;i<n;i++){
      if(visited[i+1]) continue;
      v2.push_back(i+1);
}

std::cout<<v1.size()<<std::endl;
for(auto i:v1){
      std::cout<<i<<" ";
};
std::cout<<""<<std::endl;
std::cout<<v2.size()<<std::endl;
for(auto i:v2){
      std::cout<<i<<" ";
};

return 0;
}
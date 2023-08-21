#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
      int temp = a;
      a        = b;
      b        = temp;
}

int main(int argc, char const *argv[])
{
      int n=0, m=0;
      cin>>n>>m;

      int arr1[n];
      int arr2[n];
      for(int i=0; i<n;i++){
            cin>>arr1[i];
            arr2[arr1[i]-1]=i;
      }
      int ans=0;
      for(int i=0 ; i<n-1; i++){
            if(arr2[i]>arr2[i+1]) ans++;
      }

      while (m--)
      {
            
      
      }
      
      return 0;
}

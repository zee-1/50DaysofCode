#include <iostream>
#include <algorithm>
#include <vector>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::vector;
// using std::sort;

using namespace std;


// int max_child(vi w, int num, int mw){
//       int ans=0, buck;
//       sort(w.begin(),w.end());
//       for(int i=num-1; i>=0; i--){
//             buck=0;
//             int res_w = mw-w[i];
            
//                   if(w[i]>0){
//                         buck++;
//                         ans++;
//                         if(res_w>0)
//                               for(int j=i-1; j>=0; j--)
//                                     if(w[j]>0 and (res_w-w[j])>=0){
//                                           if(buck==2)
//                                                 break;
//                                           else{
//                                                 w[j]=-1;
//                                                 buck++;
//                                           }
//                                     }
//                   }

//       }
// return ans;
// }
/*
8 10
11 12 10 1 9 7 3 13
*/
int maxchild_pro(vector<int> w, int num, int mw){
      sort(w.begin(),w.end());
      int count=0;
      for(int i= num-1;i>=0 ; i--){
            int buck=0;
            if(w[i]>=0){
                  int res_w = mw-w[i];
                  if(res_w>=0){
                        count++;
                        buck++;
                        auto it = std::upper_bound(w.begin(),w.end()-(w.size()-i),res_w);
                        int ind = (it- w.begin())-1;
                        if((res_w-w[ind])>=0 and w[ind]>=0 and ind>=0){
                              if(buck==2){
                                    break;
                              }else{
                              w[ind]=-1;
                              buck++;
                              }
                        }
                  }
            }
      }

return count;
}



int main(int argc, char const *argv[])
{
      int n,m;
      cin>>n>>m;
      vector<int> w(n);
      for(int i=0; i<n;i++) cin>>w[i];
      cout<<maxchild_pro(w,n,m)<<endl;
      w.clear();
      return 0;
}

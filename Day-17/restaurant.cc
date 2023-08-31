#include <iostream>
#include <algorithm>
#include <set>
#include <map>

#define vi vector<int>
#define In(a) for(auto &i:a) cin>>i;
#define Out(a) for(auto i:a) cout<<i<<"-";
using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin. tie(nullptr);
      cout.tie(nullptr);
      int n;
      cin>>n;
      pair<int,int> p;
      map<int,int> a;
      while(n--){
            cin>>p.first>>p.second;
            a[p.first]+=p.second;
      }
      for(auto i:a){
            cout<<i.first<<" "<<i.second<<endl;
      }

      return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int modify(vector<int> v){
      int ans=0;
      int pos=0,Pos=0;
      bool f1 = true;
      for(int i=0; i<(v.size()); i++){
            if((v[i+1]-v[i])<=0 and f1){
                  pos = i;
                  f1 = false;
            }
            if((v[i]-v[i-1])<=0 and (v[i+1]-v[i])>0){
                  Pos = i+1;
            }
      }
      if(Pos == 0){
            Pos = v.size();
      }
      cout<<"Pos"<<Pos<<endl;
      cout<<"pos"<<pos<<endl;
            
      ans= Pos-pos;
      return ans;
}
int main(int argc, char const *argv[])
{
      vector<int> v={1,2,2,2,6};
      cout<<modify(v);
      return 0;
}

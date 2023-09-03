#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::string;
using std::reverse;
using std::unordered_map;

int main(int argc, char const *argv[])
{
      string str;
      std::cin>>str;
      unordered_map<char,unsigned int> hashMap;
      bool odd_occurrance=false;
      char char_with_odd_occurance = 0;


      for(auto i:str){
            if(hashMap.find(i)!=hashMap.end()){
                  hashMap[i]++;
            }else{
                  hashMap[i]=1;
            }
      };
      for(auto i:hashMap){
            if(i.second%2==1) {
                  if(!odd_occurrance ){
                        odd_occurrance=true;
                        char_with_odd_occurance = i.first;
                  }
                  else{
                        std::cout<<"NO SOLUTION"<<std::endl;
                        return 0;
                  }
            }
      };
      string ans;
      for(auto i:hashMap){
            if(i.first == char_with_odd_occurance){
                  continue;
            }
            for(int j=0;j<i.second/2;j++)
                  ans+=i.first;
      };

      string part2 = ans;
      for(int i=0;i<hashMap[char_with_odd_occurance];i++){
            ans+=char_with_odd_occurance;
      }
      reverse(part2.begin(),part2.end());
      std::cout<<ans+part2<<std::endl;
return 0;

}
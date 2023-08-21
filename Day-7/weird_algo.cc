#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
      long long int num=0;
      cin>>num;
      while(num !=1){
            std::cout<<num<<" ";
            if(num%2==0){
                  num=num/2;
            }else{
                  num=(num*3+1);
            }
      }
      std::cout<<num<<std::endl;
      return 0;
}

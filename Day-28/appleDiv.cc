#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

int divApplr(vector<int> num){
    auto size = num.size();
    sort(num.begin(),num.end());

    int64_t sum1 = 0,
    sum2=num[size-1];
    for(int i=0; i<size-1; i++){
        sum1 +=num[i];
    }
    int64_t avg = (sum1+sum2)/size;
    int ptr1=0,ptr2=size-2;
    int64_t presentMin = __INT64_MAX__;
    while(sum1>sum2){
        // auto temp = (sum1-sum2);
        // if(temp<avg){
        // sum1-=num[ptr2];
        // sum2+=num[ptr2];
        // ptr2--;
        // }else{
            sum1-=num[ptr1];
            sum2+=num[ptr1];
            ptr1++;
        // }
        presentMin = min(presentMin,int64_t(abs(sum1-sum2)));
    }
    return presentMin;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int temp=0; std::cin>>temp;
        v.push_back(temp);
    }
    auto ans = divApplr(v);
    std::cout<<ans<<std::endl;
return 0;
}
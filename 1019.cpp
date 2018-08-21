/**********************
author: yomi
date: 18.4.8
ps: 又把ABC给忘了 ---> 仔细看看题 发现不是那回事呀 直接用数字表示就可以
Consider a number N > 0 in base b >= 2,
where it is written in standard notation with k+1 digits ai
as the sum of (aibi) for i from 0 to k. Here, as usual,
0 <= ai < b for all i and ak is non-zero.
Then N is palindromic if and only if ai = ak-i for all i.
**********************/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, b;
    string ans = "", tmp = "";
    vector<int>num;
    cin >> n >> b;
    do{
        ans += (n%b)+'0';
        num.push_back(n%b);
        n /= b;
    }while(n);
    tmp = ans;
    reverse(ans.begin(), ans.end());
    if(ans == tmp){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    reverse(num.begin(), num.end());
    for(int i=0; i<num.size()-1; i++){
        cout << num[i] << ' ';
    }
    cout << num[num.size()-1];
    return 0;
}

/**
27 2
*/

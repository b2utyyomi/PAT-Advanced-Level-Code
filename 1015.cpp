/**********************
author: yomi
date: 18.7.1
ps: 惊天大bug 一定要找到你 你等着 现在我要去学高数了
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
bool IsPrime(int n)
{
    if(n<=1)
        return false;
    int sqr = (int)sqrt(n*1.0);
    for(int i=2; i<=sqr; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int convertTo10(int n, int r)
{
    int ans = 0, product = 1;
    while(n){
        ans = ans + (n%10)*product;
        n/=10;
        product = product * r;
    }
    return ans;
}
char a[256];
int main()
{
    int n, r;
    while(cin >> n){
        if(n < 0)
            break;
        cin >> r;
        if(!IsPrime(n)){
            cout << "No" << endl;
        }
        else{
            int m=0, temp=0;
            memset(a, 0, sizeof(a));
            int cnt = 0;
            do{
                a[cnt++] = (n%r)+'0';
                n/=r;
            }while(n);
            a[cnt] = 's';
            sscanf(a, "%d", &temp); ///测试点3WA 为啥呢 喂喂喂 为啥呢
            m = convertTo10(temp, r);
//            for(int i=0; i<cnt; i++){
//                m = m*r+(a[i]-'0');
//            }
            if(IsPrime(m)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }


    }
    return 0;
}
/**
73 10
23 2
23 10
-2
**/

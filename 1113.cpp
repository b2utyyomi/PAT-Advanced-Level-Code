/******************************
author:yomi
date:18.8.29
ps: 十分钟啊 我以为得用随机选择算法 但是我给忘了 用sort水一下吧 竟然过了 喜出望外
******************************/
#include<iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn= 100010;
int a[maxn];
int sum1, sum2, sum;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n/2; i++){
        sum1 += a[i];
        //cout << a[i] << ' ';
    }
    for(int i=n/2; i<n; i++){
        sum2+= a[i];
    }
    sum = sum2-sum1;
    if(n%2 == 1){
        cout << "1 " << sum;
    }
    else{
        cout << 0 << ' ' <<  sum;
    }
    return 0;
}
/**
Sample Input 1:

10
23 8 10 99 46 2333 46 1 666 555

Sample Output 1:

0 3611

Sample Input 2:

13
110 79 218 69 3721 100 29 135 2 6 13 5188 85

Sample Output 2:

1 9359

**/

/**********************
author: yomi
date: 18.8.23
ps: 这种模拟题 脑子要爆炸了 花了半小时A掉了 乙级里有 所以几个月前做过一次
最外面一层超级好写了 往里面写的时候变量替换搞得头要炸了 好在也写出来了
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100010], b[110][110];
int main()
{
    int N, n, m, cnt;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+N);
    m = ceil(sqrt(N));
    while(N%m){
        m++;
    }
    n = N/m;
    int t = 0, t1=0;
    cnt = N-1;
    while(cnt>=0){
        for(int i=t; i<n-t1; i++){///n
            b[t][i] = a[cnt--];
        }
        if(cnt<0)
            break;
        for(int i=t+1; i<m-t1; i++){///m-1
            b[i][n-1-t] = a[cnt--];
        }
        if(cnt<0)
            break;
        for(int i=n-2-t1; i>=t; i--){///n-1
            b[m-1-t][i] = a[cnt--];
        }
        if(cnt<0)
            break;
        for(int i=m-2-t1; i>=1+t; i--){///m-2
            b[i][t] = a[cnt--];
        }
        t++;
        t1++;
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n-1; j++){
            cout << b[i][j] << ' ';
        }
        cout << b[i][n-1] << endl;
    }
    return 0;
}
/**
Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76
**/



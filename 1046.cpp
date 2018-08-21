/**********************
author: yomi
date: 18.3.23
ps: 好的算法能改变一切啊
**********************/
#include <iostream>
#include <cstdio>
using namespace std;
int a[100010], dis[100010];
int main()
{
    int n, sum = 0;
    //cin >> n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        //cin >> a[i];
        scanf("%d", &a[i]);
        sum += a[i];
        dis[i] += sum;
    }

    int t, c, d;
    //cin >> t;
    scanf("%d", &t);
    int cnt = 0;
    while(t--){
        if(cnt)
            //cout <<endl;
            printf("\n");
        //cin >> c >> d;
        scanf("%d%d", &c, &d);
        int tmp = 0;
        if(c > d){
            tmp = c;
            c = d;
            d = tmp;
        }
        int sum1 = dis[d-1]-dis[c-1];
//        for(int i=c; i<=d-1; i++){  ///TLE
//            sum1 += a[i];
//        }

        printf("%d", min(sum1, sum-sum1));
        cnt++;
    }
    return 0;
}
/* TLE ERROR
#include <iostream>
#include <cstdio>
using namespace std;

int a[200010];
int swap1(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
int main()
{
    int n;
    //cin >> n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        a[i+n] = a[i];
    }

//    for(int i=0; i<2*n; i++)
//        cout << a[i] << endl;
    int t, c, b;
    //cin >> t;
    scanf("%d", &t);
    int f = 0;
    while(t--){
        if(f)
            printf("\n");
        int sum1 = 0, sum2 = 0, cnt = 0, flag = 0;
        //cin >> c >> b;
        scanf("%d%d", &c, &b);
        ///之前一直在判断值 然而如果有重复的数字那不就完了吗 要用下标啊
        if(c > b)
            swap1(c, b);
        for(int i=c-1; i<b-1; i++){
            sum1 += a[i];
        }
        for(int i=b-1; i<c-1+n; i++){
            sum2 += a[i];
        }
        //cout << min(sum1, sum2);
        printf("%d", min(sum1, sum2));
        f++;
    }
    return 0;
}
*/

/**
5 1 2 4 14 9
3
1 3
2 5
4 1
*/

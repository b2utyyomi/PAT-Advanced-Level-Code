/**********************
author: yomi
date: 18.6.9
ps:二分解法 然后竟然超时了 我莫不是用了假的二分 这个逻辑出了小小的问题
改掉就A了
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int bs(int left, int right, int x, int s)
{
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(a[mid]+x == s){
            return a[mid];
        }
        else if(a[mid]+x < s){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}
int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int flag = 0;
    for(int i=0; i<n; i++){
       // for(int j=i+1; j<n; j++){ 不知道自己在这搞什么 双重循环不超时才怪嘞
            int ans = bs(i+1, n-1, a[i], s);
            if(ans!=-1){
                flag = 1;
                cout << a[i] << ' ' << ans;
                break;
            }
        //}
//        if(flag)
//            break;
    }
    if(flag == 0){
        cout << "No Solution";
    }

    return 0;
}
/**
8 15
1 2 8 7 2 4 11 15
4 11
**/

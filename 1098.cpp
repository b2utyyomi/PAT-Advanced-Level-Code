/**********************
author: yomi
date: 18.8.26
ps: 做了四十分钟 堆排序不熟啊
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[150], b[150], c[150], n;
void downAdjust(int low, int high)
{
    int i=low, j = 2*i;
    while(j <= high){
        if(j+1<=high && c[j+1] > c[j]){
            j++;
        }
        if(c[i] < c[j]){
            swap(c[i], c[j]);
            i = j;
            j = 2*i;
        }
        else{
            break;
        }
    }
}
void createHeap()
{
    for(int i=n/2; i>=1; i--){
        downAdjust(i, n);
    }
}
int main()
{
    int flag = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &b[i]);
    }
    for(int i=1; i<n; i++){
        int j=i+1;
        int temp = a[j];
        while(j>1 && temp<a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
        int t;
        for(t=1; t<=n; t++){
            if(a[t]!=b[t]){
                break;
            }
        }
        if(flag == 1){
            break;
        }
        if(t == n+1){///啊啊啊啊 这个BUG找的啊 这是以1为下标啊
            flag = 1;///我用0用习惯了
        }
    }
    if(flag == 1){
        cout << "Insertion Sort" << endl;
        for(int i=1; i<n; i++){
            printf("%d ", a[i]);
        }
        printf("%d", a[n]);
    }
    else{
        cout << "Heap Sort" << endl;
        createHeap();
        for(int i=n; i>1; i--){
            swap(c[i], c[1]);
            downAdjust(1, i-1);
            int t;
            for(t=1; t<=n; t++){
                if(c[t]!=b[t]){
                    break;
                }
            }
            if(flag == 1){
                break;
            }
            if(t == n+1){///啊啊啊啊 这个BUG找的啊 这是以1为下标啊
                flag = 1;///我用0用习惯了
            }
        }
        for(int i=1; i<n; i++){
            printf("%d ", c[i]);
        }
        printf("%d", c[n]);


    }


    return 0;
}
/**
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
**/

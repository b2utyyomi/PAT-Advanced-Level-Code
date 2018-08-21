/**********************
author: yomi
date: 18.2.26
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n, a[10010], total = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    total += n*5;
    total += a[0]*6;
    for(int i=1; i<n; i++){
        if(a[i] > a[i-1]){
            total += (a[i]-a[i-1])*6;
        }
        else if(a[i] < a[i-1]){
            total += (a[i-1]-a[i])*4;
        }
    }
    cout << total;
    return 0;
}

/**
3 2 3 1
**/

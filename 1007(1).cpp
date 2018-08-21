/**********************
author: yomi
date: 18.3.2
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n, sum = -1;
    int a[10010];
    cin >> n;
    int temp = 0, tempindex = 0, leftindex = 0, rightindex = n-1;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        temp += a[i];
        if(temp < 0){
            temp = 0;
            tempindex = i+1;
        }
        else if(temp > sum){
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if(sum < 0)
        sum = 0;
    cout << sum << ' ' << a[leftindex] << ' ' << a[rightindex];
    return 0;
}



/**
10
-10 1 2 3 4 -5 -23 3 7 -21

**/

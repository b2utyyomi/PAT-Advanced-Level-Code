/**********************
author: yomi
date: 18.3.15
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n, sum = -1, leftindex = 0, temp = 0, tempindex = 0;
    int a[10010];
    cin >> n;
    int rightindex = n-1;
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
    if(sum == -1){
        cout << "0";
    }
    else{
        cout << sum;
    }
    cout << " " << a[leftindex] << " " << a[rightindex];
    return 0;
}

/**
10
-10 1 2 3 4 -5 -23 3 7 -21
**/

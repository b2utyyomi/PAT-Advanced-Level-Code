/**********************
author: yomi
date: 18.3.1
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n, a[10010];
    cin >> n;
    int temp = 0, sum = -1, leftindex=0, rightindex = n-1, tempindex = 0;
    int flag = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
//        if(a[i] > 0)   why wrong?
//            flag = 1;

    }
//    if(!flag)
//        sum = 0;
//    else{
      for(int i=0; i<n; i++){
            temp += a[i];
            if(temp<0){
                temp = 0;
                tempindex = i+1;
            }
            else if(temp>sum){
                sum = temp;
                leftindex = tempindex;
                rightindex = i;
            }
      }
//    }
    if(sum < 0) sum = 0;
    cout << sum << ' ' << a[leftindex] << ' ' << a[rightindex];
    return 0;
}

/**
10
-10 1 2 3 4 -5 -23 3 7 -21

**/

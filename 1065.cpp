/**********************
author: yomi
date: 18.3.23
ps:
**********************/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int n;
    long long a, b, c, sum = 0;
    cin >> n;
    int cnt = 0;
    for(int i=0; i<n; i++){
        sum = 0;
        if(cnt)
            cout <<endl;
        cin >> a >> b >> c;
        cout << "Case #" << i+1 <<": ";
        sum = a+b;
        if(a > 0 && b>0 && sum<0){
            cout << "true";
        }
        else if(a < 0 && b < 0 && sum >= 0){
            cout <<"false";
        }
        else{
            if(sum>c){
                cout << "true";
            }
            else{
                cout << "false";
            }
        }
        cnt++;
    }
    return 0;
}
/**
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

Case #1: false
Case #2: true
Case #3: false
**/

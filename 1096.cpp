/**********************
author: yomi
date: 18.7.28
ps:
**********************/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    int sqr = sqrt(n);
    int ans = 0;
    int beg = 0;
    int cnt = 0;
    for(int i=2; i<=sqr+1; i++){
       int j = i;
       cnt = 0;
       long long int temp = 1;
       while(1){
            temp*=j;
            if(n%temp){
                break;
            }
            j++;
            cnt++;
       }
       if(cnt > ans){
            ans = cnt;
            beg = i;
       }
    }

    if(ans == 0){
        cout << 1 << endl << n;
    }
    else{
        cout << ans << endl;
        for(int i=0; i<ans; i++){
            cout << beg+i;
            if(i!=ans-1)
                cout << "*";
        }
    }

    return 0;
}
/**
630
Sample Output:
3
5*6*7
**/

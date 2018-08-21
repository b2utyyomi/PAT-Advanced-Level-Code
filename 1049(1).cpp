/**********************
author: yomi
date: 18.6.26
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 1, ans = 0;
    while(n/a){///30710
        int left = n/(a*10);
        int now = n/a%10;
        int right = n%a;
        if(now == 0){
            ans += left*a;
        }
        else if(now == 1){
            ans += left*a+right+1;
        }
        else{
            ans += (left+1)*a;
        }
        a*=10;
    }
    cout << ans << endl;
    return 0;
}

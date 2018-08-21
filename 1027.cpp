/**********************
author: yomi
date: 18.1.
ps:
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

char num[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
int main()
{
    string r = "", g = "", bl = "";
    int a, b, c;
    cin >> a >> b >> c;
    do{
        r += num[a%13];
        a /= 13;
    }while(a);
    do{
        g += num[b%13];
        b /= 13;
    }while(b);
    do{
        bl += num[c%13];
        c /= 13;
    }while(c);
    reverse(r.begin(), r.end());
    reverse(g.begin(), g.end());
    reverse(bl.begin(), bl.end());
    cout << "#";
    if(r.length() == 1){
        r = "0"+r;
    }
    if(g.length() == 1){
        g = "0"+g;
    }
    if(bl.length() == 1){
        bl= "0"+bl;
    }
    cout << r << g << bl;
    return 0;
}
/**
15 43 71

#123456
*/


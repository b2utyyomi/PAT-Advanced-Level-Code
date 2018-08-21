/**********************
author: yomi
date: 18.8.18
ps:
**********************/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1010;
int CBT[maxn], s[maxn], cnt = 1, n;
void in(int index)
{
    if(index >  n)
        return;
    in(2*index);
    CBT[index] = s[cnt++];
    in(2*index+1);

}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    sort(s+1, s+n+1);
    in(1);
    for(int i=1; i<n; i++){
        cout << CBT[i] << ' ';
    }
    cout << CBT[n];
    return 0;
}
/**
Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
**/

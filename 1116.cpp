/******************************
author:yomi
date:18.8.30
ps:
******************************/
#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[10010];
bool vis[10010];
bool isPrime(int n)
{
    if(n == 2)
        return true;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    int n, qcnt, d, query;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> d;
        a[d] = i+1;
    }
    cin >> qcnt;
    for(int i=0; i<qcnt; i++){
        cin >> query;
        //cout << query << ": ";
        printf("%04d: ", query);
        if(a[query] == 0){
            cout << "Are you kidding?";
        }
        else if(!vis[query]){
            if(a[query] == 1){
                cout << "Mystery Award";
            }
            else if(isPrime(a[query])){
                cout << "Minion";
            }
            else{
                cout << "Chocolate";
            }
            vis[query] = true;
        }
        else{
            cout << "Checked";
        }
        cout << endl;

    }
    return 0;
}
/**
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222

Sample Output:

8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
**/

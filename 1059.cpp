/**********************
author: yomi
date: 18.7.27
ps:
1需要特判 否则不会输出 这的确是自己没能想到的。
**********************/
#include <iostream>
using namespace std;
#include <cmath>
long long int prime[1000010];
bool vis[1000010] = {false};
long long int n;
long long int a;
struct primer
{
    long long int num;
    long long int cnt;
}p[10000];
void find_prime()
{
    long long int cnt = 0;
    //long long int a = 100000000000000;
    for(long long int i=2; i<=sqrt(a); i++){
        if(!vis[i]){
            prime[cnt++] = i;
            vis[i] = true;
            for(long long int j=i+i; j<=sqrt(a); j+=i){
                vis[j] = true;
            }
        }
    }
    //cout << cnt << endl;
    n = cnt;
}
int main()
{

    cin >> a;
    find_prime();

    int cn = 0;
    cout << a << "=";
    if(a == 1){
        cout << "1";
    }
    for(long long int i=0; i<n; i++){
        if(prime[i] > a){
            break;
        }
        if(a%prime[i] == 0){
            p[cn].cnt = 0;
            p[cn].num = prime[i];
            while(a%prime[i] == 0){
                p[cn].cnt++;
                a/=prime[i];
                //cout << a << ' ' << prime[i] << endl;
            }
            cn++;
        }
    }
    if(a!=1){
        p[cn].cnt = 1;
        p[cn++].num = a;

    }
    for(int i=0; i<cn; i++){
        cout << p[i].num;
        if(p[i].cnt>1){
            cout << "^" << p[i].cnt;
        }

        if(i!=cn-1){
            cout << "*";
        }
    }
    return 0;
}
/**
97532468=2^2*11*17*101*1291
121

**/

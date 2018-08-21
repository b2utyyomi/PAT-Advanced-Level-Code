/**********************
author: yomi
date: 18.6.29
ps:
**********************/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

struct Fraction
{
    long long int up, down;
}f[200], result;
long long int gcd(long long int a, long long int b)
{
    if(a%b == 0){
        return b;
    }
    return gcd(b, a%b);
}
Fraction reduction(Fraction a)
{
    if(a.down < 0){
        a.up = -a.up;
        a.down = -a.down;
    }
    else if(a.up == 0){
        a.down = 1;
    }
    else{
        long long int d = gcd(abs(a.up), abs(a.down));

        a.up /= d;
        a.down /= d;
    }
    return a;
}
Fraction add(Fraction a, Fraction b)
{
    Fraction result;
    result.down = a.down*b.down;
    result.up = a.up*b.down+b.up*a.down;
    return reduction(result);
}
void print(Fraction result)
{
    result = reduction(result);
    if(result.down == 1){
        printf("%lld", result.up);
    }
    else if(abs(result.up)> result.down){
       printf("%lld ", result.up/result.down);
       result.up = abs(result.up);
       printf("%lld/%lld",result.up%result.down, result.down);
    }
    else{
        printf("%lld/%lld", result.up, result.down);
    }

}
int main()
{
    int n;
    char ch;
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%lld%c%lld", &f[i].up, &ch, &f[i].down);
    }
    result.up = f[0].up;
    result.down = f[0].down;
    for(int i=1; i<n; i++){
        result = add(result, f[i]);
    }
    print(result);
    return 0;
}
/**
Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
**/

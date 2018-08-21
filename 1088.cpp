/**********************
author: yomi
date: 18.6.29
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct Fraction
{
    long long int up, down;
}a, b;

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
    if(a.up == 0){
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
    result.up = a.up*b.down+a.down*b.up;
    return reduction(result);
}
Fraction minu(Fraction a, Fraction b)
{
    Fraction result;
    result.down = a.down*b.down;
    result.up = a.up*b.down-a.down*b.up;
    return reduction(result);
}
Fraction multi(Fraction a, Fraction b)
{
    Fraction result;
    result.down  = a.down*b.down;
    result.up = a.up*b.up;
    return reduction(result);
}
Fraction div(Fraction a, Fraction b)
{
    Fraction result;
    result.down = a.down * b.up;
    result.up = a.up * b.down;
    return reduction(result);
}
void print(Fraction r)
{
    r = reduction(r);
    int flag = 0;
    if(r.up < 0){
        flag = 1;
    }
    if(flag)
        printf("(");
    if(r.down == 1){
        printf("%lld", r.up);
    }
    else if(abs(r.up) > r.down){
        printf("%lld ", r.up/r.down);
        r.up = abs(r.up);
        printf("%lld/%lld", r.up%r.down, r.down);
    }
    else{
        printf("%lld/%lld", r.up, r.down);
    }
    if(flag)
        printf(")");
}
int main()
{
    scanf("%lld%*c%lld%lld%*c%lld", &a.up, &a.down, &b.up, &b.down);
    print(a);
    printf(" + ");
    print(b);
    printf(" = ");
    Fraction result = add(a, b);
    print(result);
    cout << endl;
    print(a);
    printf(" - ");
    print(b);
    printf(" = ");
    result = minu(a, b);
    print(result);
    cout << endl;
    print(a);
    printf(" * ");
    print(b);
    printf(" = ");
    result = multi(a, b);
    print(result);
    cout << endl;
    print(a);
    printf(" / ");
    print(b);
    printf(" = ");
    if(b.up == 0){
        printf("Inf");
    }
    else{
        result = div(a, b);
        print(result);

    }


    return 0;
}
/**
Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
**/

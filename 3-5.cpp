/**********************
author: yomi
date: 18.3.10
ps:
**********************/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double r1, r2;
    if(b*b-4*a*c<0)
        cout << "No real roots!";
    else{
        r1 = (-b+sqrt(b*b-4*a*c))/2*a;
        r2 = (-b-sqrt(b*b-4*a*c))/2*a;
        printf("r1=%7.2f\n", r1);
        printf("r2=%7.2f\n", r2);

    }
    return 0;
}

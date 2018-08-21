/**********************
author: yomi
date: 18.6.21
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000000007;
char str[100010];
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    int at_n = 0, pat_n = 0, t_n = 0;
    for(int i=len-1; i>=0; i--){
        if(str[i] == 'T'){
            t_n = (t_n+1)%maxn;
        }
        else if(str[i] == 'A'){
            at_n = (at_n+t_n)%maxn; /// at_n += at_n%maxn;
        }
        else if(str[i] == 'P'){
            pat_n = (pat_n+at_n)%maxn;
        }
    }
    printf("%d\n", pat_n);
    return 0;
}
/**
APPAPT

2
**/

/**********************
author: yomi
date: 18.8.27
ps:29'ÎÞ½âÆúÁÆ
**********************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxvalue = -1;
vector<int>temp, ans, fac;
void init()
{
    fac.push_back(0);
    int d=1;
    for(int i=1; i<n; i++){
        d = 1;
        for(int j=0; j<p; j++){
            d*=i;
        }
        if(d > n){
            break;
        }
        fac.push_back(d);
    }
}
void dfs(int index, int nowk, int sum, int seqsum)
{
    if(sum == n && nowk == k){
        if(seqsum > maxvalue){
            maxvalue = seqsum;
            ans = temp;
        }
        return;
    }
    if(sum>n || nowk>k)
        return;

    if(index-1>=0){
        temp.push_back(index);
        dfs(index, nowk+1, sum+fac[index], seqsum+index);
        temp.pop_back();


        dfs(index-1, nowk, sum, seqsum);
    }
}
int main()
{
    scanf("%d%d%d", &n, &k, &p);
    init();
//    for(int i=0; i<fac.size(); i++){
//        cout <<fac[i] << endl;
//    }

    dfs(fac.size()-1, 0, 0, 0);
    if(maxvalue == -1){
        printf("Impossible");
    }else{
        printf("%d = ", n);
        for(int i=0; i<ans.size()-1; i++){
            printf("%d^%d + ", ans[i], p);
        }
        printf("%d^%d", ans[ans.size()-1], p);

    }
    return 0;
}

/**
Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
**/

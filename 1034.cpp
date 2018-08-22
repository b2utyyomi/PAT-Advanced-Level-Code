/**********************
author: yomi
date: 18.8.22
ps: 写完dfs() 恍然大悟 原来我方了的原因就是 我没把相同两点之间的多边合并 心里想着出环了
这环还不是普通环 然后就没有然后了
**********************/
#include <iostream>
#include <map>
#include <set>
using namespace std;
const int maxn = 2010;
int n, k, head, totalvalue, t[maxn], num;
map<string, int>gang;
map<string, int>stringToInt;
map<int, string>intToString;
int g[maxn][maxn], si;
bool vis[maxn];
int toInt(string n)
{
    map<string, int>::iterator iter= stringToInt.find(n);
    int s = stringToInt.size();
    if(iter!=stringToInt.end()){
        return iter->second;
    }
    else{
        stringToInt[n] = s;
        return s;
    }
}
void dfs(int u)///整个dfs写懵了 我选择题解
{
    num++;
    vis[u] = true;
    if(t[u] > t[head])
        head = u;
    for(int v=0; v<si; v++){
        if(g[u][v]>0){
            totalvalue += g[u][v];
            g[u][v] = g[v][u] = 0;
            if(!vis[v]){
                dfs(v);
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    string n1, n2;
    int u, v, w, ans;
    for(int i=0; i<n; i++){
        cin >> n1 >> n2 >> w;
        u = toInt(n1);
        v = toInt(n2);
        intToString[u] = n1;
        intToString[v] = n2;
        t[u]+=w;
        t[v]+=w;
        ///g[v][u] = g[u][v] = w;错误一 因为两个人可以联系多次 我这样写 之前的权值就被覆盖了
        g[u][v]+=w;
        g[v][u]+=w;

    }
    si = stringToInt.size();
    for(int i=0; i<si; i++){
        head = i, totalvalue = 0, num = 0;
        dfs(i);
        if(num>2 && totalvalue>k){
            gang[intToString[head]] = num;
        }

    }
    cout << gang.size() << endl;
    for(map<string, int>::iterator iter=gang.begin(); iter!=gang.end(); iter++){
        cout << iter->first << ' ' << iter->second << endl;
    }
    return 0;
}
/**
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
**/

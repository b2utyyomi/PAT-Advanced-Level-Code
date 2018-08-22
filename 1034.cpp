/**********************
author: yomi
date: 18.8.22
ps: д��dfs() ��Ȼ���� ԭ���ҷ��˵�ԭ����� ��û����ͬ����֮��Ķ�ߺϲ� �������ų�����
�⻷��������ͨ�� Ȼ���û��Ȼ����
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
void dfs(int u)///����dfsд���� ��ѡ�����
{
    num++;
    vis[u] = true;
    for(int v=0; v<si; i++){
        if(g[u][v] > 0){///������ Ӧ�����жϷ��ʹ��Ͳ����ʵ�ѽ ���� ���������
            totalvalue += g[u][v];///���ټ�һ���ߵ� ���Ժ��ж�
            g[u][v] = g[v][u] = 0; ///������ɾ���Ѿ��߹��ı� ��Ȼ�ֻ��ظ�����
            if(!vis[v]){
                vis[v] = true;
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
        ///g[v][u] = g[u][v] = w;����һ ��Ϊ�����˿�����ϵ��� ������д ֮ǰ��Ȩֵ�ͱ�������
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

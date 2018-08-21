/**********************
author: yomi
date: 18.8.16
ps: ������dfs�Ϳ����ˣ� ����Ҫ��·������Ҫ���շǵ���˳����� ��������˺�һ���
�����뵽�ݴ浽string������ Ȼ��sort ������ǲ���ʵ�� �����ٸ����ϣ �鷳
�ٿ����� ��ʵ����ÿ����������ʱ��ѡȨֵ���� ���� �Ұ�ÿһ��������µĺ����Ƕ�����
�Ӵ�С���˸��򡣳ɹ������
**********************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int id;
    vector<Node>child;
}node[150];
bool vis[150];
long long int sum = 0, weight;
vector<int>path;
int cnt = 0;
int cmp(Node a, Node b)
{
    return a.data>b.data;
}
void dfs(int index)
{
    if(node[index].child.size() == 0){
        if(sum == weight){
            for(int i=0; i<path.size()-1; i++){
                cout << path[i] << ' ';
            }
            cout << path[path.size()-1] << endl;
        }
        return;
    }
    for(int i=0; i<node[index].child.size(); i++){
        int id = node[index].child[i].id;
        if(!vis[id]){
            sum += node[id].data;
            path.push_back(node[id].data);
            dfs(id);
            sum -= node[id].data;
            path.pop_back();
        }

    }
}
int main()
{
    int m, n, t, num, d;
    cin >> m >> n >> weight;
    for(int i=0; i<m; i++){
        cin >> node[i].data;
        node[i].id = i;
    }
    for(int i=0; i<n; i++){
        cin >> t >> num;
        for(int j=0; j<num; j++){
            cin >> d;
            node[t].child.push_back(node[d]);
        }
        sort(node[t].child.begin(), node[t].child.end(), cmp);
    }
    sum += node[0].data;
    path.push_back(node[0].data);
    vis[0] = true;
    dfs(0);

    return 0;
}
/**
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
**/

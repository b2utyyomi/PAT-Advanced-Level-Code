/******************************
author:yomi
date:18.9.1
ps: 交了两次都不对 这给我郁闷的呀 原来是忘记把测试代码删掉了 太尴尬
今天95分 呵哈哈哈哈 冷静冷静 只是题简单 一点弯都没有 大佬是要100的
******************************/
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    node* l;
    node* r;
    int data;
    int layer;
};
const int maxn = 50;
int po[maxn], in[maxn];
vector<int>level[maxn];
int maxlayer;
int cnt = 0;
node* create(int inL, int inR, int poL, int poR)
{
    if(poL>poR){
        return NULL;
    }
    node* root = new node;
    root->data = po[poR];
    int i;
    int numL = 0;
    for(i=inL; i<=inR; i++){
        if(po[poR] == in[i]){
            break;
        }
    }
    numL=i-inL;
    root->l = create(inL, i-1, poL, poL+numL-1);
    root->r = create(i+1, inR, poL+numL, poR-1);

    return root;

}
void bfs(node* root)
{
    queue<node* >q;
    while(!q.empty()){
        q.pop();
    }
    root->layer = 1;
    q.push(root);
    while(!q.empty()){
        node* a = q.front();

         maxlayer = max(a->layer, maxlayer);
        //cout << a->layer << endl;
        level[a->layer].push_back(a->data);
        q.pop();
        if(a->l!=NULL){
            a->l->layer = a->layer+1;
            q.push(a->l);
        }
        if(a->r!=NULL){
            a->r->layer = a->layer+1;
            q.push(a->r);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> in[i];
    }
    for(int i=1; i<=n; i++){
        cin >> po[i];
    }
    //cout << po[n] << endl;
    node* root = create(1, n, 1, n);
    //cout << root->data << endl;
    bfs(root);
    int flag = 0;
    for(int i=1; i<=maxlayer;i++){
        int s = level[i].size();
        if(flag){
            for(int j=0; j<s-1; j++){
                cout << level[i][j] << ' ';
            }
            ///搞不好这就可能来个段错误 因为s可能为零啊 这种写法要注意了 找BUG可浪费了我不少时间
            cout << level[i][s-1];
            if(i!=maxlayer){
                cout << ' ';
            }
            flag = 0;
        }
        else{
            for(int j=s-1; j>0; j--){
                cout << level[i][j] << ' ';
            }
            ///搞不好这就可能来个段错误 因为s可能为零啊 这种写法要注意了 找BUG可浪费了我不少时间
            cout << level[i][0];
            if(i!=maxlayer){
                cout << ' ';
            }
            flag = 1;
        }

    }
    return 0;
}
/**
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
**/

/******************************
author:yomi
date:18.8.30
ps: 思路是百分之百没错了 主要是我把root传丢了呀 65分结束战斗 做出来就95 差得太多了 天堂与地狱一念之间
我凉了 今天又是凉嗖嗖的一天
******************************/
#include<iostream>
using namespace std;
const int maxn = 50;
int pre[maxn], in[maxn], po[maxn];
struct node
{
    int data;
    node* l;
    node* r;
};
int n, cnt;
node* create(int L1, int R1, int L2, int R2)
{
    if(L1>R1||L2>R2){
        return NULL;
    }
    node* root = new node;
    if(pre[L1] == po[R2]){
        node* lchild = new node;
        node* rchild = new node;
        root->data = pre[L1];
        lchild->data = pre[L1+1];
        rchild->data = po[R2-1];
        root->l = lchild;
        root->r = rchild;
        root = create(L1+1, R1, L2, R2-1);
    }
    else{
        int i, j=-1;
        for(i=L1; i<=R1;i++){
            if(pre[i] == po[R2]){
                j = i;
                break;
            }
        }
        root->l = create(L1, j-1, L2, j-L1+L2-1);
        root->r = create(j, R1, j-L1+L2, R2);
    }
    return root;
}
void in_order(node* root)
{
    if(root->l){
        in_order(root->l);
    }
    in[cnt++] = root->data;
    if(root->r)
        in_order(root->r);
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> pre[i];
    }

    for(int i=1; i<=n; i++){
        cin >> po[i];
    }
    node* root = create(1, n, 1, n);
    in_order(root);
    for(int i=0; i<cnt-1; i++){
        cout << in[i] << ' ';
    }
    cout << in[cnt-1];
    return 0;
}
/**
Sample Input 1:

7
1 2 3 4 6 7 5
2 6 7 4 5 3 1

Sample Output 1:

Yes
2 1 6 4 7 3 5

Sample Input 2:

4
1 2 3 4
2 4 3 1

Sample Output 2:

No
2 1 3 4

**/

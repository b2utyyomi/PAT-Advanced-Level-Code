/**********************
author: yomi
date: 18.7.31
ps:
**********************/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int>s;
queue<int>q;
int maxSize, n, t, m;
bool tell()
{
    for(int i=1; i<=n; i++){

        if(s.size() == maxSize){
            return false;
        }
        s.push(i);
        while(!s.empty()&&s.top() == q.front()){
            s.pop();
            q.pop();
        }
    }
    if(!s.empty()){
        return false;
    }
    return true;

}
int main()
{
    cin >> maxSize >> n >> t;
    for(int j=0; j<t; j++){
        while(!s.empty()){
            s.pop();
        }
        while(!q.empty()){
            q.pop();
        }
        for(int i=0; i<n; i++){
            cin >> m;
            q.push(m);
        }
        if(tell()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
/**
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
**/





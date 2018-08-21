/**********************
author: yomi
date: 18.4.11
ps:
**********************/
#include <iostream>
#include <string>
using namespace std;

struct pass
{
    string name;
    string pw;
}p[1010], p1[1010];
int main()
{
    int T, flag = 0;
    int ps = 0;
    cin >> T;
    for(int j=0; j<T; j++){
        cin >> p[j].name >> p[j].pw;
        ps = 0;
        for(int i=0; i<p[j].pw.length(); i++){

            if(p[j].pw[i] == '1'){
                p[j].pw[i] = '@';
                ps = 1;
            }
            if(p[j].pw[i] == 'O'){
                p[j].pw[i] = 'o';
                ps = 1;
            }

            if(p[j].pw[i] == 'l'){
                p[j].pw[i] = 'L';
                ps = 1;
            }
            if(p[j].pw[i] == '0'){
                p[j].pw[i] = '%';
                ps = 1;
            }
        }
        if(ps){
            p1[flag] = p[j];
            flag++;
        }
    }
    if(flag == 0 && T == 1)
        cout << "There is 1 account and no account is modified";
    else if(flag==0)
        cout << "There are " << T << " accounts and no account is modified";
    else{
        cout << flag << endl;
        for(int i=0; i<flag; i++){
            cout << p1[i].name << ' ' << p1[i].pw;
            if(i!=flag-1)
                cout << endl;
        }
    }

    return 0;
}
/**
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

2
Team000002 RLsp%dfa
Team000001 R@spodfa
*/

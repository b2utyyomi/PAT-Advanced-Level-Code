/**********************
author: yomi
date: 18.8.13
ps: 不难的题 可是 却 出了错
最后还是改成了答案的样子。。。
**********************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <cstdio>
using namespace std;
void print(map<string, set<int> > &mmap, string &query)
{
    map<string, set<int> >::iterator iter = mmap.find(query);
    if(iter == mmap.end()){
        cout << "Not Found" << endl;
        return;
    }
    set<int> s = iter->second;
    for(set<int>::iterator iter1=s.begin(); iter1!=s.end(); ++iter1){
        //cout << *iter1 << endl;
        printf("%07d\n", *iter1);
    }
}
int main()
{
    int n, m, id, tt;
    map<string, set<int> >title;
    map<string, set<int> >author;
    map<string, set<int> >word;
    map<string, set<int> >publisher;
    map<string, set<int> >year;
    cin >> n;
    string t, au, wo, pub, y;
    char ch;
    for(int i=0; i<n; i++){
        cin >> id;
        getchar();
        getline(cin, t);
        title[t].insert(id);
        //getchar();
        getline(cin, au);
        author[au].insert(id);
        ///test code debug sort keywords

        while(cin >> wo){
            char c = getchar();
//            if(c == '\n'){
//                break;
//            }

            //cin >> ch;
            word[wo].insert(id);
            if(c == '\n'){
                break;
            }
        }

        getline(cin, pub);
        publisher[pub].insert(id);

        getline(cin, y);
        year[y].insert(id);
    }
    cin >> m;
    char ch1;
    string query;
    int flag = 1;
    for(int i=0; i<m; i++){
        flag = 1;
        cin >> tt >> ch1;
        getchar();
        getline(cin, query);
        cout << tt << ch1 << " " << query << endl;
        if(tt == 1){
            print(title, query);
        }
        if(tt == 2){
            print(author, query);
        }
        if(tt == 3){
            print(word, query);
        }
        if(tt == 4){
            print(publisher, query);
        }
        if(tt == 5){
            print(year, query);
        }
    }
    return 0;
}
/**
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
**/

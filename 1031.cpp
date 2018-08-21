/**********************
author: yomi
date: 18.4.8
ps:
**********************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    char matrix[100][100];
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            matrix[i][j] = ' ';
        }
    }
    cin >> s;
    int len = s.length();
    int n=0, m, k;
    n = (len+2)/3;
    m = len+2-2*n;
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        matrix[i][0] = s[cnt++];
    }
    for(int j=0; j<m; j++){
        matrix[n-1][j] = s[cnt++];
    }
    for(int i=n-2; i>=0; i--){
        matrix[i][m-1] = s[cnt++];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matrix[i][j];
        }

            cout << endl;
    }
    return 0;
}







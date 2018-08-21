/**********************
author: yomi
date: 18.6.24
ps:
**********************/
#include <iostream>
#include <string>
using namespace std;

bool tell(string s)
{
    int p_cnt = 0, t_cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]!='P' && s[i]!='A' && s[i]!='T'){
            return false;
        }
        if(s[i] == 'P'){
            p_cnt++;
        }
        if(s[i] == 'T'){
            t_cnt++;
        }
    }
    if(p_cnt != 1 || t_cnt!=1){
        return false;
    }
    int p_pos = s.find('P'), t_pos = s.find('T');
    int a_lcnt = 0, a_mcnt = 0, a_rcnt = 0;
    a_lcnt = s.substr(0, p_pos).length();                                     ///012345
    a_mcnt = s.substr(p_pos+1, s.length()-p_pos-1-(s.length()-t_pos)).length();//APAATA
    a_rcnt = s.substr(t_pos+1, s.length()).length();
//    cout << a_lcnt << ' ' << a_mcnt << ' ' << a_rcnt << endl;
//    cout << s.substr(p_pos+1, s.length()-p_pos-1-(s.length()-t_pos)) << endl;
    if(a_rcnt == a_lcnt*a_mcnt && a_mcnt>=1){
        return true;
    }
    return false;

}
int main()
{
    int T;
    string s;
    cin >> T;
    while(T--){
        cin >> s;
        if(tell(s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

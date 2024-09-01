#include<bits/stdc++.h>
using namespace std;
bool isImportant(int a){
    string str=to_string(a);
    if(str.length()<=2)return 0;
    if(str.length()==3 and str[0]=='1' and str[1]=='0' and str[2]=='1')return 0;
    if(str[0]=='1' and str[1]=='0' and str[2]!='0')return 1;
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        cout<< (isImportant(a)?"YES":"NO")<<endl;
    }
}
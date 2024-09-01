#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k,w,h;cin>>n>>k>>w>>h;
        string s;cin>>s;
            bool flipx=0,flipy=0;
            int x=0,y=0,count=0;
            int time=0;
            while(time<k*n){
                int index=time%n;
                if((s[index]=='R' and !flipx) or (s[index]=='L' and flipx)){
                    if(x<w){ x++; }
                    else{ x--;flipx=!flipx;}
                }
                else if((s[index]=='L' and !flipx) or (s[index]=='R' and flipx)){
                    if(x>0){ x--; }
                    else{ x++;flipx=!flipx;}
                }
                else if((s[index]=='D' and !flipy) or (s[index]=='U' and flipy)){
                    if(y>0){ y--; }
                    else{ y++;flipy=!flipy;}
                }
                else if((s[index]=='U' and !flipy) or (s[index]=='D' and flipy)){
                    if(y<h){  y++; }
                    else{ y--;flipy=!flipy;}
                }

                // cout<<index<<": "<<x<<' '<<y<<endl;
                if(x==0 and y==0){count++;}
                    time++;
                }
            cout<<count<<endl;
    }
}
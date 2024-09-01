#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;

int solve(){   

    int n,k;    
    cin>>n>>k;   
    vector<int> a(n);       
    for(int i=0;i<n;i++){        
        cin>>a[i];    
    }    
    sort(a.begin(),a.end());    
    for(int i=n-1;i>=0;i--){        
        if(k==0 or i==0){            
            break;        
        }            
        int diff=a[i]-a[i-1];    

        if(k>diff){
            a[i-1]=a[i];
            k-=diff;
        }
        else{
            a[i-1]+=k;
            k=0;
        }
        i--;      
    }  
    int ans=0;      
    for(int i=0;i<n;i++){        
        if(i%2==0){            
            ans+=a[i];        
        }        
        else{            
            ans-=a[i];        
        }    
    }    
    return abs(ans);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}







                            
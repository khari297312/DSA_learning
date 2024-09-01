#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        //sorting the array
        sort(arr.begin(),arr.end());
        
        //finding the maximum odd present in the array
        long maxOdd=0;
        int indexOfmaxOdd=-1;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                if(maxOdd<arr[i]){
                    maxOdd=arr[i];
                    indexOfmaxOdd=i;
                }
            }
        }

        // cout<<maxOdd<<endl;
        //no odd in the array
        if(indexOfmaxOdd==-1) {
            cout<<"ans";
            cout<<0<<endl;
            continue;}
        
        //finding maxOdd after swapping with less Evens
        int count=0;
        int i=0;
        while(i<indexOfmaxOdd){
            if(arr[i]%2==0){
                maxOdd+=arr[i];
                count++;
            }
            i++;
            // cout<<maxOdd<<' '<<count<<endl;
        }

        int s=indexOfmaxOdd+1,e=n-1;
        while(s<=e){
            while(arr[s]%2!=0){s++;}
            while(arr[e]%2!=0){e--;}
            if(s>e)break;

            if(arr[s]>maxOdd){count+=2;maxOdd+=(2*arr[i]);e--;}
            else if(arr[e]<maxOdd){count++;e--;}
            else{count++;s++;maxOdd+=arr[s];}
        }
        cout<<"ans:";
        cout<<count<<endl;

    }
}
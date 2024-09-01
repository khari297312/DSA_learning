// #include <bits/stdc++.h>
// using namespace std;
// int maxScore(vector<int>& a,string &s){
//     int n=a.size();
//     if(s[n-1]=='L')return -1;
//     stack<int> st;
//     int ans=0;
//     int index=n-1;
//     while(!st.empty() or index>=0){
//         if(st.empty()){
//             if(s[index]=='L')return -1;
//             if(s[index]=='R'){
//                 st.push(index);
//             }
//             index--;
//             continue;
//         }


//         if(s[index]=='R'){
//             st.pop();
//             st.push(index);
//         }

//         else if(s[index]=='.'){index--;continue;}

//         else if(s[index]=='L'){
//             int right=st.top();
//             for(int i=index;i<=right;i++){
//                 ans+=a[i];
//                 s[i]='.';
//             }
//             st.pop();
//             index=n-1;
//         }
//     }
//     return ans;
// }
// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;

//         vector<int> a(n);
//         string s;
//         for (int i=0;i<n;i++) cin>>a[i];
//         cin>>s;
//         cout<<maxScore(a,s)<<endl;
//     }
//     return 0;
// }
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int sum(vector<int>& arr, int i, int j) {
    int totalsum = 0;
    for(int k = i; k <= j; k++) {
        totalsum += arr[k];
    }
    return totalsum;
}

int main() {
    int n;
    cin >> n;
    while(n > 0) {
        int a;
        cin >> a;
        vector<int> arr(a);
        for(int i = 0; i < a; i++) {
            cin >> arr[i];
        }
        string s;
        cin >> s;

        int i = 0;
        int j = a - 1;
        stack<pair<char,int> > st;
        int totalsum = 0;

        while(i < j) {
            if(s[i] == 'L') {
                st.push(make_pair(s[i],i));
                i++;
            } 
            if(s[j] == 'R') {
                if(!st.empty() && st.top().first == 'L') {
                    totalsum += sum(arr, st.top().second, j);
                    st.pop();
                }
                j--;
            } 
            if(s[i] == 'R') {
                i++;
            } 
            if(s[j] == 'L') {
                j--;
            }
        }
        
        cout << totalsum << endl;
        n--;
    }
    return 0;
}

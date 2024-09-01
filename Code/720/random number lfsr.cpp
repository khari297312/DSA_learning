#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;
int findRandom()
{
    int num = ((int)rand() % 2);
    return num;
}
string generateBinaryString(int N)
{
    srand(time(NULL));
    string S = "";
    for (int i = 0; i < N; i++) {
        int x = findRandom();
        S += to_string(x);
    }
    return S;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    //we have given a string of length n 
    // our output is last bit of string and we are doing linear feedback shift register
    // we are using 4 bit lfsr
    string s=generateBinaryString(50);
    // last bit is xor of 1st and 2nd bit
    int i=0;
    while(i<1000){
        int last=(s[13]-'0')^(s[5]-'0')^(s[49]-'0')^(s[25]-'0');
        s=to_string(last)+s.substr(0,50);
        cout<<s<<endl;
        i++;
    }
    return 0;
}
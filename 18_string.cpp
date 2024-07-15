#include <iostream>
#include<string>
#include<vector>
using namespace std;
void reverseString(string &s){
    int start=0,end=s.size()-1;
    while(start<end){
        swap(s[start],s[end]);
        start++;end--;
    }
}
int size(string s){
    int count=0;
    //when null character is encountered the loop will break
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    return count;

}
bool palindromeString(string s){
    int start=0,end=s.size()-1;
    while(start<end){
        if(s[start]!=s[end])return false;
        start++;end--;
    }
    return true;

}

string ipDefanging(string s){
    string ans="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            // ans.push_back('[');ans.push_back('.');ans.push_back(']');
            //above can be written as
            ans=ans+"[.]";
            }
        else ans.push_back(s[i]);
    }
    return ans;
}

bool checkShifted(string s1,string s2){
    int n=s1.size()-1;
    bool clk=1,anti=1;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[(i+2)%n]){bool clk=0;};        
    }
    for(int i=0;i<s1.size();i++){
        if(s2[i]!=s1[(i+2)%n]){bool anti=0;};        
    }
    return clk or anti;
}

void RotateClk(string &s){
    int i=0;
    char temp1=s[i];i++;
    while(i<s.size()){
        char temp2=s[i];
        s[i]=temp1;i++;
        temp1=temp2;
    }
    s[0]=temp1;
}
void RotateAnti(string &s){
    int i=s.size()-1;
    char temp1=s[i];i--;
    while(i>=0){
        char temp2=s[i];
        s[i]=temp1;i--;
        temp1=temp2;
    }
    s[s.size()-1]=temp1;
}
void RotateKtimes(string &s ,int k, bool clk){
    int n=s.size()-1;
    k=k%n;
    if(clk){while(k--){RotateClk(s);}}
    else{while(k--){RotateAnti(s);}}
}

bool Pangram(string s){
    vector<int> arr(26,0);

    for(int i=0;i<s.size();i++){
        if('a'<=s[i] and s[i]<='z'){arr[s[i]-'a']++;}
        if('A'<=s[i] and s[i]<='Z'){arr[s[i]-'A']++;}
    }
    for(int i=0;i<26;i++){cout<<arr[i]<<" ";}cout<<endl;
    for(int i=0;i<26;i++){
        if(arr[i]==0){return 0;}
    }
    return 1;
}
string sortString(string s){
    vector<int> arr(26,0);
    for(int i=0;i<s.size();i++){
        if('a'<=s[i] and s[i]<='z'){arr[s[i]-'a']++;}
        if('A'<=s[i] and s[i]<='Z'){arr[s[i]-'A']++;}
    }
    string ans="";
    for(int i=0;i<26;i++){
        while(arr[i]--){
            ans.push_back(i+'a');
        }
    }
    return ans;
}
//time complexity of the above function is O(n) where n is the size of the string
int main() {
    char arr[20] ;
    // cin>>arr;
    // arr[7]='\0';//to print only first 7 characters of the input
    // cout<<arr<<endl;
    string s;
    // cin>>s;cout<<s;//you can only take single word input 
    //using getline you can take multiple word input
    // getline(cin,s);
    // cout<<s;
    // string s1="hello";string s2="world";
    // string s3=s1+s2;cout<<s3<<endl;//+ to concatenate the strings
    // string s4="hardik is a "good" boy";//this will give error
    // string s5="hardik is a \"good\"";// \ is the escape character
    // string s5;
    // getline(cin,s5);
    // cout<<s5<<endl;
    // reverseString(s5);
    // cout<<s5<<endl;
    string ipAddress="192.168.102.67";
    cout<<ipDefanging(ipAddress)<<endl;
    cout<<checkShifted("leetcode","deleetco")<<endl;
    cout<<checkShifted("amazon","azonam")<<endl;
    s="hardik";
    RotateClk(s);cout<<s<<endl;
    RotateAnti(s);cout<<s<<endl;
    RotateKtimes(s,4,1);cout<<s<<endl;
    string str;getline(cin,str);
    cout<<Pangram(str)<<endl;
    cout<<sortString(str)<<endl;


    return 0;
}
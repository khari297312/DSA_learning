#include <iostream>
#include <vector>
#include<list>
using namespace std;

template <class T>
void display(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
// template< class int>
void displaylist(list<int> &l){
    list<int> ::iterator it;
    for(it=l.begin();it!=l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main() {
     vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    display(v);
    v.pop_back();
    display(v);
    vector<int> ::iterator iter=v.begin();
    //this iterator is used to insert elements at any position
    v.insert(iter , 5,100);
    //insert 5 elements of value 100 at the beginning
    display(v);
    //v.erase(iter+ 1);
    display(v);
    //v[i] is same as v.at(i)k 

    vector<char> v1= {'a','b','c','d'};
    for(int i=0;i<4;i++){v1.at(i)+=6;}
    display(v1);




    list<int> l1;
    l1.push_back(0);
    l1.push_back(-20);
    l1.push_back(30);
    list<int> ::iterator iter1=l1.begin();
    // cout<<*iter1<<endl;
    // iter1++;
    // cout<<*iter1<<endl;
    l1.insert(iter1, 15);//use to insert in between the list
    // //l1.begin() is staring pointer, l1.end() is last null pointer (end)
    // for (iter1 = l1.begin(); iter1 != l1.end(); iter1++) {
    //     cout << *iter1 << " ";
    // }
    l1.push_front(4);
    displaylist(l1);
    l1.pop_front();
    displaylist(l1);
    l1.sort();
    displaylist(l1);

    list<int> l2;
    l2.push_back(4);
    l2.push_back(9);
    l2.push_back(1);
    l2.push_back(6);
    displaylist(l2);

    l2.sort();
    l1.merge(l2);
    displaylist(l1);
    l1.reverse();
    displaylist(l1);
    return 0;
}
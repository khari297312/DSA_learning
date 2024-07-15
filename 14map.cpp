#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map <string,int> m;
    m["a"] = 1;        m["b"] = 2;
    m["c"] = 3;
    cout<<m["a"]<<endl;
    //map is a key value pair
    //map is a associative container
    //map is a ordered container
    //map is a unique container
    //map is a sorted container
    //stl map is implemented using red black tree
    //map is a balanced binary search tree
    //map is a self balancing binary search tree
    //map is a height balanced binary search tree
    map <string, int> ::iterator iter;
    for (iter=m.begin();iter!=m.end();iter++){
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
        //this will print the key value pair
        //iter is like a pointer
        //(*iter) is a pair
        //(*iter).first is the key
        //(*iter).second is the value
    }
    m.insert(pair<string,int>("d",4));
    m.insert({"e",5 });
    //inserting a pair
    cout<<m["d"]<<endl;
    //this will print the value of key d
    m.erase("d");
    //this will erase the key d
    for (iter=m.begin();iter!=m.end();iter++){
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
    }
    return 0;

}
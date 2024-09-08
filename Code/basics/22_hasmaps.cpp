#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //hashmap has O(1) of insertion , deletion, searching 
    //implementation using linked list: O(n)
    //implementation using BST: O(logn)
    //two inbuilt hashmaps: map and unordered_map: time complexity is O(logn) and O(1) respectively
    //data is stored in key value pair<key, value>

    //creation :
    unordered_map<string,int> m;

    //insertion
    pair<string,int> p("abc",1);m.insert(p);
    pair<string,int> p1=make_pair("def",2);m.insert(p1);
    m["ghi"]=3;//there must be unique keys

    //searching
    cout<<m["abc"]<<endl;//if key is not present then it will insert the key with value 0
    cout<<m.at("def")<<endl;//if key is not present then it will throw an error

    //size
    cout<<m.size()<<endl;

    //count
    cout<<m.count("abc")<<endl;//if key is present then it will return 1 else 0

    //delete
    m.erase("abc");


    //traversaal
    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    //using iterator
    unordered_map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }


    //in unordered map the keys are stored in sorted order
    //in map the keys are stored in unsorted order based on the hash function


    //Hash functions: 1. Hash code: integer generated for each key based on hash function , it has to done uniform distribution
    //2. Compression function: it is used to convert the hash code into the index of the array(into the range of the array)

    //collision: when two keys have same hash code then it is called collision we get same index for two keys
    //collision handling : 1.open hashing -> a) sperate chaining b) open addressing
    //a) separate chaining: store the keys in linked list at the same index and store the keys in the linked list
    //b) open addressing: store the keys in the next empty index using linear probing, quadratic probing, double hashing
        //Hi(a)=h(a)+f(i) where f(i) is the probing function to get the next index at which the key is to be stored

    //2. closed addressing: 
    

    //complexity analysis:n=number of words, k=average length of the word : given n>>k complexity is O(k) -> O(1)
    //hash function should be fast and should have uniform distribution

    //n=number of keys , b=number of boxes available 
    //load factor=n/b : it should be less than 0.7, we always ensure that the load factor is less than 0.7


    //if our n increases then we have to increase the b and rehash all the keys: rehashing

   
    return 0;
}
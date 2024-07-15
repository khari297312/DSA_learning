#include <iostream>
#include<queue>
using namespace std;

class Maxheap{
    public:
    int arr[1000];
    int index=1;
    void insert(int data){
        //adding data to the last of array
        int temp=index;
        arr[temp]=data;
        index++;
        //go to its final and correct position
        while(index>0){
            int parent=(temp)/2;
            if(arr[parent]<arr[temp]){
                swap(arr[parent],arr[temp]);
                temp=parent;
            }
            else{break;}
        }
    }
    void deleteHeap(){
        //swap the first and last element
        arr[1]=arr[index-1];
        //remove the last element
        index--;
        int i=1;
        //go to its final and correct position
        while(i<index){
            int l=2*i,r=2*i+1;
            if(arr[i]<arr[l] and arr[l]>arr[r]){
                swap(arr[i],arr[l]);
                i=l;
            }
            else if(arr[i]<arr[r] and arr[r]>arr[l]){
                swap(arr[i],arr[r]);
                i=r;
            }
            else{break;}
        }
    }
    void print(){for(int i=1;i<index;i++){cout<<arr[i]<<" ";}cout<<endl;}

    //for insertion and deletion :time complexity =O(logn)
};
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void MaxHeapifyAlgo(int arr[],int n,int i){
    int index=i;
    int l=2*i+1,r=2*i+2;
    // cout<<"index: "<<index<<" ";
    // printArr(arr,n);
    if(l<n and arr[index]<arr[l]){index=l;}
    if(r<n and arr[index]<arr[r]){index=r;}
    if(index!=i){
        swap(arr[index],arr[i]);
        MaxHeapifyAlgo(arr,n,index);
    }
    
}

void MinHeapifyAlgo(int arr[],int n,int i){
    int index=i;
    int l=2*i+1,r=2*i+2;
    // cout<<"index: "<<index<<" ";
    // printArr(arr,n);
    if(l<n and arr[index]>arr[l]){index=l;}
    if(r<n and arr[index]>arr[r]){index=r;}
    if(index!=i){
        swap(arr[index],arr[i]);
        MinHeapifyAlgo(arr,n,index);
    }
    
}

void HeapSort(int arr[],int n){
    //swap first and last as first is max and last is min
    if(n==0){return;}
    swap(arr[0],arr[n-1]);

    //heapify the array (max heap)
    for(int i=(n-1)/2;i>=0;i--){MaxHeapifyAlgo(arr,n-1,i);}
    printArr(arr,n);
    //sort the array
    HeapSort(arr,n-1);
}

void HeapSortiter(int arr[],int n){
    int iter=n;
    while(iter>0){
        swap(arr[0],arr[iter-1]);
        for(int i=(iter-1)/2;i>=0;i--){MaxHeapifyAlgo(arr,iter-1,i);}
        iter--;
    }
}
//time complexity of Heap sort is O(nlogn) and space complexity is O(1)
int main() {
    //what is heap?
    //heap is a complete binary tree that comes with heap property
    //CBT: all levels are completely filled except possibly for the last level and the last level has all keys as left as possible
    //nodes always follow the heap property
    //nodes addition are from left side first and then right side

    //types of heap:Max heap and Min heap
    //Max heap: parent node is always greater than child nodes
    //Min heap: parent node is always smaller than child nodes
    //node at index i has 
    //left child at 2*i index
    //right child at 2*i+1 index
    //parent node at i/2 index 
    //CBT: leaf node are from (n/2)+1 to n index

    Maxheap h;
    // h.insert(10);h.print();
    // h.insert(20);h.print();
    // h.insert(30);h.print();
    // h.insert(40);h.print();
    // h.insert(50);h.print();
    // h.insert(60);h.print();
    // h.deleteHeap();h.print();
    // h.deleteHeap();h.print();
    // h.insert(35);h.print();
    // cout<<endl;
    int arr[]={10,20,30,25,5,40,35};
    int n=7;
    for(int i=n/2-1;i>=0;i--){
        // cout<<"i: "<<i<<endl;
        MinHeapifyAlgo(arr,n,i);
        // cout<<endl;
        }
    printArr(arr,n);

    // for(int i=2;i>=0;i--){cout<<"i: "<<i<<endl;MinHeapifyAlgo(arr,n,i);cout<<endl;}
    // HeapSort(arr,n);printArr(arr,n);
    HeapSortiter(arr,n);printArr(arr,n);
    // HeapifyAlgo(arr,7,3);












    /********************************************/
    //priority queue
    //priority queue is a data structure that follows the heap property and
    //by default it is max heap
    //priority queue is implemented using heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(5);
    for (int i = 0; i < 5; i++)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }cout<<endl;

    //to create min heap;
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(10);
    pq1.push(20);
    pq1.push(30);
    pq1.push(40);
    pq1.push(5);
    for(int i=0;i<5;i++){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }cout<<endl;

    return 0;
}
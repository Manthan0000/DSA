#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int>q;
    int n;
    int value;
    cout << "Enter How many element you want to Queue : ";
    cin >> n;
    //Enqueue and Overflow
    for (int i = 0; i < n+1;  i++)
    {
        if (q.size() >= n){
            cout << "Queue Overflow ! Cannot Enqueue more elements " << endl;}
        else{
            value = i +1 ;
            q.push(value);
            cout << "ENQUEUED element : " << value << endl;}
    }
    cout << "Queue size after Enqueue "<< q.size() << endl;

    //Dequeue and underflow
    while (!q.empty()){
        cout<<"DEQUEUED element : " << q.front() << endl;
        q.pop();
    }
    if (q.empty())
    {
        cout << "Queue Underflow ! Cannot Dequeue more elements " << endl;
    }
    cout << "Queue is now empty ";
    return 0;
}
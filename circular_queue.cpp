#include <iostream>
using namespace std;

int queue[5];
int front = -1 ;
int rear = -1 ;
int size = 5 ;

bool isempty(){
    return front == -1 ;
}

bool isfull(){
    return (rear+1) % size == front ;
}

void enqueue (int value){
    if(isfull()){
        cout << "Queue is full ! Cannot insert " << endl;
        return;
    }
    if(isempty()){
        front=rear=0;
    }else{
        rear = (rear + 1) % size ;
    }
    queue[rear] = value ;
    cout << value << " enqueue successfully!" << endl;
}

int dequeue () {
    if(isempty()){
        cout << "Queue is Empty ! Nothing to dequeue. " <<endl;
        return -1;
    }
    int data = queue[front];
    if (front==rear)
    {
        front=rear=-1;
    }else{
        front = (front + 1) % size ;
    }
    return data ;
}

void display(){
    if (isempty())
    {
        cout << "Queue is empty ! "<< endl;
        return;
    }
    cout << "Queue elements : ";
    for (int i = front ; i != rear; i=(i+1)%size)
    {
        cout << queue[i] << " ";
    }
    cout << queue[rear] << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();
    cout << "Deqeued : " << dequeue() << endl;
    cout << "Deqeued : " << dequeue() << endl;

    display();
    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
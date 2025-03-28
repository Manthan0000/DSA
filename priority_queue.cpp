#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int main() {
    priority_queue<pair<int ,string>>pq; //max heap (Default)

    pq.push({3 , "Task C"});
    pq.push({1 , "Task A"});
    pq.push({2 , "Task B"});

    while (!pq.empty())
    {
        auto task = pq.top();
        cout << "Processing " << task.second << " with priority " << task.first << endl;
        pq.pop();
    }
    return 0 ;
}
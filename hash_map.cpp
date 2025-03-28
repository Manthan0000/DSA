#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> hashMap;

    hashMap[1] = "Apple";
    hashMap[2] = "Banana";
    hashMap[3] = "Cherry";

    hashMap.insert({4, "Date"});

    for (auto& pair : hashMap)
        cout << pair.first << " -> " << pair.second << endl;

    int key = 2;
    if (hashMap.find(key) != hashMap.end())
        cout << "Found: " << hashMap[key] << endl;
    else
        cout << "Not Found" << endl;

    hashMap.erase(3);

    cout << "After deletion:" << endl;
    for (auto& pair : hashMap)
        cout << pair.first << " -> " << pair.second << endl;

    return 0;
}

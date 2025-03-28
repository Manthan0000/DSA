#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree() {
    int data;
    cin >> data;
    if (data == -1) return nullptr;

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData, rightData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cin >> rightData;
        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

void levelOrder(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

void reverseLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    stack<int> s;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        s.push(temp->data);

        if (temp->right) q.push(temp->right);
        if (temp->left) q.push(temp->left);
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = buildTree();

    levelOrder(root);
    cout << endl;

    reverseLevelOrder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
}

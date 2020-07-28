#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree,const int& node,int Min,int Max) {
    if (node ==-1)
    {
        return true;
    }
    if ( tree[node].key>Min &&  tree[node].key<Max && IsBinarySearchTree(tree,tree[node].left,Min, tree[node].key) &&
        IsBinarySearchTree(tree, tree[node].right, tree[node].key,Max ))
    {
        return true;
    }
    else {
        return false;
    }
}
bool Check(const vector<Node>& tree) {
    if (tree.size()==0)
    {
        return true;
    }
    return IsBinarySearchTree(tree, 0, INT_MIN, INT_MAX);
}
int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (Check(tree)){
        cout << "CORRECT" << endl;
    }
    else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}

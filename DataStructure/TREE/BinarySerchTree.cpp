#include <iostream>
#include<queue>
using namespace std;
struct BinarySerchTreeNode {
    int  key;
    struct BinarySerchTreeNode* left{};//左節點
    struct BinarySerchTreeNode* right{};//右節點
};
void insertNode(BinarySerchTreeNode*& root, const int& k) {
    if (root == nullptr) {
        root = new BinarySerchTreeNode;
        root->key = k;
        root->left = nullptr;//空節點(左)
        root->right = nullptr;//空節點(右)
    }
    else {
        if (k < root->key)
            insertNode(root->left, k);//儲存至左節點
        else
            insertNode(root->right, k);//儲存至右節點XDA
    }
}
void printInoderTree(BinarySerchTreeNode* n) {//inorder
    if (n != nullptr) {
        printInoderTree(n->left);
        cout << n->key << "; ";//輸出key
        printInoderTree(n->right);
    }
}
void printPreorderTree(BinarySerchTreeNode* n) {//preorder
    if (n != nullptr) {
        cout << n->key << "; ";//輸出key
        printPreorderTree(n->left);
        printPreorderTree(n->right);
    }
}
void printPostorderTree(BinarySerchTreeNode* n) {//postorder
    if (n != nullptr) {
        printPostorderTree(n->left);
        printPostorderTree(n->right);
        cout << n->key << "; ";//輸出key     
    }
}
void printLevelorderTree(BinarySerchTreeNode* n) {//levelorder
    queue <BinarySerchTreeNode*> q;//C++ queue函式
    BinarySerchTreeNode* item;
    q.push(n);
    while (!q.empty()) {
        item = q.front(); 
        cout << item->key << "; ";
        if (item->left != NULL) //若左節點不為空 push
            q.push(item->left);
        if (item->right != NULL) //若右節點不為空 push
            q.push(item->right);
        q.pop();//已push的pop出去直到為空
    }
}
int main() {
    int v1[12] { 10, 6, 8, 7, 15, 3, 9, 13, 12, 5, 14, 16 };//元素
    BinarySerchTreeNode* root = nullptr;//設定節點為空
    for (const auto& item : v1) {
        insertNode(root, item);
    }
    cout << "Inorder" << endl;
    printInoderTree(root); cout << endl;
    cout << "Preorder" << endl;
    printPreorderTree(root); cout << endl;
    cout << "Postorder" << endl;
    printPostorderTree(root); cout << endl;
    cout << "Levelorder" << endl;
    printLevelorderTree(root);
}

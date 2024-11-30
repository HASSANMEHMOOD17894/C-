#include <iostream>
#include <cmath>
#define COUNT 10
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree {
private:
    Node* root;

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == NULL) return root;

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void print2DUtil(Node* root, int space) {
        if (root == NULL) return;

        space += COUNT;
        print2DUtil(root->right, space);
        cout << endl;
        for (int i = COUNT; i < space; i++) cout << " ";
        cout << root->data << "\n";
        print2DUtil(root->left, space);
    }

    bool isFullBinaryTree(Node* root) {
        if (root == NULL) return true;
        if ((root->left == NULL && root->right != NULL) ||
            (root->left != NULL && root->right == NULL))
            return false;
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    int depth(Node* node) {
        int d = 0;
        while (node != NULL) {
            d++;
            node = node->left;
        }
        return d;
    }

    bool isPerfectR(Node* root, int d, int level = 0) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return (d == level + 1);
        if (root->left == NULL || root->right == NULL) return false;
        return isPerfectR(root->left, d, level + 1) &&
               isPerfectR(root->right, d, level + 1);
    }

    bool checkComplete(Node* root, int index, int numberNodes) {
        if (root == NULL) return true;
        if (index >= numberNodes) return false;
        return checkComplete(root->left, 2 * index + 1, numberNodes) &&
               checkComplete(root->right, 2 * index + 2, numberNodes);
    }

    int countNumNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNumNodes(root->left) + countNumNodes(root->right);
    }

    bool checkHeightBalance(Node* root, int& height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int leftHeight = 0, rightHeight = 0;
        bool l = checkHeightBalance(root->left, leftHeight);
        bool r = checkHeightBalance(root->right, rightHeight);
        height = max(leftHeight, rightHeight) + 1;
        if (abs(leftHeight - rightHeight) >= 2) return false;
        return l && r;
    }

public:
    Tree() {
        this->root = NULL;
    }

    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
        } else {
            insert(root, value);
        }
    }

    void insert(Node* node, int value) {
        if (value < node->data) {
            if (node->left == NULL) {
                node->left = new Node(value);
            } else {
                insert(node->left, value);
            }
        } else {
            if (node->right == NULL) {
                node->right = new Node(value);
            } else {
                insert(node->right, value);
            }
        }
    }

    void preorderTraversal(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(Node* node) {
        if (node == NULL) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == NULL) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void print2D() {
        print2DUtil(root, 0);
    }

    void checkTreeType() {
        int totalNodes = countNumNodes(root);
        int height = 0;
        cout << "Tree Type(s): ";
        if (isFullBinaryTree(root)) cout << "\nFull Binary Tree";
        if (isPerfectR(root, depth(root))) cout << "\nPerfect Binary Tree";
        if (checkComplete(root, 0, totalNodes)) cout << "\nComplete Binary Tree";
        if (checkHeightBalance(root, height)) cout << "\nBalanced Binary Tree";
        cout << endl;
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    Tree newTree;
    int choice = 1, value;

    while (choice != 0) {
        cout << "\n1: Insert\n2: Preorder Traversal\n3: Inorder Traversal\n4: Postorder Traversal";
        cout << "\n5: Print Tree\n6: Delete Node\n7: Check Tree Type\n0: Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                newTree.insert(value);
                break;
            case 2:
                newTree.preorderTraversal(newTree.getRoot());
                cout << endl;
                break;
            case 3:
                newTree.inorderTraversal(newTree.getRoot());
                cout << endl;
                break;
            case 4:
                newTree.postorderTraversal(newTree.getRoot());
                cout << endl;
                break;
            case 5:
                newTree.print2D();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                newTree.deleteNode(value);
                break;
            case 7:
                newTree.checkTreeType();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

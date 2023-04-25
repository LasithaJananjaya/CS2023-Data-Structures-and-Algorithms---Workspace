#include <iostream>

using namespace std;

//Creating the node structure
struct node {
  int key;
  struct node * LEFT;
  struct node * RIGHT;
};

//Function to create a node
struct node * createNode(int value) {
  struct node * temp = (struct node * ) malloc(sizeof(struct node));
  temp -> key = value;
  temp -> LEFT = temp -> RIGHT = NULL;
  return temp;
}

// Inorder traversal
void traverseInOrder(struct node * root) {

  if (root != NULL) {

    traverseInOrder(root -> LEFT);
    cout << root -> key << " ";
    traverseInOrder(root -> RIGHT);
  }
}

// Insert a node
struct node * insertNode(struct node * node, int key) {

  // If the tree is empty, create a new node as the root
  if (node == NULL)
    return createNode(key);

  // Otherwise, recur down the tree

  if (key < node -> key) {

    node -> LEFT = insertNode(node -> LEFT, key);
  } else if (key > node -> key) {
    node -> RIGHT = insertNode(node -> RIGHT, key);
  }

  // Return the unchanged node pointer
  return node;
}

// Deleting a node
struct node * deleteNode(struct node * root, int key) {
  // Base case: checking whether the tree is empty
  if (root == NULL) {
    return root;
  }

  // Otherwise, recur down the tree
  if (key < root -> key) {

    root -> LEFT = deleteNode(root -> LEFT, key);
  } else if (key > root -> key) {

    root -> RIGHT = deleteNode(root -> RIGHT, key);

  } else { // If the key matches with the root

    // Case 1: If the node has no children
    if (root -> LEFT == NULL && root -> RIGHT == NULL) {
      delete root;
      root = NULL;
    }

    // Case 2: If the node has one child
    else if (root -> LEFT == NULL) {
      struct node * temp = root;
      root = root -> RIGHT;
      delete temp;
    } else if (root -> RIGHT == NULL) {
      struct node * temp = root;
      root = root -> LEFT;
      delete temp;
    }

    // Case 3: If the node has two children
    else {
      struct node * temp = root -> RIGHT;
      while (temp -> LEFT != NULL) {
        temp = temp -> LEFT;
      }
      root -> key = temp -> key;
      root -> RIGHT = deleteNode(root -> RIGHT, temp -> key);
    }
  }

  // Return the unchanged node pointer
  return root;
}

// Driver code
int main() {
  struct node * root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch (operation) {
    case 1: // insert
      cin >> operand;
      root = insertNode(root, operand);
      cin >> operation;
      break;
    case 2: // delete
      cin >> operand;
      root = deleteNode(root, operand);
      cin >> operation;
      break;
    default:
      cout << "Invalueid Operator!\n";
      return 0;
    }
  }

  traverseInOrder(root);
}
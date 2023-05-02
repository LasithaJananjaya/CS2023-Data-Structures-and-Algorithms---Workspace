#include <iostream>

using namespace std;

//----------------------------------------------Nodes--------------------------------------
struct node {
  int key;
  struct node * LEFT;
  struct node * RIGHT;
};

//-------------------------------------------Create------------------------------------------
struct node * createNode(int value) {
  struct node * temp_var = (struct node * ) malloc(sizeof(struct node));
  temp_var -> key = value;
  temp_var -> LEFT = temp_var -> RIGHT = NULL;
  return temp_var;
}

void traverseInOrder(struct node * root_value) {

  if (root_value != NULL) {

    traverseInOrder(root_value -> LEFT);
    cout << root_value -> key << " ";
    traverseInOrder(root_value -> RIGHT);
  }
}

//----------------------------------------Insert-----------------------------------------
struct node * insertNode(struct node * node, int key) {

  if (node == NULL)
    return createNode(key);

  if (key < node -> key) {

    node -> LEFT = insertNode(node -> LEFT, key);
  }
  
  else if (key > node -> key) {
    node -> RIGHT = insertNode(node -> RIGHT, key);
  }

  return node;
}

//------------------------------------------Delete----------------------------------------------------
struct node * deleteNode(struct node * root_value, int key) {
  if (root_value == NULL) {
    return root_value;
  }

  if (key < root_value -> key) {

    root_value -> LEFT = deleteNode(root_value -> LEFT, key);
  }
  
  else if (key > root_value -> key) {

    root_value -> RIGHT = deleteNode(root_value -> RIGHT, key);

  }
  
  else {
    if (root_value -> LEFT == NULL && root_value -> RIGHT == NULL) {
      delete root_value;
      root_value = NULL;
    }

    else if (root_value -> LEFT == NULL) {
      struct node * temp_var = root_value;
      root_value = root_value -> RIGHT;
      delete temp_var;

    }
    
    else if (root_value -> RIGHT == NULL) {
      struct node * temp_var = root_value;
      root_value = root_value -> LEFT;
      delete temp_var;
    }

    else {
      struct node * temp_var = root_value -> RIGHT;
      while (temp_var -> LEFT != NULL) {
        temp_var = temp_var -> LEFT;
      }

      root_value -> key = temp_var -> key;
      root_value -> RIGHT = deleteNode(root_value -> RIGHT, temp_var -> key);
    }
  }

  return root_value;
}

int main() {
  struct node * root_value = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {

    switch (operation) {

    case 1:
      cin >> operand;
      root_value = insertNode(root_value, operand);
      cin >> operation;
      break;

    case 2:
      cin >> operand;
      root_value = deleteNode(root_value, operand);
      cin >> operation;
      break;

    default:
      cout << "Invalid!\n";
      return 0;
    }
  }

  traverseInOrder(root_value);
}
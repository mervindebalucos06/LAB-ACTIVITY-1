#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList {
private:
    Node *head;

    public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value){
      Node *newNode = new Node;
      newNode->data = value;
      newNode->next = head;
      head = newNode;
      cout << "Inserted " << value << " at the beginning." << endl;
    }

    void insertAtEnd(int value){
      Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end." << endl;
    }

    void insertAfter(int key, int value){
      Node *temp = head;
      while (temp != nullptr && temp->data != key){
        temp = temp->next;
      }

      if (temp == nullptr){
        cout << key << "not found in the list." << endl;
      } else {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << "." << endl;
      }
    }

    void deleteNode(int value) {
      Node *temp = head;
      Node *prev = nullptr;

      while (temp != nullptr && temp->data != value){
        prev = temp;
        temp = temp->next;
      }

      if (temp == nullptr){
        cout << value << " not found in the list. " << endl;
      } else {
        if  (prev == nullptr){
          head = temp->next;
        } else {
          prev->next = temp->next;
        }
        delete temp;
        cout << "Deleted node with value " << value << "." << endl;
      }
    }

    void printList(){
      int index = 1;
      Node *temp = head;
      cout << "Linked list: " << endl;
      while (temp != nullptr){
        cout << "[" << index << "]" << ": " << temp->data << "\n";
        temp = temp->next;
        index++;
      }
      cout << endl;
    }
};

int main(){
  LinkedList list;

  while (true){
    cout << "\nMenu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a value" << endl;
        cout << "4. Delete a node" << endl;
        cout << "5. Print the list" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
          case 1: {
            int value;
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
                    }
          case 2: {
            int value;
            cout << "Enter value to insert at the end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
                    }
          case 3: {
            int key, value;
            cout << "Enter value to insert after: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAfter(key, value);
            break;
          }
          case 4: {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
                    }
          case 5:
            list.printList();
            break;

          case 6:
            cout << "Exiting program." << endl;
            return 0;
          default:
            cout << "Invalid choice. Please try again. " << endl;
        }
  }

  return 0;
}
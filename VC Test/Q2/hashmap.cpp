#include<bits/stdc++.h>
using namespace std;
 
template<class T1>
class Node {
public:
    T1 data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = {};
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  
// Linked list class to
// implement a linked list.
template <class T1>
class Linkedlist {
    Node<T1>* head;
  
public:
    // Default constructor
    Linkedlist() { head = NULL; }
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(T1 data)
{
    // Create the new Node.
    Node* newNode = new Node(data);
  
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}
  
    // Function to print the
    // linked list.
    // void printList();
  
    // Function to delete the
    // node at given position
    void deleteNode(T1 delval)
{
    Node<T1>*temp1 = head, *temp2 = head;
    if(temp2->data == delval){
        delete temp2;
        return;
    }
    temp2 = temp->next;
    while (temp2 != NULL) {
        if(temp2->data == delval){
            temp1->next = temp2->next;
            delete temp2;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
        }
    }
};

template<class T1, class T2>
class Hash
{
    int BUCKET;    // No. of buckets
 
    // Pointer to an array containing buckets
    node<T2> *table;
public:
    Hash()
    {
        this->BUCKET = 10007;
        table = new node<T1>[BUCKET];
    }
    // inserts a key into hash table
    vinsertItem(T1 key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    // deletes a key from hash table
    void deleteItem(int key);
 
    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }
 
    void displayHash();
};
 

 
void Hash::deleteItem(int key)
{
  // get the hash index of key
  int index = hashFunction(key);
 
  // find the key in (index)th list
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }
 
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}
 
// function to display hash table
void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}
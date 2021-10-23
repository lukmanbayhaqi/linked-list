// C++ implementation to insert node at the middle
// of the linked list
#include <bits/stdc++.h>

using namespace std;

// structure of a node
struct Node
{
  int data;
  Node *next;
};

// function to create and return a node
Node *getNode(int data)
{
  // allocating space
  Node *newNode = (Node *)malloc(sizeof(Node));

  // inserting the required data
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// function to insert node at the middle
// of the linked list
void insertAtMid(Node **head_ref, int x)
{
  // if list is empty
  if (*head_ref == NULL)
    *head_ref = getNode(x);

  else
  {
    // get a new node
    Node *newNode = getNode(x);

    // assign values to the slow and fast
    // pointers
    Node *slow = *head_ref;
    Node *fast = (*head_ref)->next;

    while (fast && fast->next)
    {

      // move slow pointer to next node
      slow = slow->next;

      // move fast pointer two nodes at a time
      fast = fast->next->next;
    }

    // insert the 'newNode' and adjust the
    // required links
    newNode->next = slow->next;
    slow->next = newNode;
  }
}

// function to display the linked list
void display(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

// Driver program to test above
int main()
{
  // Creating the list 1->2->4->5
  Node *head = NULL;
  head = getNode(1);
  head->next = getNode(2);
  head->next->next = getNode(4);
  head->next->next->next = getNode(5);

  cout << "Linked list before insertion: ";
  display(head);

  int x = 3;
  insertAtMid(&head, x);

  cout << "\nLinked list after insertion: ";
  display(head);

  return 0;
}
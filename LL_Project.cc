#include <iostream>
#include <cstdlib>
using namespace std;


struct node
{
  string names;
  node *next;
};

// FUNCTIONS START

bool isEmpty(node *head)
{
  if(head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }

}

char menu()
{
  char choice;
  cout << "Menu: " << endl;
  cout << "1. Add Item:" << endl;
  cout << "2. Remove Item:" << endl;
  cout << "3. Show List:" << endl;
  cout << "4. Exit:" << endl;

  cin >> choice;

  return choice;

}

void insertAsFirstElement(node *&head, node *&last, string names)
{
  node *temp = new node;
  temp -> names = names;
  temp -> next = NULL;
  head = temp;
  last = temp;

}

void insert(node *&head, node *&last, string names)
{
  if(isEmpty(head))
  {
    insertAsFirstElement(head, last, names);
  }
  else
  {
    node *temp = new node;
    temp -> names = names;
    temp -> next = NULL;
    last -> next = temp;
    last = temp;
  }

}

void remove(node *&head, node *&last)
{
  if(isEmpty(head))
  {
    cout << "The list is empty..." << endl;
  }
  else if (head == last)
  {
    delete head;
    head == NULL;
    last == NULL;
  }
  else
  {
    node *temp = head;
    head = head -> next;
    delete temp;

  }

}

void showList(node *current)
{
  if(isEmpty(current))
  {
    cout << "The list is empty..." << endl;
  }
  else
  {
    cout << "The list contains: " << endl;
    while(current != NULL)
    {
      cout << current -> names << endl;
      current = current -> next;
    }
  }

}

// FUNCTIONS FINISH




int main()
{
  node *head = NULL;
  node *last = NULL;
  char choice;
  string names;

  do
  {
    choice = menu();
    switch(choice)
    {
    case '1': cout << "Enter information: " << endl;
              cin >> names;
              insert(head, last, names);
              break;

    case '2': remove(head, last);
              break;

    case '3': showList(head);
              break;
    default: cout << "System exit\n";
    }
  }
  while(choice != '4');

  return 0;
}

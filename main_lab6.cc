/*********************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Spring 2014
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

struct node
{
     int data;
     node * link;
};

// These are the three I have written for you
void build_list(node* & head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);

//These are the two that you are to write, as described in the 
//instructions page.
void remove_repeats(node*& head);
void split_list(node* original, node*& lesser, node*& greater,int split_value);
void show_list2(const node* head);



int main()
{
    int start, stop;
    int split;
    node* head = NULL;
    node *lesser;
    node * greater;

    start = time(NULL);
    build_list(head);
    remove_repeats(head);
    stop = time(NULL);
    cout << "Time to build list = " << stop - start << "seconds.\n";
    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << "seconds.\n";
    cout << "Size of the list = " << size(head) << endl << endl;

    cout << "Please enter a number where to split the list: ";
    cin >> split;
    split_list(head, lesser, greater, split);
    show_list2(lesser);
    cout << "Size of Lesser list = " << size(lesser) - 1 << endl;

     show_list2(greater);
     cout << "Size of Greater list = " << size(greater) - 1 << endl;



return 0;
}

// builds a linked list of 2000 random integers, all in the 1 to 500 range
void build_list(node*& head)
{
     node* cursor;
     head = new node;
     head->data = rand()%500 + 1;
     cursor = head;

     for(int i = 0; i < 2000; ++i)
     {
	     cursor->link = new node;
          cursor = cursor->link;
          cursor->data = rand()%500 + 1;
     }
     cursor->link = NULL;
}

void remove_repeats(node*& head)
{
     node *previous = nullptr;
     node *current = head;

     unordered_set<int> set;

     while(current != nullptr)
     {
          if(set.find(current->data) != set.end())
          {
               previous -> link = current -> link;
          }
          else{
               set.insert(current -> data);
               previous = current;
          }
          current = previous -> link;
     }
}

void split_list(node* original, node*& lesser, node*& greater,int split_value)
{
     node* it =  new node;
     lesser = it;

     for (node* tmp = original; tmp != NULL; tmp = tmp->link){
          
          it->data = tmp->data;
          it->link = new node;
          it = it->link;
          it->link = NULL;

          if (tmp->data == split_value){
               it = new node;
               greater = it;
               
          }
     }
}

// outputs the contents of a linked list to the screen
void show_list(const node* head)
{
     const node * cursor = head;
     while(cursor !=  NULL)
     {
          cout << cursor -> data << "  ";
          cursor = cursor -> link;
     }
     cout << endl;
}

void show_list2(const node* head)
{
     const node * cursor = head;
     while(cursor->link !=  NULL)
     {
          cout << cursor -> data << "  ";
          cursor = cursor -> link;
     }
     cout << endl;
}

// returns the number of nodes in a linked list
int size(const node* head)
{
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL)
     {
  	    count++;
	    cursor = cursor->link;
	}
	return count;
}

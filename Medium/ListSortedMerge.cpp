/*
Merge Sorted linked lists into one linked list.
*/
#include <iostream>

using namespace std;
//RECURSIVE SOLUTION.
struct node {
    int data;
    struct node* next;
}
//Recursive solution
struct node* sortedMerge_recur(struct node* a , struct node* b)
{
    struct node* result = NULL;
    if(a == NULL)
       return a;
    if(b == NULL)
       return b;
    if(a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge_recur(a->next,b);
    }
    else
    {
        result = b;
        result->next = sortedMerge_recur(a,b->next);
    }
    return result;
}

  //Iterative Solution
  struct node* sortedMerge_iter(struct node* a , struct node* b)
  {
    //Initialize result to the smaller of the values
    struct node* result, head;
    if(a->data <= b->data)
    {
      result = a;
      head = result;
      a = a-> next;
    }
    else{
      result = b;
      head = resutl;
      b = b->next;
    }

    while(a != NULL || b != NULL)
    {
      if(a->data <= b->data)
      {
        result->next = a;
        a = a->next;
      }
      else{
        result->next = b;
        b = b->next;
      }
      result = result->next;
    }
    while (a != NULL)
      result-> = a;
    while (b != NULL)
      result->next = b;

  return head;
  }
int main()
{

   return 0;
}

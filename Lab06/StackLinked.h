/*
* Name: Isaac Ephrem and Joshua Norman                                                                    
*  Date: 2-27-16 
* Assignment: Lab 6                                                         
*/
#if !defined (STACKLINKED_H)
#define STACKLINKED_H

#include "NextNode.h"

template < class T >
class StackLinked
{
   private:
      NextNode<T>* top;
      int sze;  // number of items in the stack

   public:
      StackLinked();
      ~StackLinked();
      bool isEmpty();
      int size();
      void popAll();
      T* pop();
      void push(T* item);
      T* peek();
};

template < class T >
StackLinked<T>::StackLinked()
{
   top = NULL;
   sze = 0;
}

template < class T >
StackLinked<T>::~StackLinked()
{
   popAll();
}

template < class T >
bool StackLinked<T>::isEmpty()
{
   return sze == 0;
}

template < class T >
int StackLinked<T>::size()
{
   return sze;
}

template < class T >
void StackLinked<T>::popAll()
{
   //loop over the stack, deleting the nodes
   //the actual items are not deleted
   if (sze == 0) return;

   NextNode<T>* curr = top;
   NextNode<T>* prev = NULL;
   while (curr != NULL)
   {
      prev = curr;
      curr = curr->getNext();
      prev->setNext(NULL);
      delete prev;
   }
}

template < class T >
T* StackLinked<T>::peek()
{
   T* item = NULL;

   //DO THIS
   if (isEmpty())
   {
        return NULL;
   }

   return top->getItem();
}

template < class T >
void StackLinked<T>::push(T* item)
{
   //DO THIS
	NextNode<T>* front = new NextNode<T>(item);
    front->setNext(top);

    top = front;

    ++sze;
}

template < class T >
T* StackLinked<T>::pop()
{
   if (sze == 0) return NULL;

   //DO THIS
	T* item = top->getItem();
    NextNode<T>* del = top;

    top = del->getNext();

    delete del , del = NULL;

    --sze;

    return item;
}

#endif
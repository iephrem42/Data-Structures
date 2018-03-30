#if !defined (QUEUELINKED_H)
#define QUEUELINKED_H

#include "NextNode.h"
using CSC2110::NextNode;

namespace CSC2110
{
template < class T >
class QueueLinked
{

   private:
      NextNode<T>* back;
      int sze;

   public:
      QueueLinked();
      ~QueueLinked();
      bool isEmpty();
      int size();
      void dequeueAll(); 
      T* peek();
      T* dequeue();
      void enqueue(T* item);

};

template < class T >
QueueLinked<T>::QueueLinked()
{
   back = NULL;
   sze = 0;
}

template < class T >
QueueLinked<T>::~QueueLinked()
{
   dequeueAll();
}

template < class T >
void QueueLinked<T>::enqueue(T* item)
{
    NextNode<T>* node = new NextNode<T>(item);

    //insert the new node
    if (isEmpty()) 
    {
      // insertion into empty queue
      node->setNext(node);
    }
    else 
    {
      // insertion into nonempty queue
      node->setNext(back->getNext());
      back->setNext(node);
    }  

    tail = node;  //new node is at back
    sze++;
}

template < class T >
bool QueueLinked<T>::isEmpty()
{
    return sze == 0;
}

template < class T >
int QueueLinked<T>::size()
{
    return sze;
}

template < class T >
void QueueLinked<T>::dequeueAll()
{
   if (sze == 0) return;

   NextNode<T>* prev = NULL;
   NextNode<T>* curr = tail->getNext();  //the head
   back->setNext(NULL);  //break the bridge link

   while (curr != NULL)
   {
      prev = curr;
      curr = curr->getNext();
      delete prev;
   }
}

template < class T >
T* QueueLinked<T>::peek()
{
    T* item = NULL;
    if (!isEmpty()) 
    {  
      // queue is not empty; retrieve front
      NextNode<T>* head = back->getNext();
      item = head->getItem();
    }
    return item;
}

template < class T >
T* QueueLinked<T>::dequeue()
{
    T* item = NULL;

    if (!isEmpty()) 
    {
      // queue is not empty; remove front
      NextNode<T>* head = back->getNext();
      item = head->getItem();

      if (head == back) 
      {  
        // one node in queue
        tail->setNext(NULL); 
        tail = NULL;        
      }
      else 
      {
        back->setNext(head->getNext());
      }  

      delete head;
      sze--;
    }

    return item;
}
}

#endif

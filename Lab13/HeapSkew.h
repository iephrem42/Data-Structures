#if !defined HEAPSKEW_H
#define HEAPSKEW_H

#include "BinaryTree.h"
#include "wx/wx.h"

template < class T >
class HeapSkew : public Drawable
{

   private:
      BinaryTree<T>* bt;
      int sze;
      BinaryTree<T>* merge(BinaryTree<T>* left, BinaryTree<T>* right);

      int (*compare_items) (T* item_1, T* item_2);

   public:
      HeapSkew(int (*comp_items) (T* item_1, T* item_2));
      ~HeapSkew();

      bool heapIsEmpty();
      void heapInsert(T* item);
      T* heapRemove();

      void draw(wxDC& dc, int width, int height);
      void mouseClicked(int x, int y);

};

// this is a MAXHEAP (largest items to top alphabetical order)
template < class T >
HeapSkew<T>::HeapSkew(int (*comp_items) (T* item_1, T* item_2)) : Drawable()
{ 
   bt = new BinaryTree<T>();
   sze = 0;

   compare_items = comp_items;
}

template < class T >
HeapSkew<T>::~HeapSkew() 
{ 
   delete bt;
}  

template < class T >
bool HeapSkew<T>::heapIsEmpty()
{
   return sze == 0;
}

template < class T >
BinaryTree<T>* HeapSkew<T>::merge(BinaryTree<T>* left, BinaryTree<T>* right)
{
  //DO THIS
  bool leftEmpty = left->isEmpty();
  bool rightEmpty = right->isEmpty();

  T* left_root = left->getRootItem();
  T* right_root = right->getRootItem();

  //DO THIS
  //If left is empty, the merge method simply returns right, and if right is empty, return left.
 if(leftEmpty)
  {
	  return right;
  }
  else if(rightEmpty);
  {
	  return left;
  }
  //If the item in left's root is smaller than the item in right's root, call merge recursively with the order of the BinaryTrees reversed.
  else if(left_root < right_root)
  {
	  left = merge(right, left);
  }
  
  //Detach left's left subtree (call it LL) and detach left's right subtree (call it LR).
  BinaryTree<T>* LL = left->detachLeftSubtree();
  BinaryTree<T>* LR = right->detachRightSubtree();

  //Attach LL to left's right.
  left->getRight()->attachLeftSubtree(LL);

  //If LR is empty, attach right to left's left and return left.
  if(LR->heapIsEmpty())
  {
	left->getLeft()->attachRightSubtree(right);
  }
  else
  {
	left = left->getLeft()->attachRightSubtree(merge(LR, right);)
	return left;
  }
	

	
}

template < class T >
void HeapSkew<T>::heapInsert(T* item)
{
   //DO THIS (calls merge, should be short)
	BinaryTree<T>* right = new BinaryTree(item);
	bt = merge(bt, right);
	sze++;
}

template < class T >
T* HeapSkew<T>::heapRemove()
{
   //DO THIS (calls merge, should be short)
   BinaryTree<T>* left = bt -> detachLeftSubtree();
   BinaryTree<T>* right = bt -> detachRightSubtree();

   T* result = bt -> getRootItem();
   delete bt;
   bt = merge(left, right);

   sze--;
   return result;
}

template < class T >
void HeapSkew<T>::draw(wxDC& dc, int width, int height)
{
   bt->draw(dc, width, height);
}

template < class T >
void HeapSkew<T>::mouseClicked(int x, int y) {bt->mouseClicked(x, y);}

#endif

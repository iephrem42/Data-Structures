#include "SortedListLinked.h"
#include "CD.h"
using CSC2110::CD;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include <iostream>
using namespace std;

void addCDs(ListArray<CD>* list, SortedListLinked<CD>* lb)
{
   ListArrayIterator<CD>* iter = list->iterator();

   //DO THIS
   //iterate over and add the cds to the list box (use lb->addItem)
	while (iter->hasNext())
	{
		lb->add(iter->next());
	}
   delete iter;
}

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   //DO THIS  
   //iterate over and delete the cds
   //SortedListLinked<CD>* item;

   int sz = list->size();

   for (int i = sz; i > 0; i--)
   {
	   list->remove(i);
   }

   delete iter;
}

int main(int argc, char* argv[])
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   //DO THIS
   //create and test the sorted linked list 
	SortedListLinked<CD>* lb = new SortedListLinked<CD>(&CD::compare_items);
	
	addCDs(cds, lb);
	
	ListLinkedIterator<CD>* sl_iter = lb->iterator();
	CD* cd;
	/*while (sl_iter->hasNext())
	{
		cd = sl_iter->next();
		cd->displayCD();
	}*/
	
	for (int i = 4; i < 7; i++)
	{
		cd = lb->get(i);
		cd->displayCD();
	}
	
	cd = lb->get(5);
	lb->remove(cd);
	
	CD* removed = cd;
	
	
	for (int i = 4; i < 7; i++)
	{
		cd = lb->get(i);
		cd->displayCD();
	}
	
	lb->remove(removed);
	
	lb->add(removed);
	
	cd = lb->get(5);
	cd->displayCD();

	
	
	deleteCDs(cds);


   return 0;
}

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
		if (((*compare_items) (lb, list)) > 0)
		{
			lb->add(lb);
			break;
		}
	}
   delete iter;
}

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();
   
   //DO THIS  
   //iterate over and delete the cds
   
   SortedListLinked<CD>* item;
   
   while (iter->hasNext())
   {
	   item->remove(item);
   }
   delete iter;
}

int main(int argc, char* argv[])
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   //DO THIS
   //create and test the sorted linked list 
   ListArrayIterator<CD>* iter = list->iterator();
   
	SortedListLinked<CD>* sl = new SortedListLinked;
	CD* cd;
	
	int sz = sl->size();
	cout << "Size before the add: " << sz << endl;
	
	int i = 0;
	
	while (iter->hasNext())
	{
		sl->add(cds->get(i));
	}
	
	sz = sl->size();
	cout << "Size after the add: " << sz << endl;
	


   return 0;
}

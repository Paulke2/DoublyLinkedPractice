/*
 * DLL.cpp
 *
 *      Author: 13027
 */
//Part 1:(20 pts) (addFirst (3pts) ,addAtFront(4 pts),push (4 pts),pop(4 pts)) + getting secret message:5 pts
//In the DLL.cpp class, get push, pop, and addFirst and addAtFront working for a doubly linked list as specified in DLL.hpp and DLL.cpp.
//For this section I've given you the test cases.  You should get the output I've given you for part 1. When you get those methods working, running this will decode the secret code 1
//
//Once you have that working, start on part 2 (note you will have to go into Coder.cpp and toggle
//comments for lines 64-110 to run part 2)
//
//Part 2: (15 pts)(insertAt(5 pts), removeAtK(5 pts)) +secret message: 5 pts
//Get  the DLL.cpp methods insertAt and removeAtK methods working for a doubly linked list.
//I've given you the test cases and the output.  When you get them working, you should be able to run this and decode the second secret code
//
//Once you have that working, start on part 3 (note that you will have to go to Coder.cpp and toggle comments for lines 112-137 to run part 3)
//
//Part 3: (8 pts) (reverse (4 pts)) + secret message: 4 pts
//For this part, you will get the method reverse working for the DLL doubly linked list class.
//This method reverses the list.  Note: it doesn't just print out the list in reverse order, it actually reverses the list, so if the original list was 3<->2<->4<->8, with 3 being first and 8 being last, the reversed list would be 8<->4<->2<->3 with 8 being first and 3 being last.
//
//once you have that working, start on part 4 (note that you will have to go to Coder.cpp and toggle
//comments for lines 139-215 to run part 4)
//
//Part 4: (11 pts) (removeX (5 pts), call by pointer) + secret message: 6 pts
//For this part, you will get the method removeX to work.  removeX removes the value x from the linked list, and uses call by pointer to change the index parameter to be the index (count) of where x occurred in the list.  So, for instance if you had:
//7<->8<->3<->5<->2<->6<->1
//And you called: removeX(3,&ind)
//When  you leave the method, you’d have
//7<->8<->5<->2<->6<->1
//And ind would hold 2
//
//Once you have this working, start on part 5.  For this you will have to go to Coder.cpp and toggle comments for lines  217- 251
//
//Part 5: (21 pts)(skip – recursive (13 pts) + secret message: 8 pts
//For this part, you will get the method skip working for the DLL doubly linked list class. This method RECURSIVELY deletes every other node.  If the boolean flag is set to true, it will delete every even node (i.e.,if the list was
//3<->2<->4<->5<->1<->7,
//the list that would result after the skip method was called would be:
//3<->4<->1.
//If the flag is set to false, the resulting list will be
//2<->5<->7
//NOTE:  For efficiency's sake, this method SHOULD NOT call removeAtK



#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DLL::DLL(){  // constructor - initializes an empty list
	last = NULL;
	first = NULL;
	size = 0;
}
DLL::DLL(int x){  // constructor, initializes a list with one new node with data x
	DNode *n = new DNode (x);
	first = n;
	last = n;
	size=1;
}
/***************************************************************************************************/
/*Part 1																																		*/
/***************************************************************************************************/
//	A PUSH adds to the end of the list

//	A POP operation is the reverse of the above operation: Remove the node at the head of the list then extract the value from that node.
/* write push, pop, addAtFront */
void DLL::push(int x){

	DNode *n = new DNode(x);
	if(last==NULL){
		first=n;
		last=n;
		size++;
	}else{


	last->next=n;
	n->prev=last;
	last=n;
	size++;

}

}
int DLL::pop(){
	DNode *n = last;
    int temp = n->data;
	if(first==last){
		first=NULL;
		last=NULL;
		size--;
		return temp;
	}

	    last=last->prev;
	    delete n;
	    last->next=NULL;
	    size--;

	    return temp;

}
void DLL::addAtFront(int x){
	// add a new node to the beginning of the list
	DNode *n = new DNode (x);

	first->prev=n;
	n->next=first;
	first=n;
	size++;


}
void DLL:: addFirst(int x){
	// add the very first node to the list
	first = new DNode (x);
last=first;
size=1;
}
/***************************************************************************************************/
/*Part 2																																		*/
/***************************************************************************************************/
/* write insertAt, removeAtK  here */
//insert x at index ind


void DLL:: insertAt(int ind, int x){
	int count =0;
	DNode *n = new DNode (x);
	DNode *current =first;
	DNode *temp;

	while (count !=ind-1){
		if(ind==0){
			break;
		}
if(count<size){
		current=current->next;

}

		count++;
	}
if(current==last){
	current->next = n;
	last = n;
	last->prev=n;
	size++;
}
else if(ind!=0){
	temp=current->next;
	current->next=n;
	n->next=temp;
	n->prev=current;
	temp->prev=n;

//	temp = current->next;
//	current->next = n;
//	n->prev=current;
//	n->next=temp;
//	temp->prev=n;
	size++;

}else{

	n->next=first;
	first = n;

	size++;
}
}







int DLL::removeAtK(int ind){
	int count =0;
	DNode *current =first;
	DNode *t =first;
	if(ind==0){
		DNode *n = first;
		int da = n->data;
first=first->next;
current=NULL;
		delete n;
		size--;
		return da;
	}else if(ind==size-1){
		int da =last->data;
		last = last->prev;

		last->next=NULL;
		size--;
		return da;

	}
	while (count !=ind-1&&count<size-1){

		current=current->next;
		count++;
	}
	int temp = current->next->data;
	size--;
	//this is breaking the code but it is bc im am not deleting prev pointer
	t=current->next;
	current->next=current->next->next;

	current=current->next;
	current->prev=t->prev;
	t->next->next->prev=current;
	return temp;
}

/****************************************************************************************/
/* Part 3                                                                                                                       */
/****************************************************************************************/
/* write reverse here */
void DLL::reverse(){
	DNode *curr =first;
	DNode *temp=NULL;
	DNode *t =first;


	while(curr!=NULL){


		curr->prev = curr->next;
		curr->next = temp;
		temp=curr;
		curr = curr->prev;



}
	first=last;
	last=t;
}
/****************************************************************************************/
/* Part 4                                                                                                                       */
/****************************************************************************************/
/* write removeX here */
void DLL::removeX(int x, int *ind){
	//for some reason, it is not deleting 6. i think its b/c prev is still pointing to 6. need to get better delete method  line 241
	int count=0;
DNode *curr =first;

while(curr!=NULL){


		if(curr->data==x){
			if(curr->prev==NULL){
				curr=curr->next;
				curr->prev=NULL;
				size--;
				first=curr;
				*ind=count;
				break;
			}else{
			*ind=count;
			curr=curr->prev;
			curr->next=curr->next->next;
			curr=curr->next;
			curr->prev=curr->prev->prev;;
			//curr->prev=NULL;
			size--;
			break;
			}
		}
		count++;
		curr=curr->next;
	if(count==size-1){
		if(curr->data!=x){
		*ind=-1;
		//size--;
		break;
		}else{
			*ind=size-1;
			size--;
			last=last->prev;
			last->next=NULL;
			break;
		}
	}
	}

}
/****************************************************************************************/
/* Part 5                                                                                                                     */
/****************************************************************************************/
/* write skip here */ // removes every other node as follows:
//if the flag is true, the first, third, fifth, etc. nodes are removed
//if the flag is false, the second,fourth,sixth, etc. nodes are removed
void DLL::skip(bool flag){
	DNode *curr =first;
	if (flag==true){
		curr=curr->next;

	}
	while(curr->next!=NULL&&curr->next->next!=NULL){
		curr->next=curr->next->next;
		curr=curr->next;
		curr->prev=curr->prev->prev;
		size--;
	}
	if(flag==true){
		first=first->next;
		first->prev=NULL;
		size--;
	}
	if(curr->next==last&&flag==false){
		last = last->prev;
		last->next=NULL;
		size--;
	}
//	if(size%2==1&&flag==true){
//		last = last->prev;
//				last->next=NULL;
//				size--;
//	}

}




/***************************************************************************************************/
/*End of your part																														*/
/***************************************************************************************************/

void DLL::printList() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << ", ";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printCode() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << alpha[tmp->data];
		tmp = tmp->next;
	}
	cout << endl;
}
DLL::~DLL(){
	DNode *tmp = first;
	DNode *tmp2 = first->next;
	while (tmp != NULL) {
		delete tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
}




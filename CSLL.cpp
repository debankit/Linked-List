#include<iostream>
using namespace std;

class Node{

	public:
	int data;
	
	//pointer to the next Node
	Node * next;
	
	Node(){
		next = NULL;
	}
};

class Linkedlist{
	
	public:
	Node * head;
	Node * tail;
	
	Linkedlist(){
		head = NULL;
		tail = NULL;
	}
	
	//insert function
	void insert( int value){
	
		Node * temp = new Node;
		
		temp -> data = value;
		
		//1st node
		if(head == NULL){
			head = temp;
			tail = temp;
		}
		
		//for other node
		else{
			tail -> next = temp;
			tail = temp;
			tail -> next = head;
		}
		
	}
	
	void insertAt(int pos, int value){
		
		Node * temp = new Node;
		temp -> data = value;
		
		if(pos ==1){
			tail -> next = temp;
			temp -> next = head;
			head = temp;
		}
		else{
			//reach thr place before the pos
			Node * current = head;
			int i=1;
			while (i< pos-1){
				i++;
				current = current -> next;
			}
			temp -> next = current -> next;
			current -> next = temp;
		}
	}
	
	//deletion at last
	void delet(){
		Node * temp = tail;
		
		//reach the pos
		Node * current = head;
		while(current->next != tail){
			current = current -> next;
		} 
	
		current -> next = head;
		tail = current;
		delete temp;
	}
	
	//delete at position
	void deleteAt(int pos){
	
		Node * current = head;
		if (pos ==1){
			head = current -> next;
			delete current;		
		}	
		
		else{
			//reach the place before the pos
			int i=1;
			while(i < pos-1){
				i++;
				current = current -> next;
			}
			Node * temp = current ->next;
			current -> next = temp -> next;
			delete temp;
		}
	}
	
	//display
	void display(){
		Node * current = head;
		
		while(current != tail){
			cout << current -> data << "->";
			current = current -> next;
		} 
		cout << tail -> data <<endl;
	}
	
	// count items
	void countitems(){
		Node *current = head;
		int i=1;
		while(current != tail){
			i++;
			current= current->next;
		}
		cout<<"Number of items = "<< i <<endl;
	}
};

int main(){
	Linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insertAt(3,0);
	l1.display();
	l1.countitems();
	l1.delet();
	l1.deleteAt(2);
	l1.display();
	return 0;
}
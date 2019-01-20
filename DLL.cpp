#include<iostream>
using namespace std;

//Describe Node
class Node{
	public:
	
	//data
	int data;
	//forword pointer
	Node * next;
	//backword pointer
	Node * pre;
	
	//defalute constructor
	Node(){
		next = NULL;
		pre = NULL;
	}
};

//Double LinkList
class DLL{
	public:
	
	Node * head;
	Node * tail;

	//by defalte point head to NULL	
	DLL(){
		head = NULL;
	}
	
	// insert Node
	void insert(int value){
		
		//create new Node (temp pointing to that)
		Node * temp = new Node;
		temp -> data = value;	
		
		//for 1st node
		if(head == NULL){
			head = temp;
		}
		
		//for Other Node
		else{
			tail -> next = temp;
			temp -> pre = tail;
		}
		tail = temp;
	}
	
	//Display function
	void display(){
		Node * current = head;
		
		while(current != NULL){
			cout << current -> data << "->";
			current = current -> next;
		}
		cout << "NULL" <<endl;
	}
	
	//Display in rev order
	void revDis(){
		Node * current = tail;
		
		while(current != NULL){
			cout << current -> data << "->";
			current = current -> pre;
		}
		cout << "NULL " <<endl;
	}
	
	
	//function for insert at position
	void insertAt(int pos, int value){
		Node * temp = new Node;
		temp -> data = value;
		
		//for 1st position
		if(pos == 1){
			temp -> next = head;
			head -> pre = temp;
			head = temp;
		}
		
		//for other position
		else{
			Node * current = head;
			int i=0;
			//reach to pos
			while(i < pos-2){
				current = current -> next;
				i++;
			}
			//moving pointer
			temp -> next = current -> next;
			current -> next -> pre = temp;
			temp -> pre = current;
			current -> next = temp;
		}
	}
		
		//delete  last Node
		void delet(){
			Node * temp = tail;
			tail = temp -> pre;
			temp -> pre = NULL;
			tail -> next = NULL;
			delete temp;
		}
		
		//delete Node at pos
		void deleteAt(int pos){
			Node * current = head;
		
		//for 1st position
			if(pos == 1){
				head = head -> next;
				delete current;
			}
			
			//for other position
			else{
				int i=1;
				//reach the position
				while(i < pos -1){
					current = current -> next;
					i++;
				}
				Node * temp = current -> next;
				current -> next = current -> next -> next;
				current -> next -> pre = current;
				delete temp;
			}
		}
		
		void countItem(){
			Node * temp = head;
			int i=1;
			while(temp != NULL){
				temp = temp -> next;
				i++;
			}
			cout << "Elements " << i-1 <<endl;
		}
		
}l1;

int main(){
	l1.insert(10);
	l1.insert(20);
	l1.insert(30);
	l1.insert(40);
	l1.insertAt(3,0);
	l1.display();
	l1.countItem();
	l1.delet();
	l1.deleteAt(2);
	l1.display();
	l1.revDis();
	
}
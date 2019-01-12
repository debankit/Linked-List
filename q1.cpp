#include <iostream>
using namespace std;

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }

};

class LinkedList{
    // Head + Circles inside linked with each other
    public:
    // Head -> Node type ptr
    Node * head;
    Node * tail;

    // Construct
    LinkedList(){
        head = NULL;
        tail = NULL;
    } 
    // Circles inside linked with each other
    // Rules how circles will be linked

    // Insert
    void insert(int value){
       // If 1st Node is added
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL){
            head = temp;
       }
       // Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    } 

    void insertAt(int pos, int value){
	//if it is first position
	if(pos==1)
	{
		//creating a new node
		Node * temp= new Node;
		temp->data = value;
		//linking the new node to the 1st node
		temp->next= head;
		//pointing the head to the new node
		head= temp;
	
	}
	
	//for other positions
	else{	        

		// Reach the place before the pos
		Node * current = head;
		int i =1;
		while(i < pos-1){
		    i++;
		    current = current->next;
		    if(current == NULL)
			break;
		}
		if(current != NULL){
			// Create a node
			Node * temp = new Node;
			temp -> data = value;


			// Moving ptrs like magic ! if not head
			temp->next = current->next;
			current->next = temp;
		
		}
		else
			cout<<"Linked List does not have "<<pos<<" elements"<<endl;
	}

    }

    // Deletion of last element
    void delet(){
        // store the tail in temp
        Node * temp = tail;
        // before tail has to point to null
        Node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL; 

        // update tail
        tail = current;
        // delete temp
         delete temp;
    }

	//deleting a node from a particular position	
	void deletAt(int pos){
		Node * current = head;
		int i=1;
		while(i< pos-1){
			i++;
			current= current->next;
			if(current == NULL)
				break;		
		}
		if(current != NULL){
			Node *temp= current-> next;
			//linking the current node to the next 2nd node
			current->next= temp->next;
			delete temp;	
		}
		else
			cout<<"Linked List does not have "<<pos<<" position"<<endl;
	}
	// to count the number of items
	void countItems(){
		Node *current = head;
		int i=0;
		while(current != NULL){
			i++;
			current= current->next;
		}
		cout<<"Number of items= "<<i <<endl;
	}
    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout <<"NULL" << endl;
    }
};


int main(){
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insertAt(2,8);
	l1.insertAt(1,5);
	l1.insertAt(10,10);
	l1.delet();
	l1.deletAt(4);
	l1.display();
	l1.countItems();
	return 0;
}

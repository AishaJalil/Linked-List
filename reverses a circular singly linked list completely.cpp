#include<iostream>
using namespace std;

class Node
{
	
	public:
		
	int data;
	Node *next;
	
	
	Node()
	{
		data=0;
		next=0;
		
	}
	
	
	Node(int data)
	{
		this->data=data;
		this->next=0;
	}
	
};

class LinkedList
{
	
	public:
	Node *head;
	Node *tail;
	
	LinkedList()
	{
		head=0;
		tail=0;
	}
	
	LinkedList(Node *n)
	{
	    head=n;	
	}
	
	
	void Insert_Tail( int value)
	{
	
		Node *newNode, *temp;
		newNode= new Node(value);
		
		if(head==0)
		{
		    head=tail=newNode;
		}
		
		else
		{
			temp=tail;
			temp->next =newNode;
			newNode->next= head;
			tail=newNode;
		}
	
		
	}


	
	void Display()
	{
		Node * iterator=head;
		while(iterator!=tail)
		{
			cout<<iterator->data<<" ";
			iterator=iterator->next;
		}
			cout<<tail->data<<endl;

	}
	
	void ReverseDisplay()
	{
		Node * iterator = reverseLinkedList();
	//	cout<<iterator->data<<" ";
		while(iterator->next!=head)
		{
			cout<<iterator->data<<" ";
			iterator=iterator->next;
		}
			cout<<tail->data<<endl;

	}
	
	Node* reverseLinkedList()
	{
		Node *current=head;
		Node *prev=0, *next=0;
		
	    do
		{
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;
		}	while(current->next!=head->next);
		
		head=prev;
	//	cout<<head->data<<"     \n";

		return head;
	}
	
		
};

int main()
{
	LinkedList LL;
	
	cout<<"Linked List after inserting values at tail\n";		
	LL.Insert_Tail(1);
	LL.Insert_Tail(2);
	LL.Insert_Tail(3);	
	LL.Insert_Tail(4);
	LL.Insert_Tail(5);
	LL.Insert_Tail(6);
	LL.Display();

   //	Node * iterator = LL.reverseLinkedList();
	cout<<"Reverse Linked List:\n";
	LL.ReverseDisplay();
	return 0;
}

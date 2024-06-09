//Doubly Linked List not circuler

#include<iostream>
using namespace std;

class Node
{
	
	public:
		
	int data;
	Node *next;
	Node *prev;
	
	
	Node()
	{
		data=0;
		next=0;
		prev=0;
		
	}
	
	
	Node(int data)
	{
		this->data=data;
		this->next=0;
		prev=0;
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
    
    void Insert_Head(int value)
    {
    	Node *newNode, *temp;
    	
    	if(head==0)
    	{
    		newNode = new Node(value);
    		head=tail=newNode;
    		
		}
		else
		{
			temp=head;
			newNode = new Node(value);
			newNode->prev = 0;
			newNode->next= temp;
			head->prev= newNode;
			head= newNode;
			
		}
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
			newNode->next= 0;
			newNode->prev= tail;
			tail->next=newNode;
	
			tail=newNode;
		}
	
		
	}

    void InsertAtAnyNode(int position , int value)
    {
    	int i=1;
    	Node *newNode, *iterator=head, *temp;
    	
    	while(iterator!=0 && i<position)
    	{
    		iterator= iterator->next;
    		i++;
		}
		temp= iterator->next;
		newNode= new Node(value);
		iterator->next=newNode;
		newNode->prev= iterator;
		newNode->next=temp;
		temp->prev=newNode;
		return;
	}
	
	void Update(int position, int value)
	{
		int i=0;
    	Node *newNode, *iterator=head;
    	
    	while(iterator!=0 && i<position)
    	{
    		iterator= iterator->next;
    		i++;
		}
		iterator->data= value;
	}
	
	void DeleteAnyNode(int position)
	{
		int i=1;
    	Node *newNode, *iterator=head, *temp;
    	if(position==0)
    	{
    		temp= head->next;
    		delete head;
    		
    		head=0;
    		head=temp;
    		
		}
		else
		{
			
         	while(iterator!=0 && i<position)
    	    {  
    	    	iterator= iterator->next;
    	    	i++;
		    }
		    
		    Node *toDelete=iterator->next;
		    iterator->next=iterator->next->next;
		    iterator->next->prev=iterator;
		    
		    delete toDelete;
		    toDelete=0;
		
	    }
	}
	
	
	void Display()
	{
		Node * iterator=head;
		while(iterator!=0)
		{
			cout<<iterator->data<<" ";
			iterator=iterator->next;
		}
		cout<<endl;
		//	cout<<tail->data<<endl;

	}
	
	void reversePrint()
	{
	    Node *iterator= tail;
		while(iterator!=0)
		{
			cout<<iterator->data<<" ";
			iterator=iterator->prev;
		}	
	//	cout<<head->data<<endl;
	}	
};

int main()
{
	LinkedList LL;
	cout<<"Linked List after inserting values at head\n";
	LL.Insert_Head(2);
	LL.Insert_Head(5);
	LL.Insert_Head(7);
	LL.Display();

	cout<<"Linked List after inserting values at tail\n";		
	LL.Insert_Tail(2);	
	LL.Insert_Tail(6);
	LL.Insert_Tail(8);
	LL.Display();

	cout<<"Linked List after inserting value at position 3.\n";
	LL.InsertAtAnyNode(3,8);
	LL.Display();
		
	cout<<"Linked List after updating value at position 6.\n";	
	LL.Update(6,1);
	LL.Display();
	
	cout<<"Linked List after deleting node at position 2\n";	
	LL.DeleteAnyNode(2);
	LL.Display();
	
	cout<<"Reverse linked list to verify reverse connection.\n";
    LL.reversePrint();
	return 0;
}

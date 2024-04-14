#ifndef list_h
#define list_h
	#include <iostream>
	#include "node.h"	
using std::cout;
using std::cin;	
template<class T>	
class List
	{
	private:
		Node<T> *first;
		Node<T> *last;
		int numElements;
		
	public:
		List();
		List(const List &other);
		bool isEmpty();
		void add(T value);
		void display();
		void insert(T value, int position);
		void remove(int position);
		T retrieve(int position);
		void reverse();
		void copyFrom(const List &other);
		void create(int num);
		void clear();
		~List();
		
	};


template<class T>
List<T>::List()
{
	first = NULL;
	numElements = 0;
	
}

template<class T>
bool List<T>::isEmpty()
{
	return(first == NULL);
	
}
template<class T>
void List<T>::add(T value)
{
	Node<T> *aux;
	aux = new Node<T>(value);
	
	if(isEmpty())
		first = last = aux;
	else 
		{
			last->modifysuccessor(aux);
			last = aux;
			
			
		}
	numElements++;
	
}
template<class T>
void List<T>:: display()
{
	Node<T> *aux= first;
	int i ;
	
	i=1;
	if(isEmpty())
	{
		cout<<"the list is empty"<<std::endl;
		
	}else{
		while(aux!=NULL)
		{
			aux->print();
			
			aux=aux->consultsuccessor();	
			i++;	
		
		}
		cout<<"NULL"<<std::endl;
	}
	
}
template<class T>
void List<T>::insert(T value , int position)
{
	Node<T> *current,*previous,*aux,*temp;
	temp=new Node<T> (value);
	int i=1;
	current=first;
	
	if(position==0 || position==1 )
	{
		first=temp;
		first->modifysuccessor(current);
		
	}else{
	
		while(i<position)
			{
				previous=current;
				current=current->next;
				i++;
			}
	
		
		if(position==numElements)
		{
			last->next=temp;
			last=last->next;
		
		}else{
				aux=current;
				previous->next=temp;
				temp->next=aux;
			}
	}
	
numElements++ ;
}
template<class T>
T List<T>:: retrieve(int position)/*funciona*/
{
	Node<T> *aux;
	int i=1;
	if(position<=numElements){
	
		aux=first;
		while(i<position)
		{
			aux=aux->next;
			i++;
		}
	}
	return(aux->retrieve());
}
	
template<class T>	
List<T>::List(const List &other)
{
	Node<T> *aux,*creating;
	aux=other.first;
	first=new Node<T>(aux->retrieve());
	aux=aux->next;
	creating=first;
	while(aux)
	{
		creating->next=new Node<T>(aux->retrieve());
		creating=creating->next;
		aux=aux->next;
	}
	
}
	

template<class T>
void List<T>::create(int n)/*funciona*/
{
	int i =1;
	int value;
	for (i=1 ; i<=n ;i++)
	{
		cout<<"insert the value to add to element "<<i<<std::endl;
		cin>>value;
		add(value);
	}
	
	
}
template<class T>
List<T>::~List()/*no probado aun */
{
	clear();
}
template<class T>
void List<T>::clear()
{
	Node<T> *freeing;

	while(first!=NULL)
	{
		freeing=first;
		first=first->next;
		delete freeing;
	}
	first=NULL;
	numElements=0;
}

template<class T>
void List<T>::remove( int position)
{
	Node<T> *current,*previous;
	int i=1;
	current=first;
	if (position>numElements){
		cout<<"there are not so many elements in the list"<<std::endl;
	}else{
		if(position==1)
		{
		first=first->next;
		
		}else{
		
			while(i<position)
			{
				previous=current;
				current=current->next;
				i++;
			}
			if(numElements==position)
			{
				last=previous;
				last->modifysuccessor(NULL);
		
			}else
				{
					previous->modifysuccessor(current->next);
				}
		
			}
		
		numElements --;
	}
	
}

template<class T>
void List<T>::copyFrom(const List<T> &other)
{
	Node<T> *aux;
	aux=other.first;
	
		while (aux)
		{
			add(aux->retrieve());
			aux=aux->next;
		}
	
}


#endif

#include <iostream>
using namespace std;
// sorted array
template <class T>
class E_BookShoop
{
private:
	static const int max_size = 500;
	T Books[max_size];
	int length;
	int currentPosition;
	double price;
	int NumOfBook;

public:
	// deafult
	E_BookShoop();
	int getLength() const;
	void makeEmpty();
	bool isFull() const;

	//operation
	void insertBook(T item);
	void deleteBook(T item);
	bool searchBook(T item);

	//reset currentPosition
	void resetCurrentPosition();

	// print informatin methods
	void getInfo();
	bool isLastItem();
	void getNextItem(T& item);
};

template <class T>
E_BookShoop<T>::E_BookShoop()
{
	length = 0;
	currentPosition = -1;
	price = 8.35;
	NumOfBook = 0;
}

template <class T>
int E_BookShoop<T>::getLength() const
{
	return length;
}

template <class T>
void E_BookShoop<T>::makeEmpty()
{
	length = 0;
}

template <class T>
bool E_BookShoop<T>::isFull() const
{
	return length == max_size;
}

template <class T>
void E_BookShoop<T>::insertBook(T item)
{
	if (!isFull())
	{
		int location = 0;

		while (location < length)
		{
			if (item > Books[location])
			{
				location++;
			}
			else
			{
				break;
			}
		}

		// shfting
		for (int i = length; i > location; i--)
		{
			Books[i] = Books[i - 1];
		}

		Books[location] = item;
		length++;
	}

	else
	{
		cout << "addtion is faild ! your bookshoop is full" << endl;
	}
}

template <class T>
void E_BookShoop<T>::deleteBook(T item)
{
	int location = 0;

	while (location < length)
	{
		if (item > Books[location])
		{
			location++;
		}
		else if (item == Books[location])
		{
			break;
		}
		else
		{
			cout << "the book not found in bookshoop !" << endl;
			return;
		}
	}
	for (int i = location; i < length - 1; i++)
	{
		Books[i] = Books[i + 1];
	}
	length--;
}

template <class T>
bool E_BookShoop<T>::searchBook(T item)
{
	int midpoint;
	int first = 0;
	int last = length - 1;
	while (first <= last)
	{
		midpoint = (first + last) / 2;
		if (item < Books[midpoint])
		{
			last = midpoint - 1;
		}
		else if (item > Books[midpoint])
		{
			first = midpoint + 1;
		}
		else if (item == Books[midpoint])
		{
			return true;
		}
		else
		{
			break;
		}
	}
	return false;
}

template <class T>
void E_BookShoop<T>::getInfo()
{
	cout << "Num Of Book" << "    " << "Title" << "    " << "Price" << endl;

	for (int i = 0; i < length; i++)
	{
		NumOfBook++;
		cout << NumOfBook << "    " << Books[i] << "    " << price<<endl;
		price += 0.5;
	}
	price = 8.35;
	NumOfBook = 0;
}

template <class T>
void E_BookShoop<T>::resetCurrentPosition()
{
	currentPosition = -1;
}

template <class T>
bool E_BookShoop<T>::isLastItem()
{
	return currentPosition == length - 1;
}

template <class T>
void E_BookShoop<T>::getNextItem(T& item)
{
	if (!isLastItem())
	{
		currentPosition++;
		item = Books[currentPosition];
	}
	else
	{
		cout << "No more item in BookShoop now" << endl;
	}
}

// array stack
template <class A>
class Visiters
{
private:
	static const int max_requests = 10;
	int top;
	A adding[max_requests];

public:
	Visiters();
	void makeEmpty(); // to delete the requests
	bool isFull() const;
	bool isEmpty() const;
	void addRequest(A requestAddItem);
	void popRequest(A& requestAddItem);
};

template <class A>
Visiters<A>::Visiters()
{
	top = -1;
}

template <class A>
void Visiters<A>::makeEmpty()
{
	top = -1;
}

template <class A>
bool Visiters<A>::isFull() const
{
	return top == max_requests - 1;
}

template <class A>
bool Visiters<A>::isEmpty() const
{
	return top == -1;
}

template <class A>
void Visiters<A>::addRequest(A requestAddItem)
{
	if (!isFull())
	{
		top++;
		adding[top] = requestAddItem;
	}
	else
	{
		cout << "add request is faild because the requests are closed now !" << endl;
	}
}

template <class A>
void Visiters<A>::popRequest(A& requestAddItem)
{
	if (!isEmpty())
	{
		requestAddItem = adding[top];
		cout << requestAddItem << " will adding to bookshoop" << endl;
		top--;
	}
	else
	{
		cout << "poping is faild because no there request to add books !" << endl;
	}
}

// unsorted array
template <class B>
class LeaderShips
{
private:
	static const int max_leaders = 6;
	B leaders[max_leaders];
	int sumOfLeaders;
	int levelLeader;

public:
	LeaderShips();
	void makeEmpty();
	bool isFull() const;
	int getSumOfLeaders() const;
	void insertLeader(B leader);
	void deleteLeader(B leader);
	bool searchLeader(B leader);
	void printAllLeaders();
};

template <class B>
LeaderShips<B>::LeaderShips()
{
	sumOfLeaders = 0;
	levelLeader = 0;
}

template <class B>
void LeaderShips<B>::makeEmpty()
{
	sumOfLeaders = 0;
}

template <class B>
bool LeaderShips<B>::isFull() const
{
	return sumOfLeaders == max_leaders;
}

template <class B>
int LeaderShips<B>::getSumOfLeaders() const
{
	return sumOfLeaders;
}

template <class B>
void LeaderShips<B>::insertLeader(B leader)
{
	if (!isFull())
	{
		leaders[sumOfLeaders] = leader;
		sumOfLeaders++;
	}
	else
	{
		cout << "can't add more leader because the sum of leaders must be maximum 6 leaders" << endl;
	}
}

template <class B>
void LeaderShips<B>::deleteLeader(B leader)
{
	for (int i = 0; i < sumOfLeaders; i++)
	{
		if (leader == leaders[i])
		{
			leaders[i] = leaders[sumOfLeaders - 1];
			sumOfLeaders--;
			return;
		}
	}
	cout << "the name of leader not found !" << endl;
}

template <class B>
bool LeaderShips<B>::searchLeader(B leader)
{
	for (int i = 0; i < sumOfLeaders; i++)
	{
		if (leader == leaders[i])
		{
			return true;
		}
	}
	return false;
}

template <class B>
void LeaderShips<B>::printAllLeaders()
{
	cout << "Name" << "    " << "Level" << endl;
	for (int i = 0; i < sumOfLeaders; i++)
	{
		levelLeader++;
		cout<<leaders[i]<< "    "<<levelLeader << endl;
	}
	levelLeader = 0;
}

// structure
template <class C>
struct Node
{
	C data;
	Node<C>* next;
};

// queue linkedlist
template <class C>
class support
{
private:
	Node<C>* front;
	Node<C>* rear;

public:
	support();
	~support();
	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	void enqueue(C remark);
	void dequeue(C& remark);
};

template <class C>
support<C>::support()
{
	front = NULL;
	rear = NULL;
}

template <class C>
support<C>::~support()
{
	makeEmpty();
}

template <class C>
void support<C>::makeEmpty()
{
	Node<C>* ptr;

	while (front != NULL)
	{
		ptr = front;
		front = front->next;
		delete ptr;
	}
	rear = NULL;
}

template <class C>
bool support<C>::isEmpty() const
{
	return front == NULL;
}

template <class C>
bool support<C>::isFull() const
{
	Node<C>* ptr = new Node<C>();
	if (ptr == NULL)
	{
		return true;
	}
	else
	{
		delete ptr;
		return false;
	}
}

template <class C>
void support<C>::enqueue(C remark)
{
	if (!isFull())
	{
		Node<C>* node = new Node<C>();
		node->data = remark;
		node->next = NULL;

		if (rear == NULL)
		{
			front = node;
		}
		else
		{
			rear->next = node;
		}
		rear = node;

	}
	else
	{
		cout << "can't add remark now !" << endl;
	}
}

template <class C>
void support<C>::dequeue(C& remark)
{
	Node<C>* ptr;
	remark=front->data;
	ptr = front;
	front = front->next;

	if (front == NULL)
	{
		rear = NULL;
	}
	delete ptr;
}

int main()
{
	cout << "welcome to E-BookShoop" << endl;
	cout << endl;
	cout << "|----------Main Menu-----------|" << endl;
	cout << "|1: Book Management            |" << endl;
	cout << "|2: Visitor Suggesions         |" << endl;
	cout << "|3: Leaderships Management     |" << endl;
	cout << "|4: Technical Support Requests |" << endl;
	cout << "|------------------------------|" << endl;

	E_BookShoop<string> e;
	Visiters <string> V;
	LeaderShips <string> L;
	support <string> S;
	int select;
	string search;
	int password;
	char again;
	e.insertBook("C++ Programming");
	e.insertBook("web development");
	e.insertBook("SQL");
	e.insertBook("Problem Solving");
	e.insertBook("Java");
	e.insertBook("Python Programming");

	L.insertLeader("Ali");
	L.insertLeader("Omar");
	L.insertLeader("Hamzeh");
	L.insertLeader("Mahmoud");

	while (true)
	{
		cout << "what do you hope enter to view ? (1-4) : ";
		cin >> select;
		cout<<endl;
		if (select >= 1 && select <= 4)
		{
			if (select == 1)
			{
				int E;
				cout << "select from this menu : " << endl;
				cout << endl;
				cout << "1: deleteBook" << endl;
				cout << "2: resetBookShoop" << endl;
				cout << "3: searching" << endl;
				cout << "4: getNextBook" << endl;
				cout << "5: printInfo" << endl;
				cout << "6: sum of books in bookshoop" << endl;
				cout<<  "7: insertBooks"<<endl;
				cout<<endl;
				cout << "i will select : ";
				cin >> E;
				if (E >= 1 && E <= 7)
				{
					if (E == 1)
					{
						cout << "please enter a password : ";
						cin >> password;
						if (password == 2006)
						{
							cout << "enter the name of book you need to delete : ";
							cin >> search;
							e.deleteBook(search);
						}
						else
						{
							cout << "error in password, try again plaese" << endl;
							continue;
						}
					}
					else if (E == 2)
					{
						cout << "please enter a password : ";
						cin >> password;
						if (password == 2006)
						{
							e.makeEmpty();
							cout << "reset operation completed, bookshhop now is empty"<<endl;
							while (true)
							{
								cout << "do you hope add a new books ? (Y or N) : ";
								cin >> again;
								if (again == 'Y' || again == 'y')
								{
									string newBook;
									cout << "enter a title of new book : ";
									cin >> newBook;
									e.insertBook(newBook);
									continue;
								}
								else
								{
									break;
								}
							}
						}
						else
						{
							cout << "error in password, try again plaese" << endl;
							continue;
						}
					}
					else if (E == 3)
					{
						cout << "enter the name of book you need to search : ";
						cin >> search;
						if (e.searchBook(search))
						{
							cout << "found "<<search << endl;
						}
						else
						{
							cout << "not found "<<search << endl;
						}
					}
					else if (E == 4)
					{
						string item;
						cout << "this is the books in the bookshoop : " << endl;
						while (!e.isLastItem())
						{
							e.getNextItem(item);
							cout << item <<endl;
						}
						e.resetCurrentPosition();
					}
					else if (E == 5)
					{
						cout << "this is all information for books in bookshoop : " << endl;
						e.getInfo();
					}
					else if (E == 6)
					{
						cout<<"the sum of books in bookshoop : " << e.getLength()<<endl;
					}

					else if(E==7)
					{
						cout<<"please enter a password : ";
						cin>>password;

						if(password==2006)
						{
							int numAdd;

							cout<<"how many the book you need to insert : ";
							cin>>numAdd;

							for(int i=0; i<numAdd; i++)
							{
								string newBook;

								cout<<"enter name of book : ";
								cin>>newBook;

								e.insertBook(newBook);
							}

							cout<<"insert operation was done"<<endl;
						}
						else
						{
							cout<<"error in password, please try again"<<endl;
							continue;
						}
					}
					else
					{
						cout << "your select is error" << endl;
					}
				}
			}
			else if (select == 2)
			{
				cout << "1: add Suggesions" << endl;
				cout << "2: delete Suggesions" << endl;
				cout << "3: checking to the Suggesions" << endl;
				int v;
				cout << "enter your select : ";
				cin >> v;
				if (v >= 1 && v <= 3)
				{
					if (v == 1)
					{
						int add;
						cout << "how many request do you have : ";
						cin >> add;
						if (add <= 10)
						{
							string request;
							for (int i = 0; i < add; i++)
							{
								cout << "insert your requests : ";
								cin >> request;
								V.addRequest(request);
							}
						}
						else
						{
							cout << "your requsts must less or equal than 10" << endl;
						}
					}
					else if (v == 2)
					{
						V.makeEmpty();
						cout << "your Suggesions is deleted" << endl;
					}
					else if (v == 3)
					{
						int poped;;
						cout << "how many requsts are insert in the past : ";
						cin >> poped;
						string popeds;
						for (int i = 0; i < poped; i++)
						{
							V.popRequest(popeds);
						}
					}
				}
				else
				{
					cout << "your select is error" << endl;
				}
			}
			else if (select == 3)
			{
				cout << "please enter a password for leadersships : ";
				cin >> password;
				if (password == 1991)
				{
					cout << "1: resetLeaders" << endl;
					cout << "2: deleteLeader" << endl;
					cout << "3: searchLeader" << endl;
					cout << "4: printAllLeaders" << endl;
					cout << "5: getSumOfLeaders" << endl;
					cout<<  "6: insertLeaders"<<endl;

					int l;
					cout << "please enter what do you hope in section leaders : ";
					cin >> l;
					if (l >= 1 && l <= 6)
					{
						if (l == 1)
						{
							L.makeEmpty();
							cout << "the leaders list is empty now" << endl;
							while (true)
							{
								cout << "do you hope to add new leader ? (Y or N) : ";
								cin >> again;
								if (again == 'y' || again == 'Y')
								{
									string newLeader;
									cout << "enter a new name leader : ";
									cin >> newLeader;
									L.insertLeader(newLeader);
									continue;
								}
								else
								{
									break;
								}
							}
						}
						else if (l == 2)
						{
							cout << "please enter the leader name to delete : ";
							cin >> search;
							L.deleteLeader(search);
						}
						else if (l == 3)
						{
							cout << "please enter the leader name to searching : ";
							cin >> search;
							if (L.searchLeader(search))
							{
								cout << "found " << search << endl;
							}
							else
							{
								cout << "not found " << search << endl;
							}
						}
						else if (l == 4)
						{
							cout << "this is all information for leaders : " << endl;
							L.printAllLeaders();
						}
						else if (l == 5)
						{
							cout << "sum of leaders equal " << L.getSumOfLeaders() << endl;
						}
						else if(l==6)
						{
							int numAdd;
							cout<<"how many the leader you need to insert : ";
							cin>>numAdd;
							for(int i=0; i<numAdd; i++)
							{
								string newLeader;
								cout<<"enter name of leader : ";
								cin>>newLeader;
								L.insertLeader(newLeader);
							}
							cout<<"insert operation was done"<<endl;
						}
					}
					else
					{
						cout << "your select is error !" << endl;
					}
				}
				else
				{
					cout << "your password uncorrect, please try again" << endl;
					continue;
				}
			}
			else if (select == 4)
			{
				cout << "please enter a password for Technical Support Requests : ";
				cin >> password;
				if (password == 2000)
				{
					S.enqueue("improve the speed of system");
					S.enqueue("adding more books from deafult subjects");
					S.enqueue("reduce the leaders");
					S.enqueue("increese the num of leaders");

					cout << "this is all Technical Support Requests : " << endl;
					string de;
					for (int i = 0; i < 4; i++)
					{
						S.dequeue(de);
						cout << "this request " << de << " was done" << endl;
					}
				}
				else
				{
					cout << "your password uncorrect, please try again" << endl;
					continue;
				}
			}
			cout << endl;
			char again;
			cout << "try again ? (y or n) " << endl;
			cin >> again;
			if (again == 'y' || again == 'Y')
			{
				continue;
			}
			else
			{
				cout<<"Thank you"<<endl;
				break;
			}
		}
		else
		{
			cout << "error in the select, please try again" << endl;
			cout << endl;
			continue;
		}
	}
	return 0;
}
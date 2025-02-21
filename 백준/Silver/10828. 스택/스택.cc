#include <iostream>
#include <string>

using namespace std;

class node
{
public:
	node(int x)
	{
		data = x;
	}
	node* n;
	int data;
private:

};

class stack
{
public:
	stack()
	{}
	void push(int x)
	{
		node* v = new node(x);
		if (size == 0)
		{
			head = v;
			tail = v;
			v->n = nullptr;
			size++;
		}
		else
		{
			tail->n = v;
			tail = v;
			size++;
		}
	}
	int pop()
	{
		if (size == 0)
		{
			return -1;
		}
		else if (size == 1)
		{
			int x = tail->data;
			size--;
			head = tail = nullptr;
			return x;

		}
		else
		{
			node* x = head;
			while (x->n != tail)
			{
				x = x->n;
			}
			int y = tail->data;
			tail = x;
			x->n = nullptr;
			size--;
			return y;
			
		}
	}
	int size_n()
	{
		return size;
	}
	int top()
	{
		if (size == 0)
		{
			return -1;
		}
		else
		{
			return tail->data;
		}
	}


private:
	node* head;
	node* tail;
	int size=0;

};
int main()
{
	int num;
	cin >> num;
	int size;

	stack one;

	while (num>0)
	{
		string str1;
		cin >> str1;
		if (str1 == "push")
		{
			int x;
			cin >> x;
			one.push(x);
		}
		else if (str1 == "pop")
		{
			cout << one.pop() << endl;
		}
		else if (str1 == "size")
		{
			cout << one.size_n() << endl;
			
		}
		else if (str1 == "empty")
		{
			if (one.size_n() == 0)
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else {
			cout << one.top() << endl;
		}
		num--;
	}

	return 0;

}
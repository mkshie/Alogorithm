#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class node {
public:
	node(node* c, int idx)
	{
		parent = c;
		index = idx;

	}
	void addchild(node* p)
	{
		ch.push_back(p);
	}
	void addparent(node* p)
	{
		parent = p;
	}
	void setidx()
	{
		vecidx = (parent->ch.size()) - 1;
	}
	node* parent = nullptr;
	vector <node*> ch;
	int index = 0;
	int vecidx = 0;
};
int cnt = 0;

void search(node* start)
{
	if (start == nullptr)
		return;
	if (start->ch.size() != 0)
	{
		for (size_t i = 0; i < start->ch.size(); i++) {
			search(start->ch[i]);
		}
	}
	else
	{
		cnt++;
	}

	return;
}

node* k[50] = { nullptr };
int count = 0;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	cin >> size;
	int par;
	node* root=nullptr;


	for (int i = 0; i < size; i++) { // tree 생성
		node* v = new node(nullptr, i);
		k[i] = v;

	}
	for (int i = 0; i < size; i++) {
		cin >> par;
		if (par != -1) {
			k[i]->addparent(k[par]); // 부모 자식 설정
			k[par]->addchild(k[i]);
			k[i]->setidx();
		}
		else if(par ==-1)
		{
			root = k[i];
		}
	}
	int del;
	cin >> del;
	if (k[del] == root)
	{
		cout << "0";
	}
	else
	{
	k[del]->parent->ch.erase((k[del]->parent->ch.begin()) + k[del]->vecidx);
	k[del] = nullptr;
	search(root);
	cout << cnt;
	}
	return 0;
}



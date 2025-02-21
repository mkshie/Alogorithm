#include <iostream>
#include <vector>
using namespace std;

//vector <char> tree;



class node {
public:
	node(char a)
	{
		data = a;
	}
	void addlchild(node* y)
	{
		lch = y;
	}
	void addrchild(node* y)
	{
		rch = y;
	}
	char getdata() {
		return data;
	}
	char data = 0;
	node* lch = nullptr;
	node* rch = nullptr;
};

node* p[27] = { nullptr };

class tree {
public:
	tree(char a) {
		node* v = new node(a);
		root = v;
	}
	void addnode(char a) {
		node* v = new node(a);
	}
	node* root = nullptr;

	void preorder(node *a) {
		cout << a->getdata();
		if (a->lch != nullptr)
			preorder(a->lch);
		if (a->rch != nullptr)
			preorder(a->rch);
		return;
	}

	void inorder(node* a) {
		if (a->lch != nullptr)
			inorder(a->lch);
		cout << a->getdata();
		if (a->rch != nullptr)
			inorder(a->rch);
		return;
	}
	void postorder(node *a) {
		if (a->lch != nullptr)
			postorder(a->lch);
		if (a->rch != nullptr)
			postorder(a->rch);
		cout << a->getdata();
		return;
	}
};

int check(char da,int num) {
	for (int i = 0; i < num; i++)
	{
		if (p[i]->data == da) {
			return i;
		}
	}
	return -1; // 일치하는 node 가 없을경우
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num = 0;
	cin >> num;;
	tree a('A');
	int pnum = 0;
	p[pnum] = a.root;
	pnum++;
	char par, lch, rch;
	for (int i = 1; i < num+1; i++)
	{
		int chnum = 0;
		cin >> par >> lch >> rch;
		if (par != 'A') {
			while (true){
				if (chnum == pnum)
				{
					node* j = new node(par);
					p[pnum] = j;
					pnum++;
					break;
				}
				if (p[chnum]->data ==par) {
					break;
				}
				chnum++;

			}
			if (lch != '.') {
				int kkk = check(lch, pnum);
				if (kkk == -1) {
					node* j = new node(lch);
					p[chnum]->addlchild(j);
					p[pnum] = j;
					pnum++;
				}
				else
				{
					p[chnum]->addlchild(p[kkk]);
				}
			}
			if (rch != '.') {
				int kkk = check(rch, pnum);
				if (kkk == -1) {
					node* j = new node(rch);
					p[chnum]->addrchild(j);
					p[pnum] = j;
					pnum++;
				}
				else
				{
					p[chnum]->addrchild(p[kkk]);
				}
			}
		}
		else // root 에 추가할때 즉 par 이 A 일때
		{
			if (lch != '.') {
				int kkk = check(lch, pnum);
				if (kkk == -1) {
					node* j = new node(lch);
					a.root->addlchild(j);
					p[pnum] = j;
					pnum++;
				}
				else
				{
					a.root->addlchild(p[kkk]);
				}

			}
			if (rch != '.') {
				int kkk = check(rch, pnum);
				if (kkk == -1) {
					node* j = new node(rch);
					a.root->addrchild(j);
					p[pnum] = j;
					pnum++;
				}
				else
				{
					a.root->addrchild(p[kkk]);
				}
			}
		}

	}
	a.preorder(p[0]);
	cout << "\n";
	a.inorder(p[0]);
	cout << "\n";
	a.postorder(p[0]);

	return 0;
}
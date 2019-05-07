#include<iostream>
#include <string>
//using namespace std;
class node 
{
public:
	string connector, actor;
	node*next;
	node(string con, string act);
};


class hashlist
{
	node*head, *tail;
public:
	hashlist();
	void add(string con,string act);
	void clear();
	string search(string sea);
	~hashlist();
};


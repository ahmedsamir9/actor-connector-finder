#include "hashlist.h"
#include<iostream>;
using namespace std;
node::node(string con, string act) {
	connector = con;
	actor = act;
	next = NULL;

}


hashlist::hashlist()
{
	head = tail = NULL;
}

void hashlist::add(string con, string act) {
	node *new_node = new node(con, act);
	if (head == NULL) {
		head = tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}
}
void hashlist::clear() {
	node*temp ;
	node *del = head;
	while (temp != NULL) {
		temp = del->next;
		delete del;
		del = temp;
	}
  }
string hashlist::search(string sea) {
	node*temp = head;
	while (temp!=NULL)
	{

	}
}
hashlist::~hashlist()
{
}

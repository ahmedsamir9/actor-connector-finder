#include "mlist.h"
#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<Windows.h>
using namespace std;
mnode::mnode() {
	
	next = NULL; 
}
mnode::mnode( string movie_name) {
	
	next = NULL;
	id;
	mname = movie_name;
}
mlist::mlist() {
	first = last = NULL;
}

void mlist::add_movies(string movie_N) {
		string  first_name, last_name;
		mnode * new_movie = new mnode(movie_N);
		int actors;
		bool repeat = false;
		string s;
		mnode*temp = first;
		while (true)
		{
		cout << "enter the movie id :" << endl;
		cin >> new_movie->id;
		while (temp!=NULL)
		{
			if (temp->id == new_movie->id) {
				repeat = true;
				break;
			}
			temp = temp->next;
		}
		if (repeat == true) {
			cout << "this id is already exist plz enter new one !" << endl;
			repeat = false;
			continue;
		}
		else
		{
			break;
		}
		}
		if (first == NULL) {
			first = last = new_movie;
			cout << "enter number of actor in this movie  " << new_movie->mname << "  :" << endl;
			cin >> actors;
			if (actors > 0) {
				cout << "actors names in  " << new_movie->mname << " :" << endl;
				for (int i = 0; i < actors; i++)
				{
					cin >> first_name >> last_name;
					s = first_name + " " + last_name;
					new_movie->list_actor.push_back(s);
				}
			}
			
		}
		else
		{
			last->next = new_movie;
			last = new_movie;
			cout << "enter number of actor in this movie " << new_movie->mname << " :" << endl;
			cin >> actors;
			if (actors > 0) {
				cout << "actors name " << new_movie->mname << " :" << endl;
				for (int i = 0; i < actors; ++i)
				{
					cin >> first_name >> last_name;
					s = first_name + " " + last_name;
					new_movie->list_actor.push_back(s);
				}
			}
		}
}

void mlist::display_all_actor( string movie_name) {
	
	mnode*temp = first;
	while (temp != NULL) {
		if (temp->mname == movie_name)break;
		temp = temp->next;
	}
	if (temp == NULL) {
		cout << "not found movie \n";
	}
	else
	{	cout << "the actors acted in  " << temp->mname << "  movie :" << endl;
		for (int i = 0; i < temp->list_actor.size(); i++)
		{
			cout << temp->list_actor[i] << endl;

			
		}
	}

}
void mlist::diplaymovies() {
	mnode*temp = first;
	cout << "movies names  :" << endl;
	while (temp!=NULL){
		cout << temp->mname << endl;
		cout << endl;
		temp = temp->next;
	}
}
void mlist::delete_Movie(string movie_name) {
	mnode *temp1 , *temp2;
	temp1 = first;
	if (temp1->mname== movie_name)
	{
		first = first->next;
		delete temp1;
	}
	else
	{
		while (temp1 != NULL)
		{
			temp2 = temp1->next;
			if (temp2->mname == movie_name)
			{
				temp1->next = temp2->next;
				delete temp2;

			}
			temp1 = temp1->next;
		}
	}

		
	 
}
void mlist::desplay_all_movies(unordered_map<string, pair<int, vector<string>>> coon)
{
	string firstname, lastname, con;
	cout << "enter the actor name please :   ";
	cin >> firstname >> lastname;
	con = firstname + " " + lastname;
	unordered_map<string, pair<int, vector<string>>> ::iterator  it;
	it = coon.find(con);
	if (it == coon.end()) {
		cout << "this actor isn't found \n";
	}
	else
	{
		for (int i = 0; i < it->second.second.size(); i++)
		{
			cout << it->second.second[i] << endl;
		}
		cout << endl;
	}
	
}
void mlist::displayactors(unordered_map<string, pair<int, vector<string>>> coon) {
	unordered_map<string, pair<int, vector<string>>> ::iterator it;
	cout << "all actor in system" << endl;
	for ( it = coon.begin(); it != coon.end(); it++)
	{
		cout << it->first << endl;
	}
	cout << endl;
}
unordered_map<string, pair<int, vector<string>>> mlist::actorr() {
	bool seen = false, isfound=false;
	vector<string>visited, value;
	unordered_map<string, pair<int, vector<string>>> con;
	int id=1;
	string key;
	mnode*temp = first;
	while (temp!=NULL)
	{
		for (int i = 0; i < temp->list_actor.size(); i++)
		{
			key = temp->list_actor[i];
			if (!visited.empty()) {
				for (int j = 0; j < visited.size(); j++)
				{
					if (key == visited[j]) {
						seen = true;
						break;
					}
				}
			}
			if (seen == true) {
				seen = false;
				continue;
			}
			else
			{
				visited.push_back(key);
				value.push_back(temp->mname);
				mnode*temp2 = first;
				while (temp2 != NULL) {
					if (temp->mname == temp2->mname) {
						temp2 = temp2->next;
					}
					if (temp2 == NULL)break;
					for (int k = 0; k < temp2->list_actor.size(); k++)
					{
						if (key == temp2->list_actor[k]) {
							isfound = true;
							break;
						}
					}
					if (isfound == true) {
						value.push_back(temp2->mname);
						isfound = false;
					}
					temp2 = temp2->next;
				}
				con[key] = make_pair(id, value);
				value.clear();
				id++;
			}
		}
		temp = temp->next;
	}
	return con;
}

unordered_map<string, vector<string>> mlist::connect() {
	vector <string> commenactors ,visited;
	string key,actor;
	bool isfound = false,visitedd= false;
	mnode*temp = first,*temp2;
	unordered_map<string, vector<string>> connetion;
	while(temp != NULL) {
		for (int i = 0; i < temp->list_actor.size(); i++)
		{
			actor = temp->list_actor[i];
			for (int j = 0; j < visited.size(); j++)
			{
				if (actor == visited[j])
				{
					visitedd = true;
					break;
				}
			}
			if (visitedd == false)
			{
				visited.push_back(actor);
				temp2 = first;
				while (temp2 != NULL)
				{
					for (int check = 0; check < temp2->list_actor.size(); check++)
					{
						if (actor == temp2->list_actor[check])
						{
							isfound = true;
							break;
						}

					}
					if (isfound == true)
					{
						for (int k = 0; k < temp2->list_actor.size(); k++)
						{
							if (actor == temp2->list_actor[k])
							{
								continue;
							}
							else  {
								commenactors.push_back(temp2->list_actor[k]);

							}
						}
					}
					isfound = false;
					temp2 = temp2->next;
				}
				key = actor;
				connetion[key] = commenactors;
				commenactors.clear();
				
			}
			visitedd = false;
		}
		temp = temp->next;
	}
	return connetion;
}


vector<string>mlist::search(unordered_map < string, vector<string>> connect, string key, string sea, vector<string>visited, vector<string>finallly) {
	bool found = false,visitedd = false;
	visited.push_back(key);
	
	unordered_map < string, vector<string>>::iterator it;
	if (key == sea) {
		finallly.push_back(key);
		return finallly;
	}
	it = connect.find(key);
	for (int i = 0; i < it->second.size(); i++)
	{
		if (it->second[i] == sea) {
			finallly.push_back(sea);
			finallly.push_back(key);
			found = true;
			return finallly;
			break;
		}
	}
	if (found == false) {
		for (int i = 0; i < it->second.size(); i++)
		{
			for (int j = 0; j < visited.size(); j++)
			{
				if (it->second[i] == visited[j]) {
					visitedd = true;
					break;
				}
			}
				if (visitedd == true)
				{
					visitedd = false;
					continue;
				}
				else if (visitedd == false)
				{
					finallly = search(connect,it->second[i], sea,visited,finallly);
				}
				if (finallly .front() == sea) {
					finallly.push_back(key);
					return finallly;
				}
		}
	}
	return finallly;
}

void mlist::choose()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, FOREGROUND_INTENSITY);
	int choice , id ;
	string s, firstname, lastname, movie_N;
	string con;
	cout << "                             _____________________________________________________________" << endl;
	cout << "                            |                                                             |" << endl;
	cout << "                            |          < welcome to actor connection finder >             |" << endl;
	cout << "                            |_____________________________________________________________|" << endl;
	while (true)
	{
		SetConsoleTextAttribute(H, FOREGROUND_INTENSITY);
		cout << " 1 : to add movies and thier actors  " << endl;
		cout << " 2 : to  enter a movie and see all actors in it " << endl;
		cout << " 3 : to enter an actor and see all the movies he/she acting in " << endl;
		cout << " 4 : to find connection betwen two actors  " << endl;
		cout << " 5 : to print all movies in the program" << endl;
		cout << " 6 : to print all actor in the program " << endl;
		cout << " 7 : to delete movie " << endl;
		cout << " 8 : to exit" << endl;
		cin >> choice;
		if (choice == 1)
		{
			SetConsoleTextAttribute(H, FOREGROUND_RED);
			cout << "how many movies do you wnat to insert :  ";
			int numofmovies,i=0;
			cin >> numofmovies;
			while (i < numofmovies)
			{
				cout << "enter the movie name plz : \n";
				cin.ignore();
				getline(cin, movie_N);
				add_movies(movie_N);
				i++; 
				
			}
			continue;
		}

		else if (choice == 2)
		{
			SetConsoleTextAttribute(H, FOREGROUND_RED);
			cout << "enter the movie name  :  ";
			cin.ignore();
			getline(cin, movie_N);
			display_all_actor(movie_N);
			continue;
		}
		else if (choice == 3)
		{
			SetConsoleTextAttribute(H, FOREGROUND_RED);
			unordered_map<string, pair<int, vector<string>>> coon = actorr();
			desplay_all_movies(coon);
			continue;
		}
		
		else if (choice == 4) {
			SetConsoleTextAttribute(H, FOREGROUND_RED);
			int number_of_ways=0;
			string firstactor, secondactor;
			unordered_map < string, vector<string>>conn = connect();
			vector<string>visited, shortest,path;
			cout << "enter the first actor :   ";
			cin.ignore();
			getline(cin, firstactor);
			cout << endl;
			cout << "enter the actor you want to find connection with :  ";
			getline(cin, secondactor);
			unordered_map < string, vector<string>>::iterator itr,check,finallly;
			itr = conn.find(firstactor);
			check = conn.find(secondactor);
			if (itr == conn.end() || check == conn.end()) {
				cout << "this actor not found \n";
			}
			else
			{
				
				for (int i = 0; i < itr->second.size(); i++)
				{
					visited.push_back(firstactor);
					for (int j = 0; j < itr->second.size(); j++)
					{
						if (itr->second[i] == itr->second[j]) {
							break;
						}
						else
						{
							visited.push_back(itr->second[j]);
						}
					}
				
					 path = search(conn, itr->second[i], secondactor, visited,path);
					 path.push_back(firstactor);
					 if (path.front() == secondactor) {
						 number_of_ways++;
						 cout << "path \n";
						 for (int j = path.size()-1; j >= 0; j--)
						 {
							 cout << path[j] << "  ";
							 if (j != 0) {
								 cout << " --> ";
							 }
						 }
						 cout << endl;
					 }
	
					 if (shortest.empty()&& path.front() == secondactor)
					 {
						shortest = path;
					 }

					 if (!shortest.empty() && path.front() == secondactor && shortest.size() > path.size())
					 {
						shortest = path;
					 }
					
					visited.clear();
					path.clear();
				}
				if (number_of_ways == 0) {
					cout << "no connectio between the tow actors \n";
				}
				else
				{
					cout << "we see all connection between this two actors \n";
					cout << "they can connect too each other by  " << number_of_ways << " way and the shortest one is :" << endl;
					for (int i = shortest.size()-1; i >= 0; i--)
					{
						cout << shortest[i] << "  ";
						if (i != 0) {
							cout << " --> ";
						}
					}
					cout<<endl;
					
				}
			
			}
		}

		else if (choice == 5) {
		SetConsoleTextAttribute(H, FOREGROUND_RED);
		diplaymovies();
		}		
		else if (choice == 6) {
		SetConsoleTextAttribute(H, FOREGROUND_RED);
		unordered_map<string, pair<int, vector<string>>> coon = actorr();

			displayactors(coon);
		}

		else if (choice == 7)
		{ 
		SetConsoleTextAttribute(H, FOREGROUND_RED);
		cout << "enter the name of movie u want to delete :" << endl;
		cin.ignore();
		getline(cin, movie_N);
		delete_Movie(movie_N);
		}
		else if (choice == 8) {
			break;
		}
		else
		{
		SetConsoleTextAttribute(H, FOREGROUND_RED);
		cout << "number is not correct " << endl;
		
		}

	}
	cout << "thank you " << endl;
	
}

void mlist::clear()
{
	mnode *temp = first;
	while (first != NULL)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
}

mlist::~mlist()
{
	clear();
}


#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace  std;
class mnode
{
public:
	mnode*next;
	int id; 
	string mname;                             /////// ask the TA about the id 
	vector<string>list_actor;
	mnode();
	mnode(string movie_name);
};
class mlist
{
private:
	mnode*first, *last;
	
public:
	mlist();
	void add_movies(string movie_N);
	void display_all_actor(string movie_name);
	void delete_Movie(string MOVie_name);
	void displayactors(unordered_map<string, pair<int, vector<string>>> coon);
	void desplay_all_movies(unordered_map<string, pair<int, vector<string>>> coon);
	void desplay_all_movies(unordered_map<string, pair<int, vector<string>>> coon);
	void choose();
	void clear();
	unordered_map < string, vector<string>> connect();
	vector<string>search(unordered_map < string, vector<string>> connect, string key, string sea, vector<string>visited, vector<string>finally);
	void diplaymovies();
	unordered_map<string,pair<int,vector<string>>>actorr();
	
	~mlist();
};

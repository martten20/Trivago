#pragma once
#pragma once
#include<vector>
#include <string>
#include <string.h>
#include<assert.h>
#include<unordered_map>
using namespace std;


class duration
{
public:
	int checkout_day;
	int checkout_month;
	int checkout_year;
	int day;
	int month;
	int year;
};


class room
{
public:
	room();
	bool single;
	bool tv;
	bool wifi;
	int dur_nam;
	duration* dur;
	int room_num;
};


class hotels
{
public:
	string name;
	string country;
	string location;
	int num_stars;
	int num_rooms;
	bool free_meals;
	bool gym;
	bool pool;

	
	room* rooms;
	hotels(void);
	void read();
	int rate;
	vector <int> rates;
	unordered_map <string, string> comment;
	void read_room();

	~hotels(void);
};


class Node
{
public:
	Node();
	Node(hotels val);
	Node* next;
	hotels value;
};


class LinkedList
{
private:

public:
	Node* head;
	Node* tail;
	int size;
	int counter;
	unordered_map<string, LinkedList> caunt;
	unordered_map<string, LinkedList> nam;
	void Append(hotels val);
	void append_hash(hotels val);
	LinkedList(void);
	void display_all();
	vector<string> display_with_query(LinkedList,bool,bool,bool);
	vector<string> diplay_at_time(LinkedList, int , int , int );
	void searchCountry();
	void searchName();
	void delete_hash(string);
	int calc_rate(vector<int>);
	void append_rate(string ,int);
	void append_comments(string,string,string);
	void update_hash();
};



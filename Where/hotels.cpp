#include "hotels.h"
#include <vector>
#include <iostream>
#include<fstream>
using namespace std;


room::room()
{
	wifi = false;
	tv = false;
	single = false;
	dur_nam = 0;
}


hotels::hotels()
{
	rate = 0;
	free_meals = false;
	gym = false;
	pool = false;

}


void hotels::read() {
	cout << "Enter Hotel Name: " << endl;
	cin >> name;
	cout << "Enter Country: " << endl;
	cin >> country;
	cout << "Enter Location: " << endl;
	cin >> location;
	cout << "Number Of Stars: " << endl;
	cin >> num_stars;
	cout << "Number Of Rooms: " << endl;
	cin >> num_rooms;
	cout << "Free Meals? " << endl;
	char fm;
	cin >> fm;
	if (fm == 'y')
		free_meals = true;
	else
		free_meals = false;
	char g;
	cout << "GYM? " << endl;
	cin >> g;
	if (g == 'y')
		gym = true;
	else
		gym = false;
	char p;
	cout << "Pool? " << endl;
	cin >> p;
	if (p == 'y')
		pool = true;
	else
		pool = false;
	cout << "Rate: " << endl;
	cin >> rate;
	read_room();

}


void hotels::read_room()
{
	rooms = new room[num_rooms];
	for (int i = 0; i < num_rooms; i++)
	{
		cout << "Enter Room Number: " << endl;
		cin >> rooms[i].room_num;
		cout << "[For Single Room Enter y] & [For Double Room Enter n] " << endl;
		char s;
		cin >> s;
		if (s == 'y')
			rooms[i].single = true;
		else
			rooms[i].single = false;
		cout << "WIFI? " << endl;
		char w;
		cin >> w;
		if (w == 'y')
			rooms[i].wifi = true;
		else
			rooms[i].wifi = false;
		char t;
		cout << "TV? " << endl;
		cin >> t;
		if (t == 'y')
			rooms[i].tv = true;
		else
			rooms[i].tv = false;
		cout << "Number Of Reservations: " << endl;
		cin >> rooms[i].dur_nam;
		rooms[i].dur = new duration[rooms[i].dur_nam];
		for (int j = 0; j < rooms[i].dur_nam; j++)
		{
			cout << "Enter Check In Date: " << endl;
			cin >> rooms[i].dur[j].day;
			cin >> rooms[i].dur[j].month;
			cin >> rooms[i].dur[j].year;
			cout << "Enter Check Out Date: " << endl;
			cin >> rooms[i].dur[j].checkout_day;
			cin >> rooms[i].dur[j].checkout_month;
			cin >> rooms[i].dur[j].checkout_year;
		}
	}
}


hotels::~hotels()
{
}


Node::Node()
{
	next = NULL;
}


Node::Node(hotels val)
{
	value = val;
}


LinkedList::LinkedList()
{
	tail = NULL;
	head = NULL;
	size = 0;
	counter = 0;
}


void LinkedList::Append(hotels val)
{
	Node* tmp = new Node(val);
	//in case the list is empty
	if (head == NULL)
		head = tail = tmp;
	else //if the list is not empty
	{
		Node* a = head;
		Node* b = head->next;
		if (tmp->value.num_stars >= head->value.num_stars) {
			tmp->next = head;
			head = tmp;
		}
		else if (tmp->value.num_stars <= tail->value.num_stars) {
			tail->next = tmp;
			tmp = tail;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (tmp->value.num_stars < a->value.num_stars && tmp->value.num_stars > b->value.num_stars) {
					a->next = tmp;
					tmp->next = b;
					break;
				}
				else if (tmp->value.num_stars == a->value.num_stars) {
					a->next = tmp;
					tmp->next = b;
					break;
				}
				else {
					a = a->next;
					b = b->next;
				}
			}
		}
	}
	size++;
}


void LinkedList::append_hash(hotels val)
{
	string s = val.country;
	string f = val.name;
	caunt[s].Append(val);
	nam[f].Append(val);
	counter++;
}


void LinkedList::display_all() {
	Node* tmp = head;
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << tmp->value.name << endl;
		cout << "Country: " << tmp->value.country << endl;
		cout << "Number Of Stars: " << tmp->value.num_stars << endl;
		cout << "Rate: " << tmp->value.rate << endl;
		cout << "Number Of Rooms: " << tmp->value.num_rooms << endl;
		if (tmp->value.free_meals == true)
			cout << "Free Meals Available" << endl;
		if (tmp->value.gym == true)
			cout << "GYM Available" << endl;
		if (tmp->value.pool)
			cout << "Pool Available" << endl;
		
		tmp = tmp->next;
	}
}


vector<string> LinkedList::diplay_at_time(LinkedList s,int d,int m,int y) {
	
	Node* temp = s.head;
	vector<string> names;
	bool ishotel=false;
	while (temp != NULL) {
		bool availble = false;
	
		for (int i = 0; i < temp->value.num_rooms; i++)
		{
			
			for (int j = 0; j < temp->value.rooms[i].dur_nam; j++) {
				long long in = temp->value.rooms[i].dur[j].day + ((temp->value.rooms[i].dur[j].month - 1) * 30) + ((temp->value.rooms[i].dur[j].year - 1) * 365);
				long long out = temp->value.rooms[i].dur[j].checkout_day + ((temp->value.rooms[i].dur[j].checkout_month - 1) * 30) + ((temp->value.rooms[i].dur[j].checkout_year - 1) * 365);

				long long comp = d + ((m - 1) * 30) + ((y - 1) * 365);

				if (in <= comp && comp <= out)
				{
					continue;
				}
				else
				{
					availble = true;
					ishotel = true;
					names.push_back(temp->value.name);
					break;
				}
			}
			if (availble == true)
			{
				break;

			}
		}
		availble = false;
		temp = temp->next;
	}
	if (ishotel == false)
	{
		names.push_back("no avilable");
	}
	return names;
}


vector<string> LinkedList::display_with_query(LinkedList s,bool p, bool g, bool fm) {
	Node* temp = s.head;
	vector<string> names;
	int siz = s.size;
	bool is = false;
	if (p == true) {
		for (int i = 0; i < siz; i++) {
			if (temp->value.pool == true) {
				is = true;
				names.push_back( temp->value.name) ;
			}
			temp = temp->next;

		}
	}
		
	if (g == true) {
		for (int i = 0; i < siz; i++) {
			if (temp->value.gym == true) {
				is = true;
				names.push_back (temp->value.name);
			}
				
			temp = temp->next;

		}
	}
		
	if (fm == true) {
		for (int i = 0; i < siz; i++) {
			if (temp->value.free_meals == true) {
				names.push_back( temp->value.name);
				is = true;
			}
			temp = temp->next;

		}
	}
	if (is == true)
		return names;
		
	if (is == false)
	{

		names.push_back("no hotels avilable with this qiery");
		return names;
	}
}


void LinkedList::searchCountry()
{
	string s;
	int n;
	cout << "Enter Country Name: " << endl;
	cin >> s;
	caunt[s].display_all();
	cout << "Press 1 To Filter By Specific Query" << endl;
	cout << "Press 2 To Filter By Duration" << endl;
	cout << "Press 3 To Exit" << endl;
	cin >> n;
	if (n == 1) {
		//display_with_query(caunt[s]);
	}
	else if (n == 2) {
//		diplay_at_time(caunt[s]);
	}
}


void LinkedList::searchName()
{
	string s;
	cout << "Enter Hotel Name: " << endl;
	cin >> s;
	nam[s].display_all();
}


void LinkedList::delete_hash(string n) {
	string c;

	c = nam[n].head->value.country;
	Node* temp = caunt[c].head;
	Node* temp2 = temp->next;
	if (temp->value.name == n) {
		caunt[c].head = caunt[c].head->next;
		delete temp;
	}
	else {
		while (temp2 != NULL && temp2->value.name != n) {
			temp2 = temp2->next;
			temp = temp->next;
		}
		if (temp2->next == NULL) {
			caunt[c].tail = temp;
		}
		else {
			temp->next = temp2->next;
		}
		delete temp2;
	}
	caunt[c].size--;
	Node* temp3 = nam[n].head;
	delete temp3;
	nam[n].size--;
	counter--;
}


void LinkedList::update_hash() {

	string c;
	string n;
	cout << "Enter Hotel Name: " << endl;
	cin >> n;
	Node* temp2 = nam[n].head;
	c = temp2->value.country;
	Node* temp = caunt[c].head;
	int answer;
	cout << "1 - Update Number of Stars" << endl;
	cout << "2 - Update Rating" << endl;
	cout << "3 - Update Number of Rooms" << endl;
	cout << "4 - Update Pool Availablity" << endl;
	cout << "5 - Update GYM Availablity" << endl;
	cout << "6 - Update Free Meals Availablity" << endl;
	cin >> answer;
	while (temp != NULL && temp->value.name != n) {
		temp = temp->next;
	}

	int x;
	char y;
	if (answer == 1) {
		cout << "Enter Number of Stars: " << endl;
		cin >> x;
		temp->value.num_stars = x;
		temp2->value.num_stars = x;
	}
	else if (answer == 2) {
		cout << "Enter Your Rating: " << endl;
		cin >> x;
		temp->value.rate = x;
		temp2->value.rate = x;
	}
	else if (answer == 3) {
		cout << "Enter Number of Rooms: " << endl;
		cin >> x;
		temp->value.num_rooms = x;
		temp2->value.num_rooms = x;
	}
	else if (answer == 4) {
		cout << "Pool Available ?" << endl;
		cin >> y;
		if (y == 'y') {
			temp->value.pool = true;
			temp2->value.pool = true;
		}
		else {
			temp->value.pool = false;
			temp2->value.pool = false;
		}
	}
	else if (answer == 5) {
		cout << "GYM Available ?" << endl;
		cin >> y;
		if (y == 'y') {
			temp->value.gym = true;
			temp2->value.gym = true;
		}
		else {
			temp->value.gym = false;
			temp2->value.gym = false;
		}
	}
	else if (answer == 6) {
		cout << "Free Meals Available ?" << endl;
		cin >> y;
		if (y == 'y') {
			temp->value.free_meals = true;
			temp2->value.free_meals = true;
		}
		else {
			temp->value.free_meals = false;
			temp2->value.free_meals = false;
		}
	}
}


int LinkedList::calc_rate(vector<int> s)
{
	int n = s.size();
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += s[i];
	}
	sum /= n;
	return sum;
}

void LinkedList::append_rate(string n, int r) {
	string c; //name of country
	c = nam[n].head->value.country; //nam[n] dah hash table bta3 el name w sa3etha bytl3k el gowa el name hyd5lk 3al country
	Node* temp = caunt[c].head; // node bymshy f hash el country l7ad mywsl el name bta3 el hotel el howa n
	while (temp != NULL && temp->value.name != n) {
		temp = temp->next; // talama el index fady aw msh nfs el hotel sa3etha b3mel next 3la el b3deeh l7ad mla2y el hotel el ana 3yzo
	}
	nam[n].head->value.rates.push_back(r); // rate m7tot fe vector 3shan kaza guest hyd5l -- b3melo push back fl vector bta3 el rate 3shan y5od mkan ll rate dah
	nam[n].head->value.rate =  calc_rate(nam[n].head->value.rates);  //
	temp->value.rates.push_back(r);
	temp->value.rate =  calc_rate(temp->value.rates);
}

void LinkedList::append_comments(string n,string name,string comments) {
	cout << "Enter Hotel's Name: " << endl;
	string c = nam[n].head->value.country;
	Node* temp = caunt[c].head;
	while (temp != NULL && temp->value.name != n) {
		temp = temp->next;
	}
	
	nam[n].head->value.comment[name] = comments;
	temp->value.comment[name] = comments;
}







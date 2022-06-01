#include<iostream>
#include<queue>
#include<string>

using namespace std;


class Bus
{
	const int size = 20;
	queue<int> que;
	//que = (int size);

public:
	Bus()
	{
		std::cout << "";
	}
};
class BusStop
{
	bool ending_station;
	int day_people;
	int day_bus;
	int day_people_time;
	int day_bus_time;
	int night_people;
	int night_bus;
	int night_people_time;
	int night_bus_time;
public:
	BusStop() :ending_station(false), day_people(0), day_bus(0), day_people_time(0), day_bus_time(0),
		night_people(0), night_bus(0), night_people_time(0), night_bus_time(0) {};
	BusStop(bool e_s, int day_p_t, int day_b_t, int night_p_t, int night_b_t) :BusStop()
	{
		ending_station = e_s;
		day_people_time = day_p_t; day_bus_time = day_b_t;
		night_people_time = night_p_t; night_bus_time = night_b_t;
	};
	void PrintInfo()
	{
		std::cout << "\n ending? - " << (ending_station == true ? " yes " : " no ");// булевый результат в текст.
		std::cout << "\n day - time - people - " << day_people_time;
		std::cout << "\n day - time - bus - " << day_bus_time << "\n night - time - people - " << night_people_time;
		std::cout << "\n night - time - bus - " << night_bus_time << "\n";
	}


};


class Client
{
	std::string query;
	int priority;
	int office;
public:
	Client() :query("unknown"), priority(0), office(0) {};
	Client(std::string query, int priority, int office) :Client()
	{
		this->query = query; this->priority = priority; this->office = office;
	}
	Client(int priority, int office) :Client()
	{
		this->priority = priority;
		this->office = office;
	}
	void ClQuerty(std::string str) { query = str; }
	int GetOffice() { return office; }
};
class Printer
{
	friend class Client;
	std::queue <Client> clients;
	std::priority_queue <Client> client_query;
	int* attached_offices;
public:
	Printer() :clients(), client_query(), attached_offices(nullptr) {};
	Printer(int* a_o_n)
	{
		for (int i = 0; i < 3; i++) { attached_offices[i] = a_o_n[i]; }
	}
	int GetPQ() { return client_query.size(); }
	void Print()
	{
		for (int i = 0; i < client_query.size(); i++)
		{
			client_query.top(); client_query.pop();
		}

	}
	void Print_queue(Client query_print)
	{
		if (query_print.GetOffice() == attached_offices[0] ||
			query_print.GetOffice() == attached_offices[1] ||
			query_print.GetOffice() == attached_offices[2])
		{
			clients.push(query_print);
			client_query.push(query_print);
			std::cout << "\n document in queue, waiting for printing...\n";
		}
		else
		{
			std::cout << "\n  !!! user does not have access to this printer !!!\n";
		}
		if (GetPQ() == 5)
		{
			std::cout << "\n document sent for printing\n";
			Print();
		}
	}

};

int main()
{
	BusStop bs1(true, 5, 15, 12, 30);
	bs1.PrintInfo();
	BusStop bs2(false, 3, 20, 25, 35);
	BusStop bs3(false, 10, 10, 22, 20);
	BusStop bs4(false, 7, 30, 30, 40);
	BusStop bs5(true, 5, 17, 19, 25);
	int n;
	n = 7;
	int x;
	x = 15 / 5;
	int y;
	y = x * n;


	Client people1(30, 5), people2(15, 2), people3(16, 1), people4(10, 6), people5(6, 2), people6(12, 3), people7("helo world", 25, 1),
		people8("good-luck world", 12, 4), people9(22, 5), people10(3, 6), people11(" I am King!", 31, 1), people12(11, 6);
	people1.ClQuerty("people1"); people2.ClQuerty("people2"); people3.ClQuerty("people3"); people4.ClQuerty("people4");
	people5.ClQuerty("people5"); people6.ClQuerty("people6"); people7.ClQuerty("people7"); people8.ClQuerty("people8");
	people9.ClQuerty("people9"); people10.ClQuerty("people10"); people11.ClQuerty("people11"); people12.ClQuerty("people12");




}
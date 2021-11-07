#pragma once
#include <iostream>
#include <string>
using namespace std;
class Result
{
private:
	string name_competition;
	string name_team;
	int place;
public:
	
	Result() : name_competition(""), name_team(""), place(0) {cout << "created" << endl << endl; }
	Result(string v_name,string v_name_team ,int v_place) :
		name_competition(v_name), name_team(v_name_team), place(v_place) {
		cout << "created" << endl << endl;
	}
	Result(const Result& v_result):
		name_competition(v_result.name_competition), name_team(v_result.name_team), place(v_result.place) 
	{
		cout << "copy constructor" << endl << endl;
	}
	// перемещающий конструктор
	Result(Result&& v_result):
		name_competition(v_result.name_competition), name_team(v_result.name_team), place(v_result.place) 
		
	{
		cout << "move constructor" << endl<<endl;
	}
	
	// перемещающий оператор присваивания
	Result& operator=(Result&& obj)
	{
		if (this != &obj) {
			/**this = obj;*/
			name_competition = obj.name_competition;
			name_team = obj.name_team;
			place = obj.place;
		}
		cout << "move assignment " << endl << endl;
		return *this;
	}
	Result& operator=(const Result& obj)
	{
		if (this != &obj) {
			name_competition = obj.name_competition;
			name_team = obj.name_team;
			place = obj.place;
		}
		cout << "assignment " << endl << endl;
		return *this;
	}

	void set_competition(string value)
	{
		name_competition = value;
	}
	void set_team(string value)
	{
		name_team = value;
	}
	void set_place(int value)
	{
		place = value;
	}


	string get_competition() const
	{
		return name_competition;
	}
	string get_team() const
	{
		return name_team;
	}
	int get_place() const
	{
		return place;
	}

	Result& the_best_result(const Result& obj)
	{
		if (name_competition == obj.get_competition())
		{
			if (place < obj.get_place()) return *this;
			else
			{
				*this = obj;
				return *this;
			}
		}
		else
		{
			cout << "Разный вид спорта" << endl;
			return *this;
		}
	}

	

	~Result()
	{
		cout<<"destroyed" << endl;
	}
};


ostream& operator<<(ostream& out, const Result& obj)
{
	return out << "Вид спорта:         " << obj.get_competition() << endl
		<< "Название команды:   " << obj.get_team() << endl
		<< "Место:              " << obj.get_place() << endl;
}
Result plus_place(Result x) {
	std::cout << "plus called" << std::endl;
	x.set_place(x.get_place()+1);
	return x;
}

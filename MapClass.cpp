#include <iostream>
#include <Windows.h>
#include <map>

using namespace std;
typedef struct Student
{
	char name[20];
	char address[100];
}Student;

//Map class without Pointer
class MapEx
{
public:
	map<int, Student> students;
	int roll;
	MapEx()
	{
		map<int, Student> students;
	}
	~MapEx()
	{
		students.clear();
	}
	void Add()
	{
		for (auto cntr = 0; cntr < 10; cntr++)
		{
			Student objStudents;
			cout << "Enter student's Roll number, Name and Address: ";
			cin >> roll;
			cin >> (objStudents).name;
			cin >> (objStudents).address;
			students.insert(pair <int, Student>(roll, objStudents));
		}
	}
	void Disp()
	{
		map<int, Student>::iterator iter;
		cout << "ROLL" << '\t' << "NAME" << '\t' << "ADDRESS" << endl;
		for (iter = students.begin(); iter != students.end(); ++iter)
		{
			cout << iter->first << '\t' << (iter)->second.name << '\t' << (iter)->second.address << endl;
		}
	}
};


//Map class with Pointer
class MapEx1
{
public:
	map<int, Student*> students;
	int roll;
	MapEx1()
	{
		map<int, Student*> students;
	}
	~MapEx1()
	{
		for (map<int, Student*>::iterator iter = students.begin(); iter != students.end(); ++iter)
		{
			if ((*iter).second) 
			{
				delete ((*iter).second);
				((*iter).second) = NULL;
			}
		}
		students.clear();
	}
	void Add()
	{
		for (auto cntr = 0; cntr < 10; cntr++)
		{
			cout << "Enter student's Roll number, Name and Address: ";
			cin >> roll;
			Student* objStudents = new Student();
			cin >> (*objStudents).name;
			cin >> (*objStudents).address;
			students.insert(pair <int, Student*>(roll, objStudents));
		}
	}
	void Disp()
	{
		map<int, Student*>::iterator iter;
		cout << "ROLL" << '\t' << "NAME" << '\t' << "ADDRESS" <<endl;
		for (iter = students.begin(); iter != students.end(); ++iter)
		{
			cout << iter->first <<'\t' << (*iter).second->name << '\t' << (*iter).second->address  << endl;
		}
	}
};

int main()
{

	//main for class without pointer type
	MapEx mapEx;
	mapEx.Add();
	mapEx.Disp();

	//main for class with pointer type
	MapEx1 mapEx1;
	mapEx1.Add();
	mapEx1.Disp();

	system("pause");
	return 0;
}
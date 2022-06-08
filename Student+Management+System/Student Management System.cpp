#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
//ID number, name, gender, age, grade of math, computer and English.
struct Student
{
	int id;
	string name;
	string gender;
	int age;
	int math;
	int computer;
	int English;
	Student *next;
	//Student *last;
};

//delay function
void delay(int ms)
{
	clock_t now = clock();
	while (clock() - now < ms);
}

//input information for a student 
void input(Student *s)
{
	cout << "Enter the id: ";
	cin >> s->id;
	cout << "Enter the name: ";
	cin >> s->name;
	while (1)
	{
		cout << "Enter the gender [male/female]: ";
		cin >> s->gender;
		if ((*s).gender == "male" || s->gender == "female")
			break;
	}
	cout << "Enter the age: ";
	cin >> s->age;
	cout << "Enter the grade of math: ";
	cin >> s->math;
	cout << "Enter the grade of computer: ";
	cin >> s->computer;
	cout << "Enter the grade of English: ";
	cin >> s->English;
}

//create an linked list
Student *create(int n)
{
	Student *head, *student, *end;
	head = new Student;
	end = head;
	for (int i = 0; i < n; i++)
	{
		cout << "\nInformation for student" << i + 1 << ": \n";
		student = new Student;
		input(student);

		end->next = student;
		//student->last = end;
		end = student;
	}
	//head->last = NULL;
	end->next = NULL;
	return head;
}

//add one more student to the end of the former linked list
void add(Student *former)
{
	while (former->next != NULL)
		former = former->next;
	Student *add = new Student;
	input(add);
	add->next = NULL;
	former->next = add;
}

//modify the n-th member of list *s
void modify(Student *s, int n)
{
	for (int i = 0; i < n; i++)
	{
		s = s->next;
	}
	string str;
	cout << "Which category?[ID/Name/Gender/Age/English/Math/Computer] ";
	while (1)
	{
		cin >> str;
		if (str == "ID")
		{
			cout << "Enter the id: ";
			cin >> s->id;
			break;
		}
		else if (str == "Name")
		{
			cout << "Enter the name: ";
			cin >> s->name;
			break;
		}
		else if (str == "Gender")
		{
			while (1)
			{
				cout << "Enter the gender [male/female]: ";
				cin >> s->gender;
				if ((*s).gender == "male" || s->gender == "female")
					break;
			}
			break;
		}
		else if (str == "Age")
		{
			cout << "Enter the age: ";
			cin >> s->age;
			break;
		}
		else if (str == "English")
		{
			cout << "Enter the grade of English: ";
			cin >> s->English;
			break;
		}
		else if (str == "Math")
		{
			cout << "Enter the grade of math: ";
			cin >> s->math;
			break;
		}
		else if (str == "Computer")
		{
			cout << "Enter the grade of computer: ";
			cin >> s->computer;
			break;
		}
		else
		{
			cout << "Please check the spelling of input and type in the correct category. ";
			continue;
		}
	}
}

//output the information of node *p
void output(Student *p)
{
	cout << p->id << "\t\t";
	cout << p->name << "\t\t";
	cout << p->gender << "\t\t";
	cout << p->age << "\t\t";
	cout << p->math << "\t\t";
	cout << p->computer << "\t\t";
	cout << p->English << "\t\t" << endl;
}

//show the information of student n
void show(Student *student, int n)
{
	cout << "ID\t\tName\t\tGender\t\tAge\t\tMath\t\tComputer\tEnglish" << endl;
	for (int i = 0; i < n; i++)
	{
		student = student->next;
	}
	output(student);
}

//show all student information
void show_all(Student *list)//没有数据时的debug
{
	Student *p = list;
	cout << "ID\t\tName\t\tGender\t\tAge\t\tMath\t\tComputer\tEnglish" << endl;
	while ((p = p->next) != NULL)
	{
		output(p);
	}
	cout << endl;
}

//delete all records or delete individual record
void remove(Student *student)
{
	char op;
	cout << "remove 1)individual record or 2)all records? ";
	while (1)
	{
		cin >> op;
		char c;
		cout << "Are you sure?[Y/N] ";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			if (op - 48 == 1)
			{
				cout << "Want to delete student #: ";
				int num;
				cin >> num;
				for (int i = 0; i < num - 1; i++)
				{
					student = student->next;
				}
				Student *s = student->next;
				student->next = student->next->next;
				student = s;
				delete student;
				break;
			}
			else if (op - 48 == 2)
			{
				Student *s = student;
				if (student = NULL)
					return;
				student = s;
				while (student->next != NULL)
				{
					s = student->next;
					student->next = student->next->next;
					delete s;
				}
				break;
			}
			else
			{
				cout << "please input your option [1~2]: ";
				continue;
			}
		}
		else if (c == 'n' || c == 'N')
			break;
	}
}

//locate the student's number with name of id number
void search(Student *student)
{
	char op;
	int n = 0;
	int flag = 1;
	cout << "Do you want to search by 1)name or 2)ID number? ";
	while (1)
	{
		cin >> op;
		if (op - 48 == 1)
		{
			string name;
			cout << "Enter the student's name: ";
			cin >> name;
			while (student->name != name)
			{
				n++;
				student = student->next;
				if (student == NULL)
				{
					flag = 0;
					cout << "Not founded. Please check the name :-(\n";
					break;
				}
			}
			break;
		}
		else if (op - 48 == 2)
		{
			int id;
			cout << "Enter the student's id: ";
			cin >> id;
			while (student->id != id)
			{
				n++;
				student = student->next;
				if (student == NULL)
				{
					flag = 0;
					cout << "Not founded. Please check the id :-(\n";
					break;
				}
			}
			break;
		}
		else
		{
			cout << "please input your option [1~2]: ";
			continue;
		}
	}

	if (flag)
		cout << "Founded...It's student #" << n << endl;
}

//histogram-plotting function
void histogramDisplay(int score[])
{
	string s[4] = { "A","B","C","D" };
	for (int i = 0; i < 4; i++)
	{
		cout << s[i] << ": ";
		for (int j = 0; j < score[i]; j++)
			cout << "*";
		cout << endl;
	}
}

//histogram-plotting for the linked list *student
void histogram(Student *student)
{
	int score[4] = { 0 };
	string s;
	cout << "Which subject?[English/Math/Computer] ";
	while (1)
	{
		cin >> s;
		if (s == "English")
		{
			while ((student = student->next) != NULL)
			{
				if (student->English >= 90 && student->English <= 100)
					score[0]++;
				else if (student->English >= 75 && student->English <= 89)
					score[1]++;
				else if (student->English >= 60 && student->English <= 74)
					score[2]++;
				else if (student->English >= 0 && student->English <= 59)
					score[3]++;
			}
			break;
		}
		else if (s == "Math")
		{
			while ((student = student->next) != NULL)
			{
				if (student->math >= 90 && student->math <= 100)
					score[0]++;
				else if (student->math >= 75 && student->math <= 89)
					score[1]++;
				else if (student->math >= 60 && student->math <= 74)
					score[2]++;
				else if (student->math >= 0 && student->math <= 59)
					score[3]++;
			}
			break;
		}
		else if (s == "Computer")
		{
			while ((student = student->next) != NULL)
			{
				if (student->computer >= 90 && student->computer <= 100)
					score[0]++;
				else if (student->computer >= 75 && student->computer <= 89)
					score[1]++;
				else if (student->computer >= 60 && student->computer <= 74)
					score[2]++;
				else if (student->computer >= 0 && student->computer <= 59)
					score[3]++;
			}
			break;
		}
		else
		{
			cout << "Please check the spelling of input and type in the correct subject.[English/Math/Computer] ";
			continue;
		}
	}
	histogramDisplay(score);
	delay(2000);
}

//the initial page of SMS, returns options number
int sms()
{
	char op;
	cout << "\n========= Student Management System =========";
	cout << "\n* * * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\n\t\t1. Add Student\n";
	cout << "\n\t\t2. Modify Student\n";
	cout << "\n\t\t3. Show All Student\n";
	cout << "\n\t\t4. Individual view\n";
	cout << "\n\t\t5. Remove Student\n";
	cout << "\n\t\t6. Locate Student\n";
	cout << "\n\t\t7. Score Histogram\n";
	cout << "\n\t\t8. Logout\n";
	cout << "\n* * * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\nEnter your option: ";
	while (1)
	{
		cin >> op;
		if (op - 48 > 0 && op - 48 < 9)
		{
			return op - 48;
		}
		else
		{
			cout << "Please enter a number [1~8]: ";
			continue;
		}
	}
}

//passcode function, enter the passcode to use the system
void passcode()
{
	//enter the passcode
	cout << "Welcome to use student management system! :-)" << endl;
	string passcode = "passcode";
	string s;
	while (1)
	{
		static int i = 5;
		cout << "Enter Passcode: ";
		cin >> s;
		if (s == passcode)
		{
			cout << "Unlocked.\a";
			delay(1000);
			cout << endl << endl;
			break;
		}
		else
		{
			cout << "Wrong passcode! " << endl;
			cout << "You have " << i - 1 << " more chance(s) to try." << endl << endl;
			i--;
			if (i == 0)
			{
				cout << "System is disabled" << endl;
				cout << "Try again in 1 minute.";
				delay(60000);
				cout << endl << endl;
				i = 5;
			}
		}
	}
}

//data saving function
void save(Student *student)
{
	ofstream outFile;
	outFile.open("data.txt");
	outFile << "ID\t\tName\t\tGender\t\tAge\t\tMath\t\tComputer\tEnglish\n";
	while ((student = student->next) != NULL)
	{
		outFile << student->id << "\t\t";
		outFile << student->name << "\t\t";
		outFile << student->gender << "\t\t";
		outFile << student->age << "\t\t";
		outFile << student->math << "\t\t";
		outFile << student->computer << "\t\t";
		outFile << student->English;
		outFile << "\n";
	}
}

int main()
{
	passcode();

	//input some data or use the default information to start the system.
	cout << "Type in some students' information to start the system." << endl;
	cout << "How many student do you want to put in?(0 for a default student, Bill) ";
	Student *student = new Student;
	int Init_num, num;
	cin >> Init_num;
	if (!Init_num)
	{
		ifstream inFile;
		inFile.open("defult data.txt");
		while (inFile.good())
		{
			Student *head, *end;
			head = new Student;
			end = head;

			inFile >> student->id;
			inFile >> student->name;
			inFile >> student->gender;
			inFile >> student->age;
			inFile >> student->math;
			inFile >> student->computer;
			inFile >> student->English;
			end->next = student;
			//student->last = end;
			end = student;

			end->next = NULL;
			//head->last = NULL;
			student = head;
		}
		inFile.close();
	}
	else
		student = create(Init_num);

	//catch options
	while (int op = sms() - 8)//while option input equals to 8, end the loop
	{
		switch (op + 8)
		{
		case 1:
			add(student);
			break;
		case 2:
			while (1)
			{
				char c;
				cout << "We suggest you to use option 6 first to get the location.[Y/N] ";
				cin >> c;
				cout << endl;
				if (c == 'y' || c == 'Y')
				{
					search(student);
					delay(1000);
					cout << endl;
					cout << "Want to modify the information of student #: ";
					cin >> num;
					modify(student, num);
					break;
				}
				else if (c == 'n' || c == 'N')
				{
					cout << "Want to modify the information of student #: ";
					cin >> num;
					modify(student, num);
					break;
				}
				else
				{
					continue;
				}
			}
			break;
		case 3:
			show_all(student);
			delay(2000);
			break;
		case 4:
			while (1)
			{
				char c;
				cout << "We suggest you to use option 6 first to get the location.[Y/N] ";
				cin >> c;
				cout << endl;
				if (c == 'y' || c == 'Y')
				{
					search(student);
					delay(1000);
					cout << endl;
					cout << "Want to see the information of student #: ";
					cin >> num;
					show(student, num);
					delay(2000);
					break;
				}
				else if (c == 'n' || c == 'N')
				{
					cout << "want to see the information of student #: ";
					cin >> num;
					show(student, num);
					delay(2000);
					break;
				}
				else
				{
					continue;
				}
			}
			break;
			break;
			delay(2000);
			break;
		case 5:
			remove(student);
			break;
		case 6:
			search(student);
			delay(2000);
			break;
		case 7:
			histogram(student);
			break;
		}
	}
	save(student);
	cout << "\nThank you for using the system. Bye~\n";
}

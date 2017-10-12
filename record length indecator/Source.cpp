#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student {
	char id[6];
	char fname[10];
	char lname[10];
	char address[25];
};

void main() {
	ofstream out("data.txt", ios::binary);
	Student student;
	char record[52];
	int num = 0;
	cout << "enter the number of records : ";
	cin >> num;
	cout << "________________________________________________\n";
	for (int i = 1; i <= num; i++) {
		cout << "enter student | " << i << " | id      : ";
		cin >> student.id;
		cout << "enter student | " << i << " | fname   : ";
		cin >> student.fname;
		cout << "enter student | " << i << " | lname   : ";
		cin >> student.lname;
		cout << "enter student | " << i << " | address : ";
		cin.ignore();
		cin.getline(student.address, sizeof(student.address));
		strcpy_s(record, student.id);
		strcat_s(record, "|");
		strcat_s(record, student.fname);
		strcat_s(record, "|");
		strcat_s(record, student.lname);
		strcat_s(record, "|");
		strcat_s(record, student.address);
		strcat_s(record, "|");
		int len = strlen(record);
		out << len;
		out.write(record, len);
		cout << "________________________________________________\n";
	}
	out.close();

	ifstream in("data.txt", ios::binary);
	Student stu;
	int i = 1;
	char temp[2];
	while (in.get(temp[0])) {
		in.get(temp[1]);
		int length = atoi(temp);
		cout << "record | " << i << " | size : " << length << endl;
		cout << "______________________\n";
		in.getline(stu.id, sizeof(stu.id), '|');
		in.getline(stu.fname, sizeof(stu.fname), '|');
		in.getline(stu.lname, sizeof(stu.lname), '|');
		in.getline(stu.address, sizeof(stu.address), '|');

		cout << "student | " << i << " | id      : " << stu.id << endl;
		cout << "student | " << i << " | fname   : " << stu.fname << endl;
		cout << "student | " << i << " | lname   : " << stu.lname << endl;
		cout << "student | " << i << " | address : " << stu.address << endl;
		cout << "________________________________________________\n";
	}


	in.close();


	system("pause");
}
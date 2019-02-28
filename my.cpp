/* Создается класс Student. Формируется динамический массив объектов. При тестировании выводится: сформированный список студентов, список студентов заданного факультета, список студентов для заданных факультета и курса.*/
#include <conio.h>
#include <string.h>
#include <iostream.h>

struct date // дата рождения
{
	char daymon[6];
	int year;
};

//=======

class Student =================

class Student{

char name[30]; //private date t;

char adr[30], fac[20]; int kurs;

public:

Student(); char *getfac(); int getkurs(); void show(); };

Student::Student()

{cout<<"Input name:"; cin>>name; cout<<"Input date of born\n"; cout<<"Day.mon:"; cin>>t.daymon; cout<<"Year:"; cin>>t.year; cout<<"Input adr:"; cin>>adr; cout<<"Input fac:"; cin>>fac;


cout<<"Input kurs:"; cin>>kurs;

}

void Student::show()

{

cout<<"Name :"<<name<<endl;

cout<<"Was born :"<<t.daymon<<'.'<<t.year<<endl; cout<<"Address :"<<adr<<endl;

cout<<"Fac :"<<fac<<endl; cout<<"Kurs :"<<kurs<<endl;

}

char *Student::getfac() { return fac; } int Student::getkurs() { return kurs; }

void spisfac(Student spis[],int n)//список студентов заданного факультетата

{char fac[20];

cout<<"Input faculty:"; cin>>fac; for(int i=0;i<n;i++)

if(strcmp(spis[i].getfac(),fac)==0)spis[i].show();

}

void spisfackurs(Student spis[],int n)

//список студентов заданных факультета и курса

{int i,k; char fac[20];

cout<<"Input faculty:"; cin>>fac; cout<<"Input the course:"; cin>>k; for(i=0;i<n;i++)

if ((strcmp(spis[i].getfac(),fac)==0)&&(spis[i].getkurs()==k)) spis[i].show();

}

//========= main ================

void main()

{ Student *spis; int n;

cout<<"Input a number of students: "; cin>>n; spis=new Student [n];

for(int i=0;i<n;i++) { cout<<"=============================="<<endl; spis[i].show();

}

spisfac(spis,n);

spisfackurs(spis,n); delete [] spis; cout<<"press any key!" while(!kbhit());

}


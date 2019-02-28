//«Комплексное число» – Complex.Класс должен содержать не - 
//сколько конструкторов и операции для сложения, вычитания, умно -
//жения, деления, присваивания.Создать два вектора размерности n
//из комплексных координат.Передать их в функцию,
//которая выполняет сложение комплексных векторов.
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <ctime>
#include <windows.h>

using namespace std;

class Complex
{
private:
	//int n; //кол-во координат в векторе
	//double *real = new double[n],
	//	*imaginary = new double[n];
	int real,   //Вещественная часть
		imaginary;   //мнимая
public:
	//конструкторы
	Complex();
	Complex(double r, double i);
	void show(int i);
};

Complex::Complex()
{
	real = rand() % 10 - 5;
	imaginary = rand() % 10 - 5;
}

void Complex::show(int i)
{
	cout << "Комплексное число "<<i<<": " << real << " + (" << imaginary << "i)" << endl;
}

//******************** MAIN **************************** 
void main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int n = 10;
	Complex *comp;
	comp = new Complex[n];
	for (int i = 0; i < n; i++)
	{
		comp[i].show(i);
	}

	while (!_kbhit());
}

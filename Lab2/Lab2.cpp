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
	double
		real,   //Вещественная часть
		imaginary;   //мнимая
public:
	//конструкторы
	Complex();
	Complex(double r, double i);
	void show(int i);
	void show();
	//деструктор
	~Complex() { };
	//перегрузки
	Complex operator+(Complex b);
	Complex operator-(Complex b);
	Complex operator*(Complex b);
	Complex operator/(Complex b);
	Complex operator=(Complex b);
};

Complex Complex::operator+(Complex b)
{
	return Complex(this->real + b.real, this->imaginary + b.imaginary);
}

Complex Complex::operator-(Complex b)
{
	return Complex(this->real - b.real, this->imaginary - b.imaginary);
}

Complex Complex::operator*(Complex b)
{
	return Complex((this->real * b.real) - (this->imaginary * b.imaginary), (this->imaginary * b.real) + (this->real * b.imaginary));
}

Complex Complex::operator/(Complex b)
{
	return Complex(((this->real * b.real) + (this->imaginary * b.imaginary)) / ((b.real * b.real) + (b.imaginary*b.imaginary)), ((this->imaginary * b.real) - (this->real * b.imaginary)) / ((b.real * b.real) + (b.imaginary * b.imaginary)));
}

Complex Complex::operator=(Complex b)
{
	return Complex(this->real = b.real, this->imaginary = b.imaginary);
}


Complex::Complex()
{
	real = rand() % 10 - 5;
	imaginary = rand() % 10 - 5;
}

Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}

void Complex::show(int i)
{
	cout << "  Комплексное число " << i << ": " << real << " + (" << imaginary << "i)" << endl;
}

void Complex::show()
{
	cout << real << " + (" << imaginary << "i)";
}

void vect_sum(Complex comp3[], Complex comp4[], int n)
{
	Complex *comp5 = new Complex[n];
	for (int i = 0; i < n; i++)
	{
		comp5[i] = comp3[i] + comp4[i];
	}
	cout << " Сумма векторов:" << endl;
	cout << " Vector3{";
	for (int j = 0; j < n; j++)
	{
		comp5[j].show();
		if (j != (n - 1))cout << ", ";
	}
	cout << "}.\n";
	delete[] comp5;
}

//******************** MAIN **************************** 
void main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	double real,
		imaginary;
	cout << "**************************** COMPLEX ****************************\n"
		<< "=======================================================================\n"
		<< "||  Данная программа выполняет арифмитические действия с              ||\n"
		<< "|| комплексными числами и сложение комплексных векторов.              ||\n"
		<< "=======================================================================\n\n"
		<< "  1. Ввод исходных данных\n"
		<< "=========================\n\n";
	cout << " Целая часть первого комплексного числа: "; cin >> real;
	cout << " Мнимая часть первого комплексного числа: "; cin >> imaginary;
	Complex comp0 = Complex(real, imaginary);
	comp0.show(1);
	cout << endl;
	cout << " Целая часть второго комплексного числа: "; cin >> real;
	cout << " Мнимая часть второго комплексного числа: "; cin >> imaginary;
	Complex comp1 = Complex(real, imaginary);
	comp1.show(2);
	cout << endl;
	cout << " Арифметические действия с комплексными числами\n "
		<< "==============================================\n\n";
	cout << " 1. Сумма: "; (comp0 + comp1).show();
	cout << endl;
	cout << " 2. Разность: "; (comp0 - comp1).show();
	cout << endl;
	cout << " 3. Произведение: "; (comp0 * comp1).show();
	cout << endl;
	cout << " 4. Частное: "; (comp0 / comp1).show();
	cout << endl;
	cout << " 5. Присваивание: "; (comp0 = comp1).show();
	cout << endl << endl;
	cout << "  2. Ввод исходных данных\n"
		<< "=========================\n\n"
		<< "  Размерность вектора: "; cin >> n;
	cout << endl;
	Complex *comp3 = new Complex[n],
		*comp4 = new Complex[n];
	for (int i = 0; i < n; i++)
	{
		cout << "  Координата первого вектора №" << i << endl
			<< "================================\n";
		cout << " Целая часть: "; cin >> real;
		cout << " Мнимая часть: "; cin >> imaginary;
		comp3[i] = Complex(real, imaginary);
		cout << endl;
	}
	cout << endl;
	for (int j = 0; j < n; j++)
	{
		cout << "  Координата второго вектора №" << j << endl
			<< "================================\n";
		cout << " Целая часть: "; cin >> real;
		cout << " Мнимая часть: "; cin >> imaginary;
		comp4[j] = Complex(real, imaginary);
		cout << endl;
	}
	cout << endl << " Вектора\n "
		<< "========\n\n";
	cout << " Первый вектор:" << endl;
	cout << " Vector1{";
	for (int i = 0; i < n; i++)
	{
		comp3[i].show();
		if (i != (n - 1))cout << ", ";
	}
	cout << "}.\n\n";
	cout << " Второй вектор:" << endl;
	cout << " Vector2{";
	for (int j = 0; j < n; j++)
	{
		comp4[j].show();
		if (j != (n - 1))cout << ", ";
	}
	cout << "}.\n\n";
	vect_sum( comp3, comp4, n);

	delete[] comp3;
	delete[] comp4;
	while (!_kbhit());
}

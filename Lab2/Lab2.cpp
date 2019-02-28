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
	~Complex() {};
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
	return Complex(((this->real * b.real) + (this->imaginary * b.imaginary))/((b.real * b.real) + (b.imaginary*b.imaginary)), ((this->imaginary * b.real) - (this->real * b.imaginary)) / ((b.real * b.real) + (b.imaginary * b.imaginary)));
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
	cout << "  Комплексное число "<<i<<": " << real << " + (" << imaginary << "i)" << endl;
}

void Complex::show()
{
	cout << real << " + (" << imaginary << "i)" << endl;
}

//******************** MAIN **************************** 
void main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	double n = 2,
		real,
		imaginary;
	//Complex *comp0,
	//		*comp1;
	cout << "**************************** COMPLEX ****************************\n"
		<< "=======================================================================\n"
		<< "||  Данная программа выполняет арифмитические действия с              ||\n"
		<< "|| комплексными числами и сложение комплексных векторов.              ||\n"
		<< "=======================================================================\n\n"
		<< "  Ввод исходных данных\n"
		<< "======================\n";
	cout << " Целая часть первого комплексного числа: "; cin >> real;
	cout << " Мнимая часть первого комплексного числа: "; cin >> imaginary;
	Complex comp0 = Complex(real, imaginary);
	comp0.show(1);
	cout << " Целая часть второго комплексного числа: "; cin >> real;
	cout << " Мнимая часть второго комплексного числа: "; cin >> imaginary;
	Complex comp1 = Complex(real, imaginary);
	comp1.show(2);
	cout << "  Арифметические действия с комплексными числами\n "
		 << "======================\n";
	cout << " 1. Сумма: "; (comp0 + comp1).show();
	cout << " 2. Разность: "; (comp0 - comp1).show();
	cout << " 3. Произведение: "; (comp0 * comp1).show();
	cout << " 4. Частное: "; (comp0 / comp1).show();
	cout << " 5. Присваивание: "; (comp0 = comp1).show();

	while (!_kbhit());
}

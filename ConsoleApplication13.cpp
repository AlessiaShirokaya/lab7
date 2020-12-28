// ConsoleApplication13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Шабло́ны (англ. template) — средство языка C++, предназначенное для кодирования обобщённых алгоритмов, без привязки к некоторым параметрам (например, типам данных, размерам буферов, значениям по умолчанию)
// Шаблоны позволяют определить конструкции (функции, классы), которые используют определенные типы, но на момент написания кода точно не известно, что это будут за типы. 
// Иными словами, шаблоны позволяют определить универсальные конструкции, которые не зависят от определенного типа.

#include <iostream>

using namespace std;


template <class T>
class dateElem
{
public:
	T number;
};

template <class T>
class date
{
	dateElem<T>* day, * month, * year;
public:
	date() :day(0), month(0), year(0) {};
	date(dateElem<T>* d, dateElem<T>* m, dateElem<T>* y) {
		day = d;
		month = m;
		year = y;
	}
	date<T>* changeDate(date<T>* ob);
	int numberBeforeNY(date<T>* ob);
	bool operator !=(date<T>* ob);
	date<T>* operator-(date<T>* ob);
	void Show_date(date<T>* obj);
};

template <class T> 
date<T>* date<T>::operator-(date<T>* ob)  // разница между двумя днями
{
	int d, m, y;
	int daysMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	date<int>* maxDate;
	date<int>* differenceRez;
	if (date::year->number > ob->year->number)
	{
		if (date::day->number < ob->day->number)
		{
			m = date::month->number - 1;
			d = daysMonth[m] + date::day->number - ob->day->number;
			if (m < ob->month->number)
			{
				y = date::year->number - 1;
				m = 12 + m - ob->month->number;
				y = y - ob->year->number;
			}
			else
			{
				m = m - ob->month->number;
				y = date::year->number - ob->year->number;
			}
		}
		else
		{
			d = date::day->number - ob->day->number;
			if (date::month->number < ob->month->number)
			{
				y = date::year->number - 1;
				m = 12 + date::month->number - ob->month->number;
				y = y - ob->year->number;
			}
			else
			{
				m = date::month->number - ob->month->number;
				y = date::year->number - ob->year->number;
			}
		}
	}
	else if (date::year->number < ob->year->number)
	{
		if (date::day->number > ob->day->number)
		{
			m = ob->month->number - 1;
			d = daysMonth[m] + ob->day->number - date::day->number;
			if (m < date::month->number)
			{
				y = ob->year->number - 1;
				m = 12 + m - date::month->number;
				y = y - date::year->number;
			}
			else
			{
				m = m - date::month->number;
				y = ob->year->number - date::year->number;
			}
		}
		else
		{
			d = ob->day->number - date::day->number;
			if (date::month->number > ob->month->number)
			{
				y = ob->year->number - 1;
				m = 12 + ob->month->number - date::month->number;
				y = y - date::year->number;
			}
			else
			{
				m = ob->month->number - date::month->number;
				y = ob->year->number - date::year->number;
			}
		}
	}
	else {
		if (date::day->number < ob->day->number)
		{
			m = date::month->number - 1;
			d = daysMonth[m] + date::day->number - ob->day->number;
			if (m < ob->month->number)
			{
				m = 12 + m - ob->month->number;
				y = 0;
			}
			else
			{
				m = m - ob->month->number;
				y = 0;
			}
		}
		else
		{
			d = date::day->number - ob->day->number;
			if (date::month->number < ob->month->number)
			{
				y = date::year->number - 1;
				m = 12 + date::month->number - ob->month->number;
				y = 0;
			}
			else
			{
				m = date::month->number - ob->month->number;
				y = 0;
			}
		}
	}
	dateElem<int>* d1 = new dateElem<int>;
	d1->number = d;
	dateElem<int>* m1 = new dateElem<int>;
	m1->number = m;
	dateElem<int>* y1 = new dateElem<int>;
	y1->number = y;
	differenceRez = new date<int>(d1, m1, y1);
	return differenceRez;
}

template <class T>
bool date<T>::operator !=(date<T>* da) // проверка двух дат на неравенство
{
	if (date::day->number == da->day->number && date::month->number == da->month->number && date::year->number == da->year->number)
		return false;
	else
	{
		return true;
	}
}

template <class T>
int date<T>::numberBeforeNY(date<T>* ob) // до нвого года
{
	int number = 0;
	int daysMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (ob->month->number == 12)
	{
		number = 31 - ob->day->number;
	}
	else {
		number = daysMonth[(ob->month->number - 1)] - ob->day->number;
		int i = ob->month->number;
		while (i != 12)
		{
			number += daysMonth[(i - 1)];
			i++;
		}
	}
	return number;
}

template <class T>
void date<T>::Show_date(date<T>* obj) // показать дату
{
	if (obj == NULL) {
		return;
	}
	cout << obj->day->number;
	cout << ".";
	cout << obj->month->number;
	cout << ".";
	cout << obj->year->number << endl;
}

template <class T>
date<T>* date<T>::changeDate(date<T>* ob) // ввести дату
{
	int d, m, y;
	cout << "День=";
	cin >> d;
	cout << endl;
	cout << "Месяц=";
	cin >> m;
	cout << endl;
	cout << "Год=";
	cin >> y;
	cout << endl;
	dateElem<int>* d1 = new dateElem<int>;
	d1->number = d;
	dateElem<int>* m1 = new dateElem<int>;
	m1->number = m;
	dateElem<int>* y1 = new dateElem<int>;
	y1->number = y;
	date<T>* objRez = new date<T>(d1, m1, y1);
	ob->day = d1;
	ob->month = m1;
	ob->year = y1;
	return objRez;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	dateElem<int>* a = new dateElem<int>;
	date<int> daaaat;
	date<int>* example = new date<int>(a, a, a);
	int ch;
	do {
		cout << endl << endl << "1 - ввести дату; \n2 - определить количество дней до нового года \n3 - вывод на дисплей; \n4 - проверка на неравенство; \n5 - интервал между датами; \n6 - завершить" << endl;
		cout << "Выбор действия: ";
		cin >> ch;
		switch (ch) {
		case 1:
			rewind;
			cout << "Изменить дату";
			cout << endl;
			daaaat.changeDate(example);
			break;
		case 2:
			rewind;
			cout << "Растчет количество дней" << endl;
			cout << "Дней до Нового Года=" << daaaat.numberBeforeNY(example);
			break;
		case 3:
			daaaat.Show_date(example);
			break;
		case 4:
		{cout << "Проверка на неравенство";
		cout << endl;
		date<int>* forCheck = new date<int>(a, a, a);
		daaaat.changeDate(forCheck);
		if (example->operator!=(forCheck))
		{
			cout << "Не совпадают";
		}
		else {
			cout << "Совпадают";
		}
		cout << endl;
		break; }
		case 5:
		{cout << "";
		cout << endl;
		date<int>* forCheck2 = new date<int>(a, a, a);
		daaaat.changeDate(forCheck2);
		date<int>* rez2 = example->operator-(forCheck2);
		cout << "Разница между датами=";
		daaaat.Show_date(rez2);
		break;
		}
		case 6:
			break;
		}
	} while (ch != 6);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

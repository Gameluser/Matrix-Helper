

#include "stdafx.h"
#include "Massive_S.h"
#include "Matrica_S.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
vector<int> massiv;
vector<vector<int>> matrix;
ofstream fout; 
char put_def[100];
int min, max, size2;
int col_stlb, col_str;
int Random(int min, int max);
void Logo(int i);
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int proc = 0, size = 0, col_stlb0 = 0, col_str0 = 0, lever, lever_m = -1, count = 0;
	while (lever_m == -1)
	{
		system("cls");
		Logo(proc);
		proc++;
		cout << "|Ввод массива с клавиатуры(1)|" << endl;
		cout << "|Генерация случайного массива(2)|" << endl;
		cout << "|Ввод матрицы с клавиатуры(3)|" << endl;
		cout << "|Генерация случайной матрицы(4)|" << endl;
		cout << "|Выход (0)|" << endl;
		cin >> lever_m;
		system("cls");
		if (lever_m == 1)
		{
			cout << "Ввод длины массива ->";
			cin >> size2;
			size2--;
			massiv = vvod_massiva(size2, massiv);
		}
		else if (lever_m == 2)
		{
			cout << "Ввод длины массива ->";
			cin >> size2;
			size2--;
			cout << "!!!Внимание!!! Число 0 распознается как пустая ячейка !!!Внимание!!!" << endl;
			cout << "Минимальное число диапазона генерации чисел ->";
			cin >> min;
			cout << "Максимальное число диапазона генерации чисел ->";
			cin >> max;
			system("cls");
			massiv = zapolnenie(size, size2, 921, massiv);
		}
		else if (lever_m == 3)
		{
			cout << "Ввод размера матрицы" << endl;
			cout << "Количество столбиков ->";
			cin >> col_stlb;
			cout << "Количество строк ->";
			cin >> col_str;
			col_stlb--;
			col_str--;
			matrix = vvod_matrici(col_stlb, col_str, matrix);
		}
		else if (lever_m == 4)
		{
			cout << "Ввод размера матрицы" << endl;
			cout << "Количество столбиков ->";
			cin >> col_stlb;
			cout << "Количество строк ->";
			cin >> col_str;
			col_stlb--;
			col_str--;
			cout << "!!!Внимание!!! Число 0 распознается как пустая ячейка !!!Внимание!!!" << endl;
			cout << "Минимальное число диапазона генерации чисел ->";
			cin >> min;
			cout << "Максимальное число диапазона генерации чисел ->";
			cin >> max;
			system("cls");
			matrix = zapolnenie_matrici(col_stlb0, col_str0, col_stlb, col_str, 921, matrix);
		}
		else if (lever_m == 0)
		{
			return 0;
		} 
		else 
		{
			lever_m = -1;
		}
		while (lever_m == 1 || lever_m == 2)
		{
			system("cls");
			vivod_massiva(size2, massiv);
			cout << "|Увеличить размер массива (1)|" << endl << "|Изменить элемент массива (2)|" << endl << "|Изменить диапазон генерации (3)|" << endl;
			cout << "|Отсортировать массив (4)|" << endl << "|Вставить элемент в массив (5)|" << endl << "|Пересоздать массив (6)|" << endl;
			cout << "|Запись маccива в файл (7)|" << endl << "|Изменить путь по умолчанию (8)|" << endl << "|Назад (0)|" << endl;
			cin >> lever;
			system("cls");
			if (lever == 1)
			{
				cout << "Количество элементов добавляемых к массиву ->";
				int v;
				cin >> v;
				int lever_1;
				cout << "Заполнить случайными значениями, или одним вашим?" << endl;
				cout << "|Случайные значения (1)|" << endl << "|Моё значение (2)|" << endl << "|Назад (0)|" << endl;
				cin >> lever_1;
				if (lever_1 == 1)
				{
					size = size2;
					size2 += v;
					massiv = zapolnenie(size, size2, 921, massiv);
				}
				else if (lever_1 == 2)
				{
					size = size2;
					size2 += v;
					int n;
					cout << "Моё значение ->";
					cin >> n;
					massiv = zapolnenie(size, size2, n, massiv);
				}
				else if (lever_1 == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 2)
			{
				int n, z;
				cout << "Номер элемента ->";
				cin >> n;
				cout << "Значение ->";
				cin >> z;
				massiv[n] = z;
			}
			else if (lever == 3)
			{
				system("cls");
				cout << "!!!Внимание!!! Число 0 распознается как пустая ячейка !!!Внимание!!!" << endl;
				cout << "Минимальное число диапазона генерации чисел ->";
				cin >> min;
				cout << "Максимальное число диапазона генерации чисел ->";
				cin >> max;
				cout << "Пересоздать массив? (1-Да, 0 - Нет)" << endl;
				int lever2;
				cin >> lever2;
				if (lever2 == 1)
				{
					size = 0;
					massiv = rezapolnenie(size, size2, 921, massiv);
				}
			}
			else if (lever == 4)
			{
				system("cls");
				int lever_c;
				cout << "|По возрастанию (1)|" << endl;
				cout << "|По убыванию (2)|" << endl;
				cout << "|Выход (0)|" << endl;
				cin >> lever_c;
				if (lever_c == 1)
					massiv = sortirovka(size2, massiv, 1);
				else if (lever_c == 2)
					massiv = sortirovka(size2, massiv, 2);
				else if (lever_c == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 5)
			{
				int n, z;
				cout << "Позиция вставки ->";
				cin >> n;
				cout << "Значение вставки ->";
				cin >> z;
				massiv = vstavka(n, z, size2, massiv);
				size2++;
			}
			else if (lever == 6)
			{
				system("cls");
				int lever_1;
				cout << "Заполнить случайными значениями, или одним вашим?" << endl;
				cout << "|Случайные значения (1)|" << endl << "|Моё значение (2)|" << endl << "|Назад (0)|" << endl;
				cin >> lever_1;
				if (lever_1 == 1)
				{
					massiv = rezapolnenie(size, size2, 921, massiv);
				}
				else if (lever_1 == 2)
				{
					int n;
					cout << "Моё значение ->";
					cin >> n;
					massiv = rezapolnenie(size, size2, n, massiv);
				}
				else if (lever_1 == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 7)
			{
				count++;
				system("cls");
				char put[100];
				if (count == 1 && put_def[1] == '\0')
				{
					cout << "Введите адрес по умолчанию, для открытия или создания файла (Пример: D:\\Desktop\\Matrica.txt)" << endl;
					cout << "!!!Внимание!!!Перед записью файл будет отформатирован!!!Внимание!!!" << endl << "->";
					cin >> put_def;
					system("cls");
				}
				cout << "Выберите путь для открытия или создания файла" << endl;
				cout << "Путь по умолчанию |(1)|" << endl << "Свой путь |(2)|" << endl << "Назад |(0)|" << endl;
				int lever_v;
				cin >> lever_v;
				system("cls");
				if (lever_v == 1)
				{
					fout.open(put_def, ios::trunc);
					if (fout.is_open() == 0)
					{
						cout << "По заданому пути нельзя создать/открыть файл" << endl;
						Sleep(2000);
						system("cls");
						vivod_massiva(size2, massiv);
					}
					else
					{
						zapisvfailmass(size2, massiv, fout);
						system("cls");
						cout << "Маccив помещен в файл по заданому пути" << endl;
						Sleep(2000);
						system("cls");
						vivod_massiva(size2, massiv);
					}
					fout.close();
				}
				else if (lever_v == 2)
				{
					cout << "Введите адрес для открытия или создания файла (Пример: D:\\Desktop\\Matrica.txt)" << endl;
					cin >> put;
					fout.open(put, ios::trunc);
					if (fout.is_open() == 0)
					{
						cout << "По заданому пути нельзя создать/открыть файл" << endl;
						Sleep(2000);
						system("cls");
						vivod_massiva(size2, massiv);
					}
					else
					{
						zapisvfailmass(size2, massiv, fout);
						system("cls");
						cout << "Матрица помещена в файл по заданому пути" << endl;
						Sleep(2000);
						system("cls");
						vivod_massiva(size2, massiv);
					}
				}
				else if (lever_v == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 8)
			{
				system("cls");
				cout << "Введите адрес по умолчанию для открытия или создания файла (Пример: D:\\Desktop\\Matrica.txt)" << endl;
				cout << "!!!Внимание!!! Перед записью файл будет отформатирован !!!Внимание!!!" << endl << "->";
				cin >> put_def;
				system("cls");
			}
			else if (lever == 0)
			{
			lever_m = -1;
			massiv.clear();
			size2 = 0;
			size = 0;
			}
		}
		while (lever_m == 3 || lever_m == 4)
		{
			system("cls");
			vivod_matrici(col_stlb, col_str, matrix);
			cout << "|Увеличить размер матрицы (1)|" << endl << "|Изменить значение в матрице (2)|" << endl << "|Изменить диапазон генерации (3)|" << endl;
			cout << "|Отсортировать матрицу (4)|" << endl << "|Расширить матрицу (5)|" << endl << "|Пересоздать матрицу (6)|" << endl;
			cout << "|Редактирование матрицы (7)|" << endl << "|Запись матрицы в файл (8)|" << endl << "|Изменить путь по умолчанию (9)|" << endl;
			cout << "|Калькулятор матриц (10)|" << endl << "|Назад (0)|" << endl;
			cin >> lever;
			system("cls");
			if (lever == 1)
			{
				system("cls");
				int col_stlb2 = col_stlb, col_str2 = col_str;
				cout << "Ввод размера новой матрицы ->";
				cin >> col_stlb >> col_str;
				col_stlb--;
				col_str--;
				int lever_1;
				cout << "Заполнить случайными значениями, или одним вашим?" << endl;
				cout << "|Случайные значения (1)|" << endl << "|Моё значение (2)|" << endl << "|Назад (0)|" << endl;
				cin >> lever_1;
				if (lever_1 == 1)
				{
					matrix = zapolnenie_matrici(col_stlb2, col_str2, col_stlb, col_str, 921, matrix);
				}
				else if (lever_1 == 2)
				{
					int n;
					cout << "Моё значение ->";
					cin >> n;
					matrix = zapolnenie_matrici(col_stlb2, col_str2, col_stlb, col_str, n, matrix);
				}
				else if (lever_1 == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 2)
			{
				system("cls");
				int x, y, z;
				vivod_matrici(col_stlb, col_str, matrix);
				cout << "Позиция заменяемого элемента (столбик, х) ->";
				cin >> x;
				cout << "Позиция заменяемого элемента (ряд, y) ->";
				cin >> y;
				cout << "Значение заменяемого элемента ->";
				cin >> z;
				matrix[x - 1][y - 1] = z;
			}
			else if (lever == 3)
			{
				system("cls");
				cout << "!!!Внимание!!! Число 0 распознается как пустая ячейка !!!Внимание!!!" << endl;
				cout << "Минимальное число диапазона генерации чисел ->";
				cin >> min;
				cout << "Максимальное число диапазона генерации чисел ->";
				cin >> max;
				cout << "Пересоздать матрицу? (1-Да, 0 - Нет)" << endl;
				int lever2;
				cin >> lever2;
				if (lever2 == 1)
				{
					matrix = rezapolnenie_matrici(0, 0, col_stlb, col_str, 921, matrix);
				}
			}
			else if (lever == 4)
			{
				system("cls");
				int lever_c;
				cout << "|По возрастанию (1)|" << endl;
				cout << "|По убыванию (2)|" << endl;
				cout << "|Выход (0)|" << endl;
				cin >> lever_c;
				if (lever_c == 1)
				matrix = sortirovka_matrici(col_stlb, col_str, matrix, 1);
				else if (lever_c == 2)
				matrix = sortirovka_matrici(col_stlb, col_str, matrix, 2);
				else if (lever_c == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 5)
			{
				system("cls");
				vivod_matrici(col_stlb, col_str, matrix);
				cout << "|Добавить пустые ряды сверху (1)|" << endl;
				cout << "|Добавить пустые ряды снизу (2)|" << endl;
				cout << "|Добавить пустые столбики справа (3)|" << endl;
				cout << "|Добавить пустые столбики слева (4)|" << endl;
				cout << "|Выход (0)|" << endl;
				int lever_v, col;
				cin >> lever_v;
				system("cls");
				if (lever_v == 1)
				{
					cout << "Колличество рядов -> ";
					cin >> col;
					matrix = rashr_matrici(col_str, col_stlb, matrix, 1, col);
				}
				else if (lever_v == 2)
				{
					cout << "Колличество рядов -> ";
					cin >> col;
					matrix = rashr_matrici(col_str, col_stlb, matrix, 2, col);

				}
				else if (lever_v == 3)
				{
					cout << "Колличество столбиков -> ";
					cin >> col;
					matrix = rashr_matrici(col_str, col_stlb, matrix, 3, col);
				}
				else if (lever_v == 4)
				{
					cout << "Колличество столбиков -> ";
					cin >> col;
					matrix = rashr_matrici(col_str, col_stlb, matrix, 4, col);
				}
				else if (lever_v == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 6)
			{
				system("cls");
				int lever_1;
				cout << "Заполнить случайными значениями, или одним вашим?" << endl;
				cout << "|Случайные значения (1)|" << endl << "|Моё значение (2)|" << endl << "|Перезаписать матрицу вручную (3)|" << endl << "|Назад (0)|" << endl;
				cin >> lever_1;
				if (lever_1 == 1)
				{
					system("cls");
					cout << "Генерация чисел произойдет по текущим значениям: Min = " << min << ", Max = " << max << endl;
					cout << "Смена параметров генерации производится в контекстном меню" << endl;
					Sleep(2000);
					matrix = rezapolnenie_matrici(col_stlb0, col_str0, col_stlb, col_str, 921, matrix);
				}
				else if (lever_1 == 2)
				{
					int n;
					cout << "Моё значение ->";
					cin >> n;
					matrix = rezapolnenie_matrici(col_stlb0, col_str0, col_stlb, col_str, n, matrix);
				}
				else if (lever_1 == 3)
				{
					cout << "Ввод размера матрицы" << endl;
					cin >> col_stlb;
					cout << "X" << endl;
					cin >> col_str;
					col_stlb--;
					col_str--;
					matrix.clear();
					matrix = vvod_matrici(col_stlb, col_str, matrix);
				}
				else if (lever_1 == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 7)
			{
				system("cls");
				vivod_matrici(col_stlb, col_str, matrix);
				cout << "|Редактировать строку (1)|" << endl << "|Редактировать столбик(2)|" << endl;
				cout << "|Назад(0)|" << endl;
				int lever_v;
				cin >> lever_v;
				if (lever_v == 1)
				{
					cout << "Номер строки ->";
					int y;
					cin >> y;
					matrix = redriadmatr(y, col_stlb, matrix);
					system("cls");
					vivod_matrici(col_stlb, col_str, matrix);
				}
				else if (lever_v == 2)
				{
					cout << "Номер столбика ->";
					int x;
					cin >> x;
					matrix = redstolbmatr(x, col_str, matrix);
					system("cls");
					vivod_matrici(col_stlb, col_str, matrix);
				}
				else if (lever_v == 0)
				{
					lever = -1;
				}
			}
			else if (lever == 8)
			{
				count++;
				system("cls");
				char put[100];
				if (count == 1 && put_def[1] == '\0')
				{
					cout << "Введите адрес по умолчанию, для открытия или создания файла (Пример: D:\\Desktop\\Matrica.txt)" << endl;
					cout << "!!!Внимание!!!Перед записью файл будет отформатирован!!!Внимание!!!" << endl << "->";
					cin >> put_def;
					system("cls");
				}
				cout << "Выберите путь для открытия или создания файла" << endl;
				cout << "Путь по умолчанию |(1)|" << endl << "Свой путь |(2)|" << endl << "Назад |(0)|" << endl;
				int lever_c;
				cin >> lever_c;
				system("cls");
				if (lever_c == 1)
				{
					fout.open(put_def, ios::trunc);
					if (fout.is_open() == 0)
					{
						cout << "По заданому пути нельзя создать/открыть файл" << endl;
						Sleep(2000);
						system("cls");
						vivod_matrici(col_stlb, col_str, matrix);
					}
					else
					{
						zapisvfailmatr(col_stlb, col_str, matrix, fout);
						system("cls");
						cout << "Матрица помещена в файл по заданому пути" << endl;
						Sleep(2000);
						system("cls");
						vivod_matrici(col_stlb, col_str, matrix);
					}
				}
				else if (lever_c == 2)
				{
					cout << "Введите адрес для открытия или создания файла (Пример: D:\\Desktop\\Matrica.txt)" << endl;
					cin >> put;
					fout.open(put, ios::trunc);
					if (fout.is_open() == 0)
					{
						cout << "По заданому пути нельзя создать/открыть файл" << endl;
						Sleep(2000);
						system("cls");
						vivod_matrici(col_stlb, col_str, matrix);
					}
					else
					{
						zapisvfailmatr(col_stlb, col_str, matrix, fout);
						system("cls");
						cout << "Матрица помещена в файл по заданому пути" << endl;
						Sleep(2000);
						system("cls");
						vivod_matrici(col_stlb, col_str, matrix);
					}
				}
				else if (lever_c == 0)
				{
					lever = -1;
				}
				fout.close();
			}
			else if (lever == 9)
			{
				system("cls");
				cout << "Введите адрес по умолчанию для открытия или создания файла (Пример: D:\\Desktop\\Matrica.txt)" << endl;
				cout << "!!!Внимание!!! Перед записью файл будет отформатирован !!!Внимание!!!" << endl << "->";
				cin >> put_def;
				system("cls");
			}
			else if (lever == 10)
			{
				int lever_mat = 999;
				while (lever_mat == 999)
				{
					system("cls");
					cout << "|Возможные действия:|" << endl;
					cout << "|(1) Умножение на число|" << endl;
					cout << "|(2) Суммирование двух матриц|" << endl;
					cout << "|(3) Разница двух матриц|" << endl;
					cout << "|(4) Умножение двух матриц|" << endl;
					cout << "|(5) Поднесение матрицы в степень|" << endl;
					cout << "|(6) Транспонирование матрицы|" << endl;
					cout << "|(0) Назад|" << endl;
					cin >> lever_mat;
					system("cls");
					if (lever_mat == 1)
					{
						int n;
						//vector<vector<int>> matrixbuff;
						system("cls");
						int lever_g;
						cout << "Использовать матрицу:" << endl;
						cout << "(1)Уже заданную" << endl;
						cout << "(2)Новою" << endl;
						cin >> lever_g;
						if (lever_g == 1)
						{
							cout << "Ввод числа на которое умножаем ->";
							cin >> n;
							matrix = mnojmatrnachisl(col_stlb, col_str, n, matrix);
							vivod_matrici(col_stlb, col_str, matrix);
						}
						else if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cin >> col_stlb;
							cout << "X" << endl;
							cin >> col_str;
							col_stlb--;
							col_str--;
							matrix.clear();
							matrix = vvod_matrici(col_stlb, col_str, matrix);
							cout << "Ввод числа на которое умножаем ->";
							cin >> n;
							matrix = mnojmatrnachisl(col_stlb, col_str, n, matrix);
							vivod_matrici(col_stlb, col_str, matrix);
						}

					}
					else if (lever_mat == 2)
					{
						vector<vector<int>> matrix2;
						int col_stlb1, col_str1;
						system("cls");
						int lever_g;
						cout << "Первая матрица:" << endl;
						cout << "(1)Уже заданная" << endl;
						cout << "(2)Новая" << endl;
						cin >> lever_g;
						if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cout << "Количество столбиков ->";
							cin >> col_stlb;
							cout << "Количество строк ->";
							cin >> col_str;
							col_stlb--;
							col_str--;
							matrix.clear();
							matrix = vvod_matrici(col_stlb, col_str, matrix);
						}
						cout << "Вторая матрица:" << endl;
						cout << "(1)Уже заданная" << endl;
						cout << "(2)Новая" << endl;
						cin >> lever_g;
						if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cout << "Количество столбиков ->";
							cin >> col_stlb1;
							cout << "Количество строк ->";
							cin >> col_str1;
							col_stlb1--;
							col_str1--;
							matrix2 = vvod_matrici(col_stlb1, col_str1, matrix2);
						}
						else if (lever_g == 1)
						{
							matrix2 = matrix;
							col_stlb1 = col_stlb;
							col_str1 = col_str;
						}
						matrix = dodmatric(col_stlb1, col_str1, col_stlb, col_str, matrix, matrix2);
						vivod_matrici(col_stlb, col_str, matrix);
					}
					else if (lever_mat == 3)
					{
						vector<vector<int>> matrix2;
						int col_stlb1, col_str1;
						system("cls");
						int lever_g;
						cout << "Первая матрица:" << endl;
						cout << "(1)Уже заданная" << endl;
						cout << "(2)Новая" << endl;
						cin >> lever_g;
						if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cout << "Количество столбиков ->";
							cin >> col_stlb;
							cout << "Количество строк ->";
							cin >> col_str;
							col_stlb--;
							col_str--;
							matrix.clear();
							matrix = vvod_matrici(col_stlb, col_str, matrix);
						}
						cout << "Вторая матрица:" << endl;
						cout << "(1)Уже заданная" << endl;
						cout << "(2)Новая" << endl;
						cin >> lever_g;
						if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cout << "Количество столбиков ->";
							cin >> col_stlb1;
							cout << "Количество строк ->";
							cin >> col_str1;
							col_stlb1--;
							col_str1--;
							matrix2 = vvod_matrici(col_stlb1, col_str1, matrix2);
						}
						else if (lever_g == 1)
						{
							matrix2 = matrix;
							col_stlb1 = col_stlb;
							col_str1 = col_str;
						}
						matrix = vidnimmatric(col_stlb1, col_str1, col_stlb, col_str, matrix, matrix2);
						vivod_matrici(col_stlb, col_str, matrix);
					}
					else if (lever_mat == 4)
					{
						vector<vector<int>> matrix2;
						int col_stlb1, col_str1;
						system("cls");
						int lever_g;
						cout << "Первая матрица:" << endl;
						cout << "(1)Уже заданная" << endl;
						cout << "(2)Новая" << endl;
						cin >> lever_g;
						if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cout << "Количество столбиков ->";
							cin >> col_stlb;
							cout << "Количество строк ->";
							cin >> col_str;
							col_stlb--;
							col_str--;
							matrix.clear();
							matrix = vvod_matrici(col_stlb, col_str, matrix);
						}
						cout << "Вторая матрица:" << endl;
						cout << "(1)Уже заданная" << endl;
						cout << "(2)Новая" << endl;
						cin >> lever_g;
						if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cout << "Количество столбиков ->";
							cin >> col_stlb1;
							cout << "Количество строк ->";
							cin >> col_str1;
							col_stlb1--;
							col_str1--;
							matrix2 = vvod_matrici(col_stlb1, col_str1, matrix2);
						}
						else if (lever_g == 1)
						{
							matrix2 = matrix;
							col_stlb1 = col_stlb;
							col_str1 = col_str;
						}
						matrix = mnojmatric(col_stlb, col_str, col_stlb1, col_str1, matrix, matrix2);
						vivod_matrici(col_stlb, col_str, matrix);
					}
					else if (lever_mat == 5)
					{
						int n;
						//vector<vector<int>> matrixbuff;
						system("cls");
						int lever_g;
						cout << "Использовать матрицу:" << endl;
						cout << "(1)Уже заданную" << endl;
						cout << "(2)Новою" << endl;
						cin >> lever_g;
						if (lever_g == 1)
						{
							cout << "Ввод степеня к которому подносим матрицу ->";
							cin >> n;
							matrix = stepmatric(col_stlb, col_str, n, matrix);
							vivod_matrici(col_stlb, col_str, matrix);
						}
						else if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cin >> col_stlb;
							cout << "X" << endl;
							cin >> col_str;
							col_stlb--;
							col_str--;
							matrix.clear();
							matrix = vvod_matrici(col_stlb, col_str, matrix);
							cout << "Ввод степеня к которому подносим матрицу ->";
							cin >> n;
							matrix = stepmatric(col_stlb, col_str, n, matrix);
							vivod_matrici(col_stlb, col_str, matrix);
						}
					}
					else if (lever_mat == 6)
					{
						//vector<vector<int>> matrixbuff;
						system("cls");
						int lever_g;
						cout << "Использовать матрицу:" << endl;
						cout << "(1)Уже заданную" << endl;
						cout << "(2)Новою" << endl;
						cin >> lever_g;
						if (lever_g == 1)
						{
							matrix = transp(col_stlb, col_str, matrix);
							vivod_matrici(col_stlb, col_str, matrix);
						}
						else if (lever_g == 2)
						{
							cout << "Ввод размера матрицы" << endl;
							cin >> col_stlb;
							cout << "X" << endl;
							cin >> col_str;
							col_stlb--;
							col_str--;
							matrix.clear();
							matrix = vvod_matrici(col_stlb, col_str, matrix);
							matrix = transp(col_stlb, col_str, matrix);
							vivod_matrici(col_stlb, col_str, matrix);
						}
					}
					else if (lever_mat == 0)
					{
					lever = -1;
					}
					else
					{
						lever_mat = 999;
					}
				}
			}
			else if (lever == 0)
			{
			lever_m = -1;
			matrix.clear();
			col_stlb = 0;
			col_str = 0;
			}
		}
	}
	system("pause");

	return 0;
}
int Random(int min, int max) 
{
	if (min == max)
	{
		return min;
	}
	else
	return min + rand() % (max - min);
}
void Logo(int i)
{
	cout << endl;
	if (i == 0)
	{
		cout << R"( _____ ______   ________  _________  ________  ___     ___    ___  )" << endl;
		Sleep(300);
		cout << R"(|\   _ \  _   \|\   __  \|\___   ___\\   __  \|\  \   |\  \  /  /| )" << endl;
		Sleep(300);
		cout << R"(\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \|\  \ \  \  \ \  \/  / / )" << endl;
		Sleep(300);
		cout << R"( \ \  \\|__| \  \ \   __  \   \ \  \ \ \   _  _\ \  \  \ \    / /  )" << endl;
		Sleep(300);
		cout << R"(  \ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \\  \\ \  \  /     \/   )" << endl;
		Sleep(300);
		cout << R"(   \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\\ _\\ \__\/  /\   \   )" << endl;
		Sleep(300);
		cout << R"(    \|__|     \|__|\|__|\|__|    \|__|  \|__|\|__|\|__/__/ /\ __\  )" << endl;
		Sleep(300);
		cout << R"(    ___  ___  _______   ___       ________  _______   |__|/_\|__|  )" << endl;
		Sleep(300);
		cout << R"(   |\  \|\  \|\  ___ \ |\  \     |\   __  \|\  ___ \ |\   __  \    )" << endl;
		Sleep(300);
		cout << R"(   \ \  \\\  \ \   __/|\ \  \    \ \  \|\  \ \   __/|\ \  \|\  \   )" << endl;
		Sleep(300);
		cout << R"(    \ \   __  \ \  \_|/_\ \  \    \ \   ____\ \  \_|/_\ \   _  _\  )" << endl;
		Sleep(300);
		cout << R"(     \ \  \ \  \ \  \_|\ \ \  \____\ \  \___|\ \  \_|\ \ \  \\  \| )" << endl;
		Sleep(300);
		cout << R"(      \ \__\ \__\ \_______\ \_______\ \__\    \ \_______\ \__\\ _\ )" << endl;
		Sleep(300);
		cout << R"(       \|__|\|__|\|_______|\|_______|\|__|     \|_______|\|__|\|__|)" << endl;
		Sleep(300);
	}
	else if (i >= 1)
	{
		cout << R"( _____ ______   ________  _________  ________  ___     ___    ___  )" << endl;
		cout << R"(|\   _ \  _   \|\   __  \|\___   ___\\   __  \|\  \   |\  \  /  /| )" << endl;
		cout << R"(\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \|\  \ \  \  \ \  \/  / / )" << endl;
		cout << R"( \ \  \\|__| \  \ \   __  \   \ \  \ \ \   _  _\ \  \  \ \    / /  )" << endl;
		cout << R"(  \ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \\  \\ \  \  /     \/   )" << endl;
		cout << R"(   \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\\ _\\ \__\/  /\   \   )" << endl;
		cout << R"(    \|__|     \|__|\|__|\|__|    \|__|  \|__|\|__|\|__/__/ /\ __\  )" << endl;
		cout << R"(    ___  ___  _______   ___       ________  _______   |__|/_\|__|  )" << endl;
		cout << R"(   |\  \|\  \|\  ___ \ |\  \     |\   __  \|\  ___ \ |\   __  \    )" << endl;
		cout << R"(   \ \  \\\  \ \   __/|\ \  \    \ \  \|\  \ \   __/|\ \  \|\  \   )" << endl;
		cout << R"(    \ \   __  \ \  \_|/_\ \  \    \ \   ____\ \  \_|/_\ \   _  _\  )" << endl;
		cout << R"(     \ \  \ \  \ \  \_|\ \ \  \____\ \  \___|\ \  \_|\ \ \  \\  \| )" << endl;
		cout << R"(      \ \__\ \__\ \_______\ \_______\ \__\    \ \_______\ \__\\ _\ )" << endl;
		cout << R"(       \|__|\|__|\|_______|\|_______|\|__|     \|_______|\|__|\|__|)" << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
}



    
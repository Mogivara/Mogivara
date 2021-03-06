#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#define _crt_secure_no_warnings
#pragma warning(disable : 4996)
using namespace std;
/*
int n; 
void Gnome_sort(int i, int j, int *mas) {

	while (i<n)
	{ 
		if (mas[i - 1] <= mas[i]) 
	{ 
			i = j; j++; 
		} 
	else
	{
		int t = mas[i]; mas[i] = mas[i - 1];
	mas[i - 1] = t; 
	i--;
	if (i == 0)
	{ i = j; j++; }
	}
	} 
	/*cout << "Отсортированный массив: ";
	for (i = 0; i<n; i++) //вывод массива
		cout<<mas[i]<<" "; } 
void main() { 
	
	setlocale(LC_ALL,"Rus");
int m, k; cout<<"Размер массива > "; 
cin>>n;
auto begin = std::chrono::steady_clock::now();
int *a=new int[n]; 
for (k=0; k<n; k++) //ввод массива
{ ; 
a[k] = rand() % 100; }
k=1; m=2; 
Gnome_sort(k, m, a); //вызов функции сортировки 
cout << "\n";
auto end = std::chrono::steady_clock::now();
auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
std::cout << "The time: " << elapsed_ms.count() << " ms\n";
delete []a; 
system("pause>>void"); }
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Сортировка выбором
/*
void choicesSort(int*, int); // прототип функции сортировки выбором

int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	int size_array; // длинна массива
	cin >> size_array;
	auto begin = std::chrono::steady_clock::now();
	getchar();
	int *sorted_array = new int[size_array]; // одномерный динамический массив
	for (int counter = 0; counter < size_array; counter++)
	{
		sorted_array[counter] = rand() % 100; // заполняем массив случайными числами
		//cout << setw(2) << sorted_array[counter] << "  "; // вывод массива на экран
	}
	cout << "\n\n";
	auto end = std::chrono::steady_clock::now();
	choicesSort(sorted_array, size_array); // вызов функции сортировки выбором

/*	for (int counter = 0; counter < size_array; counter++)
	{
		cout << setw(2) << sorted_array[counter] << "  "; // печать отсортированного массива
	}
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";
	cout << "\n";
	delete[] sorted_array; // высвобождаем память
	system("pause");
	return 0;
}

void choicesSort(int* arrayPtr, int length_array) // сортировка выбором
{
	for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
	{
		int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
		{
			if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
			{
				temp = arrayPtr[repeat_counter];
				arrayPtr[repeat_counter] = arrayPtr[element_counter];
				arrayPtr[element_counter] = temp;
			}
		}
	}
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////сортировка слиянием c++
/*
// Функция сортировки двухпутевым слиянием
void merge(int *a, int n)
{
	int mid = n / 2; // находим середину сортируемой последовательности
	if (n % 2 == 1)
		mid++;
	int h = 1; // шаг
			   // выделяем память под формируемую последовательность
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // индекс первого пути
		int j = mid; // индекс второго пути
		int k = 0;   // индекс элемента в результирующей последовательности
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // пока не дошли до конца пути
			  // заполняем следующий элемент формируемой последовательности
			  // меньшим из двух просматриваемых
				if (a[i] < a[j])
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i < step)
			{ // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j<n))
			{  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // переходим к следующему этапу
		}
		h = h * 2;
		// Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
		for (i = 0; i<n; i++)
			a[i] = c[i];
	}
}
int main()
{
	auto begin = std::chrono::steady_clock::now();
	int a[36000];
	// Заполнение массива случайными числами
	for (int i = 0; i<36000; i++)
		a[i] = rand() % 100 - 10;
	// Вывод элементов массива до сортировки
	/*for (int i = 0; i<8; i++)
		printf("%d ", a[i]);
	printf("\n");
	merge(a, 8); // вызов функции сортировки
				 // Вывод элементов массива после сортировки
	/*for (int i = 0; i<8; i++)
		printf("%d ", a[i]);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";
	printf("\n");
	getchar();
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////Быстрая сортировка c++

void quickSort(int *numbers, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = numbers[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо 
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	auto begin = std::chrono::steady_clock::now();
	
	int a[45000];
	// Заполнение массива случайными числами
	for (int i = 0; i<45000; i++)
		a[i] = rand() % 100 - 10;
	// Вывод элементов массива до сортировки
	
	/*for (int i = 0; i<30000; i++)
		printf("%d ", a[i]);
	printf("\n");*/
	quickSort(a, 0, 45000); // вызов функции сортировки
						// Вывод элементов массива после сортировки
	/*for (int i = 0; i<30000; i++)
		printf("%d ", a[i]);*/
	auto end = std::chrono::steady_clock::now();
	printf("\n");
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";
	getchar();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////Линейные вставки c++




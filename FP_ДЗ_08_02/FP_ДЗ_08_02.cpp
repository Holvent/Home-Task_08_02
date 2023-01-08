#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	cout << "Home task #8.2.1\n\n";
	//В одномерном массиве, заполненном случайными числами,
	//определить минимальный и максимальный элементы.
	const int SIZE = 10;
	int arr[SIZE]{};
	int min, max;
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 20 + 1;
		cout << arr[i] << ' ';
	}
	min = arr[0];
	max = arr[0];
	for (int j = 1; j < SIZE; j++) {
		if (arr[j] > max) max = arr[j];
		if (arr[j] < min) min = arr[j];
	}
	cout << "\nmin: " << min << "\nmax: " << max;

	cout << "\n\nHome task #8.2.2\n\n";
	//В одномерном массиве, заполненном случайными числами
	//в заданном пользователем диапазоне, найти сумму элементов,
	//значения которых меньше указанного пользователем.
	const int SIZE1 = 10;
	int arr1[SIZE1]{};
	int a, b, sum = 0, num;
	cout << "Введите начало диапазона для генерации чисел -> ";
	cin >> a;
	cout << "Введите конец диапазона -> ";
	cin >> b;
	cout << "Введите уровень для суммирования -> ";
	cin >> num;
	for (int i = 0; i < SIZE1; i++) {
		arr1[i] = a + rand() % (b - a);
		cout << arr1[i] << ' ';
	}
	for (int i = 0; i < SIZE1; i++)
		if (arr1[i] < num) sum += arr1[i];
	cout << "\nСумма:" << sum;

	cout << "\n\nHome task #8.2.3\n\n";
	//Пользователь вводит прибыль фирмы за год(12 месяцев).
	//Затем пользователь вводит диапазон(например, 3 и 6 — поиск
	//между 3 - м и 6 - м месяцем).Необходимо определить месяц,
	//в котором прибыль была максимальна и месяц, в котором
	//прибыль была минимальна с учетом выбранного диапазона.
	const int SIZE2 = 12;
	int arr2[SIZE2]{};
	int start, end, minProfit, maxProfit;
	for (int i = 0; i < SIZE2; i++){
		cout << "Введите вашу прибиль за " << i + 1<< " месяц: ";
		cin >> arr2[i];
	}
	cout << "Введите начало диапазона(мес) -> ";
	cin>>start;
	cout << "Введите конец диапазона(мес) -> ";
	cin >> end;
	minProfit = start - 1;
	maxProfit = start - 1;
	for (int i = start; i <= end - 1; i++){
		if (arr2[i] > arr2[maxProfit]) maxProfit = i;
		if (arr2[i] < arr2[minProfit]) minProfit = i;
	}
	cout << "Минимальная прибыль, (в указанном диапазоне) была в " << minProfit + 1 << " месяце\n";
	cout << "Максимальная прибыль, (в указанном диапазоне) была в " << maxProfit + 1 << " месяце\n";

	cout << "\n\nHome task #8.2.4\n\n";
	//В одномерном массиве, состоящем из N вещественных
	//чисел вычислить :
	//■ Сумму отрицательных элементов.
	//■ Произведение элементов, находящихся между min и max
	//элементами.
	//■ Произведение элементов с четными номерами.
	//■ Сумму элементов, находящихся между первым и последним отрицательными элементами.

	double sumNegativeElem = 0, minElem , maxElem, mult1 = 1, mult2 = 1, sumElem = 0;
	int temp1, temp2, firstNegative = 1, lastNegative;
	const int N = 10;
	double arr3[N]{ -1.2,-4.1,-4.2,5.7,6.1,2.5,1.8,-2.4,5.2,2.6 };

	minElem = arr3[0];
	maxElem = arr3[0];
	for (int i = 0; i < N, firstNegative>0; i++)
		if (firstNegative > arr3[i]) firstNegative = i;

	for (int i = 0, j = 1; i < N; i++, j++) {
		cout << j << ". " << arr3[i] << endl;
		if (arr3[i] < 0) {
			lastNegative = i;
			sumNegativeElem += arr3[i];
		}
		if (arr3[i] > maxElem) {
			maxElem = arr3[i];
			temp1 = i;
		}
		if (arr3[i] < minElem) {
			minElem = arr3[i];
			temp2 = i;
		}
		if (i != 0 && i % 2 != 0)
			mult2 *= arr3[i];
	}

	for (int i = temp2; i <= temp1; i++)
		mult1 *= arr3[i];

	for (int t = 0; t <= lastNegative; t++)
		sumElem += arr3[t];

	cout << "\nСумма всех отрицательных чисел: " << sumNegativeElem << endl;
	cout << "Произведение элементов, находящихся между " << minElem << " и " << maxElem << ":" << mult1 << endl;
	cout << "Произведение элементов с четными номерами: " << mult2 << endl;
	cout << "Суммa элементов, находящихся между первым и последним отрицательными элементами: " << sumElem << endl<<endl;
}
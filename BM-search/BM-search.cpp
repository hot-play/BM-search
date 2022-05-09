#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
const int SymbolNumber = 256;//Константное число, для создания массива со сдвигами

//Предтрансляция
void badChar(string pattern, int patternArray[SymbolNumber]) //Формируем массив для шаблон-строки(Предтрансляция)
{
	int patternSize = pattern.length();
	for (int i = 0; i < SymbolNumber; i++)//В начале заполняем максимальной длинной сдвига
		patternArray[i] = patternSize;
	for (int i = 0; i < patternSize - 1; i++)//Для символов, которые есть в шаблоне подсчитываем сдвиг до конца шиблона
		patternArray[(int)pattern[i]] = patternSize - 1 - i;
}

//БМ поиск
int search(string str, string pattern) {
	int strSize = str.length();//Длина строки, в которой ищем
	int patternSize = pattern.length();//Длина строки, которую ищем (шаблон)
	int *patternArray;//Массив для подсчет индекса, накоторый будем сдвигать
	badChar(pattern, patternArray);//Придтрансляция
	for (int i = 0; i <= strSize - patternSize; i += patternArray[(int)str[i]]) //С помощью массива ищем совпадения и сдвигаем на определенное количество символов
	{
		int k = i; // Идет по строке, в которой ищем
		int j = patternSize - 1; // Идет по строке, которую ищем
		for (j = patternSize - 1; j >= 0; j--)
			if (str[k] == pattern[j])
				k--;
			else //В случае, если не совпало, то возвращаемся в первый цикл
			{
				j = patternSize - 1;
				break;
			}
		if (j < 0) //Возвращаем индекс с которого начинается совпадение
		{
			delete[] patternArray;
			return i + 1 - patternSize;
		}
	}
	delete[] patternArray;
	return -1;//Если не нашли, то возвращаем -1
}
int main() {
	setlocale(LC_ALL, "Rus");
	string str;
	cout << "Строка, в которой ищем :";
	cin >> str;
	string pattern;
	cout << "Строка, которую ищем (шаблон) :";
	cin >> pattern;
	int result = -1;
	result = search(str, pattern);
	if (result != -1)
		cout << endl << "Вхождение было обнаружено в " << result << " индексе" << endl;
	else
		cout << endl << "Вхождений обнаружено не было" << endl;
	system("pause");
}


# include <iostream>
#include<string>

// Прототипы функций для задачи 1:
template<typename T>
void search_Max(T& var1,T& var2, T& var3); // Шаблонная процедура поиска максимального числа и замены им всех остальных чисел 
bool exam_Value(std::string value); // Функция проверки введённого пользователем значения на соответствие числу (false - не число, true - число)
char data_Type(std::string arr[], const short length); // Функция определения типа данных, введённых пользователем 

// Общие прототипы функций для задач 2 и 3:
template<typename T>
void print_Array(T arr[], const short length); // Шаблонная процедура вывода массива
template<typename T>
void change_Array(T arr[], const short length); // Шаблонная процедура для изменения исходного массива в зависимости от выбора пользователя

// Прототип функции для задачи 2:
double& ref_Element(double arr[], const short length);

// Прототип функции для задачи 3:
void comparison(short arr1[], short arr2[], const short length1, const short length2);

int main() {
	// Задача 1. Изменение значений переменных на максимальное значение 
	std::cout << "\033[91mTask 1. Changing variable values to maximum value\033[0m\n\n";
	const short size1 = 3;
	std::string my_Strings[size1]; // Объявляем массив строк с размером = 3 (3 числа по условию задачи)
	for (short i = 0; i < size1; i++) { // Цикл ввода значений и их оперативной проверки на соответствие критериям числа
		std::cout << "Enter a number N " << i + 1 << " = ";
		std::cin >> my_Strings[i]; // Текущий элемент массива инициализируется любым введённым пользователем значением
		while (exam_Value(my_Strings[i]) == false) { // Цикл проверки введённого пользователем значения на соответствие критериям числа
			std::cout << "Input error! The entered value isn't a number!\nEnter a number again -> ";
			std::cin >> my_Strings[i];
		}
	}
	char my_Data_Type = data_Type(my_Strings, size1); // Объявляем и инициализируем переменную для хранения типа данных, введённых пользователем
	if (my_Data_Type == 'd') {
		double var1 = stod(my_Strings[0]), var2 = stod(my_Strings[1]), var3 = stod(my_Strings[2]);
		search_Max(var1, var2, var3);
		std::cout << "\n\033[92mResult is:\033[0m\nNumber N 1 = " << var1 << "\nNumber N 2 = " << var2 << "\nNumber N 3 = " << var3 << "\n\n";
	}
	else 
		if (my_Data_Type == 'l') {
			long long var1 = stoll(my_Strings[0]), var2 = stoll(my_Strings[1]), var3 = stoll(my_Strings[2]);
			search_Max(var1, var2, var3);
			std::cout << "\n\033[92mResult is:\033[0m\nNumber N 1 = " << var1 << "\nNumber N 2 = " << var2 << "\nNumber N 3 = " << var3 << "\n\n";
		}
		else
			if (my_Data_Type == 'i') {
				int var1 = stoi(my_Strings[0]), var2 = stoi(my_Strings[1]), var3 = stoi(my_Strings[2]);
				search_Max(var1, var2, var3);
				std::cout << "\n\033[92mResult is:\033[0m\nNumber N 1 = " << var1 << "\nNumber N 2 = " << var2 << "\nNumber N 3 = " << var3 << "\n\n";
			}
			else
				if (my_Data_Type == 's') {
					short var1 = stoi(my_Strings[0]), var2 = stoi(my_Strings[1]), var3 = stoi(my_Strings[2]);
					search_Max(var1, var2, var3);
					std::cout << "\n\033[92mResult is:\033[0m\nNumber N 1 = " << var1 << "\nNumber N 2 = " << var2 << "\nNumber N 3 = " << var3 << "\n\n";
				}

	// Задача 2. Ссылка на первый отрицательный элемент массива
	std::cout << "\033[91mTask 2. Reference to the first negative element of an array\033[0m\n\nSource array is: ";
	const short size2 = 5;
	double array2[size2]{ 1, 2.5, 0, -1.4, -2 };
	print_Array(array2, size2);
	char my_Choise; // Локальная переменная для хранения выбора пользователя
	std::cout << "\033[93mDo you want to change the source array?\nPress '1' if changes aren't needed \033[4mor\033[0m \033[93mpress any other key to make changes.\nYour choise\033[0m -> ";
	std::cin >> my_Choise;
	std::cout << std::endl;
	if (my_Choise != '1') {
		change_Array(array2, size2);
		std::cout << "\nChanged array is: ";
		print_Array(array2, size2);
	}
	std::cout << "\033[92mThe first negative element of array is " << ref_Element(array2, size2) << "\033[0m\n\n";
	
	// Задача 3. Обнуление одинаковых элементов массива
	std::cout << "\033[91mTask3. Resetting identical array elements to zero\033[0m\n\nFirst source array is: ";
	const short size3_1 = 5, size3_2 = 7;
	short array3_1[size3_1]{ 5, 8, 4, 6, 10 }, array3_2[size3_2]{ 11, -15, 6, 1, 6, 50, 10 };
	print_Array(array3_1, size3_1);
	std::cout << "Second source array is: ";
	print_Array(array3_2, size3_2);	
	std::cout << "\033[93mDo you want to change the first source array?\nPress '1' if changes aren't needed \033[4mor\033[0m \033[93mpress any other key to make changes.\nYour choise\033[0m -> ";
	char Choise;
	std::cin >> Choise;
	std::cout << std::endl;
	if (Choise != '1') {
		change_Array(array3_1, size3_1);
		std::cout << "\nChanged first array is: ";
		print_Array(array3_1, size3_1);
	}
	std::cout << "\033[93mDo you want to change the second source array?\nPress '1' if changes aren't needed \033[4mor\033[0m \033[93mpress any other key to make changes.\nYour choise\033[0m -> ";
	std::cin >> my_Choise;
	std::cout << std::endl;
	if (my_Choise != '1') {
		change_Array(array3_2, size3_2);
		std::cout << "\nChanged second array is: ";
		print_Array(array3_2, size3_2);
	}
	comparison(array3_1, array3_2, size3_1, size3_2);
	std::cout << "\033[92mFinal second array is: \033[0m";
	print_Array(array3_2, size3_2);
	std::cout << std::endl;

	return 0;
}

template<typename T>
void search_Max(T& var1, T& var2, T& var3) {
	T max; // Объявляем переменную для хранения максимального значения
	if (var1 > var2)
		max = var1 > var3 ? var1 : var3;
	else
		max = var2 > var3 ? var2 : var3;
	var1 = var2 = var3 = max;
}

bool exam_Value(std::string value) {
	short length_String = size(value); // Для организации следующего далее цикла проверки определяем длину строки (длину массива символов)	
	short counter_Point = 0; // Переменная для хранения кол-ва символов "."
	bool first_Negative = false; // Переменная для хранения признака первого символа "-" (true, если первый символ "-")
	for (short i = 0; i < length_String; i++) {
		short key_Symbol = short(value[i]); // В цикле работаем с текущим символом строки, проверяя его по коду ASCII-таблицы		
		if (i == 0 && key_Symbol == 45) // Проверка на знак "-" в начале строки
			first_Negative = true;
		if (key_Symbol == 46) // Расчёт кол-ва точек в строке
			counter_Point++;
		// Если символ "-" не первый, символ "." первый, символ "." второй при первом "-", кол-во символов "." > 1
		// и все остальные символы не цифра от 0 до 9, то останавливаем функцию и возвращаем в mian "false"
		if ((key_Symbol == 45 && i != 0) || (key_Symbol == 46 && i == 0) || (key_Symbol == 46 && i == 1 && first_Negative == true) || counter_Point > 1 || key_Symbol > 57 || key_Symbol == 47 || key_Symbol < 45) 
			return false;		
	}
	return true;
}

char data_Type(std::string arr[], const short length) {
	for (short i = 0; i < length; i++) { // Цикл проверки на тип данных "double"
		short length = size(arr[i]); // Для организации следующего далее цикла определяем длину строки (длину массива символов)	
		for (short j = 0; j < length; j++)  // Цикл проверки каждой строки на наличие символа '.'
			if (arr[i][j] == '.')  // Если хотя бы один символ в любом введённом пользователем значении равен '.', то 
				return 'd';
	}	
	for (short i = 0; i < length; i++) { // Цикл проверки на тип данных	"long long"
		long long var = stoll(arr[i]);
		if (var > 2147483647 || var < -2147483648)
			return 'l';
	}
	for (short i = 0; i < length; i++) { // Цикл проверки на тип данных	"integer"
		int var = stoi(arr[i]);
		if (var > 32767 || var < -32768)
			return 'i';
	}
	return 's';
}

template<typename T>
void print_Array(T arr[], const short length) {	
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b \n" << std::endl;
}

template<typename T>
void change_Array(T arr[], const short length) {	
	for (short i = 0; i < length; i++) {
		std::cout << "Enter array's element N " << i << " = ";
		std::cin >> arr[i];
	}			
}

double& ref_Element(double arr[], const short length) {	
	for (short i = 0; i < length; i++)
		if (arr[i] < 0)
			return arr[i];
	return arr[0];
}

void comparison(short arr1[], short arr2[], const short length1, const short length2) {
	for (short i = 0; i < length1; i++) { // Цикл перебора элементов массива 1
		short* p_Arr1 = &arr1[i]; // Объявляем указатель на область памяти, в которой хранится значение текущего элемента массива 1
		for (short j = 0; j < length2; j++) { // Цикл перебора элементов массива 2
			short* p_Arr2 = &arr2[j]; // Объявляем указатель на область памяти, в которой хранится значение текущего элемента массива 2
			// Если в области памяти, на которую указывает p_Arr2 хранится то же самое, что и в области памяти, на которую 
			// указывает p_Arr1, то значение в области памяти, на которую указывает p_Arr2, меняем на "0"
			if (*p_Arr2 == *p_Arr1) 
				*p_Arr2 = 0;
		}
	}
}
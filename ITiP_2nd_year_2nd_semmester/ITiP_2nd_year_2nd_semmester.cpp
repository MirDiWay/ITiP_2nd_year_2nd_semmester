#include <iostream>
#include <string>
#include <random>

short inputStartDataUser;

void GreetingForTheUser_void() // Начальная информация для пользователя
{
	setlocale(LC_ALL, "Russian");
	std::cout << "+-------------------------------------------------------------------------------+" << std::endl;
	std::cout << "| Доброл пожаловать в программу по предмету:                                    |" << std::endl;
	std::cout << "| Информационные технологии и программирования                                  |" << std::endl;
	std::cout << "| Данная программа написана студентом:                                          |" << std::endl;
	std::cout << "| из группы УБСТ-2404                                                           |" << std::endl;
	std::cout << "| Миронов Владислав Дмитриевич (MirDiWay)                                       |" << std::endl;
	std::cout << "| 14 вариант                                                                    |" << std::endl;
	std::cout << "| В данной программе поэтапно программируется выполнение задач,                 |\n";
	std::cout << "| пока курс не завершиться или не нужно будеть написать более сложную программу |\n";
	std::cout << "| которую не получится разместить в этом коде                                   |" << std::endl;
	std::cout << "+-------------------------------------------------------------------------------+" << std::endl << std::endl << std::endl << std::endl;
}

void SelectingATaskForTheUser_void() // удобный метод для вывода списка действий, доступных пользователю
{
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Для начала работы выберите направления задания, что бы получить ответ:" << std::endl;
	std::cout << "*выбрать можно только цифру, писать буковки и символы незя - закон!" << std::endl << std::endl;
	std::cout << "1. Задание 2-1" << std::endl;
	std::cout << "2. Задание 2-2" << std::endl;
	std::cout << "3. Контрольная работа" << std::endl;
}

void ChoosingThePathOfTheUsersFirstSubtask_void()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "+==========================================================================+" << std::endl;
	std::cout << "[ Задание 2-1                                                              ]" << std::endl;
	std::cout << "[ Сортировка перемешиванием                                                ]" << std::endl;
	std::cout << "[ Тип данных double                                                        ]" << std::endl;
	std::cout << "[ Быстрая сортировка                                                       ]" << std::endl;
	std::cout << "[ Метод Хоара не используется                                              ]" << std::endl;
	std::cout << "[ Количество элементов в массиве: 50                                       ]" << std::endl;
	std::cout << "[ Элементы: сгенерированно случайно                                        ]" << std::endl;
	std::cout << "[ Диапазон генерации: от 11040 до 31704                                    ]" << std::endl;
	std::cout << "+==========================================================================+" << std::endl << std::endl;

	std::cout << "Выберите действие которое хотите выполнить" << std::endl;
	std::cout << "1. Сгенерировать 50 рандомных значений" << std::endl;
	std::cout << "     записать сгенерированные значения в файл" << std::endl;
	std::cout << "     отсортировать значения" << std::endl;
	std::cout << "     вывести информацию работы в виде времяни" << std::endl;
	std::cout << "     сохранить данные в файл" << std::endl;
	std::cout << "2. Совершить такую же работу, как при выборе понкта 1, но только" << std::endl;
	std::cout << "     с: 1'000, 10'000, 100'000, 500'000 и 1'000'000" << std::endl;
	std::cout << "     рандомными сгенерированными данными" << std::endl;
	std::cout << "0. Вернуться к списку заданий" << std::endl;
}

void SortingTheArrayAccordingToTheMainOption() // Метод для первой задачи
{
	double RangeOfValuesFrom = 11040, RangeOfValuesTo = 31704;
	const int NumberOfGenerations = 50;
	double ArrayOfGeneratedData[NumberOfGenerations];

	// переменные для работы метода рандома
	std:: random_device randomDevice;
	std:: mt19937 gen(randomDevice());
	std::uniform_real_distribution<> dis(RangeOfValuesFrom, RangeOfValuesTo);

	// цикл для генерации данных, и записи их в массив
	for (int i = 0; i < NumberOfGenerations; ++i)
	{
		ArrayOfGeneratedData[i] = dis(gen);
	}
	
	// вывод мокрого ответа
	std::cout << "--{Сгенерированый массив данных}--------------------------------------------------------" << std::endl;
	for (int q=0; q < NumberOfGenerations; ++q)
	{
		std::cout << q+1 << "}   " << ArrayOfGeneratedData[q] << std::endl;
	}

	// сортировка перемешиванием
	bool swapped = true;
	int staret = 0;
	int end = NumberOfGenerations - 1;

	while (swapped)
	{
		// Сортировка в одну сторону
		swapped = false;
		for (int i = staret; i < end; ++i)
		{
			if (ArrayOfGeneratedData[i] > ArrayOfGeneratedData[i + 1])
			{
				std::swap(ArrayOfGeneratedData[i], ArrayOfGeneratedData[i + 1]);
				swapped = true;
			}
		}

		// Сортировка в другую сторону
		if (!swapped) break;
		swapped = false;
		--end;
		for (int i = end - 1; i >= staret; --i)
		{
			if (ArrayOfGeneratedData[i] > ArrayOfGeneratedData[i + 1])
			{
				std::swap(ArrayOfGeneratedData[i], ArrayOfGeneratedData[i + 1]);
				swapped = true;
			}
		}
		++staret;
	}
	// Вывод сухого ответа
	std::cout << "--{Отсортированный массив данных}--------------------------------------------------------" << std::endl;
	for (int w = 0; w < NumberOfGenerations; ++w)
	{
		std::cout << w + 1 << "}   " << ArrayOfGeneratedData[w] << std::endl;
	}
}

int main()
{
	GreetingForTheUser_void();
	while (true) // цикл, что бы программа не закрывалась, и продолжала свою работу, когда действие выполнилось
	{
		inputStartDataUser = NULL;
		SelectingATaskForTheUser_void();

		std::cout << "Ваш выбор: "; std::cin >> inputStartDataUser;

		switch (inputStartDataUser)
		{
			case 1: 
			ChoosingThePathOfTheUsersFirstSubtask_void();
			std::cout << "Ваш выбор: "; std::cin >> inputStartDataUser;
			switch (inputStartDataUser)
			{
				case 1: break;
				case 2: break;
				case 0: break; // Логика такая, что код как бы выполнился, и мы выходим из switch
				default: std::cout << "Вы ввели не правильные данные" << std::endl; break;
			}break;

			case 2: break;
			case 3: break;
			default: std::cout << "Вы ввели не правильные данные" << std::endl; break;
		}
		inputStartDataUser = NULL;
	}
}
//short ≧ 1 байт памяти
//int ≧ 4 байта памяти
//long ≧ 8 байт памяти


#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

short inputStartDataUser;
short numberOfDecimalPlaces = 20; // Что бы постоянно было фиксированное количество знаков после запятой. Логика такая, что если я захочу поменять количество выводных знаков после запятой, мне достаточно будет тут поменять цифры, а не бегать по коду и искать все выводные данные

std::string GetCurrentDateTime() // Вмеря, для вывода данных о том, сколько шла генерация, сколько времяни происходила сортировка, для ведения логов
{
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);
	std::ostringstream oss;
	oss << std::put_time(&localTime, "%d.%m.%Y_%H:%M:%S");
	return oss.str();
}

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

void SaveDataToAFile_void(const std::vector<double>& originalData, const std::vector<double>& sortedData, const std::string& filename, short numberOfDecimalPlaces)
{
	std::ofstream outFile(filename);
	if (!outFile)
	{
		std::cerr << "Ошибка открытия файла: " << filename << std::endl;
		return;
	}

	outFile << std::fixed << std::setprecision(numberOfDecimalPlaces);

	// Записываем исходные данные
	outFile << "=== Исходные данные ===" << std::endl;
	for (size_t i = 0; i < originalData.size(); ++i)
	{
		outFile << originalData[i];
		if (i != originalData.size() - 1)
			outFile << " | ";
	}
	outFile << std::endl << std::endl;

	// Записываем отсортированные данные
	outFile << "=== Отсортированные данные ===" << std::endl;
	for (size_t i = 0; i < sortedData.size(); ++i)
	{
		outFile << sortedData[i];
		if (i != sortedData.size() - 1)
			outFile << " | ";
	}
	outFile << std::endl;

	outFile.close();
	std::cout << "Данные сохранены в " << filename << std::endl;
}

void SortingTheArrayAccordingToTheMainOption(int usersChoice) // Метод для первой задачи			*usersChoice - передает тип задачи,которое пользователь выбрал
{
	auto startTime = std::chrono::high_resolution_clock::now();
	double RangeOfValuesFrom = 11040, RangeOfValuesTo = 31704;
	std::vector<double>	ArrayOfGeneratedData(usersChoice);
	
	// переменные для работы метода рандома
	std:: random_device randomDevice;
	std:: mt19937 gen(randomDevice());
	std::uniform_real_distribution<> dis(RangeOfValuesFrom, RangeOfValuesTo);

	// цикл для генерации данных, и записи их в массив
	for (int i = 0; i < usersChoice; ++i)
	{
		ArrayOfGeneratedData[i] = dis(gen);
	}

	// вывод мокрого ответа
	std::cout << "--{"<<usersChoice<<" случайно сгенерированных данных}--------------------------------------------------------" << std::endl;
	for (int q=0; q < usersChoice; ++q)
	{
		std::cout << q+1 << "} " << std::fixed << std::setprecision(numberOfDecimalPlaces) << ArrayOfGeneratedData[q] << std::endl;
	}

	std::vector<double> SortedData = ArrayOfGeneratedData;

	// сортировка перемешиванием
	// сортировка перемешиванием
	bool swapped = true;
	int start = 0, end = usersChoice - 1;
	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end; ++i)
		{
			if (SortedData[i] > SortedData[i + 1])
			{
				std::swap(SortedData[i], SortedData[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
		swapped = false;
		--end;
		for (int i = end - 1; i >= start; --i)
		{
			if (SortedData[i] > SortedData[i + 1])
			{
				std::swap(SortedData[i], SortedData[i + 1]);
				swapped = true;
			}
		}
		++start;
	}

	// Вывод сухого ответа
	std::cout << "--{"<<usersChoice<<" отсортированно данных}--------------------------------------------------------" << std::endl;
	for (int w = 0; w < usersChoice; ++w)
	{
		std::cout << w + 1 << "} " << std::fixed << std::setprecision(numberOfDecimalPlaces) << ArrayOfGeneratedData[w] << std::endl;
	}

	// сохраняем и исходные, и отсортированные данные в один файл
	std::string filename = "GeneratedAndSorted_" + std::to_string(usersChoice) + ".txt";
	SaveDataToAFile_void(ArrayOfGeneratedData, SortedData, filename, numberOfDecimalPlaces);
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
			case 1: // Первая практическая 	   
			ChoosingThePathOfTheUsersFirstSubtask_void();
			std::cout << "Ваш выбор: "; 
			std::cin >> inputStartDataUser;
			switch (inputStartDataUser)
			{
				case 1: SortingTheArrayAccordingToTheMainOption(50); break;
				case 2: 
				{
					long numberOfGenerationsArray[] = {1000, 10000, 100000, 500000, 1000000};
					for (long stepStep : numberOfGenerationsArray)
					{
						SortingTheArrayAccordingToTheMainOption(stepStep);
					} break;
				}
				case 0: break;
				default: std::cout << "Вы ввели не правильные данные" << std::endl; break;
			}break;
			/*
				Логика такая:
				Пользователь выберает то задание, которое ему интересно, если первое, то генерируем 50 случайных данных
				Если пользователь выбрал 2 задание, то поочерёдно генерируем массив случайных данных.
				Если 0, то код считается выполненым и выходим из этого блока кода
				А так как мы в блоке блоке, то выход реализуется вообще из всех блоков, но так как код в цикле
				то открывается меню заново.
			*/
			case 2: break; // Вторая практическая
			case 3: break; // Контрольная работа
			default: std::cout << "Вы ввели не правильные данные" << std::endl; break;
		}
		inputStartDataUser = NULL;
	}
}
//short ≧ 1 байт памяти
//int ≧ 4 байта памяти
//long ≧ 8 байт памяти


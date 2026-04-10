#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <vector>
#include <sstream>

short inputStartDataUser;
short numberOfDecimalPlaces = 20;


struct TimeInfo // счечик для слежки за временем
{
	std::string genStart;
	std::string genEnd;
	double genDuration;

	std::string sortStart;
	std::string sortEnd;
	double sortDuration;
};

std::string GetCurrentDateTime() // способ вывести время
{
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);
	std::ostringstream oss;
	oss << std::put_time(&localTime, "%H:%M:%S");
	return oss.str();
}

void GreetingForTheUser_void() //Начальная информация для пользователя 
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

void SelectingATaskForTheUser_void()
{
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "1. Задание 2-1" << std::endl;
	std::cout << "2. Задание 2-2" << std::endl;
	std::cout << "3. Контрольная работа" << std::endl;
}

void ChoosingThePathOfTheUsersFirstSubtask_void()
{
	std::cout << "1. 50 элементов" << std::endl;
	std::cout << "2. 1'000   10'000   100'000   500'000   1'000'000 элементов" << std::endl;
	std::cout << "0. Назад" << std::endl;
}

// метод, который позволит сохранить данные в корень программы ввиде текстового документа
void SaveDataToAFile_void(
	const std::vector<double>& originalData,
	const std::vector<double>& sortedData,
	const std::string& filename,
	short numberOfDecimalPlaces,
	const TimeInfo& t)
{
	std::ofstream outFile(filename);

	if (!outFile)
	{
		std::cerr << "Ошибка открытия файла: " << filename << std::endl;
		return;
	}

	outFile << std::fixed << std::setprecision(numberOfDecimalPlaces);

	outFile << "\n\n====== Исходные данные ======" << std::endl;
	for (size_t i = 0; i < originalData.size(); ++i)
	{
		outFile << originalData[i];
		if (i != originalData.size() - 1)
			outFile << " | ";
	}

	outFile << "\n\n====== Отсортированные данные ======" << std::endl;
	for (size_t i = 0; i < sortedData.size(); ++i)
	{
		outFile << sortedData[i];
		if (i != sortedData.size() - 1)
			outFile << " | ";
	}

	outFile << "\n=== Время выполнения ===\n";
	outFile << "+-----------------------------------------------------------------+\n";
	outFile << "| ===Генерация                                                    |\n";
	outFile << "|      Начало: " << t.genStart << "                                           |\n";
	outFile << "|      Конец: " << t.genEnd << "                                            |\n";
	outFile << "|      Длительность: " << t.genDuration << " секунд                |\n";
	outFile << "+-----------------------------------------------------------------+\n";
	outFile << "+-----------------------------------------------------------------+\n";
	outFile << "| ===Сортировка                                                   |\n";
	outFile << "|      Начало: " << t.sortStart << "                                           |\n";
	outFile << "|      Конец: " << t.sortEnd << "                                            |\n";
	outFile << "|      Длительность: " << t.sortDuration << " секунд                |\n";
	outFile << "+-----------------------------------------------------------------+\n\n";

	outFile.close();
	std::cout << "Данные сохранены в " << filename << std::endl;
}

TimeInfo SortingTheArrayAccordingToTheMainOption(int usersChoice)
{
	TimeInfo t;

	double 
	RangeOfValuesFrom = 11040, 
	RangeOfValuesTo = 31704;
	std::vector<double> ArrayOfGeneratedData(usersChoice);

	std::random_device randomDevice;
	std::mt19937 gen(randomDevice());
	std::uniform_real_distribution<> dis(RangeOfValuesFrom, RangeOfValuesTo);

	// генерация случайных данных на основе генератора
	t.genStart = GetCurrentDateTime();
	auto genStart = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < usersChoice; ++i)
	{
		ArrayOfGeneratedData[i] = dis(gen);
	}

	auto genEnd = std::chrono::high_resolution_clock::now();
	t.genEnd = GetCurrentDateTime();
	t.genDuration = std::chrono::duration<double>(genEnd - genStart).count();

	std::cout << "--{" << usersChoice << " случайно сгенерированных данных}--\n";
	for (int q = 0; q < usersChoice; ++q)
	{
		std::cout << q + 1 << "} "
			<< std::fixed << std::setprecision(numberOfDecimalPlaces)
			<< ArrayOfGeneratedData[q] << std::endl;
	}

	std::vector<double> SortedData = ArrayOfGeneratedData;

	// режим сортировки
	t.sortStart = GetCurrentDateTime();
	auto sortStart = std::chrono::high_resolution_clock::now();

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

	auto sortEnd = std::chrono::high_resolution_clock::now();
	t.sortEnd = GetCurrentDateTime();
	t.sortDuration = std::chrono::duration<double>(sortEnd - sortStart).count();

	std::cout << "--{" << usersChoice << " отсортированно данных}--\n";
	for (int w = 0; w < usersChoice; ++w)
	{
		std::cout << w + 1 << "} "
			<< std::fixed << std::setprecision(numberOfDecimalPlaces)
			<< SortedData[w] << std::endl;
	}

	std::cout << "\n=== Время выполнения ===\n";
	std::cout << "+-----------------------------------------------------------------+\n";
	std::cout << "| ===Генерация                                                    |\n";
	std::cout << "|      Начало: " << t.genStart << "                                           |\n";
	std::cout << "|      Конец: " << t.genEnd << "                                            |\n";
	std::cout << "|      Длительность: " << t.genDuration << " секунд                |\n";
	std::cout << "+-----------------------------------------------------------------+\n";
	std::cout << "+-----------------------------------------------------------------+\n";
	std::cout << "| ===Сортировка                                                   |\n";
	std::cout << "|      Начало: " << t.sortStart << "                                           |\n";
	std::cout << "|      Конец: " << t.sortEnd << "                                            |\n";
	std::cout << "|      Длительность: " << t.sortDuration << " секунд                |\n";
	std::cout << "+-----------------------------------------------------------------+\n\n";

	std::string filename = "GeneratedAndSorted_" + std::to_string(usersChoice) + ".txt";
	SaveDataToAFile_void(ArrayOfGeneratedData, SortedData, filename, numberOfDecimalPlaces, t);

	return t;
}

int main()
{
	GreetingForTheUser_void();

	while (true)  // Что бы программа не закрывалась после выполнения блока кода, сделан цикл
	{
		inputStartDataUser = 0;
		SelectingATaskForTheUser_void();

		std::cout << "Ваш выбор: ";
		std::cin >> inputStartDataUser;

		switch (inputStartDataUser)
		{
			case 1:
			{
				ChoosingThePathOfTheUsersFirstSubtask_void();
				std::cout << "Ваш выбор: ";
				std::cin >> inputStartDataUser;

				switch (inputStartDataUser)
				{
					case 1:
						SortingTheArrayAccordingToTheMainOption(50);
						break;

					case 2:																 
					{
						long numberOfGenerationsArray[] = {  500000, 1000000 };	   /*1000, 10000, 100000,*/

						auto totalStart = std::chrono::high_resolution_clock::now();

						for (long stepStep : numberOfGenerationsArray)
						{
							SortingTheArrayAccordingToTheMainOption(stepStep);
						}

						auto totalEnd = std::chrono::high_resolution_clock::now();

						double totalTime = std::chrono::duration<double>(totalEnd - totalStart).count();

						std::cout << "\n=== ОБЩЕЕ ВРЕМЯ ===\n";
						std::cout << "Полное выполнение: " << totalTime << " сек\n";

						break;
					}

					case 0: break;
					default:
						std::cout << "Вы ввели не правильные данные\n";
						break;
					}
				break;
			}

		default:
			std::cout << "Вы ввели не правильные данные\n";
			break;
		}
	}
}

//short ≧ 1 байт памяти 
//int ≧ 4 байта памяти 
//long ≧ 8 байт памяти
/*
  В файле "Header_ITiP_2nd_year_2nd_semmester.h" лежат основные переменные, библиотеки, данные, путь к другому коду для работы программы и прочее.
  В файле "ITiP_2nd_year_2nd_semmester.cpp" Основной реализованный код.
*/

#include "Header_ITiP_2nd_year_2nd_semmester.h"
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

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
					MeasureTotalTime_void([&]()
						{
							SortingTheArrayAccordingToTheMainOption_void(numberOfGenerationsArray);
						});
					break;

				case 2:
				{
					MeasureTotalTime_void([&]()
					{
						for (long stepStep : multiplicityNumberOfGenerationsArray)
						{
							SortingTheArrayAccordingToTheMainOption_void(stepStep);
						}
					});
					break;
				}

				case 0: break;
				default:
					std::cout << "Вы ввели не правильные данные\n";
					break;
				}
				break;
			}
			case 2:
				TheSecondTask_int();
				break;
			case 3:
				ControlWork_int();
				break;
			default:
				std::cout << "Вы ввели не правильные данные\n";
				break;
		}
	}
}
#include "Header_ITiP_2nd_year_2nd_semmester.h"

TimeInfo_struct_void SortingTheArrayAccordingToTheMainOption_void(long usersChoice)
{
	TimeInfo_struct_void timeInfoData;

	std::vector<double> ArrayOfGeneratedData(usersChoice);
	std::random_device randomDevice;
	std::mt19937 gen(randomDevice());
	std::uniform_real_distribution<> dis(RangeOfValuesFrom, RangeOfValuesTo);

	// генерация случайных данных на основе генератора
	timeInfoData.genStart = GetCurrentDateTime_void();
	auto genStart = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < usersChoice; ++i)
	{
		ArrayOfGeneratedData[i] = dis(gen);
	}

	auto genEnd = std::chrono::high_resolution_clock::now();
	timeInfoData.genEnd = GetCurrentDateTime_void();
	timeInfoData.genDuration = std::chrono::duration<double>(genEnd - genStart).count();

	std::cout << "--{" << usersChoice << " случайно сгенерированных данных}--\n";
	for (int q = 0; q < usersChoice; ++q)
	{
		std::cout << q + 1 << "} "
			<< std::fixed << std::setprecision(numberOfDecimalPlaces)
			<< ArrayOfGeneratedData[q] << std::endl;
	}

	std::vector<double> SortedData = ArrayOfGeneratedData;

	// режим сортировки
	timeInfoData.sortStart = GetCurrentDateTime_void();
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
	timeInfoData.sortEnd = GetCurrentDateTime_void();
	timeInfoData.sortDuration = std::chrono::duration<double>(sortEnd - sortStart).count();

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
	std::cout << "|      Начало: " << timeInfoData.genStart << "                                           |\n";
	std::cout << "|      Конец: " << timeInfoData.genEnd << "                                            |\n";
	std::cout << "|      Длительность: " << timeInfoData.genDuration << " секунд                |\n";
	std::cout << "+-----------------------------------------------------------------+\n";
	std::cout << "+-----------------------------------------------------------------+\n";
	std::cout << "| ===Сортировка                                                   |\n";
	std::cout << "|      Начало: " << timeInfoData.sortStart << "                                           |\n";
	std::cout << "|      Конец: " << timeInfoData.sortEnd << "                                            |\n";
	std::cout << "|      Длительность: " << timeInfoData.sortDuration << " секунд                |\n";
	std::cout << "+-----------------------------------------------------------------+\n\n";

	std::string filename = "GeneratedAndSorted_" + std::to_string(usersChoice) + ".txt";
	SaveDataToAFile_void(ArrayOfGeneratedData, SortedData, filename, numberOfDecimalPlaces, timeInfoData);

	return timeInfoData;
}
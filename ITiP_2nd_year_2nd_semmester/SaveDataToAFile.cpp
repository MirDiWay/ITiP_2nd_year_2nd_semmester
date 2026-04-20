#include "Header_ITiP_2nd_year_2nd_semmester.h"

void SaveDataToAFile_void(const std::vector<double>& originalData, const std::vector<double>& sortedData, const std::string& filename, short numberOfDecimalPlaces, TimeInfo_struct_void& timeInfoData)
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
	outFile << "|      Начало: " << timeInfoData.genStart << "                                           |\n";
	outFile << "|      Конец: " << timeInfoData.genEnd << "                                            |\n";
	outFile << "|      Длительность: " << timeInfoData.genDuration << " секунд                |\n";
	outFile << "+-----------------------------------------------------------------+\n";
	outFile << "+-----------------------------------------------------------------+\n";
	outFile << "| ===Сортировка                                                   |\n";
	outFile << "|      Начало: " << timeInfoData.sortStart << "                                           |\n";
	outFile << "|      Конец: " << timeInfoData.sortEnd << "                                            |\n";
	outFile << "|      Длительность: " << timeInfoData.sortDuration << " секунд                |\n";
	outFile << "+-----------------------------------------------------------------+\n\n";

	outFile.close();
	std::cout << "Данные сохранены в " << filename << std::endl;
}
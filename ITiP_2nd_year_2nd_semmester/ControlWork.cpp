#include "Header_ITiP_2nd_year_2nd_semmester.h"

using namespace std;

// Функция проверки расширения файла
bool isTxtFile(const string& path)
{
	if (path.length() < 4) return false;
	return path.substr(path.length() - 4) == ".txt";
}

int ControlWork_int()
{
	std::cout << "Необходимо написать программу, которая" << std::endl;
	std::cout << "Получает путь к исходному файлу" << std::endl;
	std::cout << "После обрабатывает текст и" << std::endl;
	std::cout << "записывает обработанный текст в исходный файл" << std::endl;
	std::cout << "В 14 варианте сказано, что все слова word должны замениться словом letter" << std::endl;
	std::cout << "Для работы программы был заранее создан тестовый файл, что бы просто сохранить текст" << std::endl;
	std::cout << "Но пользователю нужно будет все равно указывать на исходный файл. Файл должен быть " << std::endl;
	std::cout << "разрешения .txt" << std::endl;
	std::cout << "Ключевым моментом является то, что имя файла должно быть на английском языке" << std::endl << std::endl;

	string path;

	// Запрос файла
	while (true) {
		cout << "Введите путь к txt файлу: ";
		getline(cin, path);

		if (isTxtFile(path)) 
		{
			break;
		}
		else 
		{
			cout << "Ошибка: файл должен иметь расширение .txt\n";
		}
	}

	ifstream inFile(path);
	if (!inFile.is_open())
	{
		cout << "Ошибка открытия файла\n";
		return 1;
	}

	string text, line;
	while (getline(inFile, line)) 
	{
		text += line + "\n";
	}
	inFile.close();

	string result = text;
	string target = "word";
	string replacement = "letter";

	int count = 0;
	size_t pos = 0;

	// Замена всех вхождений
	while ((pos = result.find(target, pos)) != string::npos)
	{
		result.replace(pos, target.length(), replacement);
		pos += replacement.length();
		count++;
	}

	// Открываем файл для дозаписи
	ofstream outFile(path, ios::app);
	if (!outFile.is_open()) 
	{
		cout << "Ошибка записи в файл\n";
		return 1;
	}

	outFile << "\n\n===Редакт:\n";
	outFile << result;

	outFile.close();

	// Вывод только количества замен
	cout << "Количество замен: " << count << endl;

	return 0;
}

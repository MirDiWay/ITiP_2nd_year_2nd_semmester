#include <iostream>
#include <string>

void GreetingForTheUser_void()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Доброл пожаловать в программу по предмету:" << std::endl;
	std::cout << "Информационные технологии и программирования" << std::endl << std::endl;
	std::cout << "Данная программа написана студентом:" << std::endl;
	std::cout << "из группы УБСТ-2404" << std::endl;
	std::cout << "Миронов Владислав Дмитриевич (MirDiWay)" << std::endl;
	std::cout << "14 вариант" << std::endl << std::endl;
	std::cout << "В данной программе поэтапно программируется выполнение задач,\n";
	std::cout << "пока курс не завершиться или не нужно будеть написать более сложную программу\n";
	std::cout << "которую не получится разместить в этом коде" << std::endl << std::endl;
}

void SelectingATaskForTheUser_void()
{
	std::cout << "Для начала работы выберите направления задания, что бы получить ответ:" << std::endl;
	std::cout << "*выбрать можно только цифру, писать буковки и символы незя - закон!" << std::endl << std::endl;
	std::cout << "1. Сортировка перемешиванием | Массив чисел типа double | Быстрая сортировка | Метод Хоарая" << std::endl;
	std::cout << "2. null" << std::endl;
	std::cout << "3. null" << std::endl;
	std::cout << "4. null" << std::endl;
	std::cout << "5. null" << std::endl;
	std::cout << "6. null" << std::endl;
}

void SortingTheArrayAccordingToTheMainOption()
{
	std::cout << "\nВариант №14" << std::endl;
	std::cout << "Сортировка перемешиванием" << std::endl;
	std::cout << "Тип данных double" << std::endl;
	std::cout << "Быстрая сортировка" << std::endl;
	std::cout << "Метод Хоара не используется" << std::endl << std::endl;
	std::cout << "Количество элементов в массиве: 50" << std::endl;
	std::cout << "Элементы: сгенерированно случайно" << std::endl;
	std::cout << "Диапазон генерации: от 11040 до 31704" << std::endl << std::endl;

	double anArrayOfDataOfTheTypeDouble;
}


int main()
{ 
	GreetingForTheUser_void();
	SelectingATaskForTheUser_void();
	int inputStartDataUser; // записываем данные, что бы понять, что пользователь хочет выбрать

	std::cout << "Ваш выбор: "; std::cin >> inputStartDataUser;
	
	switch (inputStartDataUser)
	{
		case 1: SortingTheArrayAccordingToTheMainOption(); break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		default: std::cout << "Вы ввели не правильные данные" << std::endl; break;
	}
}
//short ≧ 1 байт памяти
//int ≧ 4 байта памяти
//int8_t ≧ 1 байт памяти
//int16_t ≧ 2 байта памяти
//int32_t ≧ 4 байта памяти
//int64_t ≧ 8 байт памяти
//long ≧ 8 байт памяти


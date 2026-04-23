#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <vector>
#include <sstream>
#include <array>
#include <queue>
#include <cstdlib>

// глобальные переменные
extern short inputStartDataUser;
extern short numberOfDecimalPlaces;
extern long numberOfGenerationsArray;
extern std::vector<long> multiplicityNumberOfGenerationsArray;
extern double RangeOfValuesFrom;
extern double RangeOfValuesTo;

// функции
void ChoosingThePathOfTheUsersFirstSubtask_void();
void GreetingForTheUser_void();
void SelectingATaskForTheUser_void();
int TheSecondTask_int();
int ControlWork_int();

std::string GetCurrentDateTime_void();

struct TimeInfo_struct_void
{
	std::string genStart;
	std::string genEnd;
	double genDuration;

	std::string sortStart;
	std::string sortEnd;
	double sortDuration;
};

TimeInfo_struct_void SortingTheArrayAccordingToTheMainOption_void(long);

template <typename Func>
void MeasureTotalTime_void(Func func)
{
	auto totalStart = std::chrono::high_resolution_clock::now();
	func();
	auto totalEnd = std::chrono::high_resolution_clock::now();

	double totalTime = std::chrono::duration<double>(totalEnd - totalStart).count();

	std::cout << "\n=== ОБЩЕЕ ВРЕМЯ ===\n";
	std::cout << "Полное выполнение: " << totalTime << " сек\n";
}

void SaveDataToAFile_void(
	const std::vector<double>& originalData,
	const std::vector<double>& sortedData,
	const std::string& filename,
	short numberOfDecimalPlaces,
	TimeInfo_struct_void& timeInfoData);
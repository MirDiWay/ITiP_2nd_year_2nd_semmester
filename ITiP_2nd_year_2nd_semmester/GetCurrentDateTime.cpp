#include "Header_ITiP_2nd_year_2nd_semmester.h"

std::string GetCurrentDateTime_void()
{
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);

	std::ostringstream oss;
	oss << std::put_time(&localTime, "%H:%M:%S");

	return oss.str();
}
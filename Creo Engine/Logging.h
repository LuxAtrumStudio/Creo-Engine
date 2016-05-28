#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

namespace LOGGING {
	void initializeLogging();
	void logError(string log, string location);
	void logWarning(string log, string location);
	void logSuccess(string log, string location);
	void logData(string log, string location);
	void log(int code);
	void terminateLogging();
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "Conscientia.h"
using namespace std;

namespace LOGGING {
	void initializeLogging();
	void logError();
	void logWarning();
	void logSuccess();
	void logData();
	void terminateLogging();
}
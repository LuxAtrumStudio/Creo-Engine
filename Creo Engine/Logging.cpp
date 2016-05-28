#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "Conscientia.h"
#include "Logging.h"
using namespace std;
ofstream logFile;
bool logOpen = false;
void LOGGING::initializeLogging() {
	logFile.open("Log.log");
	if (logFile.is_open()) {
		logOpen = true;
	}
	time_t currentTime;
	string dateTime;
	currentTime = time(0);
	dateTime = ctime(&currentTime);
	string temp = "";
	for (int a = 0; a < dateTime.size() - 1; a++) {
		temp = temp + dateTime[a];
	}
	dateTime = temp;
	string File = "Log Data.log";
	if (logOpen == true) {
		logSuccess("Created New Log File", "Logging.cpp/initializeLogging");
		logData(dateTime, "Consolas.cpp/initializeLogging");
	}
}
void LOGGING::logError(string log, string location) {
	if (logOpen == true) {
		logFile << "[Error]:" + log + "[" + location + "]\n";
	}
}
void LOGGING::logWarning(string log, string location) {
	if (logOpen == true) {
		logFile << "[Warning]:" + log + "[" + location + "]\n";
	}
}
void LOGGING::logSuccess(string log, string location) {
	if (logOpen == true) {
		logFile << "[Success]:" + log + "[" + location + "]\n";
	}
}
void LOGGING::logData(string log, string location) {
	if (logOpen == true) {
		logFile << "[Data]:" + log + "[" + location + "]\n";
	}
}
void LOGGING::log(int code) {
	if (logOpen == true) {
		logFile << "[" + to_string(code) + "]" << "\n";
	}
}
void LOGGING::terminateLogging() {
	logSuccess("Terminated Log", "Logging.cpp/terminateLogging");
	logFile.close();
}
#include <iostream>
#include "Conscientia.h"
#include "Logging.h"
using namespace std;

int main() {
	CONSCIENTIA::initializeConscientia();
	LOGGING::initializeLogging();
	LOGGING::terminateLogging();
	CONSCIENTIA::terminateConscientia();
	return(1);
}
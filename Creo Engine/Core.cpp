#include <iostream>
#include "Conscientia.h"
#include "Graphics Framework.h"
using namespace std;

int main(int argc, char** argv) {
	CONSCIENTIA::InitializeConscientia();
	LOGGING::InitializeLogging();
	LOGGING::TerminateLogging();
	CONSCIENTIA::TerminateConscientia();
	return(1);
}
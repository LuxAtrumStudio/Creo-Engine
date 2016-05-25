#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
struct menuList {
	string name;
	vector<string> items;
};
struct menuPage {
	string name;
	vector<menuList> lists;
};
struct menuHierarchy {
	string name;
	vector<menuPage> pages;
};
namespace CONSCIENTIA {
	/*=====>>>>>-----CORE FUNCTIONS-----<<<<<=====*/
	/*=====>>>>>-----Initilization-----<<<<<=====*/
	void initializeConscientia();
	void advancedInit(bool cursor, bool echo, bool raw);
	/*>>>>>-----SETTINGS-----<<<<<*/
	void setAutoRefresh(bool setting);
	/*=====>>>>>-----Run Time-----<<<<<=====*/
	/*>>>>>-----WINDOW-----<<<<<*/
	/*>>>>>-----Initilization-----<<<<<*/
	void createWindow(string name, int posX, int posY, int sizeX, int sizeY, bool border, bool title);
	/*>>>>>-----Management-----<<<<<*/
	void clearAllWindows();
	int findWindowPointer(string name);
	/*-----POINTER-----*/
	void setBorder(int pointer, bool setting);
	void clearWindow(int pointer);
	void setWindowTitle(int pointer, bool setting);
	void setCurrentWindow(int pointer);
	/*-----CURRENT-----*/
	void csetBorder(bool setting);
	void cclearWindow();
	void csetWindowTitle(bool setting);
	/*-----FIND-----*/
	void fsetBorder(string name, bool setting);
	void fclearWindow(string name);
	void fsetWindowTitle(string name, bool setting);
	void fsetCurrentWindow(string name);
	/*-----WINDOWS-----*/
	void drawBorder(int pointer);
	void drawTitle(int pointer);
	/*>>>>>-----Termination-----<<<<<*/
	void terminateAllWindows();
	void terminateWindow(int pointer);
	/*>>>>>-----USER INTERFACE-----<<<<<*/
	/*>>>>>-----Input-----<<<<<*/
	char gchar();
	int gint();
	int cint();
	string cstr();
	float gfloat();
	/*>>>>>-----Output-----<<<<<*/
	/*-----POINTER-----*/
	void print(int pointer, string str);
	void mprint(int pointer, int x, int y, string str);
	/*-----CURRENT-----*/
	void cprint(string str);
	void cmprint(int x, int y, string str);
	/*-----FIND-----*/
	void fprint(string name, string str);
	void fmprint(string name, int x, int y, string str);
	/*>>>>>-----SYSTEM-----<<<<<*/
	/*>>>>>-----Update-----<<<<<*/
	void update();
	/*=====>>>>>-----Termination-----<<<<<=====*/
	void terminateConscientia();
	/*=====>>>>>-----ADVANCED FUNCITONS-----<<<<<=====*/
	/*=====>>>>>-----Output Funcitons-----<<<<<=====*/
	/*>>>>>-----INTERACTIVE-----<<<<<*/
	/*>>>>>-----Menu-----<<<<<*/
	string menu(string menuFileDirectory, int posX, int posY, int sizeX, int sizeY);
	menuHierarchy loadMenuHierarchy(string menuFileDirectory);
	void displayMenu(menuHierarchy menu, int currentPage, int currentList, int currentItem);
	int findTextStart(string str, int space);
	/*>>>>>-----DISPLAY-----<<<<<*/
	/*>>>>>-----Loading Bars-----<<<<<*/
	int initializeLoadingBar(string process);
	void loadingBar(int index, double percent);
	void terminateLoadingBar(int index);
	/*=====>>>>>-----Input Funcitons-----<<<<<=====*/
	/*=====>>>>>-----System Funcitons-----<<<<<=====*/
}
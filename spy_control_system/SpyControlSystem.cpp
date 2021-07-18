#include <iostream>
#include "Control.h"


using namespace std;

// override global 
void* operator new(size_t size)
{
	Spy* p = (Spy*)malloc(size);
	return p;
}
void operator delete(void* pdead)
{
	free(pdead);
}

// override placement 
void* operator new(size_t size, int id) {
	Spy* p = (Spy*)malloc(size);
	return p;
}
void operator delete(void* pdead, int i) {
	free(pdead);
}


int main() {
	Control m;
	try
	{
		while (true) {
			int choice = m.ShowMenu_GetChoice();
			if (choice == -5) throw "input error";
			switch (choice) {
			case 0:
				m.ExitSystem();
				goto exit_loop;
			case 1:
				m.AddSpy();
				break;
			case 2:
				m.ShowAll();
				break;
			case 3:
				m.DeleteSpy();
				break;
			case 4:
				m.Modify();
				break;
			case 5:
				m.Find();
				break;
			case 6:
				m.SortSpyId();
				break;
			case 7:
				m.Clear();
				break;
			case 8:
				m.ShowCopyRight();
				break;
			case 9:
				m.ShowMyName();
				break;
			case 10:
				m.ShowCNMBless();
				break;
			case -1:
				m.ShowQuote();
				break;
			default:
				system("cls"); //刷新屏幕
				break;
			}
		}
	}
	catch (const char* error)
	{
		std::cout << error << endl;
	}
	catch (...) // catch all
	{
		std::cout << "error" << endl;
	}
exit_loop:

	return 0;
}

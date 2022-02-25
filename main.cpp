#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */
#include <string>
#include <iostream>
#include <fstream>
#include "Windows.h"
#include "shellapi.h"
#include<chrono>
#include<thread>

char currentTime[80];

int main()
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
	char test[80] = "12:30AM";

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	/*
	strftime(buffer, 80, "Now it's %I:%M%p.", &timeinfo);
	std::cout << buffer << "\n";
	strftime(buffer, 80, "%I:%M", &timeinfo);
	
	
	if (strcmp(test, buffer)) {
		std::cout << "bruh" << "\n";
	}
	*/
	// convert string -> char[80]
	std::string time[8];
	
	for (int i = 0; i < 8; i++) {
		std::cout << "Type timestamp number " << i + 1 << "\n";
		std::cin >> time[i];
	
	}
	/*
	for (int i = 0; i < 8; i++) {
		std::cout << time[i] << "\n";

	}
	*/
	std::string link[8];

	for (int i = 0; i < 8; i++) {
		std::cout << "Type link number " << i + 1 << "\n";
		std::cin >> link[i];
	
	}
	/*
	
	for (int i = 0; i < 8; i++) {
		std::cout << link[i] << "\n";

	}

	*/
	
	
	//ShellExecuteA(NULL, "open", link1, NULL, NULL, SW_SHOWNORMAL);
	//main loop here

	// for every iterator, cast string to char array, write to buffer, compare current time to buffer

	bool debounce = false;
	char lastSuccess[80];

	while (true) {
		strftime(currentTime, 80, "%I:%M%p", &timeinfo);

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		
		for (int i = 0; i < 8; i++) {
			strftime(currentTime, 80, "%I:%M%p", &timeinfo);

			std::string j = time[i];
			char timeBuffer[80];
			strcpy_s(timeBuffer, j.c_str());
			

			int sameTime = strcmp(timeBuffer, currentTime);
			int success = strcmp(lastSuccess, currentTime);


			if (sameTime == 0) {

				std::cout << "THIS IS THE LAST SUCCESS: " << lastSuccess << "\n";
				std::cout << success << "\n";
				std::cout << "The current time is: " << currentTime << "\n";

				if (success != 0) {
					ShellExecuteA(NULL, "open", link[i].c_str(), NULL, NULL, SW_SHOWNORMAL);
					
				}
				strcpy_s(lastSuccess, timeBuffer);


			
			}
			else {
				debounce = false;
			}
		}
		
		//std::cout << "done" << "\n";

	}


	return 0;
}
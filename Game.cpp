#include <stdio.h>
#include <Windows.h>

#include "..\P3 - Mini Anti Cheat\MiniAntiCheatCommon.h"

int main(int argc, const char* argv[]) {
	if (argc > 1) {
		printf("Too many arguments\n");

		return -1;
	}

	HANDLE hDevice = CreateFile(L"\\\\.\\MiniAntiCheat", GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);

	if (hDevice == INVALID_HANDLE_VALUE) {
		printf("Couldn't Open a Handle - Error: %u\n", GetLastError());

		return -1;
	}

	MiniAntiCheatOutput output;
	DWORD bytes;
	BOOL success = DeviceIoControl(hDevice, CHECK_BLACKLIST_TO_START, nullptr, 0, &output, sizeof(output), &bytes, nullptr);

	if (!success) {
		printf("Failed for DeviceIoControl using CHECK_BLACKLIST_TO_START - Error %u\n", GetLastError());

		return -1;
	}

	if (!output.isSafeToStart) {
		printf("You have Notepad.exe opened - Please close it to open the game!\n");

		return -1;
	}

	printf("Welcome to the Game\n");

	int option = 0;
	while (option != 1) {
		printf("1. Exit\n\nExit or Wait: ");
		if (scanf_s("%d", &option) == 1) {
			break;
		}
		else {
			printf("Wrong Input\n\n");
			continue;
		}
	}

	printf("Exited!\n");

	CloseHandle(hDevice);

	return 0;
}
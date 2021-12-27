#include <iostream>
#include <windows.h>
using namespace std;

DWORD pid;
DWORD value_addr = 0x0100579C;	//메모리 주소 직접 구해야 됨
int original_value;
int change_value;

int main()
{
	cout << "지뢰찾기에 ReadProcessMemory / WriteProcessMemory 사용하기" << endl;
	cout << "제작자 : 일령(ma5ter@naver.com)" << endl;
	system("pause");
	system("cls");	// step 1
	cout << "프로세스를 찾습니다..." << endl;
	HWND hwnd = FindWindowA(0, ("Minesweeper"));
	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hwnd)
	{
		cout << "성공" << endl;
	}
	else
	{
		cout << "실패" << endl;
		return 0;
	}	// step 2
	system("pause");
	while (1)
	{
		system("cls");
		ReadProcessMemory(pHandle, (void*)value_addr, &original_value, sizeof(int), 0);
		cout << "현재시간 : " << original_value << endl;
		cout << "바꿀시간 :" << flush;
		cin >> change_value;
		WriteProcessMemory(pHandle, (LPVOID)value_addr, &change_value, sizeof(int), 0);
		cout << "!!적용완료!!" << endl;
		system("pause");	// step 3
	}
}
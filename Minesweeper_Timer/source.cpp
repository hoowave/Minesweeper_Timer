#include <iostream>
#include <windows.h>
using namespace std;

DWORD pid;
DWORD value_addr = 0x0100579C;	//�޸� �ּ� ���� ���ؾ� ��
int original_value;
int change_value;

int main()
{
	cout << "����ã�⿡ ReadProcessMemory / WriteProcessMemory ����ϱ�" << endl;
	cout << "������ : �Ϸ�(ma5ter@naver.com)" << endl;
	system("pause");
	system("cls");	// step 1
	cout << "���μ����� ã���ϴ�..." << endl;
	HWND hwnd = FindWindowA(0, ("Minesweeper"));
	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hwnd)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "����" << endl;
		return 0;
	}	// step 2
	system("pause");
	while (1)
	{
		system("cls");
		ReadProcessMemory(pHandle, (void*)value_addr, &original_value, sizeof(int), 0);
		cout << "����ð� : " << original_value << endl;
		cout << "�ٲܽð� :" << flush;
		cin >> change_value;
		WriteProcessMemory(pHandle, (LPVOID)value_addr, &change_value, sizeof(int), 0);
		cout << "!!����Ϸ�!!" << endl;
		system("pause");	// step 3
	}
}
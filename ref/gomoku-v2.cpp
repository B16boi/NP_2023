#include <iostream>
#include "TCPIP_Sync.h"
#include <windows.h> //for gotoxy()
#include <conio.h>

#define W 52	  //�ѽL�e
#define H 32	  //�ѽL��
int T[W][H] = {}; //�����ѽL���A�A 0x00:���U�l

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void Check3()
{
	int x, y, z, n, m, p, ax, ay;
	int T1[2] = { 'O', 'X' };
	int V[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
	int count = 0;
	for (z = 0; z < 2; z++)
		for (y = 0; y < H; y += 2)
			for (x = 0; x < W; x += 2)
				for (m = 0; m < 4; m++)
				{
					n = 0;
					ax = x + V[m][0] * n;
					ay = y + V[m][1] * n;
					if ((ax < 0) || (ax >= W) || (ay < 0) || (ay >= W) || (T[ax][ay] != 0))
						continue;
					for (n = 2; n < 8; n += 2)
					{
						ax = x + V[m][0] * n;
						ay = y + V[m][1] * n;
						if ((ax < 0) || (ax >= W) || (ay < 0) || (ay >= W) || (T[ax][ay] != T1[z]))
							break;
					}
					if (n == 8)
					{
						ax = x + V[m][0] * n;
						ay = y + V[m][1] * n;
						if ((ax < 0) || (ax >= W) || (ay < 0) || (ay >= W) || (T[ax][ay] != 0))
							continue;
						count++;
					}
				}
	if (count >= 1)
	{
		gotoxy(0, H);
		printf("%c:���T", T1[z]);
	}
}
void Check4()
{
	int x, y, z, n, m, p, ax, ay;
	int T1[2] = { 'O', 'X' };
	int V[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
	int count = 0;
	for (z = 0; z < 2; z++)
		for (y = 0; y < H; y += 2)
			for (x = 0; x < W; x += 2)
				for (m = 0; m < 4; m++)
				{
					n = 0;
					ax = x + V[m][0] * n;
					ay = y + V[m][1] * n;
					if ((ax < 0) || (ax >= W) || (ay < 0) || (ay >= W) || (T[ax][ay] != 0))
						continue;
					for (n = 2; n < 10; n += 2)
					{
						ax = x + V[m][0] * n;
						ay = y + V[m][1] * n;
						if ((ax < 0) || (ax >= W) || (ay < 0) || (ay >= W) || (T[ax][ay] != T1[z]))
							break;
					}
					if (n == 10)
					{
						ax = x + V[m][0] * n;
						ay = y + V[m][1] * n;
						if ((ax < 0) || (ax >= W) || (ay < 0) || (ay >= W) || (T[ax][ay] != 0))
							continue;
						count++;
					}
				}
	if (count >= 1)
	{
		gotoxy(0, H);
		printf("%c:���|", T1[z]);
	}

}
void Check5()
{
	int x, y, z, n, m, p, ax, ay;
	int T1[2] = { 'O', 'X' };
	int V[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

	for (z = 0; z < 2; z++)
		for (y = 0; y < H; y += 2)
			for (x = 0; x < W; x += 2)
				for (m = 0; m < 4; m++)
				{
					for (n = 0; n < 10; n += 2)
					{
						ax = x + V[m][0] * n;
						ay = y + V[m][1] * n;
						if ((ax < 0) || (ax >= W) || (ay < 0) || (ay >= W) || (T[ax][ay] != T1[z]))
							break;
					}
					if (n >= 10)
					{
						gotoxy(0, H);
						printf("%c:���l�ѳs�u", T1[z]);
					}
				}
}

void Check() {
	Check3();
	Check4();
	Check5();
}
SOCKET SSock, CSock, Sock;
int F = 0; // 0:Ready, 1:Client, 2:Server

void SFun(PVOID p)
{ // Server Mode:�B�z���ݳs�J
	sockaddr_in Addr;
	char S1[2000];
	int i, x, y, Len = sizeof(sockaddr);
	Sock = accept(SSock, (sockaddr*)&Addr, &Len);
	F = 2; //�����s�u
	gotoxy(0, H);
	printf("����(%s)�s�J", inet_ntoa(Addr.sin_addr));
	while (1)
	{
		i = recv(Sock, S1, sizeof(S1) - 1, 0);
		if (i > 0)
		{
			S1[i] = 0;
			i = sscanf_s(S1, "(%d-%d)", &x, &y); //�ѪR�U�Ѧ�m
			if (i == 2)
			{
				gotoxy(x, y);
				printf("X");
				T[x][y] = 'X';
				Check();
			}
			else if (i < 0)
			{
				gotoxy(0, H);
				printf("�������u");
				break;
			}
		}
	}
}

void CFun(PVOID p)
{ // Client Mode:�B�z���ݳs�J
	sockaddr Addr;
	char S1[2000];
	int i, x, y, Len = sizeof(sockaddr);
	while (1)
	{
		i = recv(CSock, S1, sizeof(S1) - 1, 0);
		if (i > 0)
		{
			S1[i] = 0;							 // gotoxy(0, H);
			i = sscanf_s(S1, "(%d-%d)", &x, &y); //�ѪR�U�Ѧ�m
			if (i == 2)
			{
				gotoxy(x, y);
				printf("X");
				T[x][y] = 'X';
				Check();
			}
			else if (i < 0)
			{
				gotoxy(0, H);
				printf("�������u");
				break;
			}
		}
	}
}

int main()
{
	int x, y, z, x1, y1, t;
	char IP[100], S1[50];
	// 1.ø�s�C����
	for (y = 0; y < H; y++)
		for (x = 0; x < W; x++)
		{
			gotoxy(x, y);
			x1 = x % 2;
			y1 = y % 2;
			if (x1 && y1)
				printf("+");
			else if ((!x1) && y1)
				printf("-");
			else if (x1 && (!y1))
				printf("|");
		}
	// 2.�Ұ�TCP Server(���ݻ��ݳs�J�AThread)
	Start_TCP_Server(&SSock, 6000);
	_beginthread(SFun, 0, 0); //�B�z���ݫȤH�s�J
	// 3.Ū����L�A�B�z:�s�u�B�U�ѡB���R�B���...
	unsigned char c;
	int cx = W / 2, cy = H / 2; //��Ъ�l��m(����)
	do
	{
		gotoxy(cx, cy);
		c = _getch();
		// 1.���ʴ��
		if (c == 0x48)
			cy -= 2; //�W
		else if (c == 0x50)
			cy += 2; //�U
		else if (c == 0x4b)
			cx -= 2; //��
		else if (c == 0x4d)
			cx += 2; //�k
		if (cx < 0)
			cx = W - 2;
		else if (cx >= W)
			cx = 0;
		if (cy < 0)
			cy = H - 2;
		else if (cy >= H)
			cy = 0;
		// 2.�U��
		if (c == 0x0d)
		{
			printf("O"); // Enter
			T[cx][cy] = 'O';
			sprintf_s(S1, "(%d-%d)", cx, cy);
			send(Sock, S1, strlen(S1), 0); //�e�X�U�Ѧ�m
		}
		// 3.��H��
		else if ((c == 'c') || (c == 'C'))
		{
			gotoxy(0, H);
			printf("IP=");
			scanf_s("%s", IP, 99);
			Start_TCP_Client(&CSock, 6000, IP);
			F = 1;
			_beginthread(CFun, 0, 0);
			Sock = CSock;
		}
		// 4.
		Check();
	} while ((c != 'q') && (c != 'Q'));
	gotoxy(0, H);
	printf("�C������\n");
	closesocket(SSock);
	if (F >= 1)
		closesocket(Sock); //�����׺ݳs�u
}


#include"HumanInMaze.h"
#include"MazeMap.h"
#include<windows.h>
#include<iostream>
using namespace std;

//���캯������ʼ���Թ��е��˵�Ĭ������
HIM::HIM():Human('T'),PreX(1000),PreY(1000),PosX(0),PosY(0),Dir(NORTH) { }

//���캯�����û�ָ���Թ��е��˵ĳ�����
HIM::HIM(int X, int Y):Human('T'), PreX(1000), PreY(1000), PosX(X), PosY(Y),Dir(NORTH) { }

//���캯�����û�ָ���Թ��е��˵ĳ����ء��泯����
HIM::HIM(int X, int Y, Direction dir): Human('T'), PreX(1000), PreY(1000), PosX(X), PosY(Y), Dir(dir){ }

//���캯�����û�ָ���Թ��е��˵ĳ����ء��泯����ͱ�ʾ�˵ķ���
HIM::HIM(int X, int Y, Direction dir, char human):PreX(1000), PreY(1000), PosX(X), PosY(Y), Dir(dir),Human(human){ }

//�����˵ĳ�����
void HIM::setBirthPos(int X, int Y) {
	PosX = X;
	PosY = Y;
}

//���ô����˵ķ���
void HIM::setHumanPic(char human) {
	Human = human;
}

//�����ƶ�ǰ��λ��
void HIM::SavePosition() {
	PreX = PosX;
	PreY = PosY;
}

//������һ��
void HIM::moveEAST() {
	SavePosition();
	PosX = PosX + 1;
	PosY = PosY;
}
//��������һ��
void HIM::moveSOUTH() {
	SavePosition();
	PosX = PosX;
	PosY = PosY + 1;
}
//��������һ��
void HIM::moveWEST() {
	SavePosition();
	PosX = PosX - 1;
	PosY = PosY;
}
//������һ��
void HIM::moveNORTH() {
	SavePosition();
	PosX = PosX;
	PosY = PosY  - 1;
}

//����������һ�ε�ͼ��
void HIM::DrawHumanMove() {
	gotoxy(PreX, PreY);
	cout << ' ';
	gotoxy(PosX, PosY);
	cout << Human;
}

//��ǰ��������һ�β��ж��Ƿ񵽳���
void HIM::moveForward() {
	
	switch (Dir) {
	case NORTH:moveNORTH(); break;
	case SOUTH:moveSOUTH(); break;
	case EAST:moveEAST(); break;
	case WEST:moveWEST(); break;
	default:cout << "����ʧ�����ˣ�" << endl;
	}
	Sleep(1000);
	DrawHumanMove();
	if (MazeMap::CheckExitOrNot(PosX,PosY)) {
		OutOrNot = true;
		gotoxy(0,17);
		cout << "�����ڳ����ˣ�" << endl;
	}
}

//����ת
void HIM::TurnRight() {
	switch (Dir) {
	case NORTH:Dir = EAST; break;
	case SOUTH:Dir = WEST; break;
	case EAST:Dir = SOUTH; break;
	case WEST:Dir = NORTH; break;
	default:cout << "����ʧ�����ˣ�" << endl;
	}
	Sleep(1000);
}

//����ת
void HIM::TurnLeft() {
	switch (Dir) {
	case NORTH:Dir = WEST; break;
	case SOUTH:Dir = EAST; break;
	case EAST:Dir = NORTH; break;
	case WEST:Dir = SOUTH; break;
	default:cout << "����ʧ�����ˣ�" << endl;
	}
	Sleep(1000);
}

//�ж�һ��(�ı䳯���ǰ��һ��)
bool HIM::Action() {
	//�жϳ�ʼλ���Ƿ�Ϊǽ��
	if (MazeMap::CheckWallOrNot(PosX, PosY)) {
		gotoxy(0, 15);
		cout << "�ó�ʼλ��Ϊǽ�ڣ�����������" << endl;
		OutOrNot = false;
	}
	//�����λ���ǳ�ʼλ�ã���ֱ�ӻ�������
	if (PreX == 1000 || PreY == 1000) {
		gotoxy(PosX, PosY);
		cout << Human;
	}
	//���ڼ�¼��ǰλ�õ���ߵ�����
	int LeftX, LeftY;
	//���ڼ�¼��ǰλ�õ�ǰ��������
	int ForwardX, ForwardY;
	switch(Dir) {
	case NORTH: LeftX = PosX - 1; LeftY = PosY;
				ForwardX = PosX; ForwardY = PosY - 1; break;
	case SOUTH: LeftX = PosX + 1; LeftY = PosY;
			    ForwardX = PosX; ForwardY = PosY + 1; break;
	case EAST:  LeftX = PosX; LeftY = PosY - 1;
			    ForwardX = PosX + 1; ForwardY = PosY; break;
	case WEST:  LeftX = PosX; LeftY = PosY + 1;
			    ForwardX = PosX - 1; ForwardY = PosY; break;
	default:cout << "����ʧ�����ˣ�" << endl;
	}
	//�ж�����Ƿ�Ϊǽ�����Ǿ������ߣ������ж�ǰ���Ƿ�Ϊǽ�����Ǿ���ǰ���ߣ���������ת
	if (MazeMap::CheckWallOrNot(LeftX,LeftY)) {
		if (MazeMap::CheckWallOrNot(ForwardX, ForwardY)) {
			TurnRight();
			return false;
		}
		else {
			moveForward();
			return true;
		}
	}
	else {
		TurnLeft();
		moveForward();
		return true;
	}
}

//�Թ��е��˿�ʼ����
void HIM::start() {
	int i = 0;
	while (!OutOrNot) {
		if (Action()) {
			++i;
			gotoxy(0, 15);
			cout << i << "��";
		}
	}
}

//�ı���λ��
void HIM::gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
};
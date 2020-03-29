#include"HumanInMaze.h"
#include"MazeMap.h"
#include<windows.h>
#include<iostream>
using namespace std;

//构造函数：初始化迷宫中的人的默认属性
HIM::HIM():Human('T'),PreX(1000),PreY(1000),PosX(0),PosY(0),Dir(NORTH) { }

//构造函数：用户指定迷宫中的人的出生地
HIM::HIM(int X, int Y):Human('T'), PreX(1000), PreY(1000), PosX(X), PosY(Y),Dir(NORTH) { }

//构造函数：用户指定迷宫中的人的出生地、面朝方向
HIM::HIM(int X, int Y, Direction dir): Human('T'), PreX(1000), PreY(1000), PosX(X), PosY(Y), Dir(dir){ }

//构造函数：用户指定迷宫中的人的出生地、面朝方向和表示人的符号
HIM::HIM(int X, int Y, Direction dir, char human):PreX(1000), PreY(1000), PosX(X), PosY(Y), Dir(dir),Human(human){ }

//设置人的出生地
void HIM::setBirthPos(int X, int Y) {
	PosX = X;
	PosY = Y;
}

//设置代表人的符号
void HIM::setHumanPic(char human) {
	Human = human;
}

//保存移动前的位置
void HIM::SavePosition() {
	PreX = PosX;
	PreY = PosY;
}

//向东行走一次
void HIM::moveEAST() {
	SavePosition();
	PosX = PosX + 1;
	PosY = PosY;
}
//向南行走一次
void HIM::moveSOUTH() {
	SavePosition();
	PosX = PosX;
	PosY = PosY + 1;
}
//向西行走一次
void HIM::moveWEST() {
	SavePosition();
	PosX = PosX - 1;
	PosY = PosY;
}
//向北行走一次
void HIM::moveNORTH() {
	SavePosition();
	PosX = PosX;
	PosY = PosY  - 1;
}

//绘制人行走一次的图像
void HIM::DrawHumanMove() {
	gotoxy(PreX, PreY);
	cout << ' ';
	gotoxy(PosX, PosY);
	cout << Human;
}

//向当前朝向行走一次并判断是否到出口
void HIM::moveForward() {
	
	switch (Dir) {
	case NORTH:moveNORTH(); break;
	case SOUTH:moveSOUTH(); break;
	case EAST:moveEAST(); break;
	case WEST:moveWEST(); break;
	default:cout << "我迷失方向了！" << endl;
	}
	Sleep(1000);
	DrawHumanMove();
	if (MazeMap::CheckExitOrNot(PosX,PosY)) {
		OutOrNot = true;
		gotoxy(0,17);
		cout << "俺终于出来了！" << endl;
	}
}

//向右转
void HIM::TurnRight() {
	switch (Dir) {
	case NORTH:Dir = EAST; break;
	case SOUTH:Dir = WEST; break;
	case EAST:Dir = SOUTH; break;
	case WEST:Dir = NORTH; break;
	default:cout << "我迷失方向了！" << endl;
	}
	Sleep(1000);
}

//向左转
void HIM::TurnLeft() {
	switch (Dir) {
	case NORTH:Dir = WEST; break;
	case SOUTH:Dir = EAST; break;
	case EAST:Dir = NORTH; break;
	case WEST:Dir = SOUTH; break;
	default:cout << "我迷失方向了！" << endl;
	}
	Sleep(1000);
}

//行动一次(改变朝向或前进一步)
bool HIM::Action() {
	//判断初始位置是否为墙壁
	if (MazeMap::CheckWallOrNot(PosX, PosY)) {
		gotoxy(0, 15);
		cout << "该初始位置为墙壁，请重新设置" << endl;
		OutOrNot = false;
	}
	//如果该位置是初始位置，则直接绘制人像
	if (PreX == 1000 || PreY == 1000) {
		gotoxy(PosX, PosY);
		cout << Human;
	}
	//用于记录当前位置的左边的坐标
	int LeftX, LeftY;
	//用于记录当前位置的前方的坐标
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
	default:cout << "我迷失方向了！" << endl;
	}
	//判断左边是否为墙，不是就向左走，否则判断前方是否为墙，不是就向前方走，否则向右转
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

//迷宫中的人开始行走
void HIM::start() {
	int i = 0;
	while (!OutOrNot) {
		if (Action()) {
			++i;
			gotoxy(0, 15);
			cout << i << "步";
		}
	}
}

//改变光标位置
void HIM::gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
};
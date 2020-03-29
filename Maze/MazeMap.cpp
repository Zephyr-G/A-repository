/*迷宫类定义*/

#include"MazeMap.h"
#include<iostream>
using namespace std;

int MazeMap::MazeWidth = 0;
int MazeMap::MazeHeight = 0;
int MazeMap::MazeMapArray[screenHeight][screenWidth];
//构造函数：使用默认的迷宫属性
MazeMap::MazeMap() : Wall('*'),Road(' ') {}
//构造函数：使用用户给定的地图
MazeMap::MazeMap(int* mazemap,int row,int column): Wall('*'), Road(' '){
	MazeHeight = row; MazeWidth = column;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			MazeMapArray[i][j] = mazemap[i*column + j];
}
//构造函数：使用用户给定的地图和墙壁符号
MazeMap::MazeMap(int* mazemap, int row, int column, char wall): Wall(wall), Road(' '){
	MazeHeight = row; MazeWidth = column;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			MazeMapArray[i][j] = mazemap[i*column + j];
}
//设置墙的符号
void MazeMap::setWall(char wall) {
	Wall = wall;
}
//设置道路的符号
void MazeMap::setRoad(char road) {
	Road = road;
}
//使用默认的迷宫地图
void MazeMap::DefaultMap() {
	int map[7][7] = { {WALL,ROAD,WALL,WALL,WALL,WALL,WALL},
					  {WALL,ROAD,ROAD,WALL,ROAD,WALL,WALL},
					  {WALL,WALL,ROAD,WALL,ROAD,WALL,WALL},
					  {WALL,WALL,ROAD,WALL,ROAD,WALL,WALL},
					  {WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL},
					  {WALL,ROAD,ROAD,WALL,WALL,ROAD,ROAD},
					  {WALL,ROAD,WALL,WALL,WALL,WALL,WALL} };
	setMazeMap(*map, 7, 7);
}
//设置迷宫地图
void MazeMap::setMazeMap(int* mazemap, int row, int column) {
	MazeHeight = row;
	MazeWidth = column;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			MazeMapArray[i][j] = mazemap[i * column + j];
}
//在控制台打印迷宫
void MazeMap::DrawMap() {
	for (int i = 0; i < MazeHeight; ++i) {
		for (int j = 0; j < MazeWidth; ++j)
			if (MazeMapArray[i][j] == WALL)
				cout << Wall;
			else
				cout << Road;
		cout << endl;
	}
}
//检查某处是否为墙，是返回true,不是返回false
bool MazeMap::CheckWallOrNot(int X, int Y) {
	if (MazeMapArray[Y][X] == WALL)
		return true;
	else
		return false;
}
//检查某处是否为出口，是返回true,不是返回false
bool MazeMap::CheckExitOrNot(int X, int Y) {
	if (MazeMapArray[Y][X] == ROAD && (X == 0 || X == (MazeWidth - 1) || Y == 0 || Y == (MazeHeight - 1)))
		return true;
	else
		return false;
}



/*�Թ��ඨ��*/

#include"MazeMap.h"
#include<iostream>
using namespace std;

int MazeMap::MazeWidth = 0;
int MazeMap::MazeHeight = 0;
int MazeMap::MazeMapArray[screenHeight][screenWidth];
//���캯����ʹ��Ĭ�ϵ��Թ�����
MazeMap::MazeMap() : Wall('*'),Road(' ') {}
//���캯����ʹ���û������ĵ�ͼ
MazeMap::MazeMap(int* mazemap,int row,int column): Wall('*'), Road(' '){
	MazeHeight = row; MazeWidth = column;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			MazeMapArray[i][j] = mazemap[i*column + j];
}
//���캯����ʹ���û������ĵ�ͼ��ǽ�ڷ���
MazeMap::MazeMap(int* mazemap, int row, int column, char wall): Wall(wall), Road(' '){
	MazeHeight = row; MazeWidth = column;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			MazeMapArray[i][j] = mazemap[i*column + j];
}
//����ǽ�ķ���
void MazeMap::setWall(char wall) {
	Wall = wall;
}
//���õ�·�ķ���
void MazeMap::setRoad(char road) {
	Road = road;
}
//ʹ��Ĭ�ϵ��Թ���ͼ
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
//�����Թ���ͼ
void MazeMap::setMazeMap(int* mazemap, int row, int column) {
	MazeHeight = row;
	MazeWidth = column;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			MazeMapArray[i][j] = mazemap[i * column + j];
}
//�ڿ���̨��ӡ�Թ�
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
//���ĳ���Ƿ�Ϊǽ���Ƿ���true,���Ƿ���false
bool MazeMap::CheckWallOrNot(int X, int Y) {
	if (MazeMapArray[Y][X] == WALL)
		return true;
	else
		return false;
}
//���ĳ���Ƿ�Ϊ���ڣ��Ƿ���true,���Ƿ���false
bool MazeMap::CheckExitOrNot(int X, int Y) {
	if (MazeMapArray[Y][X] == ROAD && (X == 0 || X == (MazeWidth - 1) || Y == 0 || Y == (MazeHeight - 1)))
		return true;
	else
		return false;
}



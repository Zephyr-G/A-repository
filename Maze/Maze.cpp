#include <iostream>
#include "MazeMap.h"
#include "HumanInMaze.h"
#include <stdlib.h>
#include<windows.h>
using namespace std;
void hide_cursor()
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}
MazeMap mazemap;
HIM human(1,6);
int map[8][8] = {	  {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
					  {WALL,ROAD,ROAD,WALL,ROAD,WALL,WALL,WALL},
					  {WALL,WALL,ROAD,WALL,ROAD,WALL,WALL,WALL},
					  {WALL,WALL,ROAD,WALL,ROAD,WALL,WALL,WALL},
					  {WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,WALL},
					  {WALL,ROAD,ROAD,WALL,WALL,ROAD,ROAD,ROAD},
					  {WALL,ROAD,WALL,WALL,WALL,ROAD,WALL,WALL},
					  {WALL,WALL,WALL,WALL,WALL,ROAD,WALL,WALL} };
int main(){
	hide_cursor();
	mazemap.DefaultMap();
	//mazemap.setMazeMap(*map, 8, 8);
	mazemap.DrawMap();
	//human.setBirthPos(5, 7);
	human.start();
	system("pause");
	return 0;
}

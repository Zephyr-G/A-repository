/*定义迷宫类*/
#ifndef MAZEMAP_H_
#define MAZEMAP_H_

const int WALL = 1;
const int ROAD = 0;
const int screenHeight = 100;
const int screenWidth = 100;
class MazeMap {
public:
	MazeMap();//构造函数：使用默认的迷宫属性
	MazeMap(int* mazemap,int row,int column);//构造函数：使用用户给定的地图
	MazeMap(int* mazemap, int row, int column,char wall);//构造函数：使用用户给定的地图和墙壁符号
	void setWall(char wall);//设置墙的符号
	void setRoad(char road);//设置道路的符号
	void DefaultMap();//使用默认的迷宫地图
	void setMazeMap(int* mazemap, int row, int column);//修改迷宫地图
	void DrawMap();//在控制台绘制迷宫
	static bool CheckWallOrNot(int X,int Y);//检查某处是否为墙，是返回true,不是返回false
	static bool CheckExitOrNot(int X,int Y);//检查某处是否为出口，是返回true,不是返回false
private:
	char Wall;
	char Road;
	static int MazeMapArray[screenHeight][screenWidth];
	static int MazeHeight;
	static int MazeWidth;
};
#endif //MAZEMAP_H_

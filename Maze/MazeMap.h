/*�����Թ���*/
#ifndef MAZEMAP_H_
#define MAZEMAP_H_

const int WALL = 1;
const int ROAD = 0;
const int screenHeight = 100;
const int screenWidth = 100;
class MazeMap {
public:
	MazeMap();//���캯����ʹ��Ĭ�ϵ��Թ�����
	MazeMap(int* mazemap,int row,int column);//���캯����ʹ���û������ĵ�ͼ
	MazeMap(int* mazemap, int row, int column,char wall);//���캯����ʹ���û������ĵ�ͼ��ǽ�ڷ���
	void setWall(char wall);//����ǽ�ķ���
	void setRoad(char road);//���õ�·�ķ���
	void DefaultMap();//ʹ��Ĭ�ϵ��Թ���ͼ
	void setMazeMap(int* mazemap, int row, int column);//�޸��Թ���ͼ
	void DrawMap();//�ڿ���̨�����Թ�
	static bool CheckWallOrNot(int X,int Y);//���ĳ���Ƿ�Ϊǽ���Ƿ���true,���Ƿ���false
	static bool CheckExitOrNot(int X,int Y);//���ĳ���Ƿ�Ϊ���ڣ��Ƿ���true,���Ƿ���false
private:
	char Wall;
	char Road;
	static int MazeMapArray[screenHeight][screenWidth];
	static int MazeHeight;
	static int MazeWidth;
};
#endif //MAZEMAP_H_

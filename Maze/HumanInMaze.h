/*定义迷宫中的人类*/
#ifndef HumanInMaze_H_
#define HumanInMaze_H_
enum Direction{EAST,SOUTH,WEST,NORTH};
//HIM=HumanInMaze
class HIM {
public:
	HIM();//构造函数：初始化迷宫中的人的默认属性
	HIM(int X, int Y);//构造函数：用户指定迷宫中的人的出生地
	HIM(int X, int Y, Direction dir);//构造函数：用户指定迷宫中的人的出生地、面朝方向
	HIM(int X, int Y, Direction dir,char human);//构造函数：用户指定迷宫中的人的出生地、面朝方向和表示人的符号
	void setBirthPos(int X, int Y);//设置人的出生地
	void setHumanPic(char human);//设置代表人的符号
	void SavePosition();//保存移动前的位置
	void moveEAST();//向东行走一次（仅改变坐标）
	void moveSOUTH();//向南行走一次（仅改变坐标）
	void moveWEST();//向西行走一次（仅改变坐标）
	void moveNORTH();//向北行走一次（仅改变坐标）
	void moveForward();//向当前方向前进一次，绘制移动图像并判断是否到达出口
	void TurnRight();//向右转
	void TurnLeft();//向左转
	void gotoxy(int X, int Y);//改变光标位置
	void DrawHumanMove();//绘制移动图像
	bool Action();//行动一次(改变朝向或前进一步)
	void start();//开始行走

private:
	char Human;
	int PreX;//前一个位置坐标
	int PreY;//
	int PosX;//当前位置坐标
	int PosY;//
	Direction Dir;//当前朝向，及前进方向
	bool OutOrNot;//是否到达出口，否为false
};
#endif //HumanInMaze_H_
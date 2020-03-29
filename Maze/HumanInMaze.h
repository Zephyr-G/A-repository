/*�����Թ��е�����*/
#ifndef HumanInMaze_H_
#define HumanInMaze_H_
enum Direction{EAST,SOUTH,WEST,NORTH};
//HIM=HumanInMaze
class HIM {
public:
	HIM();//���캯������ʼ���Թ��е��˵�Ĭ������
	HIM(int X, int Y);//���캯�����û�ָ���Թ��е��˵ĳ�����
	HIM(int X, int Y, Direction dir);//���캯�����û�ָ���Թ��е��˵ĳ����ء��泯����
	HIM(int X, int Y, Direction dir,char human);//���캯�����û�ָ���Թ��е��˵ĳ����ء��泯����ͱ�ʾ�˵ķ���
	void setBirthPos(int X, int Y);//�����˵ĳ�����
	void setHumanPic(char human);//���ô����˵ķ���
	void SavePosition();//�����ƶ�ǰ��λ��
	void moveEAST();//������һ�Σ����ı����꣩
	void moveSOUTH();//��������һ�Σ����ı����꣩
	void moveWEST();//��������һ�Σ����ı����꣩
	void moveNORTH();//������һ�Σ����ı����꣩
	void moveForward();//��ǰ����ǰ��һ�Σ������ƶ�ͼ���ж��Ƿ񵽴����
	void TurnRight();//����ת
	void TurnLeft();//����ת
	void gotoxy(int X, int Y);//�ı���λ��
	void DrawHumanMove();//�����ƶ�ͼ��
	bool Action();//�ж�һ��(�ı䳯���ǰ��һ��)
	void start();//��ʼ����

private:
	char Human;
	int PreX;//ǰһ��λ������
	int PreY;//
	int PosX;//��ǰλ������
	int PosY;//
	Direction Dir;//��ǰ���򣬼�ǰ������
	bool OutOrNot;//�Ƿ񵽴���ڣ���Ϊfalse
};
#endif //HumanInMaze_H_
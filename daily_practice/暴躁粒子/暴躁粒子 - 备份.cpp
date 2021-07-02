#include <graphics.h> 
#include <math.h>
#include <time.h>

#define WIDTH      1024    //��Ļ�Ŀ� 
#define HEIGHT     768     //��Ļ�ĸ� 
#define NUM_MOVERS  800	   //С������ 
#define FRICTION   0.96f   //Ħ����������ϵ�� 

//����С��ṹ
struct Mover
{
	COLORREF  color;   //��ɫ 
	float     x,y;     //���� 
	float     vX,vY;   //�ٶ� 
	float     radius;  //�뾶 
 } ;
 
 //����ȫ�ֱ���
 Mover movers[NUM_MOVERS] ;    //
 int mouseX,mouseY;          //
 int prevMouseX ,prevMouseY; //
 int mouseVX,mouseVY;		 //
 int isMouseDown;			 //
 
 void startup()
 {
 	//����������� 
 	srand((unsigned int)time(NULL));
 	
 	//��ʼ��С������
	for(int i = 0;i<NUM_MOVERS;i++) 
	{
		movers[i].color = RGB(rand() % 256 ,rand() &256,rand() % 256);
		movers[i].x = rand()% WIDTH;
		movers[i].y = rand()% HEIGHT;
		movers[i].vX = float(cos(float(i))) * (rand() % 34);
		movers[i].vY = float(sin(float(i))) * (rand() % 34);
		movers[i].radius = (rand() % 34)/15.0;		
	}
 	
 	//��ʼ������������ǰ������꣬�ϴ���궼�ڻ�������
	 mouseX = prevMouseX = WIDTH / 2;
	 mouseY = prevMouseY = HEIGHT / 2;
	 
	 isMouseDown = 0;
	 
	 initgraph(WIDTH,HEIGHT) ;
	 BeginBatchDraw();
 }
 
 void show()
 {
 	clearrectangle(0,0,WIDTH - 1,HEIGHT - 1);
 	
 	for(int i = 0;i<NUM_MOVERS;i++)
	{
		//��С�� 
		setcolor(movers[i].color);
		setfillstyle(movers[i].color);
		fillcircle(int (movers[i].x + 0.5),int (movers[i].y  + 0.5),int (movers[i].radius + 0.5));
	 } 
 	FlushBatchDraw() ;
 	Sleep(5);	
 }
 
 void updateWithoutInput()
 {
 	float toDist = WIDTH * 0.86;
 	float blowDist = WIDTH * 0.5;
 	float striDist = WIDTH * 0.125;
 	
 	mouseVX = mouseX - prevMouseX;
 	mouseVY = mouseY - prevMouseY;
 	
 	prevMouseX = mouseX;
 	prevMouseY = mouseY;
 	
 	for(int i = 0;i<NUM_MOVERS;i++)   //������С����б��� 
 	{
 		float x = movers[i].x;
 		float y = movers[i].y;
 		float vX = movers[i].vX;
 		float vY = movers[i].vY;
 		
 		float dX = x - mouseX;
 		float dY = y - mouseY;
 		float d = sqrt(dX * dX + dY * dY);
 		
 		if(d!=0)
 		{
 			dX = dX/d;
 			dY = dY/d;
		 }
 		else
 		{
 			dX = 0;
 			dY = 0;
		 }
 		
 		//��С��������< toDist ,�ڴ˷�Χ��С��ͻ��ܵ�����ָ��
		 if(d < toDist)
		 {
		 	//
		 	//
		 	float toACC = (1 - (d/toDist)) * WIDTH * 0.0014f;
		 	//
		 	vX = vX - dX * toACC;
		 	vY = vY - dY * toACC;
		 }
		 
		 //�����������£�����С��������<blowDist���ڴ����Χ�ڣ� ʱ���ܵ��������
		 if(isMouseDown && d < blowDist) 
		 {
		 	float blowACC = (1 - (d/ blowDist))  * 10;
		 	
		 	vX = vX + dX * blowACC + 0.5f - float(rand()) / RAND_MAX;
		 	vY = vY + dY * blowACC + 0.5f - float(rand()) / RAND_MAX;	
		 }
		 
		 if(d < striDist)
		 {
		 	float mACC = (1 - (d/striDist))	 * WIDTH * 0.00026f;
		 	vX = vX * FRICTION;
		 	vY = vY * FRICTION;
		 	
		 	float avgVX = abs(vX);
		 	float avgVY = abs(vY);
		 	
		 	float avgV = (avgVX + avgVY) * 0.5f;
		 	
		 	if(avgVX<0.1)
		 		vX = vX * float(rand())/ RAND_MAX * 3;
		 	if(avgVY < 0.1) 
		 		vY = vY * float(rand())/ RAND_MAX * 3;
		 		
		 	float sc = avgV * 0.45f;
		 	sc = max(min(sc, 3.5f),0.4f);
		 	movers[i].radius = sc;
		 	
		 	float nextX = x + vX;
		 	float nextY = y + vY;
		 	
		 	if(nextX > WIDTH)
		 	{
		 		nextX = WIDTH;
		 		vX    = -1*vX;
			 }
		 	else if(nextX<0)
		 	{
		 		nextX = 0;
		 		vX=-1*vX;
			 }
		 	if(nextY > HEIGHT)
		 	{
		 		nextY = HEIGHT;
		 		vY = -1 * vY;
			 }
			 else if(nextY < 0)
			 {
			 	nextY = 0;
			 	vY = -1*vY;
			 }
			 
			 movers[i].vX = vY;
			 movers[i].vY = vY;
			 movers[i].x  = nextX;
			 movers[i].y  = nextY;	 
		 }	
	 }
	}
 	void updateWithInput() 
 	{
 		MOUSEMSG m;
 		while(MouseHit())
 		{
 			m = GetMouseMsg() ;
 			if(m.uMsg == WM_MOUSEMOVE)
 			{
 				mouseX = m.x;
 				mouseY = m.y;
			 }
 			else if (m.uMsg == WM_LBUTTONDOWN)
 				isMouseDown = 1;
 			else if(m.uMsg == WM_LBUTTONUP)	
 				isMouseDown = 0;
		 }
	 }
 	
 	void gameover()
 	{
 		EndBatchDraw();
 		closegraph();
	 }
 	
 	int main()
 	{
 		startup();
 		while(1)
 		{
 			show();
 			updateWithInput();
 			updateWithoutInput();
		 }
 		gameover();
 		return 0;
	 }

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

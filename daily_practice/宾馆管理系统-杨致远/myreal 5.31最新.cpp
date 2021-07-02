#include <windows.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int system_time_year()
{
	int year;
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);

    year = 1900+p->tm_year ; /*��ȡ��ǰ���,��1900��ʼ������Ҫ��1900*/
    return year;
}
 int system_time_month()
{
	int month;
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);


    month = 1+p->tm_mon;      /*��ȡ��ǰ�·�,��Χ��0-11,����Ҫ��1*/
	return month;
    
}
 int system_time_day()
{
	int day;
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);

    day = p->tm_mday;        /*��ȡ��ǰ�·�����,��Χ��1-31*/
	return day;  
}
	int system_time_hour()
{
	int h=0;
	time_t t=time(NULL);
    time_t t1;
    time(&t1); 
	h=(t%(3600*24)/3600+8);//ʱ  
    return h;

} 
int system_time_mintue()
	{
	 int m=0;
	 time_t t=time(NULL);
     time_t t1;
     time(&t1); 
	 m=t%3600/60;           //�� 
	 return m;

	} 
	int system_time_second()
	{
	 int s=0;
	 time_t t=time(NULL);
     time_t t1;
     time(&t1);
     s=t%60;                //�� 
	 return s;
	} 

//������ԭʼ�ķ������� 
int save_Room()
{
	const char* filename = "room.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}

	char grad[22] = "ACEDBCAEBECADCEBADCEC"; 
//	acedbcaebecadcebadcec

	int  nu[21]={105,121,145,132,116,125,103,144,
	112,143,124,102,133,123,141,111,101,136,122,142,126};   
	    
	char stat[22] = "NYYNYNYNYNYNYNNYNYNYY";

	for(int i = 0;i<21;i++)
	{	
		fprintf(fp,"���ͣ�Grade = %c ����ţ�Num = %d ��ǰ״̬��State = %c\n",grad[i] , nu[i] , stat[i]);
	}
	fclose(fp);
	return 0;
}


int load_Room()
{
	
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	cout<<"��ǰ���з����״̬�ȼ�������ţ����䵱ǰ״̬�ֱ�Ϊ��"<<endl; 
	char buf[512];
	int n = 0;
	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		if(line)
		{
			printf(" %s",line);
			n++;
		}
	}
	cout<<"\n����"<<n<<"�������¼"<<endl;
	cout<<"\n"<<endl;
	cout<<"�������ͷ�ABCDE����ȼ������䵱ǰ״̬N����û�п���Y�����п���"<<endl;
	fclose(fp);
	return 0;
}

//������ԭʼ�Ŀ�����ס��¼���� 
int save_guest()
{
	const char* filename = "guest.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}

	char name[12][12] = {"Ashley","Amanda","Jessica","Sarah","Brittany",
	"Megan","Jennifer","Nicole","Stephanie","Katherine","Allon"};

	char id[12][18] = {"410145121015218","101451451200110","210181150404566",
		"220551511550484","235124031013024","312545147845440","320025154413883",
		"930154540188383","871212415458538","827545811458575","132134314211422"};

	char gender[12] = "MWMMMWMWMWM";

	char grad[12] = "CEBABCDBDEC"; 
 
	char  nu[12][4]   ={"121","145","116","103",
	"112","124","133","111","136","142","126"}; 
	char year[12][5]  = {"2019","2018","2019","2019","2018","2019","2019","2019","2018","2019","2019"};
	char month[12][3] = {"11","12","3","5","8","9","6","7","5","4"};
	char day[12][3]   = {"31","27","23","19","15","11","9","8","2","1","5"};
	char hour[12][3]  = {"12","23","0","10","21","13","14","15","16","18","12"};
	char minute[12][3] = {"56","42","58","42","35","28","16","9","7","10","12"};
	char second[12][3] = {"00","01","55","13","53","54","53","12","21","41","33"};


	for(int j = 0;j<11;j++)
	{	
		fprintf(fp,"������name = %9s ID��id = %18s �Ա�gender = %c ��ס�ķ�����𼰷����: %c %s��ס��ʱ��Ϊ: %4s/%2s/%2s  %2s:%2s:%2s\n"			
			,name[j] , id[j] , gender[j],grad[j],nu[j],year[j],month[j],day[j],hour[j],minute[j],second[j]);  												
}
	fclose(fp);
	return 0;
}

int load_guest()
{
	const char* filename = "guest.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}

	char buf[512];
	int n = 0;
	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		if(line)
		{
			printf(" %s",line);
			n++;
		}
	}
	cout<<"\n���ڹ���"<<n<<"�����˼�¼"<<endl;
	cout<<"\n\n"<<endl;
	fclose(fp);
	return 0;
}

int new_save_guest(char name[32],char id[18],char gender,char grad,char  nu[4],int year,int month,int day,int hour,int mintue,int second ) //year month,day,hour,minute,second    
{
	const char* filename = "guest.txt";
	FILE* fp = fopen(filename ,"ab");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	fprintf(fp,"������name = %9s ID��id = %18s �Ա�gender = %c ��ס�ķ�����𼰷����: %c %s��ס��ʱ��Ϊ: %4d/%2d/%2d  %2d:%2d:%2d\n",name , id , gender,grad,nu,year,month,day,hour,mintue,second);   //      

	fclose(fp);
	return 0;
}

//д�����¿�����ס�������Ϣ
int save_new_Room(char grad,char nu[4])
{
	const char* filename = "room.txt";
	FILE* fp = fopen(filename,"ab");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}
	fprintf(fp,"���ͣ�Grade = %c ����ţ�Num = %s ��ǰ״̬��State = %c",grad , nu ,'Y');

	fclose(fp);
	return 0;
}


//��ȡ�����·�����Ϣ���ַ������ַ���acc[]
//�ҳ���ȡ���ַ���acc[]��ԭ�ļ������У�n��


 int gets_str_new_Room___load_getline_old_Room(char grad,char nu[4])
{
	
	char *p;
	char acc[5];
	acc[0] = grad;
	for(int i = 1;i<4;i++)
	{
		//cout<<"i = "<<i<<endl;
		acc[i] = nu[i-1];
	}
	acc[4] = 'N';
	p = (char *)malloc(10);
	

	int n = 0;
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}

	char buf[512];

	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		n++;
		if(acc[0] == *(line+14) && acc[1] ==  *(line+30) && acc[2] == *(line+31) && acc[3] == *(line+32) && acc[4] == *(line+52))
		break;
	}

	fclose(fp);
	return n;

}


//ɾ��Room��¼�е�ָ���е�n��,�Է���ļ�¼ˢ��
int newly_delete_n_Room(int n)
{
	int m = -1;

	const char* filename = "room.txt";
	FILE* fp_ = fopen(filename ,"rb");
	
	char buf[512];
	while(! feof(fp_))
	{
		char* line = fgets(buf,512,fp_);
		m++;
	}
	fclose(fp_);
	
	
	FILE* fp = fopen(filename ,"rb");
	
	const char* filename_s = "temp.txt"; 
	FILE* fps = fopen(filename_s ,"wb");
	
	char buf_[512];
	for(int i = 1;i <= m;i++)
	{
		char* line = fgets(buf_,512,fp);
		if(i != n && i)
		{
			fprintf(fps,"%s", line);
			n++;
		}	
	}

	fclose(fp);
	fclose(fps);
	
	

	FILE* fp2 = fopen(filename ,"wb");
	
	FILE* fps2 = fopen(filename_s ,"rb");
	
	for(int i = 1;i < m;i++)
	{
		char* line = fgets(buf_,512,fps2);
		fprintf(fp2,"%s", line);
	}
	fclose(fp2);
	fclose(fps2);
	return 0;
}


/**
ɾ��ָ���ļ�filepath�е�n������
˼·:
1.���ζ�ȡԴ�ļ�����(���˵�n��),����д�뵽�µ�tmp.txt�ļ���
2.Ȼ�����Դ�ļ�����tmp.txt�ļ����¶�ȡд�뵽Դ�ļ�
3.ɾ��tmp.txt�ļ�
**/



//��ӡ��ǰ���з����¼
int print_empty_Room()
{
	int m = -1;
	const char* filename_ = "room.txt";
	FILE* fp_ = fopen(filename_ ,"rb");
	if(fp_ == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf[512];
	while(! feof(fp_))
	{
		char* line = fgets(buf,512,fp_);
		m++;
	}
	fclose(fp_);
		
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf_[512];
	int n = 0;
	for(int i = 0;i < m;i++)
	{
		char* line = fgets(buf_,512,fp);
		if(*(line+52) == 'N')
		{
			printf("%s",line);
			n++;
		}
	}
	cout<<"\n����"<<n<<"���տͷ�\n\n\n"<<endl;
	fclose(fp);
	return 0;
}

//��ӡ��ǰʱ���п��˵ķ����¼
int print_full_Room()
{
	int m = -1;
	const char* filename_ = "room.txt";
	FILE* fp_ = fopen(filename_ ,"rb");
	if(fp_ == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf[512];
	while(! feof(fp_))
	{
		char* line = fgets(buf,512,fp_);
		m++;
	}
	fclose(fp_);
		
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf_[512];
	int n = 0;
	for(int i = 0;i < m;i++)
	{
		char* line = fgets(buf_,512,fp);
		if(*(line+52) == 'Y')
		{
			printf("%s",line);
			n++;
		}
	}
	cout<<"\n����"<<n<<"���п��˵ķ���\n\n\n"<<endl;
	fclose(fp);
	return 0;
}

int main()
{

	char name[32];char id[18];char gender;char grad;char  nu[4];

	int m;

	cout<<"Welcome to hotel management system"<<endl;
//	save_Room();  //д������ԭʼ�ķ������� 
//	save_guest(); //д����ԭʼ�Ŀ�����ס��¼���� 

	while(1)
{
	cout<<  "������Ҫ���������Ĳ���:								  "<<endl;	
	cout<<  "��������1����ִ�д�ӡ��ǰʱ�̷����¼					  "<<endl;
	cout<<  "��������2����ִ�д�ӡ��ǰʱ�̵Ŀ��˼�¼				  "<<endl;
	cout<<  "��������3����ִ�д�ӡ��ǰʱ�̿շ����¼				  "<<endl;
	cout<<  "��������4����ӡ��ǰʱ���п��˵ķ����¼				  "<<endl;
	cout<<  "��������5����ִ��д������ס�Ŀ��˼�¼���Է���ļ�¼ˢ��  "<<endl;
	
	cout<<"���������֣�"<<endl;

	int sel;
	cin>>sel;

	getchar();

	switch(sel)
	{
	case 1:
		load_Room(); //������ԭʼ�ķ������ݣ���ӡԭʼ�����¼
		break;
	case 2:
		load_guest();//������ԭʼ�Ŀ�����ס��¼���� ����ӡԭʼ���˼�¼
		break;

	case 3:
		cout<<"��ӡ��ǰʱ�̿��з����¼ "<<endl;
		cout<<"N����û�ˣ�Ϊ�շ��䣻Y�������ˣ����ǿշ��䡣"<<endl;
		print_empty_Room();

		break;
	case 4:	
		cout<<"��ӡ��ǰʱ���п��˵ķ����¼ "<<endl;
		cout<<"N����û�ˣ�Ϊ�շ��䣻Y�������ˣ����ǿշ��䡣"<<endl;
		print_full_Room();

		break;
	case 5:	
		cout<<"��ǰ�շ����������б�����ס����ֻ����ס��ǰʱ�̵Ŀշ��䣬��¼������ס������Ϣ���ѡ�����¿շ���"<<endl;
		
		cout<<"������ABCDE������ͣ�ÿ������6�����䣬�ܹ�5*6 = 30�����䣬����Ŷ�����������,���£�"<<endl;
		cout<<"B,C,D,E���ͷ���ŷֱ���11��12��13��14��ͷ�ģ������β������Ϊ1��2��3��4��5��6"<<endl;
		cout<<"A����ţ�101��102��103��104��105��106��"<<endl;
		cout<<"B����ţ�111��112��113��114��115��116��"<<endl;
		cout<<"C����ţ�121��122��123��124��125��126��"<<endl;
		cout<<"D����ţ�131��132��133��134��135��136��"<<endl;
		cout<<"E����ţ�141��142��143��144��145��146��\n\n"<<endl; //B,C,D,E���ͷ���ŷֱ���11��12��13��14��ͷ�ģ������β������Ϊ1��2��3��4��5��6

		//��ӡ��ǰʱ�̿��з����¼
		cout<<"��ӡ��ǰʱ�̿��з����¼ "<<endl;
		cout<<"N����û�ˣ�Ϊ�շ��䣻Y�������ˣ����ǿշ��䡣\n"<<endl;
		print_empty_Room();

		cout<<"\n���������              ���������32���ַ�����                                 "<<endl;
		cin>> name;
		cout<<"\n��ֱ�������ID        ��IDΪ18λ���֣���                                         "<<endl;
		cin>> id;
		cout<<"\n��ֱ�����Ա�gender  ���Ա��ô�д��ĸM��W��ʾ��M����man����,W����womanŮ�ԣ�"<<endl;
		cin>> gender;
		cout<<"\n��ֱ�����ס�ķ�����𣨷�����ABCDE������ͣ���������������ӡ�Ŀշ�������Ӧ�Ĵ�д��ĸ����������BUG����				"<<endl;
		cin>> grad;
		cout<<"\n��ֱ���뷿���        �������Ϊ�����ӡ�Ŀշ�������֣�:				    "<<endl;
		cin>> nu;

	 
		new_save_guest(name,id,gender,grad,nu,system_time_year(),system_time_month(),system_time_day(),system_time_hour(),system_time_mintue(),system_time_second() );//name,id,gender,grad,nu,year month,day,hour,minute,second
																		
		//д�¿�����ס�������Ϣ
		save_new_Room(grad,nu);
		
		//��ȡ�����·�����Ϣ���ַ������ַ���acc[]
		

		cout<<"�µĿ��˼�¼¼��ɹ���������£�"<<endl;
	
		load_guest();   //*******************************************************************//

		//�ҳ���ȡ���ַ���acc[]��ԭ�ļ������У�n��
		//ɾ��Room��¼�е�ָ���е�n��,�Է���ļ�¼ˢ��
		printf("\n");
		Sleep(1982);
	    //gets_str_new_Room(grad,nu,add);

		m = gets_str_new_Room___load_getline_old_Room(grad,nu);
		
		newly_delete_n_Room(m);
		save_new_Room(grad,nu);

		cout<<"��ˢ�µķ����¼�����£�"<<endl;
		load_Room();

		break;

	default:
		cout<<"��Ч����"<<endl;
		break;
	}
}	
	
	return 0;
}


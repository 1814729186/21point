#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void line(void)
{
	printf("******************************************************************************************\n");
}

int Deal(void)
{
	int d;
	srand(time(NULL));
    d = (rand()%(53 - 0));
	return d;
}
	
void stop(void)
{
	printf("**press enter**\n");
	getchar();
	getchar();
}

void dealerscore(int c)
{
	printf("ׯ��Dealer�ĵ����ϼ�Ϊ%d\n\n",c);
}

void gamerscore(int d)
{
 
	printf("���Gamer�ĵ����ϼ�Ϊ%d\n\n",d); 
}


void main()
{
	int n,j,flag = 0,t = 0,r;
    int total_1 = 0,total_2 = 0;
	char b;
    int _break1 = 1,  _break2 = 1, i = 0;
	struct Decks
	{
	char symbol[8];
	char num[4];
	int worth;
	}poker[52] = {
		{"heart","A",11},   {"heart","2",2},   {"heart","3",3},   {"heart","4",4},   {"heart","5",5},   {"heart","6",6},   {"heart", "7",7},   {"heart","8",8},   {"heart","9",9},   {"heart","10",10},   {"heart","J",10},   {"heart","Q",10},   {"heart","K",10},//������
		{"diamond","A",11}, {"diamond","2",2}, {"diamond","3",3}, {"diamond","4",4}, {"diamond","5",5}, {"diamond","6",6}, {"diamond","7",7},  {"diamond","8",8}, {"diamond","9",9}, {"diamond","10",10}, {"diamond","J",10}, {"diamond","Q",10}, {"diamond","K",10},//��Ƭ��
		{"clud","A",11},    {"club","2",2},    {"club","3",3},    {"club","4",4},    {"club","5",5},    {"club","6",6},    {"club","7",7},     {"club","8",8},    {"club","9",9},    {"club","10",10},    {"club","J",10},    {"club","Q",10},    {"club","K",10},//÷����
		{"spade","A",11},   {"spade","2",2},   {"spade","3",3},   {"spade","4",4},   {"spade","5",5},   {"spade","6",6},   {"spade","7",7},    {"spade","8",8},   {"spade","9",9},   {"spade","10",10},   {"spade","J",10},   {"spade","Q",10},   {"spade","K",10}//������
	};
    struct Decks *p_Dec1,*p_Dec2;


	printf("***��ӭ�������Żʼ����϶ĳ�***\n������21��ר��\n���enter��ʼ��Ŀ�d��������b����\n");
		getchar();
	printf("OK!��Ϸ��ʼ!\n");
	printf("��Ϸ˫��Ϊׯ��dealer�����player\nϴ�ƿ�ʼ\nע�ͣ�heart:����\ndiamond:����\nclub:÷��\nspade:����\n");
    

    
	
	printf("���enter��ʼ�ֱ𷢷�ׯ�Һ���ҵĵ�һ����\n");
	getchar();
	r = (rand()%(53 - 0));
	p_Dec1 = &poker[r];
	printf("ׯ�ҵĵ�һ����Ϊ%s,%s\n",(*p_Dec1).symbol,(*p_Dec1).num);
	total_1 += (*p_Dec1).worth;
	dealerscore(total_1);
    r = (rand()%(53 - 0));
	p_Dec2 = &poker[r];
    printf("��ҵĵ�һ����Ϊ%s,%s\n",(*p_Dec2).symbol,(*p_Dec2).num);
	total_2 += (*p_Dec2).worth;
    gamerscore(total_2);
    line();
    getchar();

	
	while(_break1==1 || _break2==1)
	{
		if (_break1 == 1)
		{
			printf("--ׯ�һغ�--\n������Ƿ����Ҫ��?\n(����1����Ҫ�ƣ������������ַ���Ҫ��)\n");
				scanf("%d",&_break1);
				if (_break1 == 1)
                {
					r = Deal();
					p_Dec1 = &poker[r];
					printf("ׯ�ҵ���һ����Ϊ%s,%s\n",(*p_Dec1).symbol,(*p_Dec1).num);
					total_1 +=(*p_Dec1).worth;
                    dealerscore(total_1);
					if(total_1 > 21)
					{
						printf("push!!!\nׯ������˱�������һ�ʤ!\n");
					    _break1 = 0,_break2 = 0;
					    continue;
					}

				}
				else printf("�ѷ���Ҫ��\n");
		}
		else printf("ׯ���ѷ���Ҫ��\n");
		stop();
		
		if(_break2 == 1)
		{
			printf("--��һغ�--\n������Ƿ����Ҫ��?\n(����1����Ҫ�ƣ������������ַ���Ҫ��)\n");
				scanf("%d",&_break2);
				if (_break2 == 1)
                {
                    r = Deal();
					p_Dec2 = &poker[r];
					printf("��ҵ���һ����Ϊ%s,%s\n",(*p_Dec2).symbol,(*p_Dec2).num);
					total_2 +=(*p_Dec2).worth;
                    gamerscore(total_2);
					if(total_2 > 21)
					{
						printf("push!!!\n�������˱�����ׯ�һ�ʤ!\n");
					    _break1 = 0,_break2 = 0;
					continue;	
					}

				}
				else printf("�ѷ���Ҫ��\n");
		}
		else printf("����ѷ���Ҫ��\n");
		line();
	}
	stop();
	
     if(total_1<=21 && total_2<=21)
	 {
		 dealerscore(total_1);
		 gamerscore(total_2);
		 if (total_1 > total_2)
			 printf("ׯ�ҵ���������ң�ׯ�һ�ʤ!\n");
		 if (total_1 < total_2)
			 printf("��ҵ�������ׯ�ң���һ�ʤ!\n");
		 if (total_1 == total_2)
			 printf("ׯ������ҵ�����ͬ��ƽ�֡�\n");
	 }


}

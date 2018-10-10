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
	printf("庄家Dealer的点数合计为%d\n\n",c);
}

void gamerscore(int d)
{
 
	printf("玩家Gamer的点数合计为%d\n\n",d); 
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
		{"heart","A",11},   {"heart","2",2},   {"heart","3",3},   {"heart","4",4},   {"heart","5",5},   {"heart","6",6},   {"heart", "7",7},   {"heart","8",8},   {"heart","9",9},   {"heart","10",10},   {"heart","J",10},   {"heart","Q",10},   {"heart","K",10},//红心牌
		{"diamond","A",11}, {"diamond","2",2}, {"diamond","3",3}, {"diamond","4",4}, {"diamond","5",5}, {"diamond","6",6}, {"diamond","7",7},  {"diamond","8",8}, {"diamond","9",9}, {"diamond","10",10}, {"diamond","J",10}, {"diamond","Q",10}, {"diamond","K",10},//方片牌
		{"clud","A",11},    {"club","2",2},    {"club","3",3},    {"club","4",4},    {"club","5",5},    {"club","6",6},    {"club","7",7},     {"club","8",8},    {"club","9",9},    {"club","10",10},    {"club","J",10},    {"club","Q",10},    {"club","K",10},//梅花牌
		{"spade","A",11},   {"spade","2",2},   {"spade","3",3},   {"spade","4",4},   {"spade","5",5},   {"spade","6",6},   {"spade","7",7},    {"spade","8",8},   {"spade","9",9},   {"spade","10",10},   {"spade","J",10},   {"spade","Q",10},   {"spade","K",10}//黑桃牌
	};
    struct Decks *p_Dec1,*p_Dec2;


	printf("***欢迎来到澳门皇家线上赌场***\n这里是21点专区\n点击enter开始你的狂（dǔ）欢（bó）\n");
		getchar();
	printf("OK!游戏开始!\n");
	printf("游戏双方为庄家dealer及玩家player\n洗牌开始\n注释：heart:红心\ndiamond:方块\nclub:梅花\nspade:黑桃\n");
    

    
	
	printf("点击enter开始分别发放庄家和玩家的第一张牌\n");
	getchar();
	r = (rand()%(53 - 0));
	p_Dec1 = &poker[r];
	printf("庄家的第一张牌为%s,%s\n",(*p_Dec1).symbol,(*p_Dec1).num);
	total_1 += (*p_Dec1).worth;
	dealerscore(total_1);
    r = (rand()%(53 - 0));
	p_Dec2 = &poker[r];
    printf("玩家的第一张牌为%s,%s\n",(*p_Dec2).symbol,(*p_Dec2).num);
	total_2 += (*p_Dec2).worth;
    gamerscore(total_2);
    line();
    getchar();

	
	while(_break1==1 || _break2==1)
	{
		if (_break1 == 1)
		{
			printf("--庄家回合--\n请决定是否继续要牌?\n(输入1继续要牌，输入其他数字放弃要牌)\n");
				scanf("%d",&_break1);
				if (_break1 == 1)
                {
					r = Deal();
					p_Dec1 = &poker[r];
					printf("庄家的下一张牌为%s,%s\n",(*p_Dec1).symbol,(*p_Dec1).num);
					total_1 +=(*p_Dec1).worth;
                    dealerscore(total_1);
					if(total_1 > 21)
					{
						printf("push!!!\n庄家输掉了比赛，玩家获胜!\n");
					    _break1 = 0,_break2 = 0;
					    continue;
					}

				}
				else printf("已放弃要牌\n");
		}
		else printf("庄家已放弃要牌\n");
		stop();
		
		if(_break2 == 1)
		{
			printf("--玩家回合--\n请决定是否继续要牌?\n(输入1继续要牌，输入其他数字放弃要牌)\n");
				scanf("%d",&_break2);
				if (_break2 == 1)
                {
                    r = Deal();
					p_Dec2 = &poker[r];
					printf("玩家的下一张牌为%s,%s\n",(*p_Dec2).symbol,(*p_Dec2).num);
					total_2 +=(*p_Dec2).worth;
                    gamerscore(total_2);
					if(total_2 > 21)
					{
						printf("push!!!\n玩家输掉了比赛，庄家获胜!\n");
					    _break1 = 0,_break2 = 0;
					continue;	
					}

				}
				else printf("已放弃要牌\n");
		}
		else printf("玩家已放弃要牌\n");
		line();
	}
	stop();
	
     if(total_1<=21 && total_2<=21)
	 {
		 dealerscore(total_1);
		 gamerscore(total_2);
		 if (total_1 > total_2)
			 printf("庄家点数高于玩家，庄家获胜!\n");
		 if (total_1 < total_2)
			 printf("玩家点数高于庄家，玩家获胜!\n");
		 if (total_1 == total_2)
			 printf("庄家与玩家点数相同，平局。\n");
	 }


}

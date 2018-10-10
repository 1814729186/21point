 #include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void penter(void)
{
	printf("***press enter***\n");
	getchar();
}

void line(void)
{
	printf("**************************************************\n");
}

void sline(void) 
{
	printf("*********\n");
}

void dealer(int s)
{
	printf("庄家的得分为%d\n",s);
}
void gamer(int s)
{
	printf("玩家的得分为%d\n",s);
}


void main()
{
	
	int score_1=0,score_2=0;
	int b1,b2;
	int e;
	int d1=0,d2=0;
	
	
	
	
	srand(time(NULL)); 
	int RandNum, a[52] = {0};
	int i,  flag = 0, t=0;
	
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
    struct Decks *p_1,*p_2;
    
    printf("****欢迎来到澳门皇家线上赌场****\n这里是21点专场\n");
    penter();
    printf("请开始你的狂欢！！！\n");
    penter();
    printf("下面开始洗牌\n");
	 penter();
    
	 while(1)
	{
	    flag = 0;
		if(t == 52)
				break;
				
				RandNum = (rand()%(53 - 0));
				for(i = 0; i < t; i++)
				{
					if(a[i] == RandNum)
							flag = 1;		}	
				if(flag != 1)
				{			
				        a[t] = RandNum;		
				        
						t++;	
				}	
	    }
	    
	    printf("游戏开始！！！\n点击enter开始发庄家和玩家的第一张牌\n");
	    getchar();
	    p_1 = &poker[a[0]];
	    p_2 = &poker[a[1]];
	    score_1 += p_1->worth;
	    score_2 += p_2->worth;
	    printf("庄家的第一张牌为%s,%s\n",p_1->symbol,p_1->num);
	    dealer(score_1);
	    printf("玩家的第一张牌为%s,%s\n",p_2->symbol,p_2->num);
	    gamer(score_2);
	    line();
	    getchar();
	    
	    e = 2;
		b1=1,b2=1;
	    while(b1 == 1 ||b2 == 1)
	    {
	    	if (b1 == 1)
	    	{			
	        printf(">庄家回合<\n");
	        printf("请决定是否继续要牌？\n(输入数字1继续要牌，输入其他数字放弃要牌)\n");
	        scanf("%d",&b1); 
	        if(b1 == 1)
	        {
	        	p_1 = &poker[a[e]];
	      
	        	printf("庄家的下一张牌是%s,%s\n",p_1->symbol,p_1->num);
	        	score_1 += p_1->worth;
	        	e++;
	        	dealer(score_1);
	        	if(score_1 > 21)
	        	{
	        		printf("庄家的得分总计为%d\npush!!!\n庄家输掉了比赛，玩家获胜!\n",score_1);
	        		b1 = 0,b2 = 0;
	        		continue;
				}
			}else printf("已放弃要牌\n");
        	}else printf("庄家已放弃要牌\n");
        	sline();
        	
        	if(b2 == 1)
        	{
        		printf(">玩家回合<\n");
        		printf("请决定是否继续要牌？\n(输入数字1继续要牌，输入其他数字放弃要牌)\n");
        		scanf("%d",&b2);
        		if(b2 == 1)
        		{
        			p_2 = &poker[a[e]];
        			printf("玩家的下一张牌是%s,%s\n",p_2->symbol,p_2->num);
					score_2 += p_2->worth;
					e++;
					gamer(score_2);
					if(score_2>21) 
					{
	        		printf("玩家的得分总计为%d\npush!!!\n玩家输掉了比赛，庄家获胜!\n",score_2);
	        		b1 = 0; b2 = 0; 
	        		continue;
				}
				}else printf("已放弃要牌\n");
			}else printf("玩家家已放弃要牌\n");
			line();
			penter();
			getchar();
       	}
       	if(score_1<=21 && score_2<=21)
       	{
       		printf("庄家的得分是%d\n玩家的得分是%d\n",score_1,score_2);
       		 if (score_1 > score_2)
			 printf("庄家点数高于玩家，庄家获胜!\n");
		 if (score_1 < score_2)
			 printf("玩家点数高于庄家，玩家获胜!\n");
		 if (score_1 == score_2)
			 printf("庄家与玩家点数相同，平局。\n");
		   }    
}



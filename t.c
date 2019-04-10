#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<termios.h>
#define Red printf("%c[1;31m", 27);
#define Def printf("%c[0m", 27);
#define Blue printf("%c[1;34m", 27);
#define GREEN printf("%c[1;32m", 27);
#define YELLOW printf("%c[1;33m", 27);
#define PURPLE printf("%c[1;35m", 27);

void line(void);						//메인 함수
int UI(char arr[][10],int x,int y);
int getch(void);
void Print(int g_gamble);					//홀짝도박 함수
int  Gambling(int *gold);
void EvenAndOdd(int *End,int bet,int *gold,int c_count);
void store(int *gold, int item[], int *hp, int *def, int atk[2]);// 상점 함수

//전투 공용 함수
void player_itf(int mode, int Potion_chk);
void gotoxy(int x,int y);
void delay_ms(int num);
//전투 잡몹 함수
void Print_LG_Battle_status(int *hp, int *gold, int *atk, int *def, char Mname[][100], int *Matk, int *MHp, int *Turn, int *M_pick, int Potion_chk);
void Battle_LG_Player_Attack(int *hp, int *gold, int *atk, int *def, char Mname[][100], int Matk[], int MHp[], int *Turn, int *M_pick, int *Potion_chk);
void Print_Battle_Itemlist(int *item);
void soldier1_itf(int mode);
void soldier2_itf(int mode);
void soldier3_itf(int mode);
void soldier4_itf(int mode);
int Battle_LG_Monster_Attack(int *hp, int *gold, int *atk, int *def, char Mname[][100], int Matk[], int MHp[], int *Turn, int *M_pick, int *Def_chk, int Potion_chk);
int Battle_Low_Grade (int *hp, int *gold, int atk[], int *def, int item[], int *stage);
int Battle_LG_Input();
int Battle_LG_Itemuse(int *Hp, int *item, int *Potion_chk, int *stage);
//전투 중간보스, 최종보스 함수
void Print_HG_Battle_status(int *hp, int *gold, int *Atk, int *def, char Mname[][100], int *MAtk, int *MHp, int *Turn, int *M_pick,int *stage, int Potion_chk);
void Battle_HG_Player_Attack(int *hp, int *gold, int *Atk, int *def, char Mname[][100], int MAtk[], int MHp[], int *Turn, int *M_pick, int *Potion_chk,int *stage);
void md_boss_itf(int mode,int *stage);
void boss_itf(int mode);
int Battle_High_Grade(int *hp,int *gold,int Atk[],int *def,int item[],int *stage,int monster);
int Battle_HG_Monster_Attack(int *hp, int *gold, int *Atk, int *def, char Mname[][100], int MAtk[], int MHp[], int *Turn, int *M_pick, int *Def_chk, int Potion_chk);
int Battle_HG_Itemuse(int *Hp, int *item, int *Potion_chk, int *stage,int monster);

int sm_main(int *gold, int *hp, int item[7]);				// 슬롯머신 함수
void sm_effect(int *hp, int *gold);
void sm_enter(void);
void sm_intro();

int main(void)
{
	int a,b,c;					// 미니맵 구현을위한 for문 변수
	char location[10][10];				// 미니맵에 존재하는 *,ㅁ,O변수
	char location2[10][10];				// 미니맵에 존재하는 *,ㅁ,O변수
	int hp=1000, def=50, gold=1000;		// 진혁의 기본 정보 변수
	int atk[2]={100,300};				// 진혁의 기본 정보 변수
	int choice;					// 진혁 선택지 변수
	int num1,num2;					// 좌표를 나타낼 변수
	char res;
	int random[10][10];				// 이벤트좌표1 변수
	int random2f[10][10];				// 이벤트좌표2 변수
	int random1,random2,random3;
	int count=1,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
	int a1,a2,b2;					// 키보드 위치 인식 변수
	int stage=1;					// 1층 시작
	int sniffling=0; 				//게임 끝
	int item[7]={5,0,0,0,0,0,1};				//아이템 변수
	int bettle_end;					// 배틀 종료 변수
	int end;					// 이벤트 종료 변수
	
	a= sizeof(location[0])/sizeof(int);
	b= sizeof(location)/sizeof(location[0]);
	a2= sizeof(location2[0])/sizeof(int);
	b2= sizeof(location2)/sizeof(location2[0]);

	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			location[a][b]=' ';
		}
	}

	
	for(a=0;a<1;a++)
	{
		random1=rand()%10;
		random2=rand()%10;
		random[random1][random2]=1;

		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1)
		{
			continue;
		}
		random[random1][random2]=2;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1||random[random1][random2]==2)
		{
			continue;
		}
		random[random1][random2]=3;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1||random[random1][random2]==2||random[random1][random2]==3)
		{
			continue;
		}
		random[random1][random2]=4;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1||random[random1][random2]==2||random[random1][random2]==3||random[random1][random2]==4)
		{
			continue;
		}
		random[random1][random2]=5;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1||random[random1][random2]==2||random[random1][random2]==3||random[random1][random2]==4||random[random1][random2]==5)
		{
			continue;
		}
		random[random1][random2]=6;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1||random[random1][random2]==2||random[random1][random2]==3||random[random1][random2]==4||random[random1][random2]==5||random[random1][random2]==6)
		{
			continue;
		}
		random[random1][random2]=7;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1||random[random1][random2]==2||random[random1][random2]==3||random[random1][random2]==4||random[random1][random2]==5||random[random1][random2]==6||random[random1][random2]==7)
		{
			continue;
		}
		random[random1][random2]=8;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random[random1][random2]==1||random[random1][random2]==2||random[random1][random2]==3||random[random1][random2]==4||random[random1][random2]==5||random[random1][random2]==6||random[random1][random2]==7||random[random1][random2]==8)
		{
			continue;
		}
		random[random1][random2]=9;
	}
	
	for(a=0;a<1;a++)
	{
		random1=rand()%10;
		random2=rand()%10;
		random2f[random1][random2]=1;

		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1)
		{
			continue;
		}
		random2f[random1][random2]=2;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1||random2f[random1][random2]==2)
		{
			continue;
		}
		random2f[random1][random2]=3;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1||random2f[random1][random2]==2||random2f[random1][random2]==3)
		{
			continue;
		}
		random2f[random1][random2]=4;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1||random2f[random1][random2]==2||random2f[random1][random2]==3||random2f[random1][random2]==4)
		{
			continue;
		}
		random2f[random1][random2]=5;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1||random2f[random1][random2]==2||random2f[random1][random2]==3||random2f[random1][random2]==4||random2f[random1][random2]==5)
		{
			continue;
		}
		random2f[random1][random2]=6;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1||random2f[random1][random2]==2||random2f[random1][random2]==3||random2f[random1][random2]==4||random2f[random1][random2]==5||random2f[random1][random2]==6)
		{
			continue;
		}
		random2f[random1][random2]=7;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1||random2f[random1][random2]==2||random2f[random1][random2]==3||random2f[random1][random2]==4||random2f[random1][random2]==5||random2f[random1][random2]==6||random2f[random1][random2]==7)
		{
			continue;
		}
		random2f[random1][random2]=8;
	
		random1=rand()%10;
		random2=rand()%10;
		if(random2f[random1][random2]==1||random2f[random1][random2]==2||random2f[random1][random2]==3||random2f[random1][random2]==4||random2f[random1][random2]==5||random2f[random1][random2]==6||random2f[random1][random2]==7||random2f[random1][random2]==8)
		{
			continue;
		}
		random2f[random1][random2]=9;
	}
	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			location2[a][b]=' ';
		}
	}
	random[random1][random2]=9;
	
	srand(time(NULL));
	num1=rand()%10;
	num2=rand()%10;
	location[num1][num2]='O';
	
	while(1)
	{
		if(stage==1)
		{
			srand(time(NULL));
			usleep(1000);
			system("clear");
			UI(location,a,b);
		
			line();
			printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]); 		// 인터페이스 구현
			printf("\t\t1층 - Fire field\n\n");
			line();
	
			printf("\t진혁는 미탐색 지역을 탐색한다.\n\t(위 - ↑, 왼쪽 - ←, 오른쪽 - →, 아래쪽 - ↓)\n");
			
			
			while(1)
			{
				
				a1=getch();
				if(a1=='A')
				{
					location[num1][num2]='#';
					num1-=1;
					if(num1<0)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num1=0;
						line();
						sleep(1);
					}
					location[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location,a,b);

					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]);
					line();
	
					if(random[num1][num2]==9||random[num1][num2]==1||random[num1][num2]==2||random[num1][num2]==3||random[num1][num2]==4||random[num1][num2]==5||random[num1][num2]==6||random[num1][num2]==7||random[num1][num2]==8 && location[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random[num1][num2]==1 && location[num1][num2]=='O')
							{
								/*bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 2층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								break;
							}
							else if(random[num1][num2]==2 && location[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random[num1][num2]==3 && location[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random[num1][num2]==4 && location[num1][num2]=='O')
							{
								/*bettle_end=Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);\
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random[num1][num2]==5 && location[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random[num1][num2]==6 && location[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random[num1][num2]==7 && location[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random[num1][num2]==8 && location[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random[num1][num2]==9 && location[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
				else if(a1=='D')
				{
					location[num1][num2]='#';
					num2-=1;
					if(num2<0)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num2=0;
						line();
						sleep(1);
					}
					location[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location,a,b);

					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]);
					line();
			
					if(random[num1][num2]==9||random[num1][num2]==1||random[num1][num2]==2||random[num1][num2]==3||random[num1][num2]==4||random[num1][num2]==5||random[num1][num2]==6||random[num1][num2]==7||random[num1][num2]==8 && location[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random[num1][num2]==1 && location[num1][num2]=='O')
							{
								/*bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 1층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								
								break;
							}
							else if(random[num1][num2]==2 && location[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random[num1][num2]==3 && location[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random[num1][num2]==4 && location[num1][num2]=='O')
							{
								/*Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random[num1][num2]==5 && location[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random[num1][num2]==6 && location[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random[num1][num2]==7 && location[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random[num1][num2]==8 && location[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random[num1][num2]==9 && location[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
				else if(a1=='C')
				{
					location[num1][num2]='#';
					num2+=1;
					if(num2>9)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num2=9;
						line();
						sleep(1);
					}
					location[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location,a,b);

					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]);
					line();
			
					if(random[num1][num2]==9||random[num1][num2]==1||random[num1][num2]==2||random[num1][num2]==3||random[num1][num2]==4||random[num1][num2]==5||random[num1][num2]==6||random[num1][num2]==7||random[num1][num2]==8 && location[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random[num1][num2]==1 && location[num1][num2]=='O')
							{
								/*bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 2층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								break;
							}
							else if(random[num1][num2]==2 && location[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random[num1][num2]==3 && location[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random[num1][num2]==4 && location[num1][num2]=='O')
							{
								/*Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random[num1][num2]==5 && location[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random[num1][num2]==6 && location[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random[num1][num2]==7 && location[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random[num1][num2]==8 && location[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random[num1][num2]==9 && location[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
				else if(a1=='B')
				{
					location[num1][num2]='#';
					num1+=1;
					if(num1>9)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num1=9;
						line();
						sleep(1);
					}
					location[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location,a,b);

					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]);
					line();
			
					if(random[num1][num2]==9||random[num1][num2]==1||random[num1][num2]==2||random[num1][num2]==3||random[num1][num2]==4||random[num1][num2]==5||random[num1][num2]==6||random[num1][num2]==7||random[num1][num2]==8 && location[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random[num1][num2]==1 && location[num1][num2]=='O')
							{
								/*bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 2층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								break;
							}
							else if(random[num1][num2]==2 && location[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random[num1][num2]==3 && location[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random[num1][num2]==4 && location[num1][num2]=='O')
							{
								/*Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random[num1][num2]==5 && location[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random[num1][num2]==6 && location[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random[num1][num2]==7 && location[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random[num1][num2]==8 && location[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random[num1][num2]==9 && location[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
			}
			
			
			
			
		}
		
		if(stage==2)
		{
			srand(time(NULL));
			usleep(1000);
			system("clear");
			UI(location2,a,b);
		
			line();
			printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]); 		// 인터페이스 구현
			printf("\t\t2층 - Fire field\n\n");
			line();
	
			printf("\t진혁는 미탐색 지역을 탐색한다.\n\t(위 - ↑, 왼쪽 - ←, 오른쪽 - →, 아래쪽 - ↓)\n");
			while(1)
			{
				a1=getch();
				if(a1=='A')
				{
					location2[num1][num2]='#';
					num1-=1;
					if(num1<0)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num1=0;
						line();
						sleep(1);
					}
					location2[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location2,a,b);
	
					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]); 		// 인터페이스 구현
					line();
			
					if(random2f[num1][num2]==9||random2f[num1][num2]==1||random2f[num1][num2]==2||random2f[num1][num2]==3||random2f[num1][num2]==4||random2f[num1][num2]==5||random2f[num1][num2]==6||random2f[num1][num2]==7||random2f[num1][num2]==8 && location2[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random2f[num1][num2]==1 && location2[num1][num2]=='O')
							{
								/*bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 2);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 2층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n3. 최종 보스 에게로 이동.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
									else if(choice==3)
									{
										bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
										if(bettle_end==1)
										{
											line();
											printf("진혁이는 마왕킹복이를 쓰러뜨려서 2019iot반의 평화를 가져왔습니다.\n\n---happy ending---");
											line();
											sleep(1);
											return 0;
										}
										else if(bettle_end==0)
										{
											printf("마왕에게 진 진혁이는 마왕의 넓은 마음으로 살아서 나오지만 입구에 있는 마왕의 자동차를 타고 집으로 돌아가 버려서 마왕은 집에 가지못하게 되었습니다.\n\n");
											
											return 0;
										}
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==2 && location2[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==3 && location2[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random2f[num1][num2]==4 && location2[num1][num2]=='O')
							{
								/*Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random2f[num1][num2]==5 && location2[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random2f[num1][num2]==6 && location2[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random2f[num1][num2]==7 && location2[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random2f[num1][num2]==8 && location2[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random2f[num1][num2]==9 && location2[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
				else if(a1=='D')
				{
					location2[num1][num2]='#';
					num2-=1;
					if(num2<0)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num2=0;
						line();
						sleep(1);
					}
					location2[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location2,a,b);
	
					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]); 		// 인터페이스 구현
					line();
					if(random2f[num1][num2]==9||random2f[num1][num2]==1||random2f[num1][num2]==2||random2f[num1][num2]==3||random2f[num1][num2]==4||random2f[num1][num2]==5||random2f[num1][num2]==6||random2f[num1][num2]==7||random2f[num1][num2]==8 && location2[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random2f[num1][num2]==1 && location2[num1][num2]=='O')
							{
								/*bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 2);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 2층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n3. 최종 보스 에게로 이동.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
									else if(choice==3)
									{
										bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
										if(bettle_end==1)
										{
											line();
											printf("진혁이는 마왕킹복이를 쓰러뜨려서 2019iot반의 평화를 가져왔습니다.\n\n---happy ending---");
											line();
											sleep(1);
											return 0;
										}
										else if(bettle_end==0)
										{
											printf("마왕에게 진 진혁이는 마왕의 넓은 마음으로 살아서 나오지만 입구에 있는 마왕의 자동차를 타고 집으로 돌아가 버려서 마왕은 집에 가지못하게 되었습니다.\n\n");
											
											return 0;
										}
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==2 && location2[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==3 && location2[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random2f[num1][num2]==4 && location2[num1][num2]=='O')
							{
								/*Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random2f[num1][num2]==5 && location2[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random2f[num1][num2]==6 && location2[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random2f[num1][num2]==7 && location2[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random2f[num1][num2]==8 && location2[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random2f[num1][num2]==9 && location2[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
				else if(a1=='C')
				{
					location2[num1][num2]='#';
					num2+=1;
					if(num2>9)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num2=9;
						line();
						sleep(1);
					}
					location2[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location2,a,b);
	
					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]); 		// 인터페이스 구현
					line();
					if(random2f[num1][num2]==9||random2f[num1][num2]==1||random2f[num1][num2]==2||random2f[num1][num2]==3||random2f[num1][num2]==4||random2f[num1][num2]==5||random2f[num1][num2]==6||random2f[num1][num2]==7||random2f[num1][num2]==8 && location2[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random2f[num1][num2]==1 && location2[num1][num2]=='O')
							{
								/*ettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 2);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 2층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n3. 최종 보스 에게로 이동.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
									else if(choice==3)
									{
										bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
										if(bettle_end==1)
										{
											line();
											printf("진혁이는 마왕킹복이를 쓰러뜨려서 2019iot반의 평화를 가져왔습니다.\n\n---happy ending---");
											line();
											sleep(1);
											return 0;
										}
										else if(bettle_end==0)
										{
											printf("마왕에게 진 진혁이는 마왕의 넓은 마음으로 살아서 나오지만 입구에 있는 마왕의 자동차를 타고 집으로 돌아가 버려서 마왕은 집에 가지못하게 되었습니다.\n\n");
											
											return 0;
										}
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==2 && location2[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==3 && location2[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random2f[num1][num2]==4 && location2[num1][num2]=='O')
							{
								/*Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random2f[num1][num2]==5 && location2[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random2f[num1][num2]==6 && location2[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random2f[num1][num2]==7 && location2[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random2f[num1][num2]==8 && location2[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random2f[num1][num2]==9 && location2[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
				else if(a1=='B')
				{
					location2[num1][num2]='#';
					num1+=1;
					if(num1>9)
					{
						usleep(10000);
						line();
						printf("더이상 갈 수 없는 장소 입니다.\n\n");
						num1=9;
						line();
						sleep(1);
					}
					location2[num1][num2]='O';
					usleep(1000);
					system("clear");
					UI(location2,a,b);
	
					line();
					printf("    hp = %5d\t   최소공격력 = %5d\t  최대공격력 = %5d\t방어력 = %5d\t 골드 = %d\n    힐링 포션 = %d개\t화속성 포션 = %d개   \t수속성 포션 = %d개\t빛속성 포션 = %d개\n    탈출권 = %d개\n\n",hp,atk[0],atk[1],def,gold,item[0],item[1],item[2],item[3],item[6]); 		// 인터페이스 구현
					line();
					if(random2f[num1][num2]==9||random2f[num1][num2]==1||random2f[num1][num2]==2||random2f[num1][num2]==3||random2f[num1][num2]==4||random2f[num1][num2]==5||random2f[num1][num2]==6||random2f[num1][num2]==7||random2f[num1][num2]==8 && location2[num1][num2]=='O')
					{
						usleep(30000);
						system("clear");
						printf("이벤트 발생!\n");
						while(1)
						{
							if(random2f[num1][num2]==1 && location2[num1][num2]=='O')
							{
								/*bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 2);
								if(bettle_end==1)
								{
									line();
									printf("진혁이는 몬스터를 성공적으로 잡았습니다!\n\n");
									line();
									sleep(1);
									printf("포탈 발견!\n\n1. 2층으로 이동한다.\n2. 싫어 가지 않을꺼야.\n3. 최종 보스 에게로 이동.\n>>");
									scanf("%d", &choice);
									if(choice==1)
									{
										stage=2;
										break;
									}
									else if(choice==2)
									{
										printf("진혁이는 시공의 폭풍 속으로 빨려들어가서 사망하였습니다.\n\n");
										return 0;
									}
									else if(choice==3)
									{
										bettle_end=Battle_High_Grade(&hp, &gold, atk, &def, item, &stage, 1);
										if(bettle_end==1)
										{
											line();
											printf("진혁이는 마왕킹복이를 쓰러뜨려서 2019iot반의 평화를 가져왔습니다.\n\n---happy ending---");
											line();
											sleep(1);
											return 0;
										}
										else if(bettle_end==0)
										{
											printf("마왕에게 진 진혁이는 마왕의 넓은 마음으로 살아서 나오지만 입구에 있는 마왕의 자동차를 타고 집으로 돌아가 버려서 마왕은 집에 가지못하게 되었습니다.\n\n");
											
											return 0;
										}
									}
								}
								else if(bettle_end==0)
								{
									line();
									printf("진혁이는 몬스터에게 격렬하게 저항하였으나 먹혔습니다.\n\n");
									line();
									sleep(1);
									
									return 0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==2 && location2[num1][num2]=='O' && count2==0)
							{
								/*sniffling=Gambling(&gold);//gameover 에 end return 받아옴,gold포인터로 받음
								count2=1;
								if(gold<0)
								{
									gold=0;
								}*/
								break;
							}
							else if(random2f[num1][num2]==3 && location2[num1][num2]=='O')
							{
								/*store(&gold, item, &hp, &def, atk); // choice*/
								break;
							}
							else if(random2f[num1][num2]==4 && location2[num1][num2]=='O')
							{
								/*Battle_Low_Grade(&hp, &gold, atk, &def, item, &stage);
								if(hp<=0)
								{
									sleep(1);
									line();
									printf("진혁는 힘겨운 시련을 견디지 못하고 사망하였습니다\n\t---THE END---");
									line();
									sleep(1);
								}*/
								break;
							}
							else if(random2f[num1][num2]==5 && location2[num1][num2]=='O')
							{
								/*end=sm_main(&gold, &hp, item);*/
								break;
							}
							else if(random2f[num1][num2]==6 && location2[num1][num2]=='O')
							{
								printf("c");
								break;
							}
							else if(random2f[num1][num2]==7 && location2[num1][num2]=='O')
							{
								printf("d");
								break;
							}
							else if(random2f[num1][num2]==8 && location2[num1][num2]=='O')
							{
								printf("e");
								break;
							}
							else if(random2f[num1][num2]==9 && location2[num1][num2]=='O')
							{
								printf("f");
								break;
							}
							else
							{
								printf("더이상 참여할 이벤트가 없습니다.\n");
								break;
							}
						}
					}
					break;
				}
			}
			
		}
	}
	return 0;
}

void line(void)							// 라인
{
	printf("===================================================================================================\n\n");
}

int UI(char arr[][10], int x, int y)				// 미니맵 구현
{	
	int a,b;
	
	printf("\t======================================================\n");
	for(a=0; a<10; a++)				
	{
		if(a==0||a==1||a==2||a==3||a==4||a==5||a==6||a==7||a==8||a==9)
		{
			printf("\t||");
		}
		for(b=0; b<10; b++)
		{
			printf("  %c  ", arr[a][b]);
			if(b==9)
			{
				break;
			}
		}
		if(a==0||a==1||a==2||a==3||a==4||a==5||a==6||a==7||a==8||a==9)
		{
			printf("||");
		}
		printf("\n");
		if(a==9)
		{
			break;
		}
	}
	printf("\t======================================================\n");
}

int getch(void)					// 키보드 이동키 함수
{
	int ch;
	struct termios buf;
	struct termios save;
	
	tcgetattr(0,&save);
	buf=save;
	buf.c_lflag&=~(ICANON|ECHO);
	buf.c_cc[VMIN]=1;
	buf.c_cc[VTIME]=0;
	tcsetattr(0,TCSAFLUSH,&buf);
	ch=getchar();
	tcsetattr(0,TCSAFLUSH,&save);
	
	return ch;
}

int  Gambling(int *gold) 	//홀짝 배팅금액 설정함수
{
	int slect;		//선택 변수
	int betting;		//배팅
	int end=0;
	int count=1;
	printf("현재 소지금은 %d 입니다. \n판돈을 걸어주세요\n",*gold);
	printf("배팅 금액 >>");
	scanf("%d",&betting);
	if(betting==0)		//0원 입력시 재입력
	{
		printf("판돈은 0원을 걸수 없습니다.\n디시 금액을 적어주세요.\n");
		printf("배팅 금액 >>");
		scanf("%d",&betting);
	}
	else if(betting>*gold)	//소지금 초과시 재입력
	{
		printf("판돈은 소지금을 넘을 수 없습니다.\n디시 금액을 적어주세요.\n");
		printf("배팅 금액 >>");
		scanf("%d",&betting);

	}

	while(1)
	{
		system("clear");
		printf("%d 라운드 배팅 금액 : %d\n",count,betting);
		EvenAndOdd(&end,betting,gold,count);//홀짝 선택,홀로그램 ,게임결과,골드변화,포인터 게임종료유무
		sleep(2);
		if(end==1)break;//게임 패 했을때 종료.
		count++;
		if(count==4)break;//3회 성공시 종료.
		printf("다음 라운드에 도전하시겠습니까?\n");
		printf("1.도전  2.중단\n   =>>");
		scanf("%d",&slect);
		if(slect==2)
		{
			end=1;
			break;
		}
	}
	
	return end;
}

void EvenAndOdd(int *End,int bet,int *gold,int c_count)
{
	int slect;
	int gamble;

	printf("홀짝을 선택 해주세요\n");
	printf("1.홀  2.짝\n");
	printf("당신의 선택은 ?>>"); 
	scanf("%d",&slect);
	for(int i=0;i<70;i++)		//빠르게 홀로그램 출력
	{
		system("clear");
		gamble=rand()%10+1;
		Print(gamble);
		usleep(50000);
	}
	for(int i=0;i<5;i++)		//조금느리게
	{
		system("clear");
		gamble=rand()%10+1;
		Print(gamble);
		usleep(300000);
	}
	for(int i=0;i<3;i++)		//느리게
	{
		system("clear");
		gamble=rand()%10+1;
		Print(gamble);
		usleep(500000);
	}
	for(int i=0;i<3;i++)		//많이 느리게
	{
		system("clear");
		gamble=rand()%10+1;
		Print(gamble);
		sleep(1);
	}
	for(int i=0;i<2;i++)		//홀로그램 끝
	{
		system("clear");
		gamble=rand()%10+1;
		Print(gamble);
		sleep(2);
	}
	gamble=rand()%10+1;		//홀짝 결정
	system("clear");
	printf("빠밤~~~\n");
	Print(gamble);			//홀로그램  출력
	if(gamble%2==0)			//짝수일때
	{
		if(slect==1)		//홀수 선택
		{
			printf("%d이 나왔습니다. 아쉽네요 짝입니다.\n",gamble);
			*End=1;	
		}
		else			//짝수선택
		{
			printf("%d이 나왔습니다.축하합니다 짝입니다.\n",gamble);
		}
	}
	else				//홀수일때
	{
		if(slect==1)		//홀수선택
		{
			printf("%d이 나왔습니다.축하합니다 홀입니다.\n",gamble);
		}
		else			//짝수선택
		{
			printf("%d이 나왔습니다.아쉽네요 홀입니다.\n",gamble);
			*End=1;
		}
	}
	if(c_count==1)			//1라운드 선택결과
	{
		if(*End==1)		//졌을때
		{
			*gold-=bet*3;
			printf("당신은 %d 골드를 잃었습니다.\n",bet*3);
		}
		else			//이겼을때
		{
			*gold+=bet*2;
			printf("당신은 %d 골드를 얻었습니다.\n",bet*2);
		}
	}
	if(c_count==2)			//2라운드 선택결과
	{
		if(*End==1)		//졌을때
		{
			*gold-=bet*2;
			*gold-=bet*10;
			printf("당신은 %d 골드를 잃었습니다.\n",bet*10);
		}
		else			//이겼을때
		{
			*gold+=bet*8;
			*gold-=bet*2;
			printf("당신은 %d 골드를 얻었습니다.\n",bet*8);
		}
	}
	if(c_count==3)			//3라운드 선택결과
	{
		if(*End==1)		//졌을때
		{
			*gold-=bet*8;
			*gold-=bet*20;
			printf("당신은 %d 골드를 잃었습니다.\n",bet*20);
		}
		else			//이겼을때
		{
			*gold+=bet*16;
			*gold-=bet*8;
			printf("당신은 %d 골드를 얻었습니다.\n",bet*16);
		}
	}

}

void Print(int g_gamble)		//홀로그램 출력
{
	switch(g_gamble)
	{
		case 1:
			printf("\t┌────────┐\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t└────────┘\n");
			break;
		case 2:
			printf("\t┌────────┐\n");
			printf("\t│   OOOO │\n");
			printf("\t│      O │\n");
			printf("\t│   OOOO │\n");
			printf("\t│   O    │\n");
			printf("\t│   OOOO │\n");
			printf("\t└────────┘\n");
			break;
		case 3:
			printf("\t┌────────┐\n");
			printf("\t│   OOOO │\n");
			printf("\t│      O │\n");
			printf("\t│   OOOO │\n");
			printf("\t│      O │\n");
			printf("\t│   OOOO │\n");
			printf("\t└────────┘\n");
			break;
		case 4:
			printf("\t┌────────┐\n");
			printf("\t│   O O  │\n");
			printf("\t│   O O  │\n");
			printf("\t│   OOOO │\n");
			printf("\t│     O  │\n");
			printf("\t│     O  │\n");
			printf("\t└────────┘\n");
			break;
		case 5:
			printf("\t┌────────┐\n");
			printf("\t│   OOOO │\n");
			printf("\t│   O    │\n");
			printf("\t│   OOOO │\n");
			printf("\t│      O │\n");
			printf("\t│   OOOO │\n");
			printf("\t└────────┘\n");
			break;
		case 6:
			printf("\t┌────────┐\n");
			printf("\t│   O    │\n");
			printf("\t│   O    │\n");
			printf("\t│   OOOO │\n");
			printf("\t│   O  O │\n");
			printf("\t│   OOOO │\n");
			printf("\t└────────┘\n");
			break;
		case 7:
			printf("\t┌────────┐\n");
			printf("\t│   OOOO │\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t└────────┘\n");
			break;
		case 8:
			printf("\t┌────────┐\n");
			printf("\t│   OOOO │\n");
			printf("\t│   O  O │\n");
			printf("\t│   OOOO │\n");
			printf("\t│   O  O │\n");
			printf("\t│   OOOO │\n");
			printf("\t└────────┘\n");
			break;
		case 9:
			printf("\t┌────────┐\n");
			printf("\t│   OOOO │\n");
			printf("\t│   O  O │\n");
			printf("\t│   OOOO │\n");
			printf("\t│      O │\n");
			printf("\t│      O │\n");
			printf("\t└────────┘\n");
			break;
		case 10:
			printf("\t┌────────┐\n");
			printf("\t│ O OOOO │\n");
			printf("\t│ O O  O │\n");
			printf("\t│ O O  O │\n");
			printf("\t│ O O  O │\n");
			printf("\t│ O OOOO │\n");
			printf("\t└────────┘\n");
			break;
	}
}

void store(int *gold, int item[], int *hp, int *def, int atk[2])		// 상점 함수
{
        int choice;
        int escape=rand()%100+1;
        for(int a=0;a<2;)
        {
        system("clear");
        line();
        printf("\t필요한게 있으면 골라보게나!\n힐링포션을 제외한 모든 품목은 하나씩밖에 가질수 없다네~\n");
        printf("\t  현재 소지 골드 : %dG\n",*gold);
        line();
        printf("0. 나가기\n1. 힐링 포션 500G \n2. 화속성 포션 1000G [1회 구매 가능]\n3. 수속성 포션 1000G [1회 구매 가능]\n4. 빛속성 포션 50,000G [최종보스전용][1회 구매 가능]\n5. 흑염룡의 눈물 2,000G [All 스텟 ++][1회 구매 가능]\n6. Event Item!! 포션 세트 2000G [힐링, 화속성, 수속성 포션 세트][1회 구매 가능]\n");
        if(escape>=70)                                  // 함정스테이지 확률 등장
        {
        printf("7. 함정 스테이지 탈출권 50,000G [최대 5개까지 구입 가능]\n");
        }
        if(*gold<=0)
        {
        	line();
        	printf("더이상 돈이 남아있지 않습니다. 필드로 돌아갑니다.\n");
        	line();
        	sleep(1);
        	break;
        }
        scanf("%d",&choice);
        switch(choice)
        {
        	case 0:
        	a+=3;
        	break;
                case 1:                                 // 힐링 포션
                if(*gold>=100)                          // 골드 -값 방지용
                {
                        printf("힐링 포션을 구매합니다.\n");
                        *gold-=500;
                        item[0]+=1;
                        break;
                }
                else
                {
                        printf("돈이 없어 사지 못합니다.\n");
                        break;
                }
                break;
                case 2:                                 // 화속성 포션
                if(*gold>=500)                          // 골드 -값 방지용
                {
                        if(item[1]==0)
                        {
                                printf("화속성 포션을 구매합니다.\n");
                                *gold-=1000;
                                item[1]+=1;
                                break;
                        }
                        else                            // 소지하지 않았을 경우
                        {
                                line();
                                printf("\t이미 소지하고 있는 아이템입니다.\n");
                                break;
                        }
                        break;
                }
                else
                {
                        printf("돈이 없어 사지 못합니다.\n");
                        break;
                }
                break;
                case 3:                                 // 수속성 포션
                if(*gold>=500)                         // 골드 -값 방지용
                {
                        if(item[2]==0)
                        {
                                printf("수속성 포션을 구매합니다.\n");
                                *gold-=1000;
                                item[2]+=1;
                                break;
                        }
                        else                            // 소지하지 않았을 경우
                        {
                                line();
                                printf("\t이미 소지하고 있는 아이템입니다.\n");
                                break;
                        }
                        break;
                }
                else
                {
                        printf("돈이 없어 사지 못합니다.\n");
                        break;
                }
                case 4:                                 // 빛속성 포션
                if(*gold>=10000)                         // 골드 -값 방지용
                {
                        if(item[3]==0)
                        {
                                printf("빛속성 포션을 구매합니다.\n");
                                *gold-=50000;
                                item[3]+=1;
                                break;
                        }
                        else                            // 소지하지 않았을 경우
                        {
                                line();
                                printf("\t이미 소지하고 있는 아이템입니다.\n");
                                break;
                        }
                        break;
                }
                else
                {
                        printf("돈이 없어 사지 못합니다.\n");
                        break;
                }
                
                case 5:                                 // 흑염룡의 눈물
                if(*gold>=10000)                         // 골드 -값 방지용
                {
                        if(item[4]==0)                  // 소지하지 않았을 경우
                        {
                                printf("크크큭... 강해지는 느낌이군...\n");
                                *gold-=2000;
                                *hp+=200;
                                *def+=50;
                                atk[0]+=100;
                                atk[1]+=100;
                                item[4]+=1;
                                break;
                        }
                        else                            // 1개 이상 소지하고 있을 경우
                        {
                                line();
                                printf("\t이미 소지하고 있는 아이템입니다.\n");
                                break;
                        }
                        break;
                }
                else
                {
                        printf("돈이 없어 사지 못합니다.\n");
                        break;
                }
                
                case 6:                                 // 포션세트
                if(*gold>=1000)                         // 골드 -값 방지용
                {
                        if(item[5]==0)                  // 소지하지 않았을 경우
                        {
                                printf("힐링 포션, 화속성 포션, 수속성 포션이 1개씩 추가됩니다!\n");
                                *gold-=2000;
                                item[0,1,2]+=1;
                                item[5]+=1;
                                break;
                        }
                        else                            // 1개 이상 소지하고 있을 경우
                        {
                                line();
                                printf("\t이미 구매했습니다.\n");
                                break;
                        }
                        break;
                }
                else
                {
                        printf("돈이 없어 사지 못합니다.\n");
                        break;
                }
                case 7:                                 // 스테이지 탈출권
                if(*gold>=1000 && escape>=70)                         // 골드 -값 방지용
                {
                        if(item[6]>=5)                  // 소지하지 않았을 경우
                        {
                                printf("스테이지 탈출권을 구입합니다.\n");
                                *gold-=50000;
                                item[6]+=1;
                                break;
                        }
                        else                            // 1개 이상 소지하고 있을 경우
                        {
                                line();
                                printf("\t이미 5개를 소지하고 있는 아이템입니다.\n");
                                break;
                        }
                        break;
                }
                else
                {
                        printf("돈이 없어 사지 못합니다.\n");
                        break;
                }
        }
        line();
                sleep(1);
        }
}

int Battle_Low_Grade (int *hp, int *gold, int atk[], int *def, int item[], int *stage)
{
	char Monster_Name[4][100] = {"졸개 복이(물)", "졸개 돌복이(물)","졸개 복이(화)", "졸개 돌복이(화)"}; // 몬스터 이름
	int Monster_Atk[4] = {300, 350, 500, 600};		  // 몬스터 공격력
	int Monster_Hp[4] = {1000, 1700, 1500, 2500}; 	          // 몬스터 Hp
	int Monster_Gold[4] = {2000, 3000, 3500, 4000};	          // 몬스터가 드롭할 gold 상한								 
	int M_pick; 						  // 복이와 돌복이 둘중에 랜덤으로 픽
	int Choice;						  // 선택 변수
	int Turn = 1;						  // 턴 표시 변수
	int Phase_chk = 0;					  // 플레이어와 몬스터의 공격 차례 체크를 위한 변수
	int Def_chk = 0;					  // 플레이어가 방어를 선택했는지 체크	
	int Potion_chk = 0;					  // 속성 포션 사용여부 체크
	int cal;						  // 계산값 저장용 변수
	int Itemuse;
	
	if(*stage == 1) M_pick = rand()%2;			  // 스테이지 1인 경우 물속성 복이 또는 돌복이가 선택됨
	else if (*stage == 2) M_pick = rand()%2+2;		  // 스테이지 2인 경우 화속성 복이 또는 돌복이가 선택됨
	
	for(int i= 0; i< 4; i++) // 몬스터 출현 멘트 깜박임
	{
		system("clear");
		gotoxy(10, 10);
		printf("%s 가 출현했다!", Monster_Name[M_pick]);
		usleep(500000);
		gotoxy(10, 10);
		printf("                   ");
		usleep(500000);
	}
	
	while(1)
	{
		if(Monster_Hp[M_pick] <= 0) 
		{
			cal = rand()%Monster_Gold[M_pick]+1;		// 1~몬스터 골드 상한까지 랜덤으로 골드를 획득
			*gold += cal;
			printf("\n진혁은 Gold %d 을 획득했다\n", cal); 
			return 1; // 몬스터 처치시 1을 리턴
		}
		if(*hp <= 0) return 0; // 플레이어 사망시 0을 리턴 
		
		Print_LG_Battle_status(hp, gold, atk, def, Monster_Name, Monster_Atk, Monster_Hp, &Turn, &M_pick, Potion_chk); // 전투 스테이터스 출력 함수 호출
			
		if(Phase_chk == 0)
		{
			switch( Choice = Battle_LG_Input() )
			{
				case 1:		
					Battle_LG_Player_Attack(hp, gold, atk, def, Monster_Name, Monster_Atk, Monster_Hp, &Turn, &M_pick, &Potion_chk); // 플레이어 공격 함수 호출
				break;
				case 2: 
					Def_chk = 1;					// 방어를 선택할 경우 방어 선택 체크 변수를 1로
					printf("진혁은 방어태세를 취했다\n");
				break;
				case 3:
					if( Itemuse = Battle_LG_Itemuse(hp, item, &Potion_chk, stage) ) // 아이템 사용 함수 호출
					{
						sleep(2);
						continue;	// 아이템을 사용하지 못한 경우 재 선택
					}  
				break;
				case 4:
					if( rand()%100 <20 ) //20%의 확률로 도망 성공
					{
						printf("진혁은 전투에서 도망쳤다\n");
						sleep(2);
						return 1; // 도망에 성공할 경우 1을 리턴
					}
					printf("도망을 시도했지만 실패했다\n");
				break;
				default :
					printf("선택을 잘못 했습니다.\n");
					continue;
				break;
			}
			sleep(2);
			Phase_chk = 1;		// 플레이어가 행동을 취한 후 몬스터 공격 가능
			continue;	
		}
		if(Phase_chk == 1) 
		{
			Phase_chk = Battle_LG_Monster_Attack(hp, gold, atk, def, Monster_Name, Monster_Atk, Monster_Hp, &Turn, &M_pick, &Def_chk, Potion_chk); // 몬스터 공격 함수 호출
			sleep(2);
		}
		Turn++;	//몬스터 공격 이후 턴 증가
	}
}

void Battle_LG_Player_Attack(int *hp, int *gold, int *atk, int *def, char Mname[][100], int Matk[], int MHp[], int *Turn, int *M_pick, int *Potion_chk)
{
	int cal = rand()%(atk[1]-atk[0]+1) + atk[0];	// 유저 공격 데미지 계산
	int added_damage = 0;				// 속성 추가데미지 변수
	
	if(*Potion_chk) added_damage = cal*0.2; 	// 해당 스테이지에 적합한 포션을 사용한 경우 계산 된 유저 공격 데미지에 20%만큼 추가 데미지로 산정
	
	MHp[*M_pick] -= cal + added_damage;		// 유저 공격 데미지 + 속성 추가 데미지만큼 몬스터 체력 감소
	
	// 몬스터 피격 깜박임
	if(*M_pick == 0) soldier1_itf(2);
	else if(*M_pick == 1) soldier2_itf(2);
	else if(*M_pick == 2) soldier3_itf(2);
	else if(*M_pick == 3) soldier4_itf(2);
	gotoxy(1, 21);
	
	printf("진혁이 공격했다. %s 는 %d", Mname[*M_pick], cal);
	printf(" (속성 추가 데미지 + %d ) 의 데미지를 입었다.\n", added_damage); 
	
}

int Battle_LG_Monster_Attack(int *hp, int *gold, int *atk, int *def, char Mname[][100], int Matk[], int MHp[], int *Turn, int *M_pick, int *Def_chk, int Potion_chk)
{
	int cal = rand()%(Matk[*M_pick]-49)+50;		//몬스터 공격 데미지 계산
	
	if(*Turn%3 == 0 ) // 3턴 마다 차징
	{
		printf("\n%s 는 깊게 숨을 들이쉬어 힘을 모았다\n", Mname[*M_pick]); 
		return 0;
	}
	else if(*Turn%4 == 0 ) cal = cal*3; // 4턴에 계산 된 데미지의 3배 
	
	if(*Def_chk == 1) // 플레이어가 방어를 선택했을 경우 몬스터의 데미지 90% 감소
	{ 
		cal = cal * 0.1; 
		Def_chk = 0; 
	} 
	if( cal - *def <= 0 ) cal = 1;		// 몬스터 공격 데미지가 유저의 방어력보다 낮을 경우 데미지를 1로 고정
	else cal = cal - *def;			// 몬스터 공격 데미지가 유저의 방어력보다 낮지 않을 경우 유저 방어력 만큼 감산 
	
	*hp -= cal;				
	
	// 플레이어 피격 깜박임
	player_itf(2, Potion_chk);
	gotoxy(1, 21);
	
	printf("\n%s 가 %s했다. 진혁은 %d의 데미지를 입었다\n", Mname[*M_pick], *Turn%4 ? "공격":"힘차게 공격", cal);
	
	return 0;
}

void Print_LG_Battle_status(int *hp, int *gold, int *atk, int *def, char Mname[][100], int *Matk, int *MHp, int *Turn, int *M_pick, int Potion_chk)
{
	system("clear");
	printf("\n%s\nHp : %4d\t   공격력 : %3d\n\n", Mname[*M_pick], MHp[*M_pick], Matk[*M_pick]);
	printf("=================================================================================");
	player_itf(1, Potion_chk);					// 유저 그래픽 프린트
	if(*M_pick == 0) soldier1_itf(1);		// 몬스터 그래픽 프린트
	else if(*M_pick == 1) soldier2_itf(1);
	else if(*M_pick == 2) soldier3_itf(1);
	else if(*M_pick == 3) soldier4_itf(1);
	gotoxy(0, 13);
	printf("=================================================================================\n");
	
	printf("Turn : %2d\n진혁의 Hp : %4d\t 진혁의 공격력 : %3d ~ %3d\t  진혁의 방어력 : %3d\n\n", *Turn, *hp, atk[0], atk[1], *def);
	printf("┌────────────────────────────────────────────────┐\n");
	printf("│1. 공격     2. 방어	3. 아이템 사용   4. 도망 │\n");
	printf("└────────────────────────────────────────────────┘\n");
}

int Battle_LG_Itemuse(int *Hp, int *item, int *Potion_chk, int *stage)
{
	int Choice;
	int Usechk = 0;
	
	Print_Battle_Itemlist(item);	// 아이템 리스트 프린트 함수 호출
	Choice = Battle_LG_Input();

	if( item[Choice-1] == 0) // 선택한 아이템을 소지 하고 있지 않은 경우
	{
		printf("해당 아이템을 소지하고 있지 않습니다\n");
		return 1;
	}
	else
	{
		if( Choice == 1 || (Choice == 2 && *stage ==1) ||  (Choice == 3 && *stage ==2) ) Usechk =1; // 아이템 사용 여부 체크
		if( Choice == 1 ) *Hp = 1000;  // 힐링포션을 사용한 경우 체력 회복
		else if (Choice == 2 && *stage ==1) *Potion_chk = 1;
		else if (Choice == 3 && *stage ==2) *Potion_chk = 2; // 스테이지에 맞는 강화포션을 사용한 경우 
		else if( Choice > 4 || Choice <= 0 ) printf("선택을 잘못 했습니다.\n");
	}
	
	if (Usechk == 1 && Choice == 1) printf("힐링 포션을 사용하여 체력을 회복했다.\n");  
	else if (Usechk == 1 && (Choice >= 2 && Choice <=3 ) ) printf("%s 을 사용했다.\n", *stage == 1 ? "화속성 강화 포션" : "물속성 강화 포션" ); 
	else if (Usechk == 0 && (Choice >= 2 && Choice <=4 ) ) printf("현재 스테이지에서는 사용할 수 없다.\n");
	
	if( item[Choice-1] != 0 && (Choice >= 1 && Choice <=4) && Usechk == 1 ) item[Choice-1]--;  // 사용한 아이템의 소지 갯수 감산	
	if( Usechk == 1 && (Choice >= 1 && Choice <= 4) ) return 0;
	else return 1;
	
}

void Print_Battle_Itemlist(int *item)
{
	printf("\n");
	printf("┌───────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("│1. 힐링포션(%d)     2. 화속성 강화포션(%d)	3. 물속성 강화포션(%d)      4. 빛속성 강화포션(%d)  	    │\n", item[0], item[1], item[2], item[3] );
	printf("└───────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
}

void soldier1_itf(int mode)//졸병1
{
	int x=30;
	int y=8;
	Blue
	if(mode==1)//일반모습
	{
		gotoxy(x,y);
		printf("   ^@@^");
		gotoxy(x,y+1);
		printf(">>[@⊙ @]<<");
		gotoxy(x,y+2);
		printf("  %c_@@_/",92);
		gotoxy(1,1);
	}
	else //피격모습
	{
		for(int q=0;q<5;q++)
		{
			gotoxy(x,y);
			printf("   ^@@^");
			gotoxy(x,y+1);
			printf(">>[@＊@]<<");
			gotoxy(x,y+2);
			printf("  %c_@@_/",92);
			gotoxy(1,1);
			
			delay_ms(100);
			
			gotoxy(x,y+0);
			printf("            ");
			gotoxy(x,y+1);
			printf("            ");
			gotoxy(x,y+2);
			printf("            ");
			gotoxy(1,1);
			
			delay_ms(100);
		}
		soldier1_itf(1);
	}
	Def
}

void soldier2_itf(int mode)//졸병2
{
	int x=30;
	int y=8;
	
	Blue
	if(mode==1)//일반모습
	{
		gotoxy(x,y);
		printf("   *@@*");
		gotoxy(x,y+1);
		printf(">>[@⊙ @]<<");
		gotoxy(x,y+2);
		printf("  %c_@@_/",92);
		gotoxy(1,1);
	}
	else //피격모습
	{
		for(int q=0;q<5;q++)
		{
			gotoxy(x,y);
			printf("   *@@*");
			gotoxy(x,y+1);
			printf(">>[@＊@]<<");
			gotoxy(x,y+2);
			printf("  %c_@@_/",92);
			gotoxy(1,1);
			
			delay_ms(100);
			
			gotoxy(x,y);
			printf("            ");
			gotoxy(x,y+1);
			printf("            ");
			gotoxy(x,y+2);
			printf("            ");
			gotoxy(1,1);
			
			delay_ms(100);
		}
		soldier2_itf(1);
	}
	Def
}
void soldier3_itf(int mode)//졸병3
{
	int x=30;
	int y=8;
	
	Red
	if(mode==1)//일반모습
	{
		gotoxy(x,y);
		printf("   ^@@^");
		gotoxy(x,y+1);
		printf(">>[@⊙ @]<<");
		gotoxy(x,y+2);
		printf("  %c_@@_/",92);
		gotoxy(1,1);
	}
	else //피격모습
	{
		for(int q=0;q<5;q++)
		{
			gotoxy(x,y);
			printf("   ^@@^");
			gotoxy(x,y+1);
			printf(">>[@＊@]<<");
			gotoxy(x,y+2);
			printf("  %c_@@_/",92);
			gotoxy(1,1);
			
			delay_ms(100);
			
			gotoxy(x,y+0);
			printf("            ");
			gotoxy(x,y+1);
			printf("            ");
			gotoxy(x,y+2);
			printf("            ");
			gotoxy(1,1);
			
			delay_ms(100);
		}
		soldier3_itf(1);
	}
	Def
}
void soldier4_itf(int mode)//졸병4
{
	int x=30;
	int y=8;
	
	Red
	if(mode==1)//일반모습
	{
		gotoxy(x,y);
		printf("   ^@@^");
		gotoxy(x,y+1);
		printf(">>[@⊙ @]<<");
		gotoxy(x,y+2);
		printf("  %c_@@_/",92);
		gotoxy(1,1);
	}
	else //피격모습
	{
		for(int q=0;q<5;q++)
		{
			gotoxy(x,y);
			printf("   ^@@^");
			gotoxy(x,y+1);
			printf(">>[@＊@]<<");
			gotoxy(x,y+2);
			printf("  %c_@@_/",92);
			gotoxy(1,1);
			
			delay_ms(100);
			
			gotoxy(x,y+0);
			printf("            ");
			gotoxy(x,y+1);
			printf("            ");
			gotoxy(x,y+2);
			printf("            ");
			gotoxy(1,1);
			
			delay_ms(100);
		}
		soldier4_itf(1);
	}
	Def
}

void player_itf(int mode, int Potion_chk)//플레이어
{
	int x=6;
	int y=8;
	
	if(mode==1)//일반모습
	{
		gotoxy(x,y);
		printf("O");
		gotoxy(x+2,y);
		if(Potion_chk == 1) Red
		else if (Potion_chk == 2) Blue
		else if (Potion_chk == 3) YELLOW
		printf("/");
		Def
		gotoxy(x,y+1);
		printf("T");
		gotoxy(x,y+2);
		printf("^");
		gotoxy(1,1);
	}
	else//피격 모습
	{
		for(int q=0;q<5;q++)
		{
			gotoxy(x,y);
			printf("O");
			gotoxy(x,y+1);
			printf("T");
			gotoxy(x,y+2);
			printf("^");
			gotoxy(1,1);
			
			delay_ms(100);
			
			gotoxy(x,y);
			printf(" ");
			gotoxy(x,y+1);
			printf(" ");
			gotoxy(x,y+2);
			printf(" ");
			gotoxy(1,1);
			
			delay_ms(100);
		}
		player_itf(1, Potion_chk);
	}
}

int Battle_High_Grade(int *hp,int *gold,int atk[],int *def,int item[],int *stage,int monster)
{
	char Monster_Name[4][100]={"데빌 킹복이(물)","마왕 킹복이(악)","데빌 킹복이(불)","마왕 킹복이(악)"};
	int Monster_Atk[4] = {500, 650, 750, 1000};			//몬스터 공격력
	int Monster_Hp[4] = {2000, 2500, 3000, 5000}; 	         	//몬스터 체력
	int Monster_Gold[4] = {3000, 3500, 5000, 10000};	  	//몬스터 골드드랍 								 
	int M_pick=monster-1; 						//몬스터 배열좌표
	int Choice;						 	//선택문 변수
	int Turn = 1;						 	//턴 카운트
	int Phase_chk = 0;					 	//상대턴 마이턴
	int Def_chk = 0;					 	//방어 on/off
	int cal;							//랜덤 저장
	int Potion_chk = 0;						//포션 변수
	
	if(*stage==2) M_pick+=2;					//층수에 따른 몬스터 뱐화
	
	system("clear");
	for(int q=0;q<3;q++)//몬스터 출현 이벤트
	{
		gotoxy(10,10);
		printf("%s가 나타났다.",Monster_Name[M_pick]);
		gotoxy(1,1);
		delay_ms(500);
		
		gotoxy(10,10);
		printf("                           ");
		gotoxy(1,1);
		delay_ms(500);
	}
	for(;;)
	{
		if(Monster_Hp[M_pick] <= 0) //몬스터 사망
		{
			cal = rand()%Monster_Gold[M_pick]+1;//골드 랜덤
			*gold += cal;//골드 누적
			printf("진혁은 Gold %d 을 획득했다\n", cal); //출력
			return 1;//몬스터 사망 return 1;
		}
		if(*hp <= 0) return 0;//플레이어 사망 return 0;
		
		Print_HG_Battle_status(hp, gold, atk, def, Monster_Name, Monster_Atk, Monster_Hp, &Turn, &M_pick,stage, Potion_chk);//배틀 화면 출력
		
		if(Phase_chk==0)//플레이어 턴
		{
			switch(Choice=Battle_LG_Input())//입력값 저장
			{
				case 1://공격 선택
					Battle_HG_Player_Attack(hp, gold, atk, def, Monster_Name, Monster_Atk, Monster_Hp, &Turn, &M_pick, &Potion_chk,stage);
				
				break;
			
				case 2://방어 선택
					Def_chk=1;
					printf("진혁은 방어태세를 취했다\n");
				break;
			
				case 3://아이템 선택
					Choice=Battle_HG_Itemuse(hp, item, &Potion_chk, stage,monster);
					if(Choice)
					{
						sleep(2);
						continue;
					}
				break;
			
				case 4://도망 선택
					if(rand()%100<20) 
					{
						printf("진혁은 전투에서 도망쳤다\n");
						sleep(2);
						return 2; // 도망에 성공할 경우 1을 리턴
					}
					printf("도망을 시도했지만 실패했다\n");
				break;
			
				default://그외
					printf("선택을 잘못 했습니다.\n");
					continue;
				break;
			}
			sleep(2);
			Phase_chk = 1;
			continue;
		}
		else//몬스터 턴
		{
			Phase_chk = Battle_HG_Monster_Attack(hp, gold, atk, def, Monster_Name, Monster_Atk, Monster_Hp, &Turn, &M_pick, &Def_chk, Potion_chk);	
			sleep(2);
		}
		Turn++;
	}
}

//플레이어 공격
void Battle_HG_Player_Attack(int *hp, int *gold, int *Atk, int *def, char Mname[][100], int MAtk[], int MHp[], int *Turn, int *M_pick, int *Potion_chk,int *stage)
{
	int cal = rand()%(Atk[1]-Atk[0]+1) + Atk[0];//공격랜덤 저장
	int added_damage = 0;
	
	if(*Potion_chk) added_damage = cal*0.2; //속성데미지 20%
	
	MHp[*M_pick] -= cal + added_damage;//공격
	
	if(*M_pick%2 == 0) md_boss_itf(2,stage);//중간보스
	else if(*M_pick%2 == 1) boss_itf(2);//최종보스
	gotoxy(1, 21);
	
	printf("진혁이 공격했다. %s 는 %d", Mname[*M_pick], cal);//출력
	printf(" (속성 추가 데미지 + %d ) 의 데미지를 입었다.\n", added_damage);
	
}

//몬스터 공격
int Battle_HG_Monster_Attack(int *hp, int *gold, int *Atk, int *def, char Mname[][100], int MAtk[], int MHp[], int *Turn, int *M_pick, int *Def_chk, int Potion_chk)
{
	int cal = rand()%(MAtk[*M_pick]-49)+50;//공격력 랜덤 저장
	
	if(*Turn%3 == 0 ) // 3턴 마다 차징
	{
		printf("\n%s 는 깊게 숨을 들이쉬어 힘을 모았다\n", Mname[*M_pick]); 
		return 0;
	}
	else if(*Turn%4 == 0 ) cal = cal*3; // 4턴에 계산 된 데미지의 3배 
	
	if(*Def_chk == 1) // 플레이어가 방어를 선택했을 경우 몬스터의 데미지 90% 감소
	{ 
		cal = cal * 0.1; //90%감소
		*Def_chk = 0; //방어해제
	} 
	if( cal - *def <= 0 ) cal = 1;//최소데미지 1
	else cal = cal -*def;
	
	*hp -= cal;
	
	player_itf(2, Potion_chk);//플레이어
	gotoxy(1, 21);
	
	//출력
	printf("\n%s 가 %s했다. 진혁은 %d의 데미지를 입었다\n", Mname[*M_pick], *Turn%4 ? "공격":"힘차게 공격", cal);
	
	return 0;
}

void boss_itf(int mode)//보스 캐릭
{
	int x=30;//가로
	int y=6;//세로
	PURPLE
	if(mode==1)//일반모습
	{
		gotoxy(x,y);
		printf("   /%c   /%c   	",92,92);
		gotoxy(x,y+1);
		printf(" _//%c%c_//%c%c_",92,92,92,92);
		gotoxy(x,y+2);
		printf("/           %c	",92);
		gotoxy(x,y+3);
		printf("(   O   O   )	");
		gotoxy(x,y+4);
		printf(" %c >     < /	",92);
		gotoxy(x,y+5);
		printf("  %c___X___/	",92);
		gotoxy(1,1);
	}
	else//피격모습
	{
		for(int q=0;q<3;q++)
		{
			gotoxy(x,y);
			printf("   /%c   /%c   	",92,92);
			gotoxy(x,y+1);
			printf(" _//%c%c_//%c%c_",92,92,92,92);
			gotoxy(x,y+2);
			printf("/           %c	",92);
			gotoxy(x,y+3);
			printf("(   X   X   )	");
			gotoxy(x,y+4);
			printf(" %c >     < /	",92);
			gotoxy(x,y+5);
			printf("  %c___X___/	",92);
			gotoxy(1,1);
			
			delay_ms(300);
			
			gotoxy(x,y);
			printf("                          ");
			gotoxy(x,y+1);
			printf("                          ");
			gotoxy(x,y+2);
			printf("                          ");
			gotoxy(x,y+3);
			printf("                          ");
			gotoxy(x,y+4);
			printf("                          ");
			gotoxy(x,y+5);
			printf("                          ");
			gotoxy(1,1);
			
			delay_ms(300);
		}
		boss_itf(1);
	}
	Def
}

void md_boss_itf(int mode,int *stage)//중간 보스 캐릭
{
	int x=30;
	int y=7;
	
	//if(*stage==1) Blue;
	//else Red;
	
	if(mode==1)//일반 모습
	{
		gotoxy(x,y);
		printf("      <⊙ >");
		gotoxy(x,y+1);
		printf("      -[]-- ▲");
		gotoxy(x,y+2);
		printf(" ====|   ★ |■");
		gotoxy(x,y+3);
		printf("      ------");
		gotoxy(x,y+4);
		printf("   /=========%c",92);
		gotoxy(x,y+5);
		printf("   %c=========/",92);
		gotoxy(1,1);
	}
	else//피격 모습
	{
		for(int q=0;q<3;q++)
		{
			gotoxy(x,y);
			printf("      <＊>");
			gotoxy(x,y+1);
			printf("      -[]-- ▲");
			gotoxy(x,y+2);
			printf(" ====|   ★ |■");
			gotoxy(x,y+3);
			printf("      ------");
			gotoxy(x,y+4);
			printf("   /=========%c",92);
			gotoxy(x,y+5);
			printf("   %c=========/",92);
			gotoxy(1,1);
			
			delay_ms(300);
			
			gotoxy(x,y);
			printf("                   ");
			gotoxy(x,y+1);
			printf("                   ");
			gotoxy(x,y+2);
			printf("                   ");
			gotoxy(x,y+3);
			printf("                   ");
			gotoxy(x,y+4);
			printf("                   ");
			gotoxy(x,y+5);
			printf("                   ");
			gotoxy(1,1);
			
			delay_ms(300);
		}
		md_boss_itf(1,stage);
	}
	//Def;
}

//아이템 사용
int Battle_HG_Itemuse(int *Hp, int *item, int *Potion_chk, int *stage,int monster)
{
	int Choice;
	
	Print_Battle_Itemlist(item);//아이템 출력
	
	Choice = Battle_LG_Input();//입력값 저장
	
	if(Choice<1||Choice>4) //범위 이탈
	{
		printf("선택을 잘못 했습니다.\n");
		return 1;//실패시 return 1;
	}
	else if(item[Choice-1] ==0 ) //재고가 없을시
	{
		printf("해당 아이템을 소지하고 있지 않습니다\n");
		return 1;//실패시 return 1;
	}
	else
	{
		switch(Choice)
		{
			case 1:
				if(*Hp>=1000) printf("이미 최대체력 입니다.\n");
				else
				{
					printf("힐링 포션을 사용하여 체력을 회복했다.\n");
					*Hp  = 1000;
					item[Choice-1]--;
				}
			break;
			case 2:
				if(*stage == 1) 
				{
					printf("화속성 강화포션을 사용했다.\n");
					*Potion_chk = 1;
					item[Choice-1]--;
				}
				else printf("현재 스테이지에서는 사용할 수 없다\n");
			break;
			case 3:
				if(*stage == 2) 
				{
					printf("물속성 강화포션을 사용했다.\n");
					*Potion_chk = 2;
					item[Choice-1]--;
				}
				else printf("현재 스테이지에서는 사용할 수 없다\n");
			break;
			case 4:
				if(monster==2)
				{
					printf("빛속성 강화포션을 사용했다.\n");
					*Potion_chk = 3;
					item[Choice-1]--;
				}
				else printf("현재 스테이지에서는 사용할 수 없다\n");
			break;
		}
	}
	
}

//배틀 화면 출력
void Print_HG_Battle_status(int *hp, int *gold, int *Atk, int *def, char Mname[][100], int *MAtk, int *MHp, int *Turn, int *M_pick,int *stage, int Potion_chk)
{
	system("clear");//화면 클리어
	printf("\n%s\nHp : %4d\t   공격력 : %3d\n\n", Mname[*M_pick], MHp[*M_pick], MAtk[*M_pick]); //몬스터 스탯 출력
	printf("=================================================================================");
	player_itf(1, Potion_chk);
	if(*M_pick%2 == 0) md_boss_itf(1,stage);////////////////////
	else if(*M_pick%2 == 1) boss_itf(1);//////////////
	gotoxy(0, 13);
	printf("=================================================================================\n");
	
	printf("Turn : %2d\n진혁의 Hp : %4d\t 진혁의 공격력 : %3d ~ %3d\t  진혁의 방어력 : %3d\n\n", *Turn, *hp, Atk[0], Atk[1], *def);//내 스탯 출력
	printf("┌────────────────────────────────────────────────┐\n");
	printf("│1. 공격     2. 방어	3. 아이템 사용   4. 도망 │\n");
	printf("└────────────────────────────────────────────────┘\n");
}

int Battle_LG_Input() 
{
    char choicebuffer[10]={'\0',};
    char enter;    
    while(1)
    { 
        printf(">> ");
        scanf("%s%c", choicebuffer, &enter);
        if(choicebuffer[0] >=48 && choicebuffer[0] <=57) return choicebuffer[0]-48;
        else printf("다시 입력하세요");
    }
}

void delay_ms(int num)//지연시간 1/1000초
{
	usleep(num*1000);
}

void gotoxy(int x, int y)//커서 옮기기
{
     printf("\033[%d;%df",y,x);
     fflush(stdout);
}

int sm_main(int *gold, int *hp, int item[7])
{
	int number[3];
	int select;
	int i;
	int out;

	srand(time(NULL));
	Red;
	system("clear");
	printf("\n==[슬롯]================================\n");
	printf("내 몸의 같은 숫자가 네 유일한 빛이다...\n");
	printf("골드와 목숨을 걸어라...\n");
	printf("========================================\n");
	printf("====< 0 >=======< 0 >====\n");
	printf(" WWWWWWWVWWWWWWWVWWWWWWW \n");
	printf("\n\n    .<N>. .<N>. .<N>.\n");
	printf(" MMMMMMMNMMMMMMMNMMMMMMM \n");
	printf("=========================\n");

	printf("\n=========================\n");
	if(*hp<=0)("GIVE ME YOUR SOUL..\n");
	else 
	{
		printf("HP   : %d\n", *hp);
		printf("GOLD : %d\n", *gold);
	}
	printf("=========================\n");
	sm_enter();
	if(*gold<=0) 
	{
		*gold=0;
		if(item[6]==1)
		{
			printf("탈출권으로 꺼져라...\n");
			Def;
			item[6]=0;
			out=0;
			sleep(2);
			return out;
		}
	}
	*gold-=500;
	for(i=0;i<=2;i++) 
	{
		number[i]=rand()%9;
	}

	sm_effect(hp, gold);

	system("clear");
	printf("\n\n\n\n\n====< 0 >=======< 0 >====\n");
	printf(" WWWWWWWVWWWWWWWVWWWWWWW \n");
	printf("    .<%d>. .<%d>. .<%d>.\n",number[0], number[1], number[2]);
	printf(" MMMMMMMNMMMMMMMNMMMMMMM \n");
	printf("=========================\n");
	printf("\n=========================\n");
	if(*hp<=0)("GIVE ME YOUR SOUL..\n");
	else 
	{
		printf("HP   : %d\n", *hp);
		printf("GOLD : %d\n", *gold);
	}
	printf("=========================\n");
	printf(" <[5][0][0][g][0][L][d]>\n");
	printf("=========================\n");
	sleep(3);
	if(number[0]==number[1]&&number[0]==number[2]&&number[1]==number[2])
	{
		Blue;
		printf("\n\nYOU WIN\n");
		Def;
		out=1;
		return out;
	}
	else
	{
		if(*hp==500) printf("\n\n앞이 안보입니다! 들리는 건 슬롯의 웃음 소리...\n");
		if(*hp==100) printf("\n\n다리에 힘이 풀려 주저 앉았습니다! 움직일 수 있는 건 슬롯의 레버 뿐...\n");
		if(*gold<=0&&*hp>0) 
		{
			*hp-=100;
			if(hp<=0) hp=0;
			printf("\n\n피를 다오... [-100 HP]\n");
			sleep(1);
		}
		else if(*gold==0&&*hp==0)
		{
			printf("\n\nYOU DIE\n");
			Def;
			sleep(2);
			out=0;
			return out;
		}
		printf("\n\n다시...\n");
		sleep(3);
		sm_main(gold, hp, item);
	}

}

void sm_effect(int *hp, int *gold)
{
	srand(time(NULL));

	char num[10]={'1', '3', '2', '4', '5', '6', '7', '3', '2', '1'};
	int i;
	int j=0;
	for(i=0;i<=20;i++)
	{
		printf("\n\n\n\n\n====< 0 >=======< 0 >====\n");
		printf(" WWWWWWWVWWWWWWWVWWWWWWW \n");
		printf("\n\n    .<%c>. .<%c>. .<%c>.\n", num[j], num[j+1], num[j-1]);
		printf(" MMMMMMMNMMMMMMMNMMMMMMM \n");
		printf("=========================\n");
		printf("\n=========================\n");
		if(*hp<=0)("GIVE ME YOUR SOUL..\n");
		else 
		{
			printf("HP   : %d\n", *hp);
			printf("GOLD : %d\n", *gold);
		}

		printf("=========================\n");
		printf(" <[5][0][0][g][0][L][d]>\n");
		printf("=========================\n");
		usleep(35000);
		j++;
		if(j>10) j=0;
		system("clear");
	}
}

void sm_enter(void)
{
	char en;

	//while(getchar() != '\n');
	printf(" <[5][0][0][g][0][L][d]>\n");
	printf("=========================\n");
	scanf("%c", &en);
	system("clear");
}

void sm_intro(void)
{
	int i;
	char chat[3][300]={"내 몸의 같은 숫자가 네 유일한 빛이다...", " ", "골드와 목숨을 걸어라..."};
	system("clear");
	for(i=0; i<=2; i++)
	{
		printf("\n==[슬롯]================================\n");
		printf("\n%s\n",chat[0]);
		if(i<=1) printf("\n%s\n\n",chat[1]);
		if(i==2) printf("\n%s\n\n",chat[2]);
		printf("========================================\n\n");
		sleep(1);
		if(i!=2)system("clear");
	}
	sleep(3);
	system("clear");
}

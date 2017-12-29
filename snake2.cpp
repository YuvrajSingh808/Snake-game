#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
using namespace std;
int main(){
	system("cls");
	char snake[10] = {'*','*','*','*','*','*','*','*','*'},key,food = '@';
	int posx=0,posy=0,score=0;
	cout<<snake;
	key = _getch();
	int abc = key;
	int foodx = (rand()%90) + 10;
	int foody = (rand()%90) + 10;
	unsigned int seedval;
	time_t t;
	seedval = (unsigned)time(&t);
	srand(seedval);
	if(key=='D'||key=='d'){//right
		right:
		while(1){
			system("cls");
			gotoxy(posx,posy);
			cout<<snake;
			posx++;
			Sleep(100);
			gotoxy(foodx,foody);
			cout<<food;
			if(posx>=100){
				posx = 0;
			}
			if(foodx == posx && foody==posy){
				score++;
				foodx = (rand()%90) + 10;
				foody = (rand()%90) + 10;
			}
			if(kbhit()){
				key = _getch();
				if(key=='A'||key=='a'){
					goto left;
				}
				else if(key=='W'||key=='w'){
					goto up;
					posx = posx;
				}
				else if(key=='S'||key=='s'){
					goto down;
					posx = posx;
				}
				else if(key == 'x'){
					goto score;
				}
			}
		}
	}
	else if(key=='A'||key=='a'){//left
		left:
		while(1){
			system("cls");
			gotoxy(posx,posy);
			cout<<snake;
			posx--;
			Sleep(100);
			gotoxy(foodx,foody);
			cout<<food;
			if(posx<=0){
				posx = 100;
			}
			if(foodx == posx && foody==posy){
				score++;
				foodx = (rand()%90) + 10;
				foody = (rand()%90) + 10;
			}
			if(kbhit()){
				key = _getch();
				if(key=='D'||key=='d'){
					goto right;
				}
				else if(key=='W'||key=='w'){
					goto up;
					posx = posx;
				}
				else if(key=='S'||key=='s'){
					goto down;
					posx = posx;
				}
				else if(key == 'x'){
					goto score;
				}
			}
		}
	}
	else if(key=='W' || key=='w'){//up
		up:
		while(1){
			system("cls");
			for(int i=0;i<10;i++){
				gotoxy(posx,posy);
				cout<<snake[i]<<endl;
				posy--;
				Sleep(100);
				gotoxy(foodx,foody);
				cout<<food;
				if(kbhit())
					break;
			}
			if(posy<=0){
				posy=100;
			}
			if(foodx == posx && foody==posy){
				score++;
				foodx = (rand()%90) + 10;
				foody = (rand()%90) + 10;
			}
			if(kbhit()){
				key = _getch();
				if(key=='S'||key=='s'){
					goto down;
				}
				else if(key=='A'||key=='a'){
					goto left;
					posx+=10;
				}
				else if(key=='D'||key=='d'){
					goto right;
				}
				else if(key == 'x'){
					goto score;
				}
			}
		}
	}
	else if(key=='S'||key=='s'){//down
		down:
		while(1){
			system("cls");
			for(int i=0;i<10;i++){
				gotoxy(posx,posy);
				cout<<snake[i]<<endl;
				posy++;
				Sleep(100);
				gotoxy(foodx,foody);
				cout<<food;
				if(kbhit())
					break;
			}
			if(posy>=100){
				posy=0;
			}
			if(foodx == posx && foody==posy){
				score++;
				foodx = (rand()%90) + 10;
				foody = (rand()%90) + 10;
			}
			if(kbhit()){
				key = _getch();
				if(key=='W'||key=='w'){
					goto up;
				}	
				else if(key=='D'||key=='d'){
					goto right;
				}
				else if(key=='A'||key=='a'){
					goto left;
					posx-=10;
				}
				else if(key == 'x'){
					goto score;
				}
			}
		}
	}
	else if(key == 'x'){//score
	score:
	gotoxy(0,0);
	cout<<"score = "<<score;
	key = _getch();
	if(key=='W'||key=='w'){
		goto up;
	}	
	else if(key=='D'||key=='d'){
		goto right;
	}
	else if(key=='A'||key=='a'){
		goto left;
		posx-=10;
	}
	else if(key=='S'||key=='s'){
		goto down;
	}
	}
}

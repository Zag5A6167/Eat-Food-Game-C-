#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int screenWidth = 10;
int screenHeight = 10;
int snakeX;
int snakeY;
int snakeTx[1000],snakeTy[1000];
int snakeTailLen;
int score;
int fruitX;
int fruitY;

bool isRunning;
enum snakeDir{LEFT,RIGHT,UP,DOWN};
snakeDir sDir;
void Ginit(){
	isRunning = false;
	snakeX = screenWidth / 2;
	snakeY = screenHeight / 2;
	score = 0;
	fruitX = rand() % screenWidth;
	fruitY = rand() % screenHeight;
}
void Update(){
	
	switch(sDir){
	case LEFT:
		snakeX--;
		break;
	case RIGHT:
		snakeX++;
		break;
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	}

	if(snakeX < 0){
		snakeX = screenWidth - 1;
	}else if(snakeX >= screenWidth){
		snakeX = 0;
	}
	// if(snakeY < 0){
	// 	screenHeight = screenHeight -1;
	// }else if(snakeY >= screenHeight){
	// 	screenHeight = 0;
	// }
	if(snakeX == fruitX && snakeY == fruitY){
		fruitX = rand() % screenWidth;
		fruitY = rand() % screenHeight;
		score++;
		
	}
}
void Render(){
	system("cls");
	//Wall top
	for(int i = 0;i < screenWidth+1;i++){
		cout << "*";

	}
	cout << "\n";
	for(int i = 0 ;i < screenHeight;i++){
		for(int j = 0;j<=screenWidth;j++){
			if(j == 0 || j == screenWidth){
				cout << "+";
			
			}
			if(i == snakeY && j == snakeX){
				cout << "S";
			}else if(i == fruitY && j == fruitX){
				cout << "F";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}

	for(int i = 0 ;i < screenWidth+1;i++){
		cout << "*";
	}
	cout << endl;
	cout << score;
}
void Init(){

}
void UserInput(){
	if(_kbhit()){
		switch(_getch()){
		case 'a':
			sDir = LEFT;
			break;
		case 'd':
			sDir = RIGHT;
			break;
		case 'w':
			sDir = UP;
			break;
		case 's':
			sDir = DOWN;
			break;
		case 'e':
			isRunning = true;
			cout << "Exit";
			break;	
		}

	}
}
int main(){
	Ginit();
	while(!isRunning){
		Render();
		UserInput();
		Update();
	}
	return 0;
}
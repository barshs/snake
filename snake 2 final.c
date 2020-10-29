#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
void first();
void setup();
void fruit();
void draw();
void input();
void logic();
int height=40, width=40,gameover=0;
char ch;
int x,y,fruitx,fruity,score=0,flag,tailX[100],tailY[100];
int l=0;
void ResetScreenPosition()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut,Position);
}

int main()
{
printf("press (^)for UP,(<)for RIGHT,(>)for LEFT,(V)for DOWN\n");
printf("***********************\n");
printf("PLEASE PLAY IN FULL SCREEN\n");
printf("***********************\n");

    system("pause");
system("cls");
    first();
}
void first(){

	int m,n;
	char ch;

		l=0;
	setup();
	fruit();
	while(!gameover){
ResetScreenPosition();

	draw();
	input();
    logic();

    for(m=0; m<10000; m++){
    	for(n=0; n<2000; n++){

		}
	}


}
 Sleep(500);
system("cls");
system("pause");
printf("\n\n\n\t\t\tTHE SCORE IS %d\n\n\n\t\t\t",l-1);
printf("\n\t\t\t!!!!!!!!!!  GAMEOVER  !!!!!!!!!!\n\n\n\t\t\t");

}

void setup(){
	gameover=0;
	x=width/2;
	y=height/2;
}
	void fruit()
	{
	    label1:
	fruitx=rand()%40;

	if(fruitx==0)
	 goto label1;

	 label2:
	 fruity=rand()%40;

	if(fruity==0)
	 goto label2;
	 l++;
	}


void draw(){


	int i,j;
	for(i=0; i<height; i++){
		for(j=0; j<width; j++){
			if(i==0 || j==0 || i==height-1|| j==width-1)
			{
			     char c=178;
               printf("%c",c);
			}
			else{
			if(i==y && j==x)
			 printf("O");

			 else if(i==fruity && j==fruitx)
             {
                 ch=254;
			 printf("%c",ch);
             }


			 else{
			 	int p=0,k;
			 	for(k=0; k<l; k++){

			 if(i==tailY[k] && j== tailX[k]){
			 	printf("o");
			 	p=1;
			 }
		}
			 if(p==0)
			printf(" ");
		}
		}
		}
		printf("\n");

	}


}

void input(){

	if(kbhit()){

		switch((getch()))
		{

		    case 75:
            flag=1;
            break;

        case 77:
            flag=2;
            /* Code for down arrow handling */
            break;

		   	case 72:
            flag=3;
            break;

        case 80:
            flag=4;
            /* Code for down arrow handling */
            break;
		}
		switch(ch)
		{
		    case 'a':
				flag=1;
				break;

			case 'd':
				flag=2;
				break;
			case 'w':
				flag=3;
				break;

			case 'z':
				flag=4;
				break;

		   case 'x':
		   	gameover=1;
		   	break;
		}

		}

}

void logic(){
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2x,prev2y;
	tailX[0]=x;
	tailY[0]=y;

	for(i=1; i<l; i++){
		prev2x=tailX[i];
		prev2y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2x;
		prevY=prev2y;

	}

	switch(flag){

		case 1:
				x--;
				break;

			case 2:
				x++;
				break;
			case 3:
				y--;
				break;

			case 4:
				y++;
				break;

			default:
				break;

	}
	if(x==width-1 || x==0 || y==height-1|| y==0)
	 gameover=1;


	if(y==fruity && x==fruitx){

		fruit();

	}

}

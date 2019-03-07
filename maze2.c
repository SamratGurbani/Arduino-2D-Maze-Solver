#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define ROW 3
#define COL 41

 int maze[30][30]={ 
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
                   {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                   {0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
                   {0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0},
                   {0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
                   {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,1},
                   {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                   {1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
                   {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0},
                   {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0},
                   {0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0},
                   {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0},
                   {0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
                   {0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
                   {0,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0},
                   {0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0},
                   {0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0},
                   {0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                   {0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1},
                   {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
                   {0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0},
                   {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0},
                   {0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
                   {0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  };



void gotoxy(int x,int y)
{
 COORD pos={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void move(char dir,int r,int c)
{
 if(!maze[r][c])
 {
  return;
 }

 gotoxy(COL+c,ROW+r);
 putchar(148);

 if(dir&&(r==0||c==0||r==29||c==29))
 {
  Beep(900,900);
  exit(0);
 }
 
 if(dir==0) dir='L';

 Sleep(250);

 gotoxy(COL+c,ROW+r);
 putchar(46);

 if(dir!='L'&&maze[r][c-1])
 {
  move('R',r,c-1);
  gotoxy(COL+c,ROW+r);
  putchar(148);
  gotoxy(COL+c-1,ROW+r);
  putchar(32);
  Sleep(250);
  gotoxy(COL+c,ROW+r);
  putchar(46);  
 }
 if(dir!='R'&&maze[r][c+1])
 {
  move('L',r,c+1);
  gotoxy(COL+c,ROW+r);
  putchar(148);
  gotoxy(COL+c+1,ROW+r);
  putchar(32);
  Sleep(250);
  gotoxy(COL+c,ROW+r);
  putchar(46);    
 }
 if(dir!='T'&&maze[r-1][c])
 {
  move('B',r-1,c);
  
  gotoxy(COL+c,ROW+r-1);
  putchar(32);
 
  gotoxy(COL+c,ROW+r);
  putchar(148);
  Sleep(250);

  gotoxy(COL+c,ROW+r);
  putchar(46);  
 }
 if(dir!='B'&&maze[r+1][c]) 
 {
  move('T',r+1,c);
  gotoxy(COL+c,ROW+r);
  putchar(148);
  gotoxy(COL+c,ROW+r+1);
  putchar(32);
  
  Sleep(250);
  gotoxy(COL+c,ROW+r);
  putchar(46);  
 }
 
}

void main()
{
 int i,j,r,c;
 int start=9;
 
 r=9;
 c=0;

 system("cls");
 printf("\n\n\n");
 for(i=0;i<30;i++)
 {
  printf("\t\t\t\t\t");
  if(i==start)
   putchar(175);
  else
   putchar(' ');

  for(j=0;j<30;j++)
  {
   if(maze[i][j])
    putchar(' ');
   else
    putchar(219);
  }
  puts("");
 }

 printf("\t\t\t\t       %*s%s",15,"","END");

 move(0,r,c);
}

 



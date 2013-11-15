/*
 ============================================================================
 Name        : Tugas.c
 Author      : wajatmaka
 Build       : Linux Slackware
 Copyright   : Dwiyan Galuh W
 Description : Grafis
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void garis(int,int,int,int);
void garisout(int,int,int,int);
void lingkaran(int,int,int);

int x,y,x1,x2,y11,y2,dx,dy,r,menu;
int GraphDriver,GraphMode,ErrorCode;
double p, duaDy, duaDyKurangDx;

int main(){
printf("=========================\n");
printf("    Grafika Komputer     \n");
printf("=========================\n");
printf("1. Garis\n");
printf("2. Lingkaran\n");
printf("3. Keluar\n");
printf("=========================\n");
printf("Pilihan anda : "); scanf("%d",&menu);
printf("=========================\n");


if(menu==1)
{

   printf("=================\n");
   printf("  Membuat Garis  \n");
   printf("=================\n");
   printf("Masukan nilai X1 : "); scanf("%d",&x1);
   printf("Masukan nilai y11 : "); scanf("%d",&y11);
   printf("Masukan nilai X2 : "); scanf("%d",&x2);
   printf("Masukan nilai Y2 : "); scanf("%d",&y2);

  // initwindow(1366, 768, "Garis");

   garis(x1,y11,x2,y2);
   garisout(x1,y11,x2,y2);
   getch();
   closegraph();
}
else if(menu==2)
{

    printf("===================\n");
    printf(" Membuat Lingkaran \n ");
    printf("===================\n");
    printf("Masukan nilai X : "); scanf("%d",&x1);
    printf("Masukan nilai Y : "); scanf("%d",&y11);
    printf("Masukan nilai r : "); scanf("%d",&r);

    lingkaran(x1,y11,r);
    getch();
    closegraph();
}
else
   system("exit");
   return 0;
}



void garisout(int x1,int y11,int x2,int y2)
{

  //Algoritma Garis Bressenham
  dx = x2-x1;
  dy = y2-y11;

  p = 2 * dy - dx;
  duaDy = 2 * dy, duaDyKurangDx = 2 * (dy - dx);
  if (x1 > x2)
  {
     x= x2;
     y = y2;
     x2 = x1;
  }
  else
  {
     x = x1;
     y = y11;
  }
  putpixel(x,768-y,4);

  while (x< x2)
  {
     x++;
     if (p<0)
        p += duaDy;
     else
     {
        y++;
        p += duaDyKurangDx;

     }
     printf("X= %d , Y= %d",x,768-y);printf("\n");

  }
}


void garis(int x1,int y11,int x2,int y2)
{
  int gd=0, gm=5;
  initgraph(&gd,&gm, 0);
  //Algoritma Garis Bressenham
  dx = x2-x1;
  dy = y2-y11;

  p = 2 * dy - dx;
  duaDy = 2 * dy, duaDyKurangDx = 2 * (dy - dx);
  if (x1 > x2)
  {
     x= x2;
     y = y2;
     x2 = x1;
  }
  else
  {
     x = x1;
     y = y11;
  }
  putpixel(x,768-y,4);

  while (x< x2)
  {
     x++;
     if (p<0)
        p += duaDy;
     else
     {
        y++;
        p += duaDyKurangDx;

     }
     printf("X= %d , Y= %d",x,768-y);printf("\n");

     putpixel(x,768-y,4);

  }
}

void lingkaran(int x1, int y11, int r)
{
  int gd1=0, gm1=5;
  initgraph(&gd1,&gm1, 0);
  //Algoritma Lingkaran Bressenham
  int p = 1 - r;
  int ddF_x = 1;
  int ddF_y = -2 * r;
  int x = 0;
  int y = r;

  putpixel(x1, y11 + r,4);
  putpixel(x1, y11 - r,4);
  putpixel(x1 + r, y11,4);
  putpixel(x1 - r, y11,4);

  while(x < y)
  {
    if(p >= 0)
    {
      y--;
      ddF_y += 2;
      p += ddF_y;
    }
    x++;
    ddF_x += 2;
    p += ddF_x;
    putpixel(x1+x,768-y11+y,4);
    putpixel(x1-x,768-y11+y,4);
    putpixel(x1+x,768-y11-y,4);
    putpixel(x1-x,768-y11-y,4);
    putpixel(x1+y,768-y11+x,4);
    putpixel(x1-y,768-y11+x,4);
    putpixel(x1+y,768-y11-x,4);
    putpixel(x1-y,768-y11-x,4);
  }
}

void lingkaranout(int x1, int y11, int r)
{

  //Algoritma Lingkaran Bressenham
  int p = 1 - r;
  int ddF_x = 1;
  int ddF_y = -2 * r;
  int x = 0;
  int y = r;

  printf("X = %d , Y = %d",x1, y11 + r);
  printf("X = %d , Y = %d",x1, y11 - r);
  printf("X = %d , Y = %d",x1+r, y11);
  printf("X = %d , Y = %d",x1 - r, y11);



  while(x < y)
  {
    if(p >= 0)
    {
      y--;
      ddF_y += 2;
      p += ddF_y;
    }
    x++;
    ddF_x += 2;
    p += ddF_x;
    printf("X = %d , Y = %d",x1+x,768-y11+y);
    printf("X = %d , Y = %d",x1-x,768-y11+y);
    printf("X = %d , Y = %d",x1+x,768-y11-y);
    printf("X = %d , Y = %d",x1-x,768-y11-y);
    printf("X = %d , Y = %d",x1+y,768-y11+x);
    printf("X = %d , Y = %d",x1-y,768-y11+x);
    printf("X = %d , Y = %d",x1+y,768-y11-x);
    printf("X = %d , Y = %d",x1-y,768-y11-x);

  }
}

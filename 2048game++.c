#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

int score=0;
int globalcounter=0;
COORD coord= {0,0};
int a[5][5]= {0,0,0,0,0,
              0,0,0,0,0,
              0,0,0,0,0,
              0,0,0,0,0,
              0,0,0,0,0
             };
int chhheck[5][5] = {0,0,0,0,0,
                     0,0,0,0,0,
                     0,0,0,0,0,
                     0,0,0,0,0,
                     0,0,0,0,0
                    };
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void draw_board()
{
    int j;

    for(j=9; j<24; j++)
    {
        gotoxy(28,j);
        printf("|     |     |     |     |     |");
    }
    gotoxy(28,8);
    printf("-------------------------------");
    gotoxy(28,11);
    printf("-------------------------------");
    gotoxy(28,14);
    printf("-------------------------------");
    gotoxy(28,17);
    printf("-------------------------------");
    gotoxy(28,20);
    printf("-------------------------------");
    gotoxy(28,23);
    printf("-------------------------------");
//31, 37, 43, 49, 55 are x coordinates
//10, 13, 16, 19, 22 are y coordinates
}

void menu()
{
    int choice;
    system("cls");
    printf("\n-----------MENU-----------");
    printf("\n1 : Play 2048 Game [Use Arrow Keys to Swipe]");
    printf("\n2 : Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        break;
    case 2:
        exit(1);
    default:
        menu();
    }
}

void goup()
{
    for(int i=0; i<5; i++)
    {
        for(int j=1; j<5; j++)
        {
            if(a[j][i] != 0)
            {
                for(int k=j-1; k>=0; k--)
                {
                    if(a[k][i] != 0 || k==0)
                    {
                        if(a[j][i] != a[k][i] && a[k][i]==0)
                        {
                            a[k][i]=a[j][i];
                            a[j][i]=0;
                        }
                        else if(a[j][i] != a[k][i] && a[k][i]!=0)
                        {
                            a[k+1][i]=a[j][i];
                            if((k+1)!=j)
                            {
                                a[j][i]=0;
                            }
                        }
                        else if(a[j][i] == a[k][i])
                        {
                            a[k][i]= (2*a[j][i]);
                            a[j][i]=0;
                            score += a[k][i];
                        }
                        break;
                    }
                }
            }
        }

    }
}



void godown()
{
    for(int i=0; i<5; i++)
    {
        for(int j=3; j>=0; j--)
        {
            if(a[j][i] != 0)
            {
                for(int k=j+1; k<=4; k++)
                {
                    if(a[k][i] != 0 || k==4)
                    {
                        if(a[j][i] != a[k][i] && a[k][i]==0)
                        {
                            a[k][i]=a[j][i];
                            a[j][i]=0;
                        }
                        else if(a[j][i] != a[k][i] && a[k][i]!=0)
                        {
                            a[k-1][i]=a[j][i];
                            if((k-1)!=j)
                            {
                                a[j][i]=0;
                            }
                        }
                        else if(a[j][i] == a[k][i])
                        {
                            a[k][i]= (2*a[j][i]);
                            a[j][i]=0;
                            score += a[k][i];
                        }
                        break;
                    }
                }
            }
        }

    }
}

void goleft()
{
    for(int j=0; j<5; j++)
    {
        for(int i=1; i<5; i++)
        {
            if(a[j][i] != 0)
            {
                for(int k=i-1; k>=0; k--)
                {
                    if(a[j][k] != 0 || k==0)
                    {
                        if(a[j][i] != a[j][k] && a[j][k]==0)
                        {
                            a[j][k]=a[j][i];
                            a[j][i]=0;

                        }
                        else if(a[j][i] != a[j][k] && a[j][k]!=0)
                        {
                            a[j][k+1]=a[j][i];
                            if((k+1)!=i)
                            {
                                a[j][i]=0;
                            }
                        }
                        else if(a[j][i] == a[j][k])
                        {
                            a[j][k]= (2*a[j][i]);
                            a[j][i]=0;
                            score += a[j][k];
                        }
                        break;
                    }
                }
            }
        }

    }
}


void goright()
{
    for(int j=0; j<5; j++)
    {
        for(int i=3; i>=0; i--)
        {
            if(a[j][i] != 0)
            {
                for(int k=i+1; k<=4; k++)
                {
                    if(a[j][k] != 0 || k==4)
                    {
                        if(a[j][i] != a[j][k] && a[j][k]==0)
                        {
                            a[j][k]=a[j][i];
                            a[j][i]=0;

                        }
                        else if(a[j][i] != a[j][k] && a[j][k]!=0)
                        {
                            a[j][k-1]=a[j][i];
                            if((k-1)!=i)
                            {
                                a[j][i]=0;
                            }
                        }
                        else if(a[j][i] == a[j][k])
                        {
                            a[j][k]= (2*a[j][i]);
                            a[j][i]=0;
                            score += a[j][k];
                        }
                        break;
                    }
                }
            }
        }

    }
}

void printscore()
{
    gotoxy(56,7);
    printf("Score : %d",score);
}

int printnumbers()
{
    int x=31;
    int y=10;
    for(int r=0; r<5; r++)
    {
        for(int c=0; c<5; c++)
        {
            gotoxy(x,y);
            if(a[r][c]!=0)
            {
                printf("%d",a[r][c]);
            }
            x+=6;
        }
        x=31;
        y+=3;
    }
}

int random()
{
    int ab;
    int c;
    int twofour[]= {2,4};
    srand(time(0));

    c=rand();
    ab=twofour[c%2];
    return ab;
}

void randomspace()
{
//31, 37, 43, 49, 55 are x coordinates
//10, 13, 16, 19, 22 are y coordinates
    struct position
    {
        int i;
        int j;
    };
    struct position p[25];
    int k=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(a[i][j]==0)
            {
                p[k].i=i;
                p[k].j=j;
                k++;
            }
        }
    }
    int c,r;
    srand(time(0));

    c=rand();
    r=c%k;
    int u=p[r].i;
    int v=p[r].j;
    int x= random();
    a[u][v]=x;
}

int check()
{
    int c=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(a[i][j]==2048)
            {
                gotoxy(30,28);
                printf("\n  YOU WIN!!  \n");
                exit(2);
            }
            if(a[i][j] != 0)
            {
                c++;
            }
        }
    }
    if(c==25)
    {
        gotoxy(30,30);
        printf("\n GAME OVER! TRY AGAIN... \n");
        exit(3);
    }
    return 1;
}


void game()
{
    int key;
    while (1)
    {
        if(kbhit())
        {
            key = getch();
            if(key == 224)
            {
                do
                {
                    key = getch();
                }
                while(key == 224);
                switch(key)
                {
                case 72:
                    goup();
                    break;
                case 75:
                    goleft();
                    break;
                case 77:
                    goright();
                    break;
                case 80:
                    godown();
                    break;
                default:
                    printf("\nOther Key");
                }
            }
            break;
        }
    }
}
int prevcheck()
{
    int i,j,c=0;
    if(globalcounter == 0)
    {
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                chhheck[i][j] = a[i][j];
            }
        }
        globalcounter++;
        return(1);
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(chhheck[i][j] != a[i][j])
            {
                c+=1;
            }
        }
    }

    if(c!=0)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}

updateofarray()
{
    int i,j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            chhheck[i][j] = a[i][j];
        }
    }
}

int main()
{
    menu();
    system("cls");
    draw_board();
    srand(time(0));
    randomspace();
    randomspace();
    printnumbers();
    printscore();
    while(check())
    {
        game();
        system("cls");
        if(prevcheck())
        {
            randomspace();
            updateofarray();
        }
        draw_board();
        printnumbers();
        printscore();
    }
    system("pause");
    printf("\n\n\n\n");
    return 0;
}

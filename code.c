#include <stdio.h>
#include <stdlib.h>
void main_game_function();//it is entry function of game
char player_1[100],player_2[100];//this two array holds the names of two players
void display(char b[9]);//to display the boxes,user info etc
void input(char *q,int j);//this helps to take the place(which have to filled with his symbol in gaming box) input from the user
void check(char *r,char symb,char *name,int *p);//it checks condition that, whether any player won the match

int main()
{
    main_game_function();//it is entry function of game

}

void main_game_function()
{
    char a[9]={'1','2','3','4','5','6','7','8','9'};//in this array the char are modified to particular symbol at particular place(which is taken by users)
    display(a);
}
void display(char* b)
{
    printf("\t\t\t\t T I C    T O C   T O E \n");//To print the headline of game
    printf("\t\t\t\t`````````````````````````` \n");
    printf("enter the name of player 1\n");
    scanf("%s",player_1);//where player_1 is char array which is defined earlier
    printf("enter the name of player 2\n");
    scanf("%s",player_2);//where player_1 is char array which is defined earlier
    printf("SYMBOL FOR %s: %c\n",player_1,'X');//To print the symbol for player 1
    printf("SYMBOL FOR %s: %c\n",player_2,'O');//To print the symbol for player 2
    printf("\t\t\t\t       |       |       \n");
    printf("\t\t\t\t   %c   |   %c   |   %c   \n",b[0],b[1],b[2]);
    printf("\t\t\t\t ------|-------|-------\n");                    //to display the boxes
    printf("\t\t\t\t       |       |       \n");
    printf("\t\t\t\t   %c   |   %c   |   %c   \n",b[3],b[4],b[5]);
    printf("\t\t\t\t ------|-------|-------\n");
    printf("\t\t\t\t       |       |       \n");
    printf("\t\t\t\t   %c   |   %c   |   %c   \n",b[6],b[7],b[8]);


    int i=1;//this is the variable which counts the no of input taken from user(that means count should not more than 9 times)
    while (i !=10)
    {
        if (i%2==1)
        {
            printf("ENTER THE PLACE (%s) : ",player_1);
            input(b,i);//function call
            i++;
            check(b,'X',player_1,&i);//to check whether any player won the match
        }
        else
        {
            printf("ENTER THE PLACE (%s) : ",player_2);
            input(b,i);//function call
            i++;
            check(b,'O',player_2,&i);//to check whether any player won the match
        }
    }
}
void input(char *q,int j)
{
    int place;//this variable helps to store the place which is given by players
    if (j%2 == 1)//this if loop runs only when we have asks input from the player_1
    {
        scanf("%d",&place);
        if ( place>9 || q[place-1]=='X' || q[place-1]=='O')//this if loop removes the extension of input places
        {//here we take index as place-1 because index of array starts from 0
            printf("invalid place\n");
            printf("ENTER THE PLACE (%s) : ",player_1);
            input(q,j);
        }
        else
        {
            q[place-1]='X';
            printf("\n");
            printf("\t\t\t\t       |       |       \n");
            printf("\t\t\t\t   %c   |   %c   |   %c   \n",q[0],q[1],q[2]);
            printf("\t\t\t\t ------|-------|-------\n");                    //this modifies(fills with symbol) and display the boxes
            printf("\t\t\t\t       |       |       \n");
            printf("\t\t\t\t   %c   |   %c   |   %c   \n",q[3],q[4],q[5]);
            printf("\t\t\t\t ------|-------|-------\n");
            printf("\t\t\t\t       |       |       \n");
            printf("\t\t\t\t   %c   |   %c   |   %c   \n",q[6],q[7],q[8]);
        }

    }
    else
    {
        scanf("%d",&place);//this if loop runs only when we have asks input from the player_2
        if ( place>9 || q[place-1]=='X' || q[place-1]=='O')//this if loop removes the extension of input places
        {
            printf("invalid place\n");
            printf("ENTER THE PLACE (%s) : ",player_2);
            input(q,j);
        }
        else
        {
            q[place-1]='O';
            printf("\n");
            printf("\t\t\t\t       |       |       \n");
            printf("\t\t\t\t   %c   |   %c   |   %c   \n",q[0],q[1],q[2]);
            printf("\t\t\t\t ------|-------|-------\n");                    //this modifies and display the boxes
            printf("\t\t\t\t       |       |       \n");
            printf("\t\t\t\t   %c   |   %c   |   %c   \n",q[3],q[4],q[5]);
            printf("\t\t\t\t ------|-------|-------\n");
            printf("\t\t\t\t       |       |       \n");
            printf("\t\t\t\t   %c   |   %c   |   %c   \n",q[6],q[7],q[8]);
        }

    }
}
void check(char *r,char symb,char *name,int *p)
{
    for (int k=0;k<7;)
    {
        if (r[k]==symb && r[k+1]==symb && r[k+2]==symb)//it checks the winning condition in row wise
        {
            printf("\n\n\t\t\t\t\t\t G A M E   O V E R\n");
            printf("\n\n\t\t\t\t\t\t  T H E   W I N N E R    I S   %s \n\n",name);//where name is player name
            *p=10;//where p holds the address of i. it is assigned to 10, because this value brakes the while loop present in main_gaming_function
        }
        k+=3;
    }
    for (int k=0;k<3;k++)
    {
        if (r[k]==symb && r[k+3]==symb && r[k+6]==symb)//it checks the winning condition in column wise
        {
            printf("\n\n\t\t\t\t\t\t G A M E   O V E R\n");
            printf("\n\n\t\t\t\t\t\t  T H E   W I N N E R    I S   %s \n\n",name);
            *p=10;
        }
    }
    if (r[0]==symb && r[4]==symb && r[8]==symb)//this checks the winning condition in corner to another corner
    {
        printf("\n\n\t\t\t\t\t\t G A M E   O V E R\n");
        printf("\n\n\t\t\t\t\t\t  T H E   W I N N E R    I S   %s \n\n",name);
        *p=10;
    }

    if (r[2]==symb && r[4]==symb && r[6]==symb)//this checks the winning condition in corner to another corner
    {
        printf("\n\n\t\t\t\t\t\t G A M E   O V E R\n");
        printf("\n\n\t\t\t\t\t\t  T H E   W I N N E R    I S   %s \n\n",name);
        *p=10;
    }
}

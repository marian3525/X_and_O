#include <iostream>
//#include <unistd.h>
using namespace std;

char a[8][8],player0_char='O',player1_char='X';

bool full()
{
    int c=0;
    for(int i=2;i<=6;i+=2)
        for(int j=2;j<=6;j+=2)
            if(a[i][j]!=' ')
                c++;
    if(c==9)
        return true;
    return false;
}

void draw()
{

    a[1][1]='+';

    for(int j=2;j<=6;j++)
        a[1][j]='-';

    a[1][7]='+';

    a[2][1]=a[2][3]=a[2][5]=a[2][7]='|'; a[2][2]=a[2][4]=a[2][6]=' ';

    a[3][1]=a[3][7]='|'; a[3][2]=a[3][4]=a[3][6]='-'; a[3][3]=a[3][5]='+';

    a[4][1]=a[4][3]=a[4][5]=a[4][7]='|';    a[4][2]=a[4][4]=a[4][6]=' ';

    a[5][1]=a[5][7]='|'; a[5][2]=a[5][4]=a[5][6]='-'; a[5][3]=a[5][5]='+';

    a[6][1]=a[6][3]=a[6][5]=a[6][7]='|'; a[6][2]=a[6][4]=a[6][6]=' ';

    a[7][1]=a[7][7]='+';

    for(int j=2;j<=6;j++)
        a[7][j]='-';

    for(int i=1;i<=7;i++)
        {
            for(int j=1;j<=7;j++)
                cout<<a[i][j];
            cout<<endl;
        }
}


char check()
{

    if(a[2][2]=='X' && a[2][4]=='X' && a[2][6]=='X' && a[2][2]!=' ')
        return a[2][2];

    if(a[2][2]=='O' && a[2][4]=='O' && a[2][6]=='O' && a[2][2]!=' ')
        return a[2][2];

    if(a[4][2]=='X' && a[4][4]=='X' && a[4][6]=='X' && a[4][2]!=' ')
        return a[4][2];

    if(a[4][2]=='O' && a[4][4]=='O' && a[4][6]=='O' && a[4][2]!=' ')
        return a[4][2];

    if(a[6][2]=='X' && a[6][4]=='X' && a[6][6]=='X' && a[6][2]!=' ')
        return a[6][2];

    if(a[6][2]=='O' && a[6][4]=='O' && a[6][6]=='O' && a[6][2]!=' ')
        return a[6][2];

    if(a[2][2]=='X' && a[4][2]=='X' && a[6][2]=='X' && a[2][2]!=' ')
        return a[2][2];

    if(a[2][2]=='O' && a[4][2]=='O' && a[6][2]=='O' && a[2][2]!=' ')
        return a[2][2];

    if(a[2][4]=='X' && a[4][4]=='X' && a[6][4]=='X' && a[2][4]!=' ')
        return a[2][4];

    if(a[2][4]=='O' && a[4][4]=='O' && a[6][4]=='O' && a[2][4]!=' ')
        return a[2][4];

    if(a[2][6]=='X' && a[4][6]=='X' && a[6][6]=='X' && a[2][6]!=' ')
        return a[2][6];

    if(a[2][6]=='O' && a[4][6]=='O' && a[6][6]=='O' && a[2][6]!=' ')
        return a[2][6];

    if(a[2][2]=='X' && a[4][4]=='X' && a[6][6]=='X' && a[2][2]!=' ')
        return a[2][2];

    if(a[2][2]=='O' && a[4][4]=='O' && a[6][6]=='O' && a[2][2]!=' ')
        return a[2][2];

    if(a[2][6]=='X' && a[4][4]=='X' && a[6][2]=='X' && a[2][6]!=' ')
        return a[2][6];

    if(a[2][6]=='O' && a[4][4]=='O' && a[6][2]=='O' && a[2][6]!=' ')
        return a[2][6];

    return 'c';
}

void update(int i,int j,char value)
{
    if(a[i][j]==' ')
        a[i][j]=value;

    for(int i=1;i<=7;i++)
        {
            for(int j=1;j<=7;j++)
                cout<<a[i][j];
            cout<<endl;
        }

}

bool valid(int i,int j)
{
    if(j==2 or j==4 or j==6)
        if(i==2 or i==4 or i==6)
            return true;
    return false;
}

void user_input(int &i, int &j)
{
    int value;
    cin>>value;

    switch(value)
    {
        case 1: {i=6,j=2;break;}
        case 2: {i=6,j=4;break;}
        case 3: {i=6,j=6;break;}

        case 4: {i=4,j=2;break;}
        case 5: {i=4,j=4;break;}
        case 6: {i=4,j=6;break;}

        case 7: {i=2,j=2;break;}
        case 8: {i=2,j=4;break;}
        case 9: {i=2,j=6;break;}

        i=0,j=0;
    }
}


int main()
{
    bool player=0,cont;;
    int i,j;
    draw();

start:
        int scoreO=0,scoreX=0;

    do
    {
            player=!player;
            cout<<"PLAYER "<<player<<" :"<<endl;
            user_input(i,j);

            if(player==0)
                update(i,j,player0_char);
            if(player==1)
                update(i,j,player1_char);
            cout<<check()<<endl;
    }
    while(check()=='c' && full()==false);

    if(full()==true && check()=='c')
        cout<<"DRAW!"<<endl;
    else
        if(player==0)
        {
            cout<<"Player O won!"<<endl;
            scoreO++;
        }
        else
        {
            cout<<"Player X won!"<<endl;
            scoreX++;
        }
    cout<<"Play again?"<<endl;
    cin>>cont;
        if(cont==1)
            goto start;
        else
            cout<<"SCORES: "<<endl;
            cout<<"X won "<<scoreX<<" times"<<endl;
            cout<<"O won "<<scoreO<<" tines"<<endl;
        if(scoreX>scoreO)
            cout<<"X is the real winner!!!"<<endl;
        if(scoreO>scoreX)
            cout<<"O is the real winner!!!"<<endl;
        if(scoreX==scoreO)
            cout<<"In the end, there is no winner :("<<endl;
    return 0;
}

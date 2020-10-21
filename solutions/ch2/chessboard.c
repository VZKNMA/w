#include <stdio.h>

char chess[8][8];

void initialchessboard(char chess[8][8]);
void showchessboard(char chess[8][8]);
void main()
{
    initialchessboard(chess);
    showchessboard(chess);
}

void showchessboard(char chess[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%c\t",chess[i][j]);
            if (j==7) printf("\n\n\n");
        }
    }
}

void initialchessboard(char chess[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
           /* if(i==2||i==3||i==4||i==5)
                chess[i][j]="-";
            elseif(i==1)
                chess[i][j]="P";
            elseif

            there is a difference between if and switch so I choose switch
两者本质的区别是 if-else语句更适合于对区间（范围）的判断，而switch语句更适合于对离散值的判断
switch用来根据一个整型值进行多路分支，并且编译器可以对多路分支进行优化，所以在多路分支时用switch比if..else if .. else结构要效率高。
            */
            switch(i)
            {
                case 0: 
                    {
                        chess[i][0]='R';
                        chess[i][7]='R';
                        chess[i][1]='N';
                        chess[i][6]='N';
                        chess[i][2]='B';
                        chess[i][5]='B';
                        chess[i][3]='Q';
                        chess[i][4]='K';
                        break;
                    }
                case 1: chess[i][j]='P'; break;
                case 6: chess[i][j]='P'; break;
                case 2: case 3: case 4: case 5:
                        chess[i][j]='-'; break;
                case 7: 
                    {
                        chess[i][0]='r';
                        chess[i][7]='r';
                        chess[i][1]='n';
                        chess[i][6]='n';
                        chess[i][2]='b';
                        chess[i][5]='b';
                        chess[i][3]='q';
                        chess[i][4]='k';
                        break;
                    }
            }
        }
    }

}

#include <stdio.h>
#include <stdlib.h>

void visit(int, int);
//由下面的入口和出口坐标可知迷宫的四周都是墙，和平常的迷宫含义不同，注意区别
int maze[9][9] = {{2, 2, 2, 2, 2, 2, 2, 2, 2},
                  {2, 0, 0, 0, 0, 0, 0, 0, 2},
                  {2, 0, 2, 2, 0, 2, 2, 0, 2},
                  {2, 0, 2, 0, 0, 2, 0, 0, 2},
                  {2, 0, 2, 0, 2, 0, 2, 0, 2},
                  {2, 0, 0, 0, 0, 0, 2, 0, 2},
                  {2, 2, 0, 2, 2, 0, 2, 2, 2},
                  {2, 0, 0, 0, 0, 0, 0, 0, 2},
                  {2, 2, 2, 2, 2, 2, 2, 2, 2}
};
int startI = 1, startJ = 1; // 入口
int endI = 7, endJ = 7; // 出口

int main(void)
{
    int i, j;
    printf("显示迷宫： \n");
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
            if(maze[i][j] == 2)
                printf("■");//这个字符代表墙壁，自己可以换
            else
                printf("□");//这个字符代表空地，自己可以换
        printf("\n");
    }
    visit(startI, startJ);
    int qwer;
    scanf("%d",&qwer);
    return 0;
}

void visit(int i, int j)
{
    int m, n;
    maze[i][j] = 1;
    if(i == endI && j == endJ)
    {
        printf("\n 显示路径： \n");
        for(m = 0; m < 9; m++)
        {
            for(n = 0; n < 9; n++)
                if(maze[m][n] == 2)
                    printf("■");//这个字符代表墙壁，自己可以换
                else if(maze[m][n] == 1)
                    printf("☆");//这个字符代表路径，自己可以换
                else
                    printf("□");//这个字符代表空地，自己可以换
            printf("\n");
        }
    }
    if(maze[i][j+1] == 0) visit(i, j+1);
    if(maze[i+1][j] == 0) visit(i+1, j);
    if(maze[i][j-1] == 0) visit(i, j-1);
    if(maze[i-1][j] == 0) visit(i-1, j);
    maze[i][j] = 0;
}



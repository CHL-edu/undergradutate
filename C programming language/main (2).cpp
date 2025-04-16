#include<stdio.h>
int main()
{
    int N;
    int M;
    scanf("%d%d",&N,&M);
    int Guss;
    scanf("%d",&Guss);
    int doM = 1;
    while(Guss >=0&&doM<=M)
    {
        if(Guss > N)
            printf("Too big\n");
        else
            if(Guss <N)
                printf("Too small\n");
            else
                {
                if(doM == 1)
                    printf("Bingo!\n");
                if(doM>1&&doM<=3)
                    printf("Lucky You!\n");
                if(doM>3)
                    printf("Good Guess!\n");
                        return 0;
                 }
        scanf("%d",&Guss);
        doM++;
    }
    if(Guss<0||doM == M+1)
        printf("Game Over\n");
    return 0;
}

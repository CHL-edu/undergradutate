#include<stdio.h>
int main ()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    
    int max_row;
    int min_col;
    int row = 0;
    int col;
    for(int i = 0;i < n;i++)
        for(int j = 0; j< n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    if(n==1)
        printf("0 0");
    while(row < n)
    {
        int Frow;
        max_row = a[row][0];
        for(int j = 0; j< n; j++)
            {
                if(max_row <= a[row][j])
                    max_row = a[row][j];
            }
        for(int j = 0; j< n; j++)
            {
                if(max_row == a[row][j])
                    col = j;
            }
        min_col = a[0][col];
        for(int j = 0; j< n; j++)
            {
                if(min_col >= a[j][col])
                    min_col = a[j][col];
            }
        for(int j = 0; j< n; j++)
            {
                if(min_col == a[j][col])
                    Frow = j;
            }
        if(Frow == row)
        {
            printf("%d %d",row, col);
            return 0;
        }
        row++;
    }
    if(row == n);
    printf("NONE");
    return 0;
}

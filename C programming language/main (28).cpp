/* ��������ɾ�Ĳ���� */
#include<stdio.h>
#define MAXN 10000    /* ������ų�����ʾ����a�ĳ��� */

int Count = 0;        /* ��ȫ�ֱ���Count��ʾ����a�д������Ԫ�ظ��� */
void select(int a[], int option, int value); /* ��������������a���к��ֲ����Ŀ��ƺ��� */
int input_array(int a[ ]);    /* ������������a�ĺ��� */
void print_array(int a[ ]);    /* �����������a�ĺ��� */
int insert(int a[ ], int value);    /* ����������a�в���һ��ֵΪvalue��Ԫ�صĺ��� */
int del(int a[ ], int value);    /* ɾ����������a�е���value��Ԫ�صĺ��� */
int modify(int a[ ], int value1, int value2); /* ����������a�е���value1��Ԫ�أ��滻Ϊvalue2 */ 
int query(int a[ ], int value);     /* �ö��ַ�����������a�в���Ԫ��value�ĺ��� */

int main(void) 
{
   int option, value, a[MAXN];

    if(input_array(a) == -1){     /* ���ú��������������� a */
         printf("Error");        /* a�����������飬�������Ӧ����Ϣ */
         return 0;
    }

    printf("[1] Insert\n");    /* ����4����ʾ�˵�*/
    printf("[2] Delete\n");
    printf("[3] Update\n");
    printf("[4] Query\n");
    printf("[Other option] End\n");
    while (1) {            /* ѭ�� */
        scanf("%d", &option);         /* �����û�����ı�� */
        if (option < 1 || option > 4) {    /* �������1��2��3��4����ı�ţ�����ѭ�� */
            break;
        }
        scanf("%d", &value);         /* �����û�����Ĳ���value */
        select(a, option, value);         /* ���ÿ��ƺ��� */
        printf("\n");
    }
    printf("Thanks.");            /* �������� */

    return 0;
}

/* ���ƺ��� */
void select(int a[ ], int option, int value) 
{
    int index, value2;

    switch (option) {
        case 1:
            index = insert(a, value);      /* ���ò��뺯������������ a �в���Ԫ��value */
            if(index == -1){        /* ���������Ѵ��ڣ��������Ӧ����Ϣ */
                printf("Error");
            }else{                        
                print_array(a);        /* ������������������������������a */
            }
            break;
        case 2:
            index = del(a, value);      /* ����ɾ���������������� a ��ɾ��Ԫ��value */
            if(index == -1){        /* û�ҵ�value���������Ӧ����Ϣ */
                printf("Deletion failed.");
        }else{
            print_array(a);         /* ����������������ɾ�������������a */
        }
            break;
        case 3:
            scanf("%d", &value2);         /* �����û�����Ĳ���value2 */
            index = modify(a, value, value2);      /* �����޸ĺ������������� a ���޸�Ԫ��value��ֵΪvalue2 */
            if(index == -1){            /* û�ҵ�value����vaule2�Ѵ��ڣ��������Ӧ����Ϣ */
                printf("Update failed.");
            }else{
            print_array(a);         /* �����������������޸ĺ����������a */
            }
            break;
        case 4:
            index = query(a, value);     /* ���ò�ѯ�������������� a �в���Ԫ��value */
            if(index == -1){        /* û�ҵ�value���������Ӧ����Ϣ */
                printf( "Not found.");
            }else{            /* �ҵ����������Ӧ���±� */
            printf("%d", index);
            }
            break;
    }
}

/* ��������뺯�� */
int input_array(int a[ ]) 
{
    scanf("%d", &Count);
    for (int i = 0; i < Count; i ++) {
        scanf("%d", &a[i]);
        if(i > 0 && a[i] <= a[i-1]){    /* a������������ */
            return -1;
        }
    }

    return 0;
}

/* ������������ */
void print_array(int a[ ]) 
{
    for (int i = 0; i < Count; i ++) { /* ���ʱ�������ּ���һ���ո�ֿ�����ĩ�޿ո� */
        if(i == 0){     
           printf("%d", a[i]);
        }else{
           printf(" %d", a[i]);
        }
    }
}

/* ����������д�� */


int insert(int a[ ], int value)
{
    int i, t;

    for(i=0;i<Count;i++)
    {
        if(a[i]==value)
        {
            return -1;
        }
        else if(a[i]>value)
            break;
    }
    t=i;
    Count++;
    for(i=Count-1;i>=t;i--)
    {
        a[i+1]=a[i];
    }
    a[t]=value;
}



int del(int a[ ], int value)
{
    int k = 0;
    int b[Count+1];
    int flag = 0;
    
    for(k = 0;k<Count;k++)
        b[k] = a[k];
    
    for( k = 0;k<Count;k++)
    {
        if(a[Count-1] == value)
        {
            flag =1;
        }
        if(a[k] == value)
            for(int m = 0; m<Count-k; m++)
                a[k+m]= b[k+m+1];
    }
    if(k == Count&&flag ==1)
    	Count--;
    if(k == Count&&flag !=1)
        return -1;
}


int modify(int a[ ], int value1, int value2)
{
    int k = 0;
    int n = 0;
    for( k = 0;k<Count;k++)
    {
        if(a[k] == value2)
            return -1;
        if(a[k] != value1)
            n++;
    }
    
    if(n == Count)
        return -1;
    
    for( k = 0;k<Count;k++)
    {
        if(a[k] == value1)
            a[k] = value2;
    }

}

int query(int a[ ], int value)
{

    int k = 0;
    for( k = 0;k<Count;k++)
    {
        if(a[k] == value)
            printf("%d",k);
    }
    if(k == Count)
        return -1; 
    return 0;

}




























#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bookstore.h"
#define FILE_NAME_MAX 50
#define SEPERATE_STRING_MAX 100
struct code{
	char IDnum[8];
	char codenum[8];
	struct code *Next;
};

struct allhistory{
	char IDname[8];
	char bookname[20];
	char borrowtime[10];
	char condition[1];
	struct allhistory *Next;
};


struct book_information{
	char name[20];
	char cata[35];
	int borrow;
	struct book_information* Next;
};


int main()
{
	int who=0;
	who=intosystem();
	if(who==1)
	{
		reader();
	}
	if(who==2)
	{
		administrater();
	}
	if(who==3)
	{
		return 0;
	}
	printf("ллʹ��\n");
	return 0;
 } 
 
 
 
 

int intosystem()
{
	char use1[10];
	int Id_num=0,Code_num=0;
	printf("\t\t\t\t��**ӭ**ʹ**��**��**��**ͼ**��**��**��**ϵ**ͳ\n\n\t\t\t\t����ʹ���밴1��\n\t\t\t\t�˳��밴2��\n");
	gets(use1);
	char x[8];
	char y[8];
	if((strlen(use1)==1)&&2==use1[0]-'0')		
			{
				return 3;
			}
			
	if((strlen(use1)==1)&&1==use1[0]-'0')
		{
			printf("\n\n");
			printf("\t*******************************\n");
			printf("\t********* �û���¼ϵͳ *********\n");
			printf("\t*******************************\n");
			printf("\n\n");
			
			printf("\tPlease enter username.\n");	
			loop2:
			printf("\tId-num:");
			int i = 0;
			for(i = 0;i<8;i++)
			{
			Id_num*=10;
			scanf("%c",&x[i]);
			if(x[i]=='\n')
			{
			scanf("%c",&x[i]);
			 } 
			if(x[i]>='0'&&x[i]<='9')
			Id_num+=x[i]-'0';
			else
			{
			printf("������������������밴1��\n�˳��밴2��\n");
			char m[8];
			gets(m);
			char j=0;
			scanf("%c",&j);
			if(j==49)
			goto loop2;
			if(j==50)
			return 3;
			}
			}
			if(i!=8)
			return 3;
			
			loop1:
			printf("\tCode-num:");
			for(i = 0;i<8;i++)
			{
			Code_num*=10;
			scanf("%c",&y[i]);
			if(y[i]=='\n')
			{
			scanf("%c",&y[i]);
			 } 
			if(y[i]>='0'&&y[i]<='9')
			Code_num+=y[i]-'0';
			else
			{
			printf("������������������밴1��\n�˳��밴2��\n");
			char m[8];
			gets(m);
			char j=0;
			scanf("%c",&j);
			if(j==49)
			goto loop1;
			if(j==50)
			return 3;
			}
			}
			if(i!=8)
			return 3;
		}
		int flag=0; 
		flag = checkcode(x,y);//�ж���Ϊ����Ա  1���Ƕ���  2���ǲ���  3 
		if(flag==1) 
		{
			printf("��ӭ����\n");
			return 1;
		}		
		if(flag==2) 
		{
			printf("��ӭ����Ա\n");
			return 2;
		}	
		if(flag==3) 
		{
			printf("�㲻���ڱ�ϵͳ\n���������밴1��\n�˳��밴2��\n");		
			int j=0;
			scanf("%d",&j);
			if(j==1)
			goto loop2;
			if(j==2)
			return 3;
		}	
		else
			{
			printf("������������������밴1��\n�˳��밴2��\n");
			int j=0;
			scanf("%d",&j);
			if(j==1)
			goto loop2;
			if(j==2)
			return 3;	
			}				
		}
		
int checkcode(char a[8],char b[8])
{
	FILE *fp;
	fp = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt","r");
	char mtemp[18];
	char Idtemp[8];
	char codenum[8];
	int i=1;
	//��ȡ���ݿ����� 
		struct code *firstcode; 
		firstcode = (struct code*)malloc(sizeof(struct code));
		struct code *Head;
		Head = (struct code*)malloc(sizeof(struct code));
		Head->Next = NULL;
		firstcode = Head;
		struct code *Nfirstcode; 
	while(	fgets(mtemp,18,fp)!=NULL)
	{
		if(i%2!=0)	
		{
		for(int j = 0;j<8;j++)
		Idtemp[j] = mtemp[j];
		
		for(int j = 0;j<8;j++)
		codenum[j]= mtemp[9+j];
				Nfirstcode = (struct code*)malloc(sizeof(struct code));
				strcpy(Nfirstcode->IDnum,Idtemp);
				strcpy(Nfirstcode->codenum,codenum);				
				Nfirstcode->Next=NULL; 
				firstcode->Next = Nfirstcode;
				firstcode = Nfirstcode;
		
			}
			i++;
	} 
	fclose(fp);
	struct code *iswhotemp; 
	iswhotemp = Head->Next;
	//�жϵ�½��Ա
	int iswho = 0;
	 for(int j = 0;iswhotemp->IDnum!=NULL;j++)
	 {
	 	int flag =0;
	 	int idisnum = 0;
	 	int codeisnum = 0;
	 	for(int i = 0;i<8;i++,idisnum++)
	 	if(iswhotemp->IDnum[i]!=a[i])
	 	break;
	 	for(int i = 0;i<8;i++,codeisnum++)
	 	if(iswhotemp->codenum[i]!=b[i])
	 	break;
	 	if(idisnum == 8&&codeisnum == 8)
		{
			if(iswhotemp->IDnum[0]=='1')
			return 1;			
			if(iswhotemp->IDnum[0]=='2')
			return 2;			
		}
		iswhotemp = iswhotemp->Next;
	 }
	 return 3;
 } 
 
 
 
void reader()
{
	while(1)
	{
	
		int n;
		printf("\n\n��ӭʹ��ͼ���ϵͳ\n\t�����밴1\n\t�鼮�����밴2\n\t��ʷ��¼�밴3\n\t�˳��밴4\n");
		scanf("%d",&n);
		if(n==1)
		{ returnbook();
		printf("����ɹ�\n"); 
		}
		else
		if(n==2){
			Recommendbook();
		}
		else	
		if(n==3){
			showallhistory();
		}
		else
		break; 
	}
}
 
 
void returnbook()
{
	char intoID[8];
	char intobookname[20];
	printf("��������ߺ�\n");
	gets(intoID);
	if(intoID[0]=='\0'||intoID[0]=='\n')
	gets(intoID);
	printf("�������鼮��\n"); 
	gets(intobookname);
	FILE *fp,*ft;
	fp = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database.txt","r");
	ft = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database temp.txt","wt+");
	int flag = 0;
	if(NULL == fp) 
	{
	printf("û��Ϣ\n");
    }
		struct allhistory *firstbook; 
		firstbook = (struct allhistory*)malloc(sizeof(struct allhistory));
		struct allhistory *Head;
		Head = (struct allhistory*)malloc(sizeof(struct allhistory));
		Head->Next = NULL;
		firstbook = Head;
		struct allhistory *Nfirstbook; 
	
    char temp[40];
    char IDnametemp[8];
	char booknametemp[20];
	char borrowtimetemp[11];
	char conditiontemp[1];
	int flag3 = 0;
    while(1){
    	fgets(temp,40,fp);
		if(temp[0]=='\0')
			break;
    		//��ֶ�ȡ 
    		int m = 0;
    		m  = strlen(temp);
    		if(temp[m-2]=='Y'||temp[m-2]=='N')
    		conditiontemp[0] = temp[m-2];
    		else
    		conditiontemp[0] = temp[m-1];
    		int j = 0;
    		for(j = 0;temp[j]!=' ';j++)
			IDnametemp[j] = temp[j];
			

			
			for(int i = 0;i<20;i++)
			booknametemp[i]='\0' ;
			int black= 0;
			int blackgo = 0;
			for(j = 0;j<40;j++)
			{
				if(temp[j] == ' '||temp[j] == '\t')
				black++;
				if(black >=1&&black<2)
				{
					booknametemp[blackgo] = temp[j];
					blackgo++;
					
				} 
			}
			
			
			for(int k = 0;k<20;k++)
			booknametemp[k]=booknametemp[k+1];

			for(int i = 0;booknametemp[20-i]>=0;i++)
			{
			booknametemp[20-i] ='\0';
			}
			
			black= 0;
			blackgo = 0;
			for(j = 0;j<40&&temp[j]!='\0';j++)
			{
				if(temp[j] == ' '||temp[j]=='\t')
				black++;
				if(black >=2&&black<3)
				{
					borrowtimetemp[blackgo] =temp[j];
					blackgo++;
				} 
			}
			
		
			
			//�γ����� 
				Nfirstbook = (struct allhistory*)malloc(sizeof(struct allhistory));
				strcpy(Nfirstbook->IDname,IDnametemp);
				strcpy(Nfirstbook->bookname,booknametemp);
				strcpy(Nfirstbook->borrowtime,borrowtimetemp);
				strcpy(Nfirstbook->condition,conditiontemp);
				int flag = 0;
				int flag2 = 0;
				for(int i = 0;i<8;i++,flag++)
				if(intoID[i]!=IDnametemp[i])
				break;	
				for(int i = 0;i<20&&booknametemp[i]!='\0'&&intobookname[i]!='\0';i++,flag2++)
				if(intobookname[i]!=booknametemp[i])
				break;	

				if(flag==8&&flag2 == strlen(intobookname)&&conditiontemp[0]=='N'){
				
					printf("�װ��Ķ���%s���ã�\n��������\t%s\t��\t%s \t�ս���\n",intoID,intobookname,borrowtimetemp);
					printf("�������ѽ�������\n");
					char x[1];
					scanf("%c",x);
					if(x[0]<='7')
					printf("����ɹ�\n");
					else
						printf("����ɷ���\n");
					for(int i = 0;i<8;i++)
					fprintf(ft,"%c",IDnametemp[i]);
					fprintf(ft," %s %s Y\n",booknametemp,borrowtimetemp);
					flag3 =1;					
				}
				else
				fprintf(ft,"%s",temp);
				
				Nfirstbook->Next=NULL; 
				firstbook->Next = Nfirstbook;
				firstbook = Nfirstbook;
				
			for(int i = 0;8>i;i++)
			{
			IDnametemp[i] ='\0';
			}				
			for(int i = 0;20>i;i++)
			{
			booknametemp[i]='\0';
			}						
			for(int i = 0;40>i;i++)
			{
			temp[i]='\0';
			}
			for(int i = 0;i<10;i++)
			borrowtimetemp[i]='\0';

	}
	
	fclose(fp);
	fclose(ft);
	
	
	remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database.txt");
	rename("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database temp.txt","C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database.txt");
	
	
	fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r");
	ft=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","wt+");
	
	
	if(flag3 == 1){
	
	while(1){
		char check[2]; 
    	char temp[55];
    	fgets(temp,55,fp);
    	if(check[0]==temp[10]&&check[1]==temp[13])
    		break;
    	else
    	{
    		check[0]=temp[10];
			check[1]=temp[13];
		}
		if(temp[0]=='\0'||temp[0]=='\n')
			break;
		char booknametemp[20];
		
		for(int i = 0;i<20;i++)
		booknametemp[i]='\0' ;
		
		int black = 0;
		int blackgo=0;
		for(int j = 0;j<55;j++)
		{
			if(temp[j] == ' '||temp[j] == '\t')
			black++;
			if(black<1)
			{
				booknametemp[blackgo++] = temp[j];		
			} 
		}
		int flag = 0;
		for(int i= 0;i<20&&intobookname[i]!='\0';i++,flag++)
		if(intobookname[i]!=booknametemp[i])
		break;
		
		if(flag == strlen(intobookname))
			{
				char foretemp[54];
				char num;
				for(int i=0;i<54;i++)
				foretemp[i] ='\0';
				int black1 = 0;
				int blackgo1 = 0;		
					for(int j = 0;j<55;j++)
				{
					if(temp[j] == ' '||temp[j] == '\t')
					black1++;
					if(black1<6)
						{
							foretemp[blackgo1++] = temp[j];		
						} 
				}
				int m= 0;
				m = strlen(temp);	
			if(temp[m-1] >='0'&&temp[m-1] <='9')
				num =temp[m-1];
			else
				num =temp[m-2];

			fprintf(ft,"%s %c\n",foretemp,num+1);
		}
			else
			fprintf(ft,"%s",temp);	
	}
	fclose(ft);
	fclose(fp);
}
	remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	rename("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	
 } 
 
int Recommendbook() {
	printf("\n\n��ӭʹ�ý��Ĺ���\n");
	showallbook(); 
	printf("\n\n\n�����밴1\n�Ƽ��밴2\n");
	int m = 0;
	int n = 0;
	scanf("%d", &m);
	switch(m){
		case 1:borrowbook();break;
		case 2:Recommendbookinner();borrowbook();break;
		default:break;
	}
	return 0;
}


void borrowbook(){
	FILE *fp,*fn,*fo;
	fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r");
	fn=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","wt+");
	fo=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database.txt","a+");
	
	
	printf("�����������һ����\n");
	char borrowbookname[20];
	gets(borrowbookname);
	if(borrowbookname[0]=='\n'||borrowbookname[0]=='\0')
	gets(borrowbookname);
	while(1){
		char check[2]; 
    	char temp[55];
    	fgets(temp,55,fp);
    	if(check[0]==temp[10]&&check[1]==temp[13])
    		break;
    	else
    	{
    		check[0]=temp[10];
			check[1]=temp[13];
		}
		if(temp[0]=='\0'||temp[0]=='\n')
			break;
		char booknametemp[20];
		char IDtemp[8];
		for(int i = 0;i<20;i++)
		booknametemp[i]='\0' ;
		
		int black = 0;
		int blackgo=0;
		for(int j = 0;j<55;j++)
		{
			if(temp[j] == ' '||temp[j] == '\t')
			black++;
			if(black<1)
			{
				booknametemp[blackgo++] = temp[j];		
			} 
		}
		int flag = 0;
		for(int i= 0;i<20&&borrowbookname[i]!='\0';i++,flag++)
		if(borrowbookname[i]!=booknametemp[i])
		break;
		
		if(flag == strlen(borrowbookname))
			{
				char foretemp[54];
				char num;
				for(int i=0;i<54;i++)
				foretemp[i] ='\0';
				int black1 = 0;
				int blackgo1 = 0;		
					for(int j = 0;j<55;j++)
				{
					if(temp[j] == ' '||temp[j] == '\t')
					black1++;
					if(black1<6)
						{
							foretemp[blackgo1++] = temp[j];		
						} 
				}
				int m= 0;
				m = strlen(temp);	
			if(temp[m-1] >='0'&&temp[m-1] <='9')
				num =temp[m-1];
			else
				num =temp[m-2];
			if(num=='0')
			{
				printf("���ڹ�ʣ��\n");
				break;
			}
			fprintf(fn,"%s %c\n",foretemp,num-1);
		}
			else
			fprintf(fn,"%s",temp);	
	}
		
			printf("������ID�ţ���ʱ�䣨ID xxxx.xx.xx��\n");
			char ttemp[20];
			for(int i =0;i<20;i++)
			ttemp[i]='\0';
			gets(ttemp);
			if(ttemp[0]=='\0'||ttemp[0]=='\n')
			gets(ttemp);
			char ttemp1[8];
			char ttemp2[11];
			for(int i =0;i<8;i++)
			ttemp1[i]=ttemp[i];
			int black2 = 0;
			int blackgo2= 0;
			for(int i =0;i<21&&ttemp[i]!='\0';i++)
			{
				if(ttemp[i]==' '||ttemp[i]=='\t')
				black2++;
				if(black2>=1)
				ttemp2[blackgo2++] =ttemp[i]; 
			}
			fprintf(fo,"\n");
			for(int i =0;i<8;i++)
			fprintf(fo,"%c",ttemp1[i]);
			fprintf(fo," %s",borrowbookname);
			for(int i =0;i<11;i++)
			fprintf(fo,"%c",ttemp2[i]);
			fprintf(fo," N");
			
	
	fclose(fp);
	fclose(fn);
	fclose(fo);
	remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	rename("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	printf("���̽���"); 
	
} 



void turnzero(char *p,int a)
{
	for(int i = 0;i<a;i++)
	*(p+i)='\0';
}

void intocata(int a,int b,char p[20],char pp[55]){
		int black= 0;
		int blackgo = 0;
		for(int j = 0;j<55;j++)
		{
			if(pp[j] == ' ')
			black++;
			if(black >=a&&black<b)
			{
				p[blackgo++] = pp[j];	
			} 
		}
		for(int k = 0;k<20;k++)
		p[k]=p[k+1];
	
}


void Recommendbookinner(){
	printf("������ID��\n");
	char tempID[8];
	gets(tempID); 
	if(tempID[0]=='\0')
	gets(tempID);
	int maxnum = 0;
	
	
	FILE *fp,*ft,*fo;
	fp = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database.txt","r");
	fo = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r");
	ft = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\Recommend database temp.txt","wt+");
	//Ѱ����ʷ������飬�����������Դ����� 
while(1){
		char check[2]; 
    	char temp[40];
    	fgets(temp,40,fp);
    	if(check[0]==temp[10]&&check[1]==temp[13])
    		break;
    	else
    	{
    		check[0]=temp[10];
			check[1]=temp[13];
		}
		if(temp[0]=='\0'||temp[0]=='\n')
			break;
		char booknametemp[20];
		char IDtemp[8];
		for(int i = 0;i<20;i++)
		booknametemp[i]='\0' ;
		for(int i = 0;i<8;i++)
		IDtemp[i] =  temp[i];
		int flagtemp=0;
		for(int i = 0;i<8;i++,flagtemp++)
		if(IDtemp[i]!=tempID[i])
		break;
		
		
		
		
		if(flagtemp==8)
		{	
		int black= 0;
		int blackgo = 0;
		for(int j = 0;j<50;j++)
		{
			if(temp[j] == ' '||temp[j] == '\t')
			black++;
			if(black >=1&&black<2)
			{
				booknametemp[blackgo++] = temp[j];		
			} 
		}
		if(booknametemp[0]==' '||booknametemp[0]=='\0')
		for(int k = 0;k<20;k++)
		booknametemp[k]=booknametemp[k+1];
		for(int i = 0;booknametemp[20-i]>=0;i++)
		{
		booknametemp[20-i] ='\0';
		}
 	while(1){
		
		char check1[2]; 
    	char temp2[55];
    	for(int i = 0;i<55;i++)
		temp2[i]='\0';		
    	fgets(temp2,55,fo);
    	if(check1[0]==temp2[10]&&check1[1]==temp2[13])
    		break;
    	else
    	{
    		check1[0]=temp2[10];
			check1[1]=temp2[13];
		}
		if(temp2[0]=='\0'||temp2[0]=='\n')
			break;
			
		int flag = 0;
		for(int i = 0;booknametemp[i] !='\0'&&temp2[i]!=' ';i++,flag++)
		{
			if(booknametemp[i]!=temp2[i])
			break;
		}
		char temp3[40];
		if(flag == strlen(booknametemp))
			{
		for(int i = 0;i<40;i++)
		temp3[i]='\0' ;
			int black2= 0;
			int blackgo2 = 0;
			for(int j = 0;j<50;j++)
			{
				if(temp2[j] == ' ')
				black2++;
				if(black2 >=1&&black2<6)
				{
					temp3[blackgo2++] = temp2[j];
				} 
			}
			}
		for(int k = 0;k<40;k++)
		temp3[k]=temp3[k+1];
		if(temp3[0]!='\0'&&flag!=0)
		{
		fprintf(ft,"%s ",temp3);
		}
		
		for(int i = 0;i<40;i++)
		temp3[i]='\0';	 
	}
	rewind(fo);
}
else;
}




	fclose(fp);
	fclose(ft);
	fclose(fo);

	fo = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r");
	
	
	//���鼮�����ӳ�
	int scorei = 0;
	char scoretemp[100];
	for(int i = 0;i<100;i++)
		scoretemp[i]  = '\0';
    while(1){
    	int score = 0;
    	char temp[55];
    	char check[2];
    	fgets(temp,55,fo);
    	if(check[0]==temp[0]&&check[1]==temp[3])
    	break;
    	else
    	{
    		check[0]=temp[0];
			check[1]=temp[3];
		}
		if(temp[0]=='\0'||temp[0]=='\n')
			break;
		for(int i = 0;i<55;i++)
		temp[i]=='\0';
		char cata1[20];
		char cata2[20];
		char cata3[20];
		char cata4[20];
		char cata5[20];
		turnzero(cata1,20);
		turnzero(cata2,20);
		turnzero(cata3,20);
		turnzero(cata4,20);
		turnzero(cata5,20);
		
			
		intocata(1,2,cata1,temp);
		intocata(2,3,cata2,temp);
		intocata(3,4,cata3,temp);
		intocata(4,5,cata4,temp);
		intocata(5,6,cata5,temp);
		
		score = stringnuminfilee(cata1)+stringnuminfilee(cata2)+stringnuminfilee(cata3)+stringnuminfilee(cata4)+stringnuminfilee(cata5); 
		scoretemp[scorei++]=score+'0';
	}
	
	
	char maxscore = '0';
	for(int i = 0;i<100&&scoretemp[i]!='\0';i++)
		if(scoretemp[i]>=maxscore)
			maxscore = scoretemp[i];
	for(int i = 0;i<100;i++,maxnum++)
		if(scoretemp[i]==maxscore)
			break;
	fclose(fo);
	fo = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r");
	int final = 0;
	while(1){
		char temp[55];
		if(temp[0]=='\0')
		break;
    	fgets(temp,55,fo);
    	if(final==maxnum)
    		{
    			printf("\n\n\t�Ƽ���Ϊ:");
    			puts(temp);
    			break;
			}
			final++;
	}
	fclose(fo);
  remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\Recommend database temp.txt");
}

void showallhistory()
{
	char rehis[8];
	for(int i =0;i<8;i++)
    rehis[i]='\0';
    printf("������ID�ţ�");
    getchar();
    gets(rehis);
	FILE *fm=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database.txt","r");
	char mtemp[40];
	char tempname[8];
	char check[2];
	printf("ID��    �鼮��  ����ʱ��  ״̬��Y/N��\n");
	while(1){
	
	fgets(mtemp,40,fm);
	if(check[0]==mtemp[5]&&check[1]==mtemp[14])
			break;
	else
			{
				check[0]=mtemp[5];
				check[1]=mtemp[14];
			}
			for(int i=0;i<8;i++)
				tempname[i]='\0';
					
			for(int i=0;mtemp[i]!=' ';i++)
				tempname[i]=mtemp[i];
			int flag=0;	
			for(int i=0;i<8;i++,flag++)
			if(rehis[i]!=tempname[i])
			break;
			if(flag == 8)
			
			printf("%s",mtemp);	
	}
	fclose(fm);
	
}

void showallbook(){
	FILE *fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r");
	if(NULL == fp) 
	{
	printf("û��Ϣ\n");
    }
		struct book_information *firstbook; 
		firstbook = (struct book_information*)malloc(sizeof(struct book_information));
		struct book_information *Head;
		Head = (struct book_information*)malloc(sizeof(struct book_information));
		Head->Next = NULL;
		firstbook = Head;
		struct book_information *Nfirstbook; 
    char temp[50];
    char nametemp[20];
	char catatemp[35];
	char borrowtemp[1];
	char check[2] = {'1','2'};
	printf("����\t\t\t����\t\t\t\t\t�ڹݼ���\n"); 
    while(1){
    	fgets(temp,50,fp);
    		if(temp[0]=='\0'||temp[0]=='\n')
    		break;
    		if(check[0]==temp[0])
    		break;
    		check[0]=temp[0];
    		//��ֶ�ȡ 
    		int m = 0;
    		m  = strlen(temp);
    		if(temp[m-2]>='0'&&temp[m-2]<='9') 
    		borrowtemp[0] = temp[m-2];
    		else
    		borrowtemp[0]=temp[m-1];
    		int j = 0;
    		for(j = 0;temp[j]!=' ';j++)
			nametemp[j] = temp[j];
			for(int i = j;i<20;i++)
			nametemp[i]='\0' ;
			
			int black= 0;
			int blackgo = 0;
			for(j = 0;j<50;j++)
			{
				if(temp[j] == ' ')
				black++;
				if(black >=1&&black<6)
				{
					catatemp[blackgo] = temp[j];
					blackgo++;
					
				} 
			}
			
			
			for(int k = 0;k<35;k++)
			catatemp[k]=catatemp[k+1];

			for(int i = 0;catatemp[35-i]>=0;i++)
			{
			catatemp[35-i] ='\0';
			}
			//�γ����� 
				Nfirstbook = (struct book_information*)malloc(sizeof(struct book_information));
				strcpy(Nfirstbook->name,nametemp);
				strcpy(Nfirstbook->cata,catatemp);
				Nfirstbook->borrow = (int)borrowtemp[0]-'0';
				
				printf("\n");
				printf("%-24s%-47s%-3d\n",Nfirstbook->name,Nfirstbook->cata,Nfirstbook->borrow);			
				Nfirstbook->Next=NULL; 
				firstbook->Next = Nfirstbook;
				firstbook = Nfirstbook;
			for(int i = 0;35>i;i++)
			{
			catatemp[i] ='\0';
			nametemp[i]='\0';
			}
			for(int i =0;i<55;i++)
			temp[i]='\0';
	}
	fclose(fp);

}




int stringnuminfilee(char nametemp[20])
{
char *filename,*spestr;
FILE *fp;
filename=(char *)malloc(FILE_NAME_MAX);
fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\Recommend database temp.txt","r");
while(1)
{
if(fp!=NULL)
{
break;
}
printf("Can't open the file.Try Again!");
}
int number = StrCount(fp,nametemp);
fclose(fp);
free(filename);
return number;
}
int StrCount(FILE *file,char *str)
{
int count=0;
char ch;
int p=0;;
while((ch=fgetc(file))!=EOF)
{
// ��ǰ������ַ�ƥ�� str ��Ӧλ�õ��ַ�
if(ch == str[p])
{
// ƥ����һ���ַ�
p++;
// ����Ѿ�ƥ��ɹ�
if(str[p] == '\0')
{
count++;
// ��ͷ��ʼ����ƥ��
p = 0;
}
}
// // ��ǰ������ַ���ƥ�� str ��Ӧλ�õ��ַ�
else
{
// ƥ��ʧ�ܣ��ļ�ָ�����
fseek(file,(p>0?-(p-1):0),SEEK_CUR);
// ��ͷ��ʼ����ƥ��
p = 0 ;
}
}
return count;
}

int administrater()
{
	printf("�����嵥 \n\tͼ����Ϣ�밴1\n\t���߹����밴2\n\t���߽�����Ϣ�밴3\n\tͼ�������������밴4\n\t�˳��밴5\n");
	char j;
	scanf("%c",&j);
	if(j=='0'||j=='\n')
	scanf("%c",&j);
	while(1)
	{
		if(j=='1') book_information();
		if(j=='2') reader_control();
		if(j=='3') showallreaderhistory();
		if(j=='4') buying_asking();
		if(j=='5') break; 
		printf("\n\n�����嵥 \n\tͼ����Ϣ�밴1\n\t���߹����밴2\n\t���߽�����Ϣ�밴3\n\tͼ�������������밴4\n\t�˳��밴5\n");
		scanf("%c",&j);
		if(j=='0'||j=='\n')
		scanf("%c",&j);
	}
	return 0;
 } 
 
 void buying_asking()
 {
 	FILE *fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\buyingbook.txt","a+") ;
 	fprintf(fp,"\n");
	printf("\n\n\t\tͼ������������\n\t\t�������빺��ʲô�飿\n");
	char m[20];
	getchar();
	gets(m);
	fprintf(fp,"%s\n",m);
	fclose(fp);
	printf("\t\t�Ѿ�Ϊ��֪ͨ��꣬��ȴ��鼮����\n");
	
 }
 

void book_information()
{
	while(1)
	{
		char n;
		printf("\n��ӭʹ��ͼ����Ϣ�༭ϵͳ\n\t�鿴ȫ���鼮�밴1\n\t�����鼮�밴2\n\tɾ���鼮�밴3\n\t�޸���Ϣ�밴4\n\t�˳��밴5\n");
		scanf("%c",&n);
		if(n=='\0'||n=='\n')
		scanf("%c",&n);
			if(n=='1') showallbook();
			if(n=='2') addbook();
			if(n=='3') deletbook();
			if(n=='4') renewbook();
			if(n=='5') break;
	}
}


void addbook()
{
	char inlib;
	char temp[55];
	printf("������������������\n(�밴������ ���� ���� ��� ���˹�ְҵ С˵���� �ڹݼ�������ʽ����)\n���磨���¶� Ӣ�� ���˹�Ҹ�˹ С˵ �¶� ��� 3��\n");
	getchar();
	gets(temp);
	int m=strlen(temp);
	if(temp[m-2]>='0'&&temp[m-2]<='9')
	inlib=temp[m-2];
	else
	inlib =temp[m-1];
	char bookname[20];
	for(int i=0;i<20;i++)
	 bookname[i]='\0';
	for(int i = 0;i<55;i++)
	{
		if(temp[i]==' '||temp[i]=='\t')
		break;
		bookname[i] = temp[i];
	}
	
	char cataname[35];
	for(int i = 0;i<35;i++)
	{
		cataname[i]='\0';
	}
	int blank = 0;
	int j  =0;
	for(int i = 0;i<55;i++)
	{
		if(temp[i]==' ')
		blank++;
		if(blank>=1&&blank<=5)
		cataname[j++]=temp[i];
	}
	for(int i = 0;i<35;i++)
	{
		cataname[i]=cataname[i+1];
	}


	

	FILE *fp;
	fp = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","a+");
	fprintf(fp,"\n%s %s %c",bookname,cataname,inlib);
	fclose(fp);
	printf("�鼮��ӳɹ�\n"); 
}  
 
 

void deletbook(){ 
    FILE *fp,*ft;
    char set[20];
    printf("������Ҫɾ�����鼮����");
    getchar();
    gets(set);

    fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r");
    ft=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","wt+");
    
    
    if(fp==NULL || ft==NULL){
        printf("����\n");
    }
    
    
    char mtemp[60];
    char tempname[20];
	for(int i=0;i<20;i++)
	tempname[i]='\0';
	while(fgets(mtemp,59,fp)!=NULL) 
		{
			
				for(int i=0;mtemp[i]!=' ';i++)
				tempname[i]=mtemp[i];
				for(int i =0;tempname[20-i]!='\0';i++)
					tempname[20-i]='\0';
				int flag = 0;
				for(int i = 0;set[i]!='\0'&&tempname[i]!='\0';i++)
				if(set[i]!=tempname[i])
				flag = 1;
				if(flag == 0);
				else
				{
					fprintf(ft,"%s",mtemp);
				}
			
		}
    fclose(fp);
    fclose(ft);

        
        
        
        
    remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	rename("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	printf("�鼮��Ϣɾ���ɹ���\n");

}


void renewbook(){ 
    FILE *fp,*ft;
    char set[20];
    char renewtemp[57];
    for(int i =0;i<20;i++)
    set[i]='\0';
    for(int i =0;i<57;i++)
    renewtemp[i]='\0';
    printf("������Ҫ�޸ĵ��鼮����");
    getchar();
    gets(set);
    printf("�������޸�֮������\n(�밴������ ��� ��� ��� ��� ��� �ڹݼ�������ʽ����)\n") ;
	gets(renewtemp);
	
    fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt","r"); 
    ft=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","wt+");
    
    
    if(fp==NULL || ft==NULL){
        printf("����\n");
    }
    
   
    char mtemp[60];
    char tempname[20];

	while(fgets(mtemp,59,fp)!=NULL) 
		{
				for(int i=0;i<20;i++)
					tempname[i]='\0';
				for(int i=0;mtemp[i]!=' ';i++)
				tempname[i]=mtemp[i];
				for(int i =0;tempname[20-i]!='\0';i++)
					tempname[20-i]='\0';
				if(strcmp(tempname,set)==0)
				{
					fprintf(ft,"%s\n",renewtemp);	
				}
				else
				fprintf(ft,"%s",mtemp);
			
		}
    fclose(fp);
    fclose(ft);

        
        
        
        
    remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	rename("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database temp.txt","C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\book database.txt");
	printf("�鼮��Ϣ�޸ĳɹ���\n");
}



void reader_control()
{
	printf("�����嵥 \n\t������Ϣ�밴1\n\t���������밴2\n\t����ɾ��3\n\t�����޸�4\n\t�˳��밴5\n");
	char j;
	scanf("%c",&j);
	if(j=='0'||j=='\n')
	scanf("%c",&j);
	while(1)
	{
		switch(j){
			case '1':showallreader();break;
			case '2':addreader();break;
			case '3':deletreader();break;
			case '4':renewreader();break;
			case '5':break;
			default:printf("\t�������\n���������밴1\n�˳��밴2\n"); 			
}
	printf("\n�����嵥 \n\t������Ϣ�밴1\n\t���������밴2\n\t����ɾ��3\n\t�����޸�4\n\t�˳��밴5\n");
	if(j=='5')
	break;
	scanf("%c",&j);
	if(j=='0'||j=='\n')
	scanf("%c",&j);
	}
 } 


void showallreader(){
	FILE *fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt","r");
	char temp[17];
	char check[2];
	printf("ID��     Code��\n");
    while(1){
    	for(int i = 0;i<17;i++)
    		temp[i]= '\0';
    		fgets(temp,50,fp);
    	
    		if(check[0]==temp[0]&&check[1]==temp[10])
    		break;
    		check[0]==temp[0];
			check[1]==temp[10];
    		
    		printf("%s\n",temp);
			}
	
	fclose(fp);

}

void addreader()
{
	char temp[18];
	printf("������ID����code����\n(�밴��ID�� code���룩��ʽ����)\n");
	getchar();
	gets(temp);

	FILE *fp;
	fp = fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt","a+");
	fprintf(fp,"\n%s",temp);
	fclose(fp);
	printf("������Ϣ��ӳɹ���\n");
} 



void deletreader(){ 
    FILE *fp,*ft;
    char set[20];
    for(int i =0;i<20;i++)
    set[i]='\0';
    printf("������Ҫɾ����ID�ţ�");
    getchar();
    gets(set);

    fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt","r");
    ft=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database temp.txt","wt+");
    
    
    if(fp==NULL || ft==NULL){
        printf("����\n");
    }
    
    
    char mtemp[60];
    char tempname[20];
	for(int i=0;i<20;i++)
	tempname[i]='\0';
	while(fgets(mtemp,59,fp)!=NULL) 
		{
			
				for(int i=0;mtemp[i]!=' ';i++)
				tempname[i]=mtemp[i];
				for(int i =0;tempname[20-i]!='\0';i++)
					tempname[20-i]='\0';
				if(strcmp(tempname,set)==0)
					continue;
				else
				{
					fprintf(ft,"%s",mtemp);
				}
			
		}
    fclose(fp);
    fclose(ft);

        
        
        
        
    remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt");
	rename("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database temp.txt","C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt");
	printf("������Ϣɾ���ɹ���\n");

}


void renewreader(){ 
    FILE *fp,*ft;
    char set[8];
    char renewtemp[18];
    for(int i =0;i<8;i++)
    set[i]='\0';
    for(int i =0;i<18;i++)
    renewtemp[i]='\0';
    printf("������Ҫ�޸ĵ�ID�ţ�");
    getchar();
    gets(set);
    printf("�������޸�֮������\n(�밴��ID�� code�ţ���ʽ����)\n") ;
	gets(renewtemp);
	
    fp=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt","r"); 
    ft=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database temp.txt","wt+");
    
    
    if(fp==NULL || ft==NULL){
        printf("����\n");
    }
    
   
    char mtemp[18];
    char tempname[8];

	while(fgets(mtemp,18,fp)!=NULL) 
		{
				for(int i=0;i<8;i++)
					tempname[i]='\0';
				for(int i=0;mtemp[i]!=' ';i++)
				tempname[i]=mtemp[i];
				if(strcmp(tempname,set)==0)
				{
					fprintf(ft,"%s",renewtemp);	
				}
				else
				fprintf(ft,"%s",mtemp);
			
		}
    fclose(fp);
    fclose(ft);

        
        
        
        
    remove("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt");
	rename("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database temp.txt","C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\code database.txt");
	printf("������Ϣ�޸ĳɹ���\n");
}

void showallreaderhistory()
{
	FILE *fm=fopen("C:\\Users\\WPC\\Desktop\\ͼ��ݹ���ϵͳ\\history database.txt","r");
	char mtemp[40];
	for(int i = 0;i<40;i++)
		mtemp[i] ='\0' ;
	char check[20];
	while(1){
		fgets(mtemp,40,fm);
		int flag = 0;
		for(int i = 0;i<20;i++)
		if(check[i]!=mtemp[i+20])
			flag=1;
	if(flag ==1)
			{
			for(int i = 0;i<20;i++)
			check[i]=mtemp[i+20];
			printf("%s",mtemp);	
			}
			else
			break;
	}
	fclose(fm);
	
}


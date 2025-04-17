#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*			int*  len 0
			char* strlen \0  
			strcpy strcat sprintf strstr strrev memset 
*/
struct number{
	int val;
	struct number *next;
};
typedef struct number NUM;

void Printlist(NUM *head){
	NUM *temp = head;
	for(int i = 0;temp->next!=NULL;i++){
		printf("*%d*",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void Freelist(NUM* head){
	NUM *temp = head;
	for(int i = 0;temp->next!=NULL;i++){
		temp = temp->next;
		free(head);
		head  = temp;
	}
}
int cmp(const void*a, const void*b){
	return (*(int*)b-*(int*)a);
}
int main(int argc, char** argv) {
	FILE *f = fopen("a.txt","r");
	FILE *fp = fopen("ap.txt","a");
	NUM* head = NULL;
	NUM* tail = NULL;
	
	
	int*  num = (int*)malloc(10*sizeof(int));
	char* str = (char*)malloc(10*sizeof(char));
	memset(str,0,strlen(str));
	int len = 0;
	for(len=0;;len++){
		if(fscanf(f,"%d",&num[len]) != 1) break;
	}
	
	for(int i =0;i<=len;i++){
		NUM* temp = (NUM*)malloc(sizeof(NUM));
		temp->next = NULL;
		temp->val =  num[i];
		if(head ==NULL){
			head = temp;
			tail = temp;
		}
		else{
			tail->next = temp;
			tail       = tail->next;
		}
	}
	
	qsort(num,len,sizeof(int),cmp);
	
	for(int i=0;i<len;i++){
		char* strt = (char*)malloc(10*sizeof(char));
		sprintf(strt,"%d ",num[i]);
		strcat(str,strt);
		free(strt);
	}
	puts(str);
	Printlist(head);
	Freelist(head);
	
	fclose(f);
	fclose(fp);
	
	return 0;
}

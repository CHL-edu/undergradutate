#include <iostream>
#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct number{
	int val;
	struct number *next;
};

typedef struct number NUM;

void modify(NUM* head){
	int pos = 0;
	int val = 0;
	scanf("%d %d",&pos,&val);
	
	NUM* temp = head;
	for(int i =0;i<pos&&temp!=NULL;i++){
		temp = temp->next;
	}
	if(temp!=NULL)
		temp->val = val;
	else
		printf("NONE");	
}

void add(NUM* head){
	int pos = 0;
	int val = 0;
	scanf("%d %d",&pos,&val);
	NUM* newnode = (NUM*)malloc(sizeof(NUM));
	newnode->next = NULL;
	newnode->val = val;	
	NUM* temp = head;
	for(int i =0;i<pos-1&&temp!=NULL;i++){
		temp = temp->next;
	}
	if(temp!=NULL){
		newnode->next = temp->next;
		temp->next = newnode;
	}
	else
		printf("NONE");	
}

void del(NUM* head){
	int pos = 0;
	scanf("%d",&pos);

	NUM* temp = head;
	NUM* temp1 = head;
	for(int i =0;i<pos-1&&temp!=NULL;i++){
		temp = temp->next;
	}
	for(int i =0;i<pos&&temp1!=NULL;i++){
		temp1 = temp1->next;
	}
	if(temp!=NULL){
		temp->next = temp1->next;
	}
	else
		printf("NONE");	
}


void bublesort(int* ary, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(ary[j] < ary[j + 1]){
                int temp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = temp;
            }
        }
    }
    
}
int cmp(const void *a,const void *b){
	return (*(int*)b - *(int*)a);
}
void sort(NUM* head){
	int len = 0;
    NUM* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
	int* num = (int*)malloc(len*sizeof(int));
	temp = head;
	for(int i =0;temp!=NULL;i++){
		num[i]  = temp->val;
		temp = temp->next;
	}
	bublesort(num,len);
	//qsort(num,len,sizeof(int),cmp);
	temp = head;
	for(int i =0;temp!=NULL;i++){
		temp->val  = num[i];
		temp = temp->next;
	}
	
	free(num);
}

void printlist(NUM* head){
	NUM* temp = head;
	for(int i =0;temp!=NULL;i++){
		printf("%d*",temp->val);
		temp = temp->next;
	}
	printf("\n");	
}

void freelist(NUM* head){
	NUM* temp = head;
	for(int i =0;temp!=NULL;i++){
		temp = temp->next;
		free(head);
		head = temp;
	}	
}
int main(int argc, char** argv) {
	FILE *f = fopen("abc.txt","r+");
    char fn[10] = {};  // 假设数字不超过 10 位
    fgets(fn, sizeof(fn), f);  // 读取第一行
    int n = atoi(fn);  // 将第一行内容转换为整数
	NUM* head = NULL;
	NUM* tail = NULL;
	for(int i = 0;i<n;i++){
		NUM* newnode = (NUM*)malloc(sizeof(NUM));
		newnode->next = NULL;
		fscanf(f,"%d",&newnode->val);
		if(head ==NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = tail->next;
		}
	}
	char* opt = (char*)malloc(sizeof(char));
	int flag = 0;
	while(flag !=1){
		scanf("%s",opt);
		switch(opt[0]){
			case 'e': flag = 1;                     break;
			case 'm': modify(head);	printlist(head);break;
			case 'a': add(head);	printlist(head);break;
			case 'd': del(head);	printlist(head);break;
			case 's': sort(head);	printlist(head);break;
			default:break;
		}	
	}
	free(opt);
	fclose(f);
	freelist(head);
	return 0;
}

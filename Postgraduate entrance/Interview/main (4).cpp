#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Number {
    int val;
    struct Number* next; // 使用结构体标签
};
typedef struct Number NUM; // 定义类型别名

void printList(NUM* head) {
    NUM* temp = head;
    while (temp != NULL) {
        printf("%d*", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char** argv) {
	int n =0;
	scanf("%d",&n);
	NUM* head = NULL;
	NUM* tail = NULL;
	for(int i =0;i<n;i++){
		NUM* newnode = (NUM*)malloc(sizeof(NUM));
		scanf("%d",&newnode->val);
		newnode->next = NULL;
		if(head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = newnode;	
		}
	}
	
	
	char* operation = (char*)malloc(10*sizeof(char));
    while (1) {
        scanf("%s", operation);
        if (operation[0] == 'e') { // end
            break;
        } else if (operation[0] == 'm') { // modifyNode
            int pos,val = 0;
			scanf("%d %d", &pos, &val);

			NUM* temp = head;
            
			for(int i = 0;i<pos;i++){
				temp = temp->next;
			}
 			if(temp != NULL) {
       			temp->val = val;  // 直接修改节点的值
    		}          
       } else if (operation[0] == 'd') { // modifyNode
            int pos=0;
			scanf("%d", &pos);

			NUM* f_temp = head;
            NUM* temp = head;
            for(int i = 0;i<pos-1&&f_temp != NULL;i++){
				f_temp = f_temp->next;
			}
			for(int i = 0;i<pos&&temp != NULL;i++){
				temp = temp->next;
			}
 			f_temp->next = temp->next;      
       } else if (operation[0] == 'i') { // insertNode
            int pos=0;
            int val=0;
			scanf("%d %d", &pos,&val);
            NUM* newnode = (NUM*)malloc(sizeof(NUM));
			newnode->next = NULL;
			newnode->val = val;
			NUM* temp = head;
			for(int i = 0;i<pos-1&&temp != NULL;i++){
				temp = temp->next;
			} 
			newnode->next = temp->next;
			temp->next =  newnode;   
        }
        
    } 
	printList(head); 
    NUM* temp = head;
	while (temp != NULL) {
		NUM* next = temp->next;
 		free(temp);
 		temp = next;
	}
    free(operation); 
    
	return 0;
}

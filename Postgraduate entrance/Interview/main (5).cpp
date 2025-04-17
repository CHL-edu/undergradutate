#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode* next;
};

// 创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 在指定位置插入节点
void insertNode(struct ListNode** head, int pos, int val) {
    struct ListNode* newNode = createNode(val);
    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct ListNode* temp = *head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position for insertion.\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// 删除指定位置的节点
void deleteNode(struct ListNode** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct ListNode* temp = *head;
    if (pos == 0) {
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position for deletion.\n");
            return;
        }
        struct ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

// 修改指定位置的节点值
void modifyNode(struct ListNode* head, int pos, int val) {
    struct ListNode* temp = head;
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position for modification.\n");
        return;
    }
    temp->val = val;
}

// 查找指定位置的节点值
int searchNode(struct ListNode* head, int pos) {
    struct ListNode* temp = head;
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return -1;
    }
    return temp->val;
}

// 打印链表
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, val, pos;
    char operation[10];

    // 输入初始链表
    printf("Enter the initial length of the list: ");
    scanf("%d", &n);
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 处理操作
    while (1) {
        scanf("%s", operation);
        if (operation[0] == 'e') { // end
            break;
        } else if (operation[0] == 'i') { // insert
            scanf("%d %d", &pos, &val);
            insertNode(&head, pos, val);
        } else if (operation[0] == 'd') { // delete
            scanf("%d", &pos);
            deleteNode(&head, pos);
        } else if (operation[0] == 'm') { // modify
            scanf("%d %d", &pos, &val);
            modifyNode(head, pos, val);
        } else if (operation[0] == 's') { // search
            scanf("%d", &pos);
            int result = searchNode(head, pos);
            printf("%d\n", result);
        }
    }

    // 输出最终链表
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}

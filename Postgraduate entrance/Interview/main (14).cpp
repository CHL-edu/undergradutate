#include <stdio.h>

#define MAX_LEVELS 100  // �����������������

int main() {
    int n;
      // �����ά����洢������

    // ����������Ĳ���
    printf("������������Ĳ���: ");
    scanf("%d", &n);
	int pyramid[n][n] = {};
    // ���������������
    printf("�����������������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &pyramid[i][j]);
        }
    }

    // �ӵײ����ϼ������·����
	for(int i = n-2;i>=0;i--){
		for(int j = i;j>=0;j--){
			pyramid[i][j]+=(pyramid[i+1][j]>pyramid[i+1][j+1]) ? pyramid[i+1][j]:pyramid[i+1][j+1];
		}
	}

    // ������·����
    printf("�Ӷ��㵽�ײ�����·����Ϊ: %d\n", pyramid[0][0]);

    return 0;
}

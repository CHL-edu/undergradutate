#include <stdio.h>
/*
"r"��ֻ��ģʽ���ļ�������ڡ�

"w"��ֻдģʽ������ļ�������������ݣ�����ļ��������򴴽��ļ���

"a"��׷��ģʽ���ļ�ָ��ʼ��λ���ļ�ĩβ��

"r+"����дģʽ���ļ�������ڡ�

"w+"����дģʽ������ļ�������������ݣ�����ļ��������򴴽��ļ���

"a+"����дģʽ���ļ�ָ���ʼλ�����ļ�ĩβ��
*/
int main() {
    FILE *pFile = fopen("example.txt", "r+"); // ���ļ�
    if (pFile == NULL) {
        perror("�޷����ļ�");
        return 1;
    }
	fputs ( "This is an apple." , pFile );
 	rewind(pFile);
    // ��ȡ��ǰ�ļ�ָ��λ��
    long pos = ftell(pFile);
    printf("��ǰ�ļ�ָ��λ��: %ld\n", pos);

    // �ƶ��ļ�ָ�뵽�����ļ���ͷ 10 �ֽڵ�λ��
    fseek(pFile, 10, SEEK_SET);
    pos = ftell(pFile);
    printf("�ƶ�����ļ�ָ��λ��: %ld\n", pos);

    // ��ȡ������ļ�����
    char buffer[100];
    fgets(buffer, sizeof(buffer), pFile);
    printf("�ļ�����: %s\n", buffer);

    fclose(pFile); // �ر��ļ�
    return 0;
}

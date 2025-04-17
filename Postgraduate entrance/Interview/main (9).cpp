#include <stdio.h>
/*
"r"：只读模式，文件必须存在。

"w"：只写模式，如果文件存在则清空内容，如果文件不存在则创建文件。

"a"：追加模式，文件指针始终位于文件末尾。

"r+"：读写模式，文件必须存在。

"w+"：读写模式，如果文件存在则清空内容，如果文件不存在则创建文件。

"a+"：读写模式，文件指针初始位置在文件末尾。
*/
int main() {
    FILE *pFile = fopen("example.txt", "r+"); // 打开文件
    if (pFile == NULL) {
        perror("无法打开文件");
        return 1;
    }
	fputs ( "This is an apple." , pFile );
 	rewind(pFile);
    // 获取当前文件指针位置
    long pos = ftell(pFile);
    printf("当前文件指针位置: %ld\n", pos);

    // 移动文件指针到距离文件开头 10 字节的位置
    fseek(pFile, 10, SEEK_SET);
    pos = ftell(pFile);
    printf("移动后的文件指针位置: %ld\n", pos);

    // 读取并输出文件内容
    char buffer[100];
    fgets(buffer, sizeof(buffer), pFile);
    printf("文件内容: %s\n", buffer);

    fclose(pFile); // 关闭文件
    return 0;
}

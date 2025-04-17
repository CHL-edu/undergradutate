#include <stdio.h>

#define MAX_LEVELS 100  // 定义金字塔的最大层数

int main() {
    int n;
      // 定义二维数组存储金字塔

    // 输入金字塔的层数
    printf("请输入金字塔的层数: ");
    scanf("%d", &n);
	int pyramid[n][n] = {};
    // 输入金字塔的数据
    printf("请输入金字塔的数据:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &pyramid[i][j]);
        }
    }

    // 从底层向上计算最大路径和
	for(int i = n-2;i>=0;i--){
		for(int j = i;j>=0;j--){
			pyramid[i][j]+=(pyramid[i+1][j]>pyramid[i+1][j+1]) ? pyramid[i+1][j]:pyramid[i+1][j+1];
		}
	}

    // 输出最大路径和
    printf("从顶层到底层的最大路径和为: %d\n", pyramid[0][0]);

    return 0;
}

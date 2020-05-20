#include <stdio.h>
 
int count = 0;
void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("%d: 將第 %d 個圓盤由 %c 移到 %c\n", count++, n, A, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        printf("%d: 將第 %d 個圓盤由 %c 移到 %c\n", count++, n, A, C);
        hanoi(n - 1, B, A, C);
    }
}
 
int main()
{
    int n;
    printf("請輸入河內塔的高度：");
    scanf("%d", &n);
 
    hanoi(n, 'A', 'B', 'C');
 
    printf("移動 %d 層河內塔共需移動 %d 次\n", n, count);
 
    return 0;
}
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//仅仅是打印函数名字替换 DEBUG <--> printf
#define DEBUG(format, ...) printf(format, ##__VA_ARGS__)
#define ERROR_INFO(format, ...) printf(format, ##__VA_ARGS__)

//替换打印函数，在打印出来的内容加上前缀
#define XFUNC_PRINT(format, arg...) printf("XFUNC: " format "", ##arg)
#define XFUNC_PRINT2(format, ...) printf("XFUNC: " format "", ##__VA_ARGS__)

//名字替换，并在打印出来的内容加上前缀,同时加入定位的功能。
#define TRC_P(fmt, args...) fprintf(stderr,"  TRC_P(%s:%d):\t" fmt, __func__, __LINE__, ##args)

//名字替换，并在打印出来的内容加上前缀,同时加入定位的功能，并让打印的前缀具备特殊颜色(\033[1;32m  \033[0m这些表示颜色，\t一定程度上使屏幕输出对齐)
#define TRC_PG(fmt, args...) fprintf(stderr, "\033[1;32m  TRC_PG(%s:%d):\t\033[0m" fmt, __func__, __LINE__, ## args)

//名字替换，并在打印出来的内容加上前缀,同时加入定位的功能，并让打印的前缀具备特殊颜色
#define TRC_PR(fmt, args...) fprintf(stderr, "\033[1;31m  TRC_PR(%s:%d):\t\033[0m" fmt, __func__, __LINE__, ## args)

void main (void)
{
	DEBUG("fortest%d", 1);
	XFUNC_PRINT("fortest%d", 2);
	XFUNC_PRINT("fortest");
	
	XFUNC_PRINT2("fortest%d", 2);
	XFUNC_PRINT2("fortest");
}
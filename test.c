#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t g_flag = 0;

void	signal_handler(int signum)
{
	// printf("%s\n", "中断する");
	// exit(1);	// 異常終了の意味, 異常終了するとvscodeのターミナルに赤文字がつく
	// printf("%s\n", "中断する！！！");
	g_flag = 1;
}

int	main(void)
{
	printf("%d\n", SIGINT);
	signal(SIGINT, signal_handler);
	while (!g_flag)
	{
	}

	printf("%s\n", "終了");
	return (0);
}

// 特定のシグナルを受信するとプロセスが変化する
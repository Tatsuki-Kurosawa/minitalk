#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int	main(void)
{
	pid_t	p_id;

	if ((p_id = fork()) == 0)
	{
		while (1)
		{
			printf("p_id: %d\n", (int)p_id);
			printf("子プロセス実行中\n");
			sleep(1);
		}
	}
	else
	{
		sleep(3);
		printf("p_id: %d\n", (int)p_id);
		kill(p_id, SIGINT);
		wait(NULL);
		printf("親プロセス終了\n");
	}
	return (0);
}

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	my_pid;

	my_pid = getpid();
	printf("my_pid=%d\n", (int)my_pid);
}

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <libc.h>

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = getpid();
	printf("PROCESSID: %d\n", (int)pid);
	if (argv[1] == "hello")
	{
		kill(pid, SIGUSR1);
	}
}

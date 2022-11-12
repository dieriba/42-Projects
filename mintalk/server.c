#include "minitalk.h"

size_t i = -1;

void is_process_running(pid_t pid)
{
    if (kill(pid, 0) < 0)
    {
        ft_putstr_fd(("An error occured during the process, exiting...\n"), 2);
        exit(EXIT_FAILURE);
    }
}

char    *ft_realloc(char *msg)
{
    char    *new_msg;
    size_t  i;

    i = -1;
    new_msg = malloc(((BUFFER_SIZE + i) * sizeof(char) + 1));
    if (!new_msg)
    {
        free(msg);
        ft_putstr_fd("Failed To ReAllocate Memory", 2);
        exit(EXIT_FAILURE);
    }
    while (msg[++i])
        new_msg[i] = msg[i];
    free(msg);
    return (new_msg);
}

void create_char(char *msg, char *c, size_t *i, int *count)
{
	msg[++(*i)] = *c;
	*(count)++;
	*c = 0;
}

void end_client(char *msg, siginfo_t *client, int *count, size_t *i)
{
	write(1, msg, (*(i) + 1));
	kill(client->si_pid, SIGUSR2);
	free(msg);
	*i = -1;
	*count = 0;
	msg = NULL;
}

void handler(int signal, siginfo_t *client, void *ucontext)
{
    (void)ucontext;
    static int	shift = -1;
    static char	c;
    static char	*msg;
	static int	count;

    if (!msg)
        msg = malloc((BUFFER_SIZE * sizeof(char) + 1));
	if (!msg)
		exit(EXIT_FAILURE); // CREATE A FT__ERROR FUNCTION THAT WILL RETURN A PRINT ERROR STATEMENT FOLLOWED BY A FREE
    is_process_running(client->si_pid);
    if (shift < 0)
        shift = 7;
    if (signal == SIGUSR1)
        c |= (1 << shift);
    shift--;
    if (shift < 0 && c)
		create_char(msg, &c, &i, &count);
    else if (c && count == BUFFER_SIZE)
        msg = ft_realloc(msg);
    else if (shift < 0 && !c)
		end_client(msg, client, &count, &i);
    kill(client->si_pid, SIGUSR1);
}

int main()
{
    pid_t pid;
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO | SA_RESTART;
    sig.sa_sigaction = handler;
    sigemptyset(&(sig.sa_mask));
    pid = getpid();
    ft_putstr_fd("Server PID is : ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    sigaction(SIGUSR2, &sig, NULL);
    sigaction(SIGUSR1, &sig, NULL);
    while (1)
        sleep(1);
}
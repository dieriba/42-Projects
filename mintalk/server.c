#include "minitalk.h"

void is_process_running(pid_t pid)
{
    if (kill(pid, 0) < 0)
    {
        ft_putstr_fd(("An error occured during the process, exiting...\n"), 1);
        exit(EXIT_FAILURE);
    }
}

void handler(int signal, siginfo_t *client, void *ucontext)
{
    (void)ucontext;
    static int shift = -1;
    static char c;

    is_process_running(client->si_pid);
    if (shift < 0)
        shift = 7;
    if (signal == SIGUSR1)
        c |= (1 << shift);
    shift--;
    if (shift < 0 && c)
    {
        ft_putchar_fd(c, 1);
        c = 0;
    }
    else if (shift < 0 && !c)
        kill(client->si_pid, SIGUSR2);
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
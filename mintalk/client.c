#include "minitalk.h"

int s_received = 0;

void handle_char(pid_t pid,unsigned char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        s_received = 0;
        if ((1 << i) & c)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (!s_received)
            pause();
        i--;
    }
}

void handle_string(int pid, char *msg)
{
    int i;

    i = -1;
    while (msg[++i])
        handle_char(pid, (unsigned char)msg[i]);
    handle_char(pid, 0);
}

void handler(int signal, siginfo_t *client, void *ucontext)
{
    (void)ucontext;
    (void)client;
    if (signal == SIGUSR1)
        s_received = 1;
    else if (signal == SIGUSR2)
    {
        ft_putstr_fd("Message succesfully sent to the server, Congrats !", 1);
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[])
{
    int pid;
    struct sigaction sig;

    if (argc != 3)
    {
        ft_putstr_fd("Usage : ./client <pid> <message_to_send>\n", 1);
        exit(EXIT_FAILURE);
    }
    sig.sa_flags = SA_SIGINFO | SA_RESTART;
    sig.sa_sigaction = handler;
    sigemptyset(&(sig.sa_mask));
    sigaction(SIGUSR2, &sig, NULL);
    sigaction(SIGUSR1, &sig, NULL);
    pid = ft_atoi(argv[1]);
    if (!pid)
    {
        ft_putstr_fd("PID of , is not possible..., please stop joking enter the real value!\n", 1);
        exit(EXIT_FAILURE);
    }
    handle_string(pid, argv[2]);
}
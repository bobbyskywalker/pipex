#include "../inc/pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd_in;
    int fd_out;
    int i;

    if (argc < 5)
    {
        errno = EINVAL;
        perror("valid exec: ./pipex infile cmd cmd outfile");
        return (1);
    }
    fd_in = open(argv[1], O_RDONLY, 0777);
    fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_in == -1 || fd_out == -1)
    {
        errno = EBADF;
        close(fd_in);
        close(fd_out);
        perror("pipex");
        exit(EXIT_FAILURE);
    }
    dup2(fd_in, STDIN_FILENO);
    i = 2;
    while (i < argc - 2)
        exec_process(argv[i++], envp);
    dup2(fd_out, STDOUT_FILENO);
    exec_command(argv[argc - 2], envp);
    return (0);
}

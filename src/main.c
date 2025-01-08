#include "../inc/pipex.h"
#include <fcntl.h>

// void process_child();
// void process_parent();
// void clean_pipex();

int main(int argc, char **argv, char **envp)
{
    int fd_in;
    int fd_out;

    fd_in = open(argv[1], O_RDONLY, 0777);
    fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    dup2(fd_in, STDIN_FILENO);
    if (argc != 5)
    {
        errno = EINVAL;
        perror("valid exec: ./pipex infile cmd cmd outfile\n");
        return (1);
    }
    exec_process(argv, envp);
    dup2(fd_out, STDOUT_FILENO);
    exec_command(argv[3], envp);
    return (0);
}

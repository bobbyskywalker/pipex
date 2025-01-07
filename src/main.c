#include "../inc/pipex.h"

void parse();
void process_child();
void process_parent();
void clean_pipex();

int main(int argc, char **argv, char **envp)
{
    int pipe_fds[2];
    int pid;

    if (argc != 5)
    {
        errno = EINVAL;
        perror("valid exec: ./pipex infile cmd cmd outfile\n");
        return (1);
    }
    if (pipe(pipe_fds) == -1)
        exit(1);
    // splits the process into child and parent (0 for child, 1 for parent)
    pid = fork();
    if (!pid)
        process_child();
    process_parent();
    return (0);
}

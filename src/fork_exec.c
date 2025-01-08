#include "../inc/pipex.h"

void    exec_command(char *arg, char **envp)
{
    char **dirs;
    char **cmd_arr;
    char *cmd;

    dirs = get_path_env_var(envp);
    cmd_arr = ft_split(arg, ' ');
    cmd = validate_command(cmd_arr[0], dirs);
    ft_arr2d_free(dirs);
    if (!cmd)
        exit(1);
    if(execve(cmd, cmd_arr, envp) == -1)
        exit(1);
}

void    exec_process(char **argv, char **envp)
{
    pid_t pid;
    int pipe_fds[2];

    if (pipe(pipe_fds) == -1)
        exit(1);
    pid = fork();
    if (pid == -1)
        exit(1);
    if (!pid)
    {
        close(pipe_fds[0]);
        dup2(pipe_fds[1], STDOUT_FILENO);
        exec_command(argv[2], envp);
    }
    else
    {
        close(pipe_fds[1]);
        dup2(pipe_fds[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

#include "../inc/pipex.h"

char **get_path_env_var(char **envp)
{
    char **dirs;
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp("PATH=", envp[i], 5) == 0)
        {
            dirs = ft_split(envp[i] + 5, ':');
            return dirs;
        }
        i++;
    }
    return (NULL);
}

char *validate_command(char *arg, char **dirs)
{
    int i;
    char *cmd_path;
    char *path;

    i = 0;
    while (dirs[i])
    {
        cmd_path = ft_strjoin(dirs[i], "/");
        path = ft_strjoin(cmd_path, arg);
        free(cmd_path);
        if (!access(path, F_OK))
            return path;
        free(path);
        i++;
    }
    errno = 3;
    perror("pipex");
    exit(EXIT_FAILURE);
}

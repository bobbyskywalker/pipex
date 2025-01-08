#ifndef PIPEX_H
# define PIPEX_H

#include "../lib/libft/libft.h"
#include "../lib/libft/gnl/get_next_line.h"
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

char  *parse_commands(int argc, char **argv, char **envp);
char  **get_path_env_var(char **envp);
char    *validate_command(char *arg, char **dirs);
void    child_process(char **argv, char **envp, int *fd, int i);
void    parent_process(char **argv, char **envp, int *fd, int i);
void    exec_process(char **argv, char **envp);
void    exec_command(char *arg, char **envp);

#endif

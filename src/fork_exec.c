/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:09:39 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/09 13:09:46 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// func to execute the command handled by the process
void	exec_command(char *arg, char **envp)
{
	char	**dirs;
	char	**cmd_arr;
	char	*cmd;

	dirs = get_path_env_var(envp);
	cmd_arr = ft_split(arg, ' ');
	cmd = validate_command(cmd_arr[0], dirs);
	ft_arr2d_free(dirs);
	if (!cmd)
		exit(1);
	if (execve(cmd, cmd_arr, envp) == -1)
		exit(1);
}

// function that executes the processes tasks
// pid == 0 for child process(es)
// pid == 1 for parent process
void	exec_process(char *arg, char **envp)
{
	pid_t	pid;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
	{
		close(pipe_fds[0]);
		dup2(pipe_fds[1], STDOUT_FILENO);
		exec_command(arg, envp);
	}
	else
	{
		close(pipe_fds[1]);
		dup2(pipe_fds[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

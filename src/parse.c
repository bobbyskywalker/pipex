/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:10:02 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/09 13:10:07 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// function to extract the PATH environment variable
// returns the directories found as a 2D array
// delimited by ':'
char	**get_path_env_var(char **envp)
{
	char	**dirs;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			dirs = ft_split(envp[i] + 5, ':');
			return (dirs);
		}
		i++;
	}
	return (NULL);
}

// function to validate the input command presence
char	*validate_command(char *arg, char **dirs)
{
	int		i;
	char	*cmd_path;
	char	*path;

	i = 0;
	while (dirs[i])
	{
		cmd_path = ft_strjoin(dirs[i], "/");
		path = ft_strjoin(cmd_path, arg);
		free(cmd_path);
		if (!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	errno = ENOENT;
	perror("pipex");
	exit(EXIT_FAILURE);
}

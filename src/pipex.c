/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:10:09 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/09 13:10:15 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <fcntl.h>

// high level function, checks for here_doc as input file presence
// the 'i' argv index changes if here_doc is present due to LIMITER
// being passed as a parameter
void	pipex(bool is_here_doc, int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (is_here_doc)
	{
		handle_here_doc(argv[2]);
		fd_in = open("tmp_file", O_RDONLY, 0777);
		fd_out = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0777);
		i = 3;
	}
	else
	{
		fd_in = open(argv[1], O_RDONLY, 0777);
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		i = 3;
	}
	file_errors(fd_in, fd_out);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	while (i < argc - 2)
		exec_process(argv[i++], envp);
	del_tmp(is_here_doc);
	dup2(fd_out, STDOUT_FILENO);
	exec_command(argv[argc - 2], envp);
}

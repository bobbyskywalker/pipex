/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:09:47 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/09 13:09:53 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

bool	check_here_doc(char *arg)
{
	if (!ft_strncmp("here_doc", arg, 8))
		return (true);
	return (false);
}

// function to gather input from stdin
// stores the content in a temporary file
void	handle_here_doc(char *limiter)
{
	char	*line;
	int		fd_tmp;

	fd_tmp = open("tmp_file", O_RDWR | O_CREAT, 0777);
	while (1)
	{
		line = get_next_line(0);
		if (!line || !ft_strncmp(line, limiter, ft_strlen(line) - 1))
			break ;
		write(fd_tmp, line, ft_strlen(line));
		free(line);
	}
	close(fd_tmp);
}

// deletes the temporary file if existent
void	del_tmp(bool is_here_doc)
{
	if (is_here_doc)
		unlink("tmp_file");
}

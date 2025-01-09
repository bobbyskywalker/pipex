/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:09:26 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/09 13:09:34 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	file_errors(int fd_in, int fd_out)
{
	if (fd_in == -1 || fd_out == -1)
	{
		errno = EBADF;
		close(fd_in);
		close(fd_out);
		perror("pipex");
		exit(EXIT_FAILURE);
	}
}

void	handle_arg_errors(int argc)
{
	if (argc < 5)
	{
		errno = EINVAL;
		perror("valid exec: ./pipex infile cmd cmd outfile");
		exit(EXIT_FAILURE);
	}
}

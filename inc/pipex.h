/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:10:38 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/09 13:10:39 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/gnl/get_next_line.h"
# include "../lib/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// fork execution
void	exec_command(char *arg, char **envp);
void	exec_process(char *arg, char **envp);

// command search & validation
char	**get_path_env_var(char **envp);
char	*validate_command(char *arg, char **dirs);

// error handlers
void	handle_arg_errors(int argc);
void	file_errors(int fd_in, int fd_out);

// here_doc utilities
bool	check_here_doc(char *arg);
void	handle_here_doc(char *limiter);
void	del_tmp(bool is_here_doc);

// main algorithm
void	pipex(bool is_here_doc, int argc, char **argv, char **envp);

#endif

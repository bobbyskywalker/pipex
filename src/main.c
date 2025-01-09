/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:09:54 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/09 13:10:01 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	bool	is_here_doc;

	handle_arg_errors(argc);
	is_here_doc = check_here_doc(argv[1]);
	pipex(is_here_doc, argc, argv, envp);
	return (0);
}

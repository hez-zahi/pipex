/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:14:43 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 04:22:24 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **env)
{
	t_pip_bo	*pipex;
	int			i;

	if (ac == 5)
	{
		i = 2;
		pipex = creat_linkdlist(ac, av, i);
		pipex = creat_pipe(ac, av, pipex);
		pipex = child_process(pipex, env);
	}
	else
		write (2, "nombre d'argument invalide\n", 27);
}

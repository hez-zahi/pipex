/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bounus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:17:32 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:35:43 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char **env)
{
	t_pip_bo	*pipex;
	int			i;

	if (ac == 6 && !ft_strncmp(av[1], "here_doc", 8))
	{
		i = 3;
		write(1, "pipe heredoc>", 13);
		while (ft_strncmp(get_next_line(0), av[2], ft_strlen(av[2])))
			write(1, "pipe heredoc>", 13);
		pipex = creat_linkdlist(ac, av, i);
		creat_pipe_heredoc(ac, av, pipex);
		pipex = child_process(pipex, env);
	}
	else if (ac >= 5)
	{
		i = 2;
		pipex = creat_linkdlist(ac, av, i);
		pipex = creat_pipe(ac, av, pipex);
		pipex = child_process(pipex, env);
	}
	else
		write(2, ERR_ARG, sizeof(ERR_ARG));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pipe_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:14:13 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:34:44 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	creat_file(char *filename, int lo_method)
{
	if (lo_method == 0)
	{
		if (access(filename, F_OK) == 0)
			return (open(filename, O_RDONLY));
		else
		{
			write(2, "zsh: No such file or directory: ", 32);
			write(2, filename, ft_strlen(filename));
			return (2);
		}
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644));
}

t_pip_bo	*creat_pipe_heredoc(int ac, char *av[], t_pip_bo *pipex)
{
	t_pip_bo	*tmp;
	int			fd[2];

	tmp = pipex;
	while (tmp->next)
	{
		if (pipe(fd) < 0)
			perror("error");
		tmp->next->infile = fd[0];
		tmp->outfile = fd[1];
		tmp = tmp->next;
	}
	tmp->outfile = creat_file(av[ac - 1], 1);
	return (pipex);
}

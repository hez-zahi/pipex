/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:10:41 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 04:33:01 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(char **env, t_pip_bo *pipex)
{
	pid_t	pid;
	char	**l;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->infile, 0);
		dup2(pipex->outfile, 1);
		l = ft_split(pipex->cmd, ' ');
		if (pipex->cmd && ft_patht(pipex->cmd, env))
		{
			if (execve(ft_patht(pipex->cmd, env), l, env) < 0)
				perror("errno");
		}
		else
			write(2, "command not found", 17);
	}
	close(pipex->infile);
	close(pipex->outfile);
}

t_pip_bo	*child_process(t_pip_bo *pipex, char **env)
{
	int			i;
	int			j;
	t_pip_bo	*dmp;

	dmp = pipex;
	i = 0;
	while (dmp)
	{
		child(env, dmp);
		dmp = dmp->next;
		i++;
	}
	j = 0;
	while (j < i)
	{
		waitpid(0, NULL, 0);
		j++;
	}
	return (pipex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:14:43 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/02/06 23:05:52 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

void	child_process(char *av[], char **env, int *fd)
{
	int		infile;
	char	**l1;

	infile = creat_file(av[1], 0);
	close(fd[0]);
	dup2(fd[1], 1);
	dup2(infile, 0);
	l1 = ft_split(av[2], ' ');
	if (av[2] && ft_patht(av[2], env))
	{
		if (execve(ft_patht(av[2], env), l1, env) < 0)
			perror("errno");
	}
	else
		write(2, "command not found", 17);
}

void	parent_process(char *av[], char **env, int *fd)
{
	int		outfile;
	char	**l2;

	outfile = creat_file(av[4], 1);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	l2 = ft_split(av[3], ' ');
	if (av[3] && ft_patht(av[3], env))
	{
		if (execve(ft_patht(av[3], env), l2, env) < 0)
			perror("errno");
	}
	else
		write(2, "command not found", 17);
}

int	main(int ac, char *av[], char **env)
{
	int		fd[2];
	pid_t	x;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			perror("error");
		x = fork();
		if (x == 0)
			child_process(av, env, fd);
		waitpid(x, NULL, 0);
		parent_process(av, env, fd);
	}
	else
		write (2, "nombre d'argument invalide\n", 27);
}

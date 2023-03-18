/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:19:41 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 04:24:04 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct pip_bo
{
	char			*cmd;
	int				infile;
	int				outfile;
	int				index;
	struct pip_bo	*next;
}t_pip_bo;

char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*patht(char *cmd, char **env);
int			creat_file(char *filename, int lo_method);
char		*ft_patht(char *cmd, char **env);
t_pip_bo	*creat_linkdlist(int ac, char *av[], int i);
t_pip_bo	*creat_pipe(int ac, char *av[], t_pip_bo *pipex);
t_pip_bo	*child_process(t_pip_bo *pipex, char **env);
#endif

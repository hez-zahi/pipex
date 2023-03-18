/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:10:34 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:33:46 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# define ERR_ARG "nombre d'argumet invalude"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
size_t		ft_strlen1(const char *s);
char		*patht(char *cmd, char **env);
int			creat_file(char *filename, int lo_method);
char		*ft_patht(char *cmd, char **env);
t_pip_bo	*creat_linkdlist(int ac, char *av[], int i);
t_pip_bo	*creat_pipe(int ac, char *av[], t_pip_bo *pipex);
t_pip_bo	*child_process(t_pip_bo *pipex, char **env);
t_pip_bo	*creat_pipe_heredoc(int ac, char *av[], t_pip_bo *pipex);
char		*get_next_line(int fd);
char		*ft_strjoin1(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*copy(char *txt, char *save, int i);
char		*conc(char *stash, char *buf);
#endif

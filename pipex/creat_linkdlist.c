/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_linkdlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:12:54 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:34:40 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pip_bo	*ft_lstnew(char *cmd, int index)
{
	t_pip_bo	*new;

	new = NULL;
	new = (t_pip_bo *)malloc(sizeof(t_pip_bo));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->infile = 0;
	new->outfile = 1;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_pip_bo	*last_add(t_pip_bo *head, char *cmd, int index)
{
	t_pip_bo	*b;
	t_pip_bo	*tmp;

	b = ft_lstnew(cmd, index);
	if (!head)
		head = b;
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = b;
	}
	return (head);
}

t_pip_bo	*creat_linkdlist(int ac, char *av[], int i)
{
	t_pip_bo	*head;

	head = NULL;
	while (i < ac - 1)
	{
		head = last_add(head, av[i], i - 2);
		i++;
	}
	return (head);
}

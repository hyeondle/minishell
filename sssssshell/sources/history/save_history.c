/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 04:12:16 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/19 10:58:00 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	save_l_hist(int fd, t_history *l_hist)
{
	t_history	*temp;

	temp = l_hist;
	while (temp->next != NULL)
	{
		write(fd, temp->history, ft_strlen(temp->history));
		temp = temp->next;
	}
}

static void	save_s_hist(int fd, t_history *s_hist)
{
	t_history	*temp;

	temp = s_hist;
	if (!fd || !s_hist)
		return ;
	if (temp && temp->next != NULL && temp->history != NULL)
		write(fd, "\n", 1);
	while (temp && temp->next != NULL && temp->history != NULL)
	{
		write(fd, temp->history, ft_strlen(temp->history));
		write(fd, "\n", 1);
		temp = temp->next;
	}
	write(fd, temp->history, ft_strlen(temp->history));
}

void	save_history(t_setting **setting)
{
	int			fd;
	int			i;
	t_setting	*set;

	fd = open(HISTORY_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening .minishell_history");
		return ;
	}
	i = 0;
	set = *setting;
	if (set->l_history != NULL)
		save_l_hist(fd, set->l_history);
	save_s_hist(fd, set->s_history);
	close(fd);
}

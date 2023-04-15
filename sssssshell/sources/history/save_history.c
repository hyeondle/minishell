/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 04:12:16 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/16 04:17:49 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	while (set->s_history->next != NULL)
	{
		write(fd, set->s_history->history, ft_strlen(set->s_history->history));
		write(fd, "\n", 2);
		set->s_history = set->s_history->next;
		i++;
	}
	close(fd);
}

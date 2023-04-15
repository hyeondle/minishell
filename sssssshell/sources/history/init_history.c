/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:53:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/16 04:00:31 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_history(t_setting **setting)
{
	t_setting	*set;
	t_history	*history;
	int			fd;
	int			i;

	set = *setting;
	i = 0;
	fd = open(HISTORY_FILE, O_RDONLY);
	if (fd == -1)
		return ;
	set->l_history[i] = get_next_line(fd);
	while (set->l_history[i])
	{
		add_history(set->l_history[i]);
		i++;
		set->l_history[i] = get_next_line(fd);
	}
	history = (t_history *)malloc(sizeof(t_history));
	history->history = NULL;
	history->next = NULL;
	set->s_history = history;
	close(fd);
}
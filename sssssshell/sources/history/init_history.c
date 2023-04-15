/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:53:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/16 05:15:04 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_history(t_setting **setting)
{
	t_history	*history;
	t_history	*temp;
	char		*str;
	int			fd;
	int			i;

	i = 0;
	fd = open(HISTORY_FILE, O_RDONLY);
	if (fd == -1)
		return ;
	str = get_next_line(fd);
	if (!str)
		return ;
	history = (t_history *)malloc(sizeof(t_history));
	if (!history)
		return ;
	history->next = NULL;
	temp = history;
	while (str)
	{
		history->history = ft_strdup(str);
		add_history(str);
		i++;
		str = get_next_line(fd);

	}
	close(fd);
}
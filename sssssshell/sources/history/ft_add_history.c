/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:57:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/16 04:11:55 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_history(char *input, t_setting **set)
{
	t_history	*s_history;
	t_history	*history;
	char		*str;

	add_history(input);
	history = (t_history *)malloc(sizeof(t_history));
	if (!history)
		return ;
	str = ft_strdup(input);
	if (!str)
		return ;
	history->history = str;
	history->next = NULL;
	if ((*set)->s_history->history == NULL)
		(*set)->s_history = history;
	else
	{
		s_history = (*set)->s_history;
		while (s_history->next != NULL)
			s_history = s_history->next;
		s_history->next = history;
	}
}
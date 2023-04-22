/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:52:45 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 20:10:15 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	token_check(char *c, int i)
{
	if (c[i + 1])
	{
		if (c[i] == '<' && c[i + 1] == '<')
			return (2);
		else if (c[i] == '>' && c[i + 1] == '>')
			return (3);
	}
	if (c[i] == '|' || c[i] == '<' || c[i] == '>')
	{
		return (1);
	}
	return (0);
}

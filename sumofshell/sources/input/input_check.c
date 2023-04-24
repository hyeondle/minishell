/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:40:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/24 09:54:30 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check input if it ends w/ closed quote or opend quote
#include "../../includes/minishell.h"

static void	quote_change(t_quote *quote, char c)
{
	if (*quote == SINGLE)
	{
		if (c == '\'')
			*quote = NONE;
	}
	else if (*quote == DOUBLE)
	{
		if (c == '\"')
			*quote = NONE;
	}
}

int	input_check(char *input)
{
	t_quote	quote;
	int		i;

	quote = NONE;
	i = 0;
	if (!input)
		return 0;
	while (input[i])
	{
		if (quote == NONE)
		{
			if (input[i] == '\'')
				quote = SINGLE;
			if (input[i] == '\"')
				quote = DOUBLE;
		}
		else
			quote_change(&quote, input[i]);
		i++;
	}
	if (quote == NONE)
		return (0);
	return (1);
}

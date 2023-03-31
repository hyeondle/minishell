/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:10:35 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/29 14:41:07 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	input_check(char *input)
{
	e_quote	quote;
	int		i;

	quote = NONE;
	i = 0;
	while (input[i])
	{
		if (quote == NONE)
		{
			if (input[i] == '\'')
				quote = SINGLE;
			if (input[i] == '\"')
				quote = DOUBLE;
		}
		else if (quote == SINGLE)
		{
			if (input[i] == '\'')
				quote = NONE;
		}
		else if (quote == DOUBLE)
		{
			if (input[i] == '\"')
				quote = NONE;
		}
		i++;
	}
	if (quote == NONE)
		return 0;
	return 1;
}

char	*check_input_add(char *additional)
{
	int	i;
	char	*temp;

	i = input_check(additional);
	if (i == 0)
		temp = ft_strjoin(additional, "\n");
	else
		return (additional);
	return temp;
}

char	*get_input(void)
{
	char	*input;
	char	*input_add;
	int		i;

	input = readline("minishell> ");
	if (!input)
	{
		printf("\n");
		return (NULL);
	}
	i = input_check(input);
	if (i == 1)
	{
		while (i)
		{
			input_add = readline("> ");
			if (!input_add)
				break;
			input_add = check_input_add(input_add);
			input = ft_strjoin(input, input_add);
			free(input_add);
			i = input_check(input);
		}
	}
	return (input);
}

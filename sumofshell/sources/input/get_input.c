/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:33:48 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 20:18:55 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//get whole input
#include "../../includes/minishell.h"

char	*get_input(t_setting **set)
{
	char	*input;
	char	*input_add;
	int		i;

	input = readline("minishell> ");
	if (!input)
	{
		ft_exit(NULL, set);
	}
	i = input_check(input);
	if (i == 1)
	{
		input = ft_strjoin(input, "\n");
		while (i)
		{
			input_add = readline("> ");
			if (!input_add)
				break ;
			input_add = check_input_add(input_add);
			input = ft_strjoin(input, input_add);
			free(input_add);
			i = input_check(input);
		}
	}
	return (input);
}

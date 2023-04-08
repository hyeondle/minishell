/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:03:12 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 02:03:51 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	operation(char *input, t_setting **set)
{
	char	**tokenized_str;
	int		i;

	i = 0;
	tokenized_str = shell_split(input);
	tokenized_str = split_by_token(tokenized_str);
	while (tokenized_str[i])
	{
		tokenized_str[i] = get_env_to_str(set, tokenized_str[i]);
		i++;
	}
	i = 0;
	while (tokenized_str[i])
	{
		printf("%d : %s%c\n", i, tokenized_str[i], '$');
		i++;
	}
}

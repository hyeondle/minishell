/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delimeter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:53:22 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:53:48 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	check_delimeter(char *str)
{
	int	i;
	int size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
			i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
			i++;
		}
		if (token_check(str[i]) && str[i] != '\0')
			size++;
		if (str[i] != '\0')
			i++;
	}
	return (size);
}

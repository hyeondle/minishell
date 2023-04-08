/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split_case_alone.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:57:38 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:57:57 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	**token_split_case_alone(char **str, int i, int k)
{
	char	**temp;
	int		n;

	n = 0;
	temp = (char **)malloc(sizeof(char *) * (dtab_size(str) + 1));
	while (n < i)
	{
		temp[n] = str[n];
		n++;
	}
	temp[n] = deli_char(str[i][k]);
	n++;
	while (str[n])
	{
		temp[n] = str[n];
		n++;
	}
	temp[n] = NULL;
	free(str[i]);
	free(str);
	return (temp);
}

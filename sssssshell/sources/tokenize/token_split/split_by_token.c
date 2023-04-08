/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:49:06 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:51:08 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**split_by_token(char **str)
{
	char	**temp_2;
	int		i;
	int		k;
	int		c;

	i = 0;
	k = 0;
	temp_2 = str;
	while (temp_2[i])
	{
		if (check_delimeter(temp_2[i]))
		{
			k = check_delimeter_type_i(temp_2[i]);
			c = split_case_index_check(temp_2, i, k);
			temp_2 = split_by_case(temp_2, i, k);
			i = i + c;
		}
		else
			i++;
	}
	return (temp_2);
}

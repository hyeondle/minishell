/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:56 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/05 12:56:32 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	split_case_index_check(char **str, int i, int k)
{
	if (k == 0)
	{
		if (str[i][k + 1] != '\0')
			return 1;
		else
			return 1;
	}
	else
	{
		if (str[i][k + 1] == '\0')
			return 2;
		else
			return 2;
	}
}

char	**split_by_case(char **str, int i, int k)
{
	char	**temp;

	if (k == 0)
	{
		if (str[i][k + 1] != '\0')
			temp = token_split_case_no_front(str, i, k);
		else
			return str;
			//temp = token_split_case_alone(str, i, k); // 에러남. 수정
	}
	else
	{
		if (str[i][k + 1] == '\0')
			temp = token_split_case_no_back(str, i, k);
		else
			temp = go_split(str, i, k);
	}
	return (temp);
}

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

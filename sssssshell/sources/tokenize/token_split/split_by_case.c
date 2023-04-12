/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:50:42 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:56:20 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
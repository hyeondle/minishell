/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_token_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:15:17 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/05 12:56:25 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**go_split(char **str, int i, int k)
{
	char	**temp;
	int		n;

	n = 0;
	temp = (char **)malloc(sizeof(char *) * (dtab_size(str) + 3));
	while (n < i)
	{
		temp[n] = str[n];
		n++;
	}
	temp[n] = ft_substr(str[i], 0, k);
	temp[n + 1] = deli_char(str[i][k]);
	temp[n + 2] = ft_substr(str[i], k + 1, ft_strlen(str[i]) - (k + 1));
	n++;
	while (str[n])
	{
		temp[n + 2] = str[n];
		n++;
	}
	temp[n + 2] = NULL;
	free(str[i]);
	free(str);
	return (temp);
}

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

char	**token_split_case_no_back(char **str, int i, int k)
{
	char	**temp;
	int		n;

	n = 0;
	temp = (char **)malloc(sizeof(char *) * (dtab_size(str) + 2));
	while (n < i)
	{
		temp[n] = str[n];
		n++;
	}
	temp[n] = ft_substr(str[i], 0, k);
	temp[n + 1] = deli_char(str[i][k]);
	n++;
	while (str[n])
	{
		temp[n + 1] = str[n];
		n++;
	}
	temp[n + 1] = NULL;
	free(str[i]);
	free(str);
	return (temp);
}

char	**token_split_case_no_front(char **str, int i, int k)
{
	char	**temp;
	int		n;

	n = 0;
	temp = (char **)malloc(sizeof(char *) * (dtab_size(str) + 2));
	while (n < i)
	{
		temp[n] = str[n];
		n++;
	}
	temp[n] = deli_char(str[i][k]);
	temp[n + 1] = ft_substr(str[i], k + 1, ft_strlen(str[i]) - (k + 1));
	n++;
	while (str[n])
	{
		temp[n + 1] = str[n];
		n++;
	}
	temp[n + 1] = NULL;
	free(str[i]);
	free(str);
	return (temp);
}

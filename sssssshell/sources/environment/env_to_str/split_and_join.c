/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 05:11:16 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/09 05:15:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
//non_modified

int	get_third_size(char *str)
{
	int k;

	k = 0;
	while (str[k] != '$')
		k++;
	k++;
	while (str[k] != '$' && str[k] != '\0' && str[k] != '\"' && str[k] != ' ' && str[k] != '\'')
		k++;
	return (k);
}

char	*split_and_join(char *p_str, int i, char *value)
{
	int	j;
	char	*str1;
	char	*str2;
	char	*str3;

	j = 0;
	str1 = (char *)malloc(sizeof(char) * (i + 1));
	str2 = (char *)malloc(sizeof(char) * (ft_strlen(value) + 1));
	str3 = (char *)malloc(sizeof(char) * (ft_strlen(p_str) - get_third_size(p_str)) + 1);
	while (j < i)
	{
		str1[j] = p_str[j];
		j++;
	}
	str1[j] = '\0';
	j = 0;
	while (value[j])
	{
		str2[j] = value[j];
		j++;
	}
	str2[j] = '\0';
	j = 0;
	while (p_str[j + get_third_size(p_str)])
	{
		str3[j] = p_str[j + get_third_size(p_str)];
		j++;
	}
	str3[j] = '\0';
	str1 = ft_strjoin(str1, str2);
	str1 = ft_strjoin(str1, str3);
	return (str1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:59:29 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/05 12:52:52 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_env_mark(char	*str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			while (str[++i] != '\'')
				i++;
			i++;
		}
		if (str[i] == '$')
			return 1;
	}
	return 0;
}

char *get_env_key(char *str, int i)
{
	int k;
	int	j;
	char *key;

	k = i + 1;
	j = 0;
	while (str[k] != '$' || str[k] != '\0' || str[k] != '\"' || str[k] != ' ')
		k++;
	key = (char *)malloc(sizeof(char) * (k - i));
	if (!key)
		return NULL;
	while (i < k)
	{
		str[i + i] = key[j];
		i++;
		j++;
	}
	key[j] = '\0';
	return key;
}

int	get_third_size(char *str)
{
	int k;

	k = 0;
	while (str[k] != '$')
		k++;
	k++;
	while (str[k] != '$' || str[k] != '\0' || str[k] != '\"' || str[k] != ' ')
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
	str1 = (char *)malloc(sizeof(char) * i);
	str2 = (char *)malloc(sizeof(char) * (ft_strlen(value) + 1));
	str3 = (char *)malloc(sizeof(char) * (ft_strlen(p_str) - get_third_size(p_str)) + 1);
	while (j < i)
	{
		str1[j] = p_str[j];
		j++;
	}
	j = 0;
	while (value[j])
	{
		str2[j] = value[j];
		j++;
	}
	j = 0;
	while (p_str[j + get_third_size(p_str)])
	{
		str3[j] = p_str[j + get_third_size(p_str)];
		j++;
	}
	str1 = ft_strjoin(str1, str2);
	str1 = ft_strjoin(str1, str3);
	return (str1);
}

char	*get_env_to_str(t_setting **set, char *str)
{
	int 	i;
	char	*key;
	char	*value;
	char	*j_str;

	i = 0;
	j_str = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			while (str[++i] != '\'')
				i++;
			i++;
		}
		if (str[i] == '$')
		{
			key = get_env_key(str, i);
			value = get_env_value((*set)->env_list, key);
			j_str = split_and_join(str, i, value);
			free(str);
			return (j_str);
		}
		i++;
	}
	return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:21:34 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 23:30:06 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	check_env_mark(char	*str)
// {
// 	int i;
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\'')
// 		{
// 			while (str[++i] != '\'')
// 				i++;
// 			i++;
// 		}
// 		if (str[i] == '$')
// 			return 1;
// 	}
// 	return 0;
// }

// char *get_env_key(char *str, int i)
// {
// 	int k;
// 	int	j;
// 	char *key;

// 	k = i + 1;
// 	j = 0;
// 	while (str[k] != '$' && str[k] != '\0' && str[k] != '\"' && str[k] != ' ' && str[k] != '\'')
// 		k++;
// 	key = (char *)malloc(sizeof(char) * (k - i));
// 	if (!key)
// 		return NULL;
// 	while (i < k)
// 	{
// 		key[j] = str[i + 1];
// 		i++;
// 		j++;
// 	}
// 	key[j - 1] = '\0';
// 	return key;
// }

// int	get_third_size(char *str)
// {
// 	int k;

// 	k = 0;
// 	while (str[k] != '$')
// 		k++;
// 	k++;
// 	while (str[k] != '$' && str[k] != '\0' && str[k] != '\"' && str[k] != ' ' && str[k] != '\'')
// 		k++;
// 	return (k);
// }

// char	*split_and_join(char *p_str, int i, char *value)
// {
// 	int	j;
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;

// 	j = 0;
// 	str1 = (char *)malloc(sizeof(char) * (i + 1));
// 	str2 = (char *)malloc(sizeof(char) * (ft_strlen(value) + 1));
// 	str3 = (char *)malloc(sizeof(char) * (ft_strlen(p_str) - get_third_size(p_str)) + 1);
// 	while (j < i)
// 	{
// 		str1[j] = p_str[j];
// 		j++;
// 	}
// 	str1[j] = '\0';
// 	j = 0;
// 	while (value[j])
// 	{
// 		str2[j] = value[j];
// 		j++;
// 	}
// 	str2[j] = '\0';
// 	j = 0;
// 	while (p_str[j + get_third_size(p_str)])
// 	{
// 		str3[j] = p_str[j + get_third_size(p_str)];
// 		j++;
// 	}
// 	str3[j] = '\0';
// 	str1 = ft_strjoin(str1, str2);
// 	str1 = ft_strjoin(str1, str3);
// 	return (str1);
// }

// char	*get_env_to_str(t_setting **set, char *str)
// {
// 	int 	i;
// 	char	*key;
// 	char	*value;
// 	char	*j_str;
// 	char	*tmp;
// 	t_quote	quote;

// 	i = 0;
// 	quote = NONE;
// 	j_str = str;
// 	while (j_str[i])
// 	{
// 		if (j_str[i] == '\"' && quote == NONE)
// 			quote = DOUBLE;
// 		else if (j_str[i] == '\"' && quote == DOUBLE)
// 			quote = NONE;
// 		if (j_str[i] == '\'' && quote != DOUBLE)
// 		{
// 			i++;
// 			while (j_str[i] != '\'' && j_str[i] != '\0')
// 				i++;
// 			if (j_str[i] != '\0')
// 				i++;
// 		}
// 		if (j_str[i] == '$')
// 		{
// 			key = get_env_key(j_str, i);
// 			value = get_env_value((*set)->env_list, key);
// 			if (!value)
// 				value = "";
// 			tmp = j_str;
// 			j_str = split_and_join(j_str, i, value);
// 			free(tmp);
// 			free(key);
// 			i = i + ft_strlen(value) - 1;
// 		}
// 		if (i != '\"' && j_str[i] != '\0')
// 			i++;
// 	}
// 	return (j_str);
// }

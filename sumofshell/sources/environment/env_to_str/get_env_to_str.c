/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:44:20 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/14 14:55:45 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
//잘못된 메모리 참조가 일어나고 있음. 해당 부분 수정할 것,
//작은 따옴표의 경우에서 달러기호를 확인하였을 때, 오류가 발생하는 것으로 보임.
//해당 부분의 추적을 좀 더 면밀하게 검토할 것
//아니면 차라리 splitandjoin을 새로 만들 것. 그 로직을 생각해서 하위 함수도 새로 구성할 것.
static t_quote quote_check(t_quote quote, char c);
int		have_dollar(char *str)
{
	int	i;
	t_quote	quote;

	i = 0;
	quote = NONE;
	while (str[i])
	{
		quote = quote_check(quote, str[i]);
		if (str[i] == '$' && quote != SINGLE)
		{
			if (str[i + 1] != '\0' && str[i + 1] != '\'' && str[i + 1] != '\"' && str[i + 1] != ' ' && str[i + 1] != '$')
				return (i);
		}
		i++;
	}
	return (-1);
}
// int		have_dollar(char *str)
// {
// 	int	i;
// 	t_quote	quote;

// 	i = 0;
// 	quote = NONE;
// 	while (str[i])
// 	{
// 		quote = quote_check(quote, str[i]);
// 		if (str[i] == '$' && quote != SINGLE)
// 		{
// 			if (str[i + 1] != '\0' && str[i + 1] != '\'' && str[i + 1] != '\"' && str[i + 1] != ' ' && str[i + 1] != '$')
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

char	*env_to_str(t_setting **set, char *str, int i)
{
	char	*value;
	char	*t_str;
	char	*storage;
	int		k;

	value = find_key_and_get_env_value(str, i, set);
	if (!value)
		value = "";
	storage = str;
	printf("\nbef : %s\n",str);
	t_str = split_and_join(str, i, value);
	printf("\naft : %s\n", t_str);
	//free(storage);
	return (t_str);
}

static t_quote quote_check(t_quote quote, char c)
{
	if (c == '\"' && quote == NONE)
		return (DOUBLE);
	else if (c == '\"' && quote == DOUBLE)
		return (NONE);
	else if (c == '\'' && quote == NONE)
		return (SINGLE);
	else if (c == '\'' && quote == SINGLE)
		return (NONE);
	else
		return (quote);
	return (quote);
}

// char	*get_env_to_str(t_setting **set, char *str)
// {
// 	int		i;
// 	char	*j_str;
// 	t_quote	quote;

// 	i = 0;
// 	quote = NONE;
// 	j_str = str;
// 	while (j_str[i])
// 	{
// 		quote = quote_check(quote, j_str[i]);
// 		if (quote != SINGLE && j_str[i] == '$')
// 		{
// 			j_str = env_to_str(set, j_str, i);
// 			continue ;
// 		}
// 		if (j_str[i] != '\0')
// 			i++;
// 	}
// 	if (have_dollar(j_str))
// 	{
// 		j_str = get_env_to_str(set, j_str);
// 	}
// 	return (j_str);
// }
char	*get_env_to_str(t_setting **set, char *str)
{
	int		i;
	char	*tmp;
	t_quote	quote;

	while ((i = have_dollar(str)) != -1)
	{
		quote = NONE;
		while (str[i])
		{
			quote = quote_check(quote, str[i]);
			if (quote != SINGLE && str[i] == '$')
			{
				tmp = env_to_str(set, str, i);
				free(str);
				str = tmp;
				break;
			}
			if (str[i] != '\0')
				i++;
		}
	}
	return (str);
}

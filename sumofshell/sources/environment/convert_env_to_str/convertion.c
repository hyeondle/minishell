/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:23:42 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/28 19:08:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*join_sentence(char *str, int i, char *key, char *value)
{
	char	*joined;
	char	*semi;
	char	*duo;

	joined = ft_substr(str, 0, i);
	semi = ft_strjoin(joined, value);
	free(joined);
	joined = ft_substr(str, i + ft_strlen(key) + 1, ft_strlen(str) - ft_strlen(key) + 1);
	duo = ft_strjoin(semi, joined);
	free(semi);
	return (duo);
}

static int	dollardollar(char *str)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NONE;
	while (str[i])
	{
		if (str[i] == '\'' && quote == SINGLE)
			quote = NONE;
		else if (str[i] == '\'' && quote == NONE)
			quote = SINGLE;
		if (str[i] == '$' && quote != SINGLE)
			return (i);
		i++;
	}
	return (-1);
}

static char	*take_my_env(t_setting **set, char *str, int i)
{
	char	*temp;
	char	*value;
	char	*key;

	key = get_env_key(str, i);
	value = get_env_value((*set)->env_list, key);
	if (!value)
		value = "";
	temp = join_sentence(str, i, key, value);
	//free(str);
	//free(key);
	if (dollardollar(temp) >= 0)
		temp = take_my_env(set, temp, dollardollar(temp));
	return (temp);
}

char	*convertion(t_setting **set, char *str)
{
	int		i;
	char	*converted;
	t_quote	quote;

	i = 0;
	quote = NONE;
	converted = str;
	if (dollardollar(str) >= 0)
		converted = take_my_env(set, str, dollardollar(str));
	return (converted);
}
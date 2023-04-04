/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:56:41 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/05 01:04:41 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//operate when export comes
t_env	*make_new_env(char *env_str)
{
	char	*env;
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	if(!new_env)
		return NULL;
	env = NULL;
	env = ft_strdup(env_str);
	new_env->env = env;
	new_env->next = NULL;
	return (new_env);
}

int	new_env(t_setting *set, char *env_str)
{
	t_env	*temp_env;

	temp_env = set->env;
	while (temp_env->next != NULL)
		temp_env = temp_env->next;
	temp_env->next = make_new_env(env_str);
	if (temp_env->next == NULL)
		return (1);
	else
		return (0);
}

int	check_env_str(char *str)
{

	//환경변수 마주치면 공백이나 따옴표 볼 때 까지 넘겨주는거임. 아니면 널 반환
	int	i;

	i = 0;
	while(str[i] != '$')
		i++;
	//하나 문장 만들고 말록한다음 $이후 델리미터까지 전달할 것
}

//echo $?abcd => 종료상태abcd
//echo $HELLO => hello
//echo $HELLOaa => 아무것도 없듬
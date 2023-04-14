/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:43:19 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/14 23:55:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//각종 에러 및 예외 처리 할 것, 빌트인 안이 아니면 execute실행하도록 함수 하나 더 추가

static int	isexecute(char **inputs, t_setting **set)
{
	char	*path;
	char	**e_path;
	char	*exec;
	int		i;

	path = get_env_value((*set)->env_list, "PATH");
	if (!path)
		return (-1);
	e_path = ft_split(path, ':');
	i = 0;
	while (e_path[i])
	{
		exec = ft_strjoin(e_path[i], "/");
		exec = ft_strjoin(exec, inputs[0]);
		if (access(exec, X_OK) == 0)
			break ;
		free(exec);
		exec = NULL;
		i++;
	}
	if (exec == NULL)
		return (-1);//error출력
	free(path);
	i = 0;
	while (e_path[i])
	{
		free(e_path[i]);
		i++;
	}
	free(e_path);
	path = inputs[0];
	inputs[0] = ft_strdup(exec);
	free(path);
	execve(exec, inputs, (*set)->envp);
	free(exec);
	perror("execve");
	return (0);
}

int	execute(char **inputs, t_setting **set)
{
	char	*o;
	int		flag;

	o = inputs[0];
	if (o == NULL)
		return (1);
	if (ft_strcmp(o, "echo") == 0)
		ft_echo(inputs);
	else if (ft_strcmp(o, "cd") == 0)
		return (0);
	else if (ft_strcmp(o, "env") == 0)
		ft_env((*set)->envp);
	else if (ft_strcmp(o, "exit") == 0)
		ft_exit(inputs, set);
	else if (ft_strcmp(o, "export") == 0)
		ft_export(set, inputs);
	else if (ft_strcmp(o, "ls") == 0)
		return (0);
	else if (ft_strcmp(o, "pwd") == 0)
		return (0);
	else if (ft_strcmp(o, "unset") == 0)
		ft_unset(set, inputs);
	else
		isexecute(inputs, set);
	return (0);
}

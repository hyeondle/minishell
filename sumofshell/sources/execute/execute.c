/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:43:19 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/28 20:09:42 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//각종 에러 및 예외 처리 할 것, 빌트인 안이 아니면 execute실행하도록 함수 하나 더 추가
static char	*get_path(char **inputs, t_setting **set, char **e_path)
{
	int		i;
	char	*exec;

	i = 0;
	if (inputs[0][0] && inputs[0][1])
		if (inputs[0][0] == '.' && inputs[0][1] == '/')
		{
			exec = ft_strdup(inputs[0]);
			return (exec);
		}
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
	return (exec);
}

static void	free_e_path(char **e_path)
{
	int	i;

	i = 0;
	while (e_path[i])
	{
		free(e_path[i]);
		i++;
	}
	free(e_path);
}

static int	isexecute(char **inputs, t_setting **set)
{
	char	*path;
	char	**e_path;
	char	*exec;

	path = get_env_value((*set)->env_list, "PATH");
	if (!path)
		return (-1);
	e_path = ft_split(path, ':');
	exec = get_path(inputs, set, e_path);
	if (exec == NULL)
	{
		free(exec);
		exit(EXIT_FAILURE);
	}
	free(path);
	path = inputs[0];
	inputs[0] = ft_strdup(exec);
	execve(exec, inputs, (*set)->envp);
	free(exec);
	perror("execve");
	return (0);
}

int	execute(char **inputs, t_setting **set)
{
	char	*o;
	int		flag;
	pid_t	pid;

	flag = 0;
	o = inputs[0];
	if (o == NULL)
		return (1);
	// if (execute_check(o))
	// 	flag = go_execute(inputs, set, o);
	// else
	// {
	if (ft_strcmp(o, "exit") == 0)
		ft_exit(inputs, set);
	else if (ft_strcmp(o, "export") == 0)
		ft_export(set, inputs);
	else if (ft_strcmp(o, "unset") == 0)
		ft_unset(set, inputs);
	else
		test_ft(inputs, (*set)->envp, set);
	// }
	return ((*set)->child_exit_status);
}

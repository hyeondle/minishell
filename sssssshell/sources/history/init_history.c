/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:53:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/17 10:23:42 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//여기서 기존 히스토리를 읽어올 때, 연결리스트로 구현 하기
//마지막 종료시에 l_history와 s_history연결해서
//.minishell_history에 저장해야함
static t_history	*empty_history()
{
	t_history	*hist;

	hist = (t_history *)malloc(sizeof(t_history));
	if (!hist)
		return (NULL);
	hist->history = NULL;
	hist->next = NULL;
	return (hist);
}

static t_history	*ft_add_l_history(t_history *temp, char	*str)
{
	t_history	*new_hist;
	t_history	*previous_history;

	previous_history = temp;
	previous_history->history = ft_strdup(str);
	new_hist = (t_history *)malloc(sizeof(t_history));
	if (!new_hist)
		return (NULL);
	new_hist->history = NULL;
	new_hist->next = NULL;
	previous_history->next = new_hist;
	return (new_hist);
}

void	init_history(t_setting **setting)
{
	t_history	*hist;
	t_history	*temp;
	char		*str;
	int			fd;
	int			i;

	i = 0;
	fd = open(HISTORY_FILE, O_RDONLY);
	if (fd == -1)
		return ;
	str = get_next_line(fd);
	if (!str)
		return ;
	(*setting)->l_history = empty_history();
	if (!(*setting)->l_history)
		return ;
	temp = (*setting)->l_history;
	while (str)
	{
		temp = ft_add_l_history(temp, str);
		add_history(str);
		i++;
		str = get_next_line(fd);
	}
	temp->history = ft_strdup(""); //아니면 현재 temp free하고 지켜보기
	temp->next = NULL;
	close(fd);
}
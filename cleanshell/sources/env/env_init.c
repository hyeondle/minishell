/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:27:39 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/05 12:59:34 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void free_env(t_env_list *env)
{
    t_env_list *current = env;
    t_env_list *next;

    while (current)
    {
        next = current->next;
        free(current->env.key);
        free(current->env.value);
        free(current);
        current = next;
    }
}

int remove_env(t_env_list **env, const char *key)
{
    t_env_list *current = *env;
    t_env_list *prev = NULL;

    while (current)
    {
        if (ft_strcmp(current->env.key, key) == 0)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                *env = current->next;
            }
            free(current->env.key);
            free(current->env.value);
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }

    return -1;
}

int update_env(t_env_list *env, const char *key, const char *new_value)
{
    t_env_list *current = env;

    while (current)
    {
        if (ft_strcmp(current->env.key, key) == 0)
        {
            free(current->env.value);
            current->env.value = ft_strdup(new_value);
            return 0;
        }
        current = current->next;
    }

    return -1;
}

int add_env(t_env_list **env, const char *key_value_pair)
{
    t_env_list  *new_node;
    char        *pair;
    char        *equal_sign;

    new_node = (t_env_list *)malloc(sizeof(t_env_list));
    if (!new_node)
        return -1;
    pair = (char *)malloc(sizeof(char) * ft_strlen(key_value_pair));
    new_node->pair = pair;
    equal_sign = ft_strchr(key_value_pair, '=');
    if (!equal_sign)
    {
        free(new_node);
        return -1;
    }
	new_node->env.key = ft_strndup(key_value_pair, equal_sign - key_value_pair);
	new_node->env.value = ft_strdup(equal_sign + 1);
	new_node->next = *env;
	*env = new_node;
	return 0;
}

char *get_env_value(t_env_list *env, const char *key)
{
    t_env_list *current = env;

    while (current)
    {
        if (ft_strcmp(current->env.key, key) == 0)
        {
            return current->env.value;
        }
        current = current->next;
    }
    return NULL;
}

void init_env(char **envp, t_setting **set)
{
    t_env_list *head = NULL;
    int i = 0;

    while (envp[i])
    {
        add_env(&head, envp[i]);
        i++;
    }
    (*set)->env_list = head;
}

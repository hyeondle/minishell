#include "../includes/minishell.h"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef enum e_io
{
	INPUT = 0,
	OUTPUT = 1
}				t_io;

typedef enum e_rw
{
	READ = 0,
	WRITE = 1
}			t_rw;

typedef enum e_stdio
{
	STDIN = 0,
	STDOUT = 1
}				t_stdio;

typedef struct	s_redir_flag
{
	t_bool	infile;
	t_bool	outfile_overwrite;
	t_bool	outfile_append;
	t_bool	here_doc;
}				t_redir_flag;

typedef struct	s_info
{
	// struct s_redir_flag	redir_flag;
	int					num_pipe;
	// int					num_process;
	int					**pipes;
	// int					idx_prcs;
	// int					idx_arg;
	// char				**arg;
	char				**envp;
}				t_info;



typedef struct	s_deque
{
	struct s_node	*front;
	struct s_node	*rear;
}				t_deque;

typedef struct	s_node
{
	int				std_output;
	int				idx;
	// int				pipe_fd[2];
	char			**cmd;
//------------------------------------------------------------------
	char			**order_redir;
	char			**file_redir;
//------------------------------------------------------------------
	char			**infile;
	char			**outfile_ow;
	char			**outfile_apd;
	char			**here_doc;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

int		**create_pipes(int num_pipe);
void	init_redir_flag(t_redir_flag *flag);
void	init_info(t_info *info, char **arg_s, char **envp_orig);
void	first_process(t_info *info);
void	fork_process(t_info *info);
char	**append_str(char **arg, char *str);
char	**tokenize(char **envp);
char	*free_and_return(char **token_env_path, char *buffer);

void	ft_p_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_env_path(char **envp)
{
	int		i;
	char	*env_path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env_path = envp[i] + 5;
			return (env_path);
		}
		i++;
	}
	return (NULL);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**token_env_path;
	char	*buffer;
	char	*temp;
	int		j;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	token_env_path = tokenize(envp);
	j = 0;
	while (token_env_path[j])
	{
		buffer = ft_strjoin(token_env_path[j], "/");
		temp = buffer;
		buffer = ft_strjoin(temp, cmd);
		free(temp);
		if (access(buffer, F_OK | X_OK) == 0)
			return (free_and_return(token_env_path, buffer));
		else
			free(buffer);
		j++;
	}
	ft_putstr_fd("command not found\n", 2);
	exit(1);
	return (NULL);
}

char	**tokenize(char **envp)
{
	char	*env_path;
	char	**token_env_path;

	env_path = find_env_path(envp);
	token_env_path = ft_split(env_path, ':');
	return (token_env_path);
}

char	*free_and_return(char **token_env_path, char *buffer)
{
	free_2d_array(token_env_path);
	return (buffer);
}

t_bool	exec(char **cmd_args, char **envp, t_setting **set)
{
	char	*cmd_with_path;

	if (!cmd_args[0])
		return (FALSE);
	if (execute_check(cmd_args[0]))
	{
		go_execute(cmd_args, set, cmd_args[0]);
		exit(1);
		return(TRUE);
	}
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		exit(1);
	}
	return (TRUE);
}

int	**create_pipes(int num_pipe)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * num_pipe);
	i = 0;
	while (i < num_pipe)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < num_pipe)
	{
		if (pipe(pipes[i]) == -1)
			exit(1);
		i++;
	}
	return (pipes);
}

t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	// node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_deque	*new_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	deque->front = NULL;
	deque->rear = NULL;
	return (deque);
}

int	deque_size(t_deque *deque)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = deque->front;
	while (node != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}

void	push_r(t_deque *deque, t_node *node)
{
	if (deque->rear == NULL)
	{
		deque->front = node;
		deque->rear = node;
	}
	else
	{
		node->prev = deque->rear;
		deque->rear->next = node;
		deque->rear = node;
	}
	//------------------------------------------------
	node->idx = deque_size(deque) - 1;
	//------------------------------------------------

}

char	**subset_arr(char **arr, int start_idx, int end_idx)
{
	int		subset_size;
	char**	subset;
	int		i;

	subset_size = end_idx - start_idx + 1;
	subset = (char**)malloc((subset_size + 1) * sizeof(char*));
	i = 0;
	while (i < subset_size)
	{
		subset[i] = (char*)malloc(ft_strlen(arr[start_idx + i]) + 1);
		ft_strlcpy(subset[i], arr[start_idx + i], ft_strlen(arr[start_idx + i]) + 1);
		i++;
	}
	subset[i] = NULL;
	return (subset);
}

char	check_redir(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "|") == 0)
		return ('p');
	else if (ft_strcmp(str, "<") == 0)
		return ('i');
	else if (ft_strcmp(str, ">") == 0)
		return ('o');
	else if (ft_strcmp(str, "<<") == 0)
		return ('h');
	else if (ft_strcmp(str, ">>") == 0)
		return ('a');
	else
		return ('e');

}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void init_2d_arr(char ***arr) {
    *arr = malloc(sizeof(char *));
    (*arr)[0] = NULL;
}

void init_node(t_node *node) {
    init_2d_arr(&(node->cmd));
    init_2d_arr(&(node->order_redir));
    init_2d_arr(&(node->file_redir));
}

char	**append_str(char **arg, char *str)
{
	int		i;
	int		size;
	char	**new_arr;

	size = 0;
	if (!arg)
		size = 0;
	else
		while (arg[size] != 0)
			size++;
	new_arr = malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (i < size)
	{
		new_arr[i] = (char*)malloc(ft_strlen(arg[i]) + 1);
		ft_strlcpy(new_arr[i], arg[i], ft_strlen(arg[i]) + 1);
		i++;
	}
	new_arr[i] = malloc(ft_strlen(str) + 1);
	ft_strlcpy(new_arr[i], str, ft_strlen(str) + 1);
	i++;
	new_arr[i] = NULL;
	if (arg)
		free_2d_arr(arg);
	return (new_arr);
}

t_deque	*parsing_pipe(char **arg)
{
	int		i;
	int		end_i;
	char	flag;
	t_deque	*deque;
	t_node	*node;

	deque = new_deque();
	node = new_node();
	init_node(node);
	push_r(deque, node);
	i = 0;
	while (arg[i])
	{
		if (ft_strcmp(arg[i], "<") == 0)
		{
			// node->infile = append_str(node->infile, arg[i + 1]);
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, "<");
			i += 2;
		}
		else if (ft_strcmp(arg[i], ">") == 0)
		{
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, ">");
			i += 2;
		}
		else if (ft_strcmp(arg[i], "<<") == 0)
		{
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, "<<");
			i += 2;
		}
		else if (ft_strcmp(arg[i], ">>") == 0)
		{
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, ">>");
			i += 2;
		}
		else if (ft_strcmp(arg[i], "|") == 0)
		{
			node = new_node();
			init_node(node);
			push_r(deque, node);
			i += 1;
		}
		else	//커맨드인 경우
		{
			node->cmd = append_str(node->cmd, arg[i]);
			i += 1;
		}
	}
	return (deque);
}

void	test_ft(char **argv, char **envp, t_setting **set)
{
//----------------------------------------------------
	t_deque	*deque = parsing_pipe(argv);
//----------------------------------------------------
	t_info	information;

	information.num_pipe = deque_size(deque) - 1;
	information.pipes = create_pipes(information.num_pipe);
//----------------------------------------------------
	t_node	*node = deque->front;
//----------------------------------------------------
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	while (node)
	{
		pid = fork();
		if (pid < 0)
			ft_p_error("Error: fork()");
		else if (pid == 0)
		{
			if (node->prev)	//이전에 파이프가 있다.
			{
				dup2(information.pipes[node->idx - 1][READ], STDIN_FILENO);
			}
			if (node->next)	//이후에 파이프가 있다.
			{
				dup2(information.pipes[node->idx][WRITE], STDOUT_FILENO);
			}
			if (node->order_redir)
			{
				for (int i=0; node->order_redir[i]; i++)
				{
					if (ft_strcmp(node->order_redir[i], "<") == 0)
					{
						fd_in = open(node->file_redir[i], O_RDONLY);
						dup2(fd_in, STDIN_FILENO);
					}
					if (ft_strcmp(node->order_redir[i], ">") == 0)
					{
						fd_out =  open(node->file_redir[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
						dup2(fd_out, STDOUT_FILENO);
					}
					if (ft_strcmp(node->order_redir[i], ">>") == 0)
					{
						fd_out =  open(node->file_redir[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
						dup2(fd_out, STDOUT_FILENO);
					}
				}
			}
			if (node->cmd)
			{
				exec(node->cmd, envp, set);
			}
			exit(0);
		}
		else
		{
			if (node->prev)
            	close(information.pipes[node->idx - 1][READ]);
            if (node->next)
        		close(information.pipes[node->idx][WRITE]);
            node = node->next;
		}
	}
	for (int i=0; i<information.num_pipe + 1; i++)
		wait(NULL);
}

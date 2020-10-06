/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:31:18 by szakaria          #+#    #+#             */
/*   Updated: 2020/10/06 00:54:20 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include "libft/libft.h"
# include "GTN/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>

# define BUFF_SIZE 1024
# define NR_J 30

#define STATUS_RUNNING 0
#define STATUS_DONE 1
#define STATUS_SUSPENDED 2
#define STATUS_CONTINUED 3
#define STATUS_TERMINATED 4

#define COMMAND_EXTERNAL 0
#define COMMAND_EXIT 1
#define COMMAND_CD 2
#define COMMAND_JOBS 3
#define COMMAND_FG 4
#define COMMAND_BG 5
#define COMMAND_EXPORT 7
#define COMMAND_UNSET 8

#define BACK 0
#define FORE 1

pid_t 			shell_pgid;
struct termios	shell_tmodes;
int				shell_is_interactive;
int				shell_terminal;

typedef struct	s_env
{
	char			*name;
	char			*environ;
	struct	s_env	*next;
}				t_env;

typedef struct	s_process
{
	char			*command;
    char			**argv;
    pid_t			pid;
    int				type;
    int				status;
    struct s_process	*next;
}				t_process;

typedef struct	s_job
{
	int					id;
    t_process			*process;
    char				*command;
    pid_t				pgid;
	int					mode;
}				t_job;

typedef struct	s_shell
{
	t_job	*job[NR_J + 1];
	t_env	*env;
}				t_shell;
t_shell		*shell;
char		**STATUS_STRING;

t_job			*make_job(char **line);

t_env			*create_env(char **environ);

void			trait(char *line, t_env *list);
void			init_shell();
void			exec_command(t_job **job, t_env *list);
void    		remove_job(int id);
void    		print_pgid_of_job(int id);
void			set_process_status(int pid, int status);
void    		print_job_status(int id);
void    		check_zombie();
void    		print_job_status(int id);
void			set_job_status(int id, int status);
void			execve_help(t_env *list, t_job **job, char *command, char *print);
void			help_to_fg(pid_t pid, int id);
void			help_back_of_built(int type, t_job *job);
void			free_2d(char **str);
void			free_job(t_job *job);

char			*help_search_join(char *str, DIR *dir, char **print);
char			**make_2d_table(char *line);
char			**list_to_tab(t_env *env);

int				insert_job(t_job *job);
int 			wait_for_job(int id);
int				get_command_type(char *command);
int     		to_jobs(t_job   *j, int type);
int				to_fg(t_process *process, t_job *j);
int				to_bg(t_process *process, t_job *j);
int				put_error_not_found(int type);
int				search_last(void);
int				put_error_no_such(int type);
int				put_error_fg(int type);
int				background_of_built(int type, t_job *j);
int				background_of_exit(t_job *j, int i);
int				trait_built(t_job *j);
int				help_trait(t_job **j, t_env *list, int *count, int *status);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:01:41 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/26 08:32:08 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

extern char **environ;

void sigint_handler(int sig) 
{
    if (sig == SIGINT) 
    {
        // printf("\n");
        write(1, "\nminishell> ", 12);
	    // rl_replace_line("", 1);
        // rl_on_new_line();
	    rl_redisplay();
    }
}

void execute_command(char *cmd, t_data *data) 
{
    int i;
    // check if the command is in the /bin directory
    // if (access(cmd, F_OK) == 0) 
    // {
    //     if (fork() == 0) 
    //     {
    //         execve(cmd, NULL, environ);
    //         perror("minishell");
    //         exit(1);
    //     }
    //     wait(NULL);
    //     return;
    // }
    if (ft_strncmp(data->cmd, "exit", 5) == 0)
        exit(0);
    if (ft_strncmp(data->cmd, "cd", 3) == 0)
    {
        parse_path(cmd, data);
        return (ft_chdir(data));
    }
    if (ft_strncmp(data->cmd, "pwd", 4) == 0)
        return (ft_pwd());
    if (cmd[0] == 'e' && cmd[1] == 'c' && cmd[2] == 'h' && cmd[3] == 'o' && cmd[4] == ' ')
        return (ft_echo(cmd));
    
    // if (ft_strncmp(cmd, "ls", 2) == 0) 
    //     return (ft_ls(cmd));
    if (ft_strncmp(cmd, "env", 3) == 0) 
    {
        extern char **environ;
        char **env = environ;
        while (*env) 
        {
            printf("%s\n", *env);
            env++;
        }
        return;
    }
    
    // exportt ////

    if (ft_strncmp(data->cmd, "export", 7) == 0) {
        print_sorted_env();
        return;
    }

    //////////
    
    if (cmd[0] != '\0')
        printf("%s: Command not found\n", cmd);
}


int main() {
    char *input;
    char prompt[256];
    t_data *data;

    data = malloc(sizeof(t_data));
    rl_catch_signals = 0;
    signal(SIGINT, sigint_handler);
    while (1)
    {
        input = readline("minishell> ");
        if (input == NULL) {
            printf("\n");
            break;
        }
        if (*input) {
            add_history(input);
        }
        parse_command(input, data);
        //parse_path(input, data);
        execute_command(input, data);
        free(input);
        }
    return 0;
}


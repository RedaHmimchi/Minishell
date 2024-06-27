/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:01:41 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/27 09:08:12 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_command(char *cmd, t_data *data) 
{
    int i;

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
    
    execute_command_in_bin(data);  
    
    // else
    // {
    //     ft_putstr_fd("minishell: ", 2);
    //     ft_putstr_fd(cmd, 2);
    //     ft_putstr_fd(": command not found (from main)\n", 2);
    //     return;
    // }
        
}


int main()
{
    char *input;
    char prompt[256];
    t_data *data;
    char *line;

    data = malloc(sizeof(t_data));
    parse_bin(input, data);
    rl_catch_signals = 0;
    initialize_signals();
    while (1)
    {
        input = readline("minishell> ");
        if (input == NULL)
        {
            printf("minishell> Goodbye\n");
            exit(0);
        }
        if (*input)
            add_history(input);
        parse_command(input, data);
        parse_args(input, data);
        //parse_path(input, data);
        execute_command(input, data);
        free(input);
        }
    return 0;
}

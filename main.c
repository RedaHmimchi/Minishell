/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:01:41 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/25 13:16:03 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void execute_command(char *cmd) 
{
    int i;
    int nl;

    if (ft_strncmp(cmd, "exit", 4) == 0)
        exit(0);
    if (ft_strncmp(cmd, "cd", 2) == 0) {
        char *path = cmd + 3;
        if (chdir(path) != 0)
            perror("minishell : cd:");
        return;
    }
    if (ft_strncmp(cmd, "pwd", 3) == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s\n", cwd);
        else
            perror("minihsell");
        return;
    }
    nl = 0;
    if (cmd[0] == 'e' && cmd[1] == 'c' && cmd[2] == 'h' && cmd[3] == 'o' && cmd[4] == ' ') 
    {
        if (cmd[5] == '-' && cmd[6] == 'n')
        {
            nl = 1;
            i = 8;
        }
        if (cmd[5] == '$')
        {
            i = 6;
            char *var = cmd + 6;
            char *value = getenv(var);
            if (value != NULL)
                printf("%s", value);
            return;
        }
        else
            i = 5;
        while (cmd[i] != '\0') 
        {
            if (cmd[i] == '\"')
                i++;
            else
            {
                printf("%c", cmd[i]);
                i++;
            }
        }
        if (nl == 0)
            printf("\n");
        return;
    }
    if (ft_strncmp(cmd, "ls", 2) == 0) 
    {
        char *path = cmd + 3;
        char *argv[3];
        argv[0] = "ls";
        argv[1] = path;
        argv[2] = NULL;
        if (cmd[3] == '\0') 
        {
            argv[1] = ".";
            argv[2] = NULL;
        }
        if (fork() == 0) 
        {
            execvp("ls", argv);
            perror("minishell");
            exit(1);
        }
        wait(NULL);
        return;
    }
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

    if (ft_strncmp(cmd, "export", 6) == 0) {
        print_sorted_env();
        return;
    }
        

    //     if (ft_strncmp(cmd, "export", 6) == 0) {
    //     char *var = cmd + 7; // Skip 'export '
    //     char *equal_sign = strchr(var, '=');
    //     if (equal_sign != NULL) {
    //         // Count the current number of environment variables
    //         int count = 0;
    //         while (environ[count] != NULL) count++;

    //         // Allocate a new array for the environment variables
    //         char **new_environ = malloc((count + 2) * sizeof(char *));
    //         if (new_environ == NULL) {
    //             perror("minishell : export:");
    //             return;
    //         }

    //         // Copy the existing environment variables to the new array
    //         for (i = 0; i < count; i++) {
    //             new_environ[i] = environ[i];
    //         }

    //         // Add the new variable to the new array
    //         new_environ[count] = var;
    //         new_environ[count + 1] = NULL;

    //         // Replace the old environment with the new one
    //         environ = new_environ;
    //     } 
    //     else
    //         perror("minishell export");
    //     return;
    // }

    //////////
    
    if (cmd[0] != '\0')
        printf("%s: Command not found\n", cmd);
}

void initialize_shell() {
}


int main() {
    char *input;
    char prompt[256];

    initialize_shell();
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
        execute_command(input);
        free(input);
        }
    return 0;
}


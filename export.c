/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:13:28 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/25 13:33:09 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char **environ;

void swap(char **a, char **b) {
	char *temp = *a;
	*a = *b;
	*b = temp;
}

void print_sorted_env() 
{
	int	count;
	int i;
	int j;

	count = 0;
	i = 0;
	j = 0;

	// Count the number of environment variables
	while (environ[count] != NULL) 
		count++;

	// Create a copy of the environ pointer for sorting
	char **env_copy = malloc((count + 1) * sizeof(char *));
	if (env_copy == NULL) {
		perror("minishell : print_sorted_env:");
		return;
	}

	// Copy the environment variables to the new array
	while (i < count)
	{
		env_copy[i] = environ[i];
		i++;
	}
	env_copy[count] = NULL;

	// Sort the environment variables using bubble sort
	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1) 
		{
			if (strcmp(env_copy[j], env_copy[j + 1]) > 0)
				swap(&env_copy[j], &env_copy[j + 1]);
			j++;
		}
		i++;
	}

	// Print the sorted environment variables
	i = 0;
	while (i < count)
	{
		printf("declare -x %s\n", env_copy[i]);
		i++;
	}

	// Free the copied environment variables
	free(env_copy);
}
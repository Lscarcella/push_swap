/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/04 12:19:44 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_element	*snake;
	t_element	*tail_a;
	t_element	*ptr;
	
	int	i;

	i = 1;
	
	if(argc > 1)
	{
		init_struct(&snake);
		check_and_store_arg(&snake, &tail_a, argv);
		ptr = snake;
		while (i < argc)
		{
			printf("snake_a : %d \n", ptr->value);
			ptr = ptr->next;
			i++;
		}
		
		// swap(&tail_a, 'a');
		rotate(&tail_a, 'a');
		i = 1;
		ptr = snake;
		while (i < argc)
		{
			printf("snake_a après opération : %d \n", ptr->value);
			ptr = ptr->next;
			i++;
		}
		
		return(0);
	}
	else
	{
		printf(COLOR_RED"Error\n"TEXT_RESET);
		return(0);
	}
}

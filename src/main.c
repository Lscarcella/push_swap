/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/05 15:34:12 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_element	*top_of_stack;
	t_element	*bot_of_stack;
	t_element	*ptr;
	
	int	i;

	i = 1;
	if(argc > 1)
	{
		// init_struct(&top_of_stack);
		check_and_store_arg(&top_of_stack, &bot_of_stack, argv);
		// if(argc == 4)
		// {
		// 	is_stack_sorted(&top_of_stack);
		// }
		ptr = top_of_stack;
		while (i < argc)
		{
			printf("stack_a : %d \n", ptr->value);
			ptr = ptr->prev;
			i++;
		}
		printf("top_of_stack : %d \n", top_of_stack->value);

		// swap(&top_of_stack, 'a');
		// rotate(&top_of_stack, 'a');
		// reverse_rotate(&top_of_stack, 'a');
		
		
		i = 1;
		ptr = top_of_stack;
		while (i < argc)
		{
			printf("stack_a après opération : %d \n", ptr->value);
			ptr = ptr->prev;
			i++;
		}
		printf("top_of_stack : %d \n", top_of_stack->value);
		return(0);
	}
	else
	{
		printf(COLOR_RED"Error\n"TEXT_RESET);
		return(0);
	}
}

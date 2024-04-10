/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/10 13:53:55 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_element	*top_of_stack;
	t_element	*bot_of_stack;

	if(argc > 2)
	{
		check_and_store_arg(&top_of_stack, &bot_of_stack, argc, argv);
		if(argc == 4)
		{
			little_stack_sort(top_of_stack, bot_of_stack, argc);
			return (0);
		}
		// swap(&top_of_stack, 'a');
		// rotate(&top_of_stack, 'a');
		// reverse_rotate(&top_of_stack, 'a');
		return(0);
	}
	else
	{
		write(2, "Error\n", 6);
		return(0);
	}
}

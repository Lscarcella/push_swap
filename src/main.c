/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/16 13:00:03 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_element	*stack_a;

	stack_a = NULL;

	if(argc > 2)
	{
		check_and_store_arg(&stack_a, argc, argv);
		if (argc <= 6)
			little_sort(stack_a, argc);
	}
	else
	{
		write(2, "Error\n", 6);
		return(0);
	}
}

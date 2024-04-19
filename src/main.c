/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/19 07:52:45 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_element	*stack_a;
	int stack_len;

	stack_len = 0;
	stack_a = NULL;
	
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	check_and_store_arg(&stack_a, argv, stack_len);
	if (argc <= 6)
			little_sort(stack_a, argc);
	else
	{
		write(2, "Error\n", 6);
		return(0);
	}
}

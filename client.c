/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butatar <butatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:12:22 by butatar           #+#    #+#             */
/*   Updated: 2023/08/31 14:17:08 by butatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		total = (s[i] - 48) + (total * 10);
		i++;
	}
	return (total);
}

void	ft_sendbit(int pid, char *a)
{
	int		i;
	int		j;

	if (pid < 1)
	{
		write(1, "PID ERROR!", 10);
		return ;
	}
	j = 0;
	while (a[j])
	{
		i = 7;
		while (i >= 0)
		{
			if ((a[j] >> i) & 1) 
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_sendbit(ft_atoi(av[1]), av[2]);
	else
		write(1, "ARGUMENT ERROR!", 16);
	return (0);
}

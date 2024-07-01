/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:52:00 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/28 02:27:58 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_exit(char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
{
	long	i;
	long	b;
	long	c;

	i = 0;
	b = 1;
	c = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		++i;
	}
	return (c * b);
}

long	ft_gettime(t_time code)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (code == MILISECOND)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (code == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		ft_error_exit("Wrong time code");
	return (FAILURE);
}

void	ft_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = ft_gettime(MICROSECOND);
	while (ft_gettime(MICROSECOND) - start < usec)
	{
		if (ft_sim_finished(data))
			break ;
		elapsed = ft_gettime(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
		{
			while (ft_gettime(MICROSECOND) - start < usec)
				;
		}
	}
}

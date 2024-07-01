/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sincro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:07:40 by diogosan          #+#    #+#             */
/*   Updated: 2024/07/01 12:48:01 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	ft_wait_threads(t_data *data)
{
	while (!ft_get_bool(&data->table_mutex, &data->all_threads_ready))
	{
		usleep(500);
	}
}

bool	ft_all_thread_runnning(pthread_mutex_t *mutex,
		long *threads, long philo_nbr)
{
	bool	ret;

	ret = false;
	ft_safe_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	ft_safe_mutex(mutex, UNLOCK);
	return (ret);
}

void	ft_increase_long(pthread_mutex_t *mutex, long *value)
{
	ft_safe_mutex(mutex, LOCK);
	(*value)++;
	ft_safe_mutex(mutex, UNLOCK);
}

void	ft_desinc_philo(t_philo *philo)
{
	if (philo->data->nbr_of_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->id % 2)
			ft_think(philo, true);
	}
}

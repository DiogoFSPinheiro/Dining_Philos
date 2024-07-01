/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:47 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/25 15:48:27 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
* Locking and unlocking mutexs 
*	Set - set value
*	Get - read value
*/
void	ft_set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	ft_safe_mutex(mutex, LOCK);
	*dest = value;
	ft_safe_mutex(mutex, UNLOCK);
}

bool	ft_get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	val;

	ft_safe_mutex(mutex, LOCK);
	val = *value;
	ft_safe_mutex(mutex, UNLOCK);
	return (val);
}

void	ft_set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	ft_safe_mutex(mutex, LOCK);
	*dest = value;
	ft_safe_mutex(mutex, UNLOCK);
}

long	ft_get_long(pthread_mutex_t *mutex, long *value)
{
	long	val;

	ft_safe_mutex(mutex, LOCK);
	val = *value;
	ft_safe_mutex(mutex, UNLOCK);
	return (val);
}

bool	ft_sim_finished(t_data *data)
{
	return (ft_get_bool(&data->table_mutex, &data->end_sim));
}

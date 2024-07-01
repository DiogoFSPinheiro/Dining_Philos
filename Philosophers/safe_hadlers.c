/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_hadlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:34:09 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/28 02:28:42 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_safe_malloc(int size)
{
	char	*mem;

	mem = malloc(size);
	if (!mem)
		ft_error_exit("malloc error");
	return (mem);
}

void	ft_safe_mutex(pthread_mutex_t *mutex, t_opcode code)
{
	if (code == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			ft_error_exit("Mutex error on Lock");
	}
	else if (code == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			ft_error_exit("Mutex error on UnLock");
	}
	else if (code == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			ft_error_exit("Mutex error on Init");
	}
	else if (code == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			ft_error_exit("Mutex error on Destory");
	}
	else
		ft_error_exit("Wrong Mutex handle");
}

void	ft_safe_phread(pthread_t *thread, void *(*func)(void *),
		void *data, t_opcode code)
{
	if (code == CREATE)
	{
		if (pthread_create(thread, NULL, func, data) != 0)
			ft_error_exit("Thread error on Create");
	}
	else if (code == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			ft_error_exit("Thread error on Join");
	}
	else if (code == DETACH)
	{
		if (pthread_detach(*thread) != 0)
			ft_error_exit("Thread error on Detach");
	}
	else
		ft_error_exit("Wrong Thread handle");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:42:42 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/21 19:15:25 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(50);
	while (1)
	{
		ft_eat(philo);
		ft_print(philo, "is sleeping", 0);
		ft_sleep(philo->data->time_to_sleep);
		ft_print(philo, "is thinking", 0);
		usleep(50);
	}
	return (NULL);
}

int	start_philos(t_philo *philos)
{
	philos->last_meals = current_time();
	if (pthread_create(&philos->thread, NULL, routine, \
		(void *)(philos)))
		return (1);
	pthread_detach(philos->thread);
	check_death(philos);
	return (0);
}

t_philo	*create_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
	if (!philos)
		return (0);
	while (++i < data->nbr_philos)
	{
		philos[i].philo_id = i;
		philos[i].data = data;
	}
	return (philos);
}

void create_process(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->data->nbr_philos)
	{
		philo[i].pid = fork();
		if (!philo[i].pid)
		{
			start_philos(philo + i);
			exit(0);
		}
	}
}

void	ft_kill(t_philo *philos)
{
	int i;

	i = -1;
	while (++i < philos->data->nbr_philos)
	{
		kill(philos[i].pid, 9);
	}
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("meal");
	sem_close(philos->data->forks);
	sem_close(philos->data->print);
	sem_close(philos->data->meal);
}

int	main(int ac, char **av)
{
	int		res;
	t_data	*data;
	t_philo	*philos;

	if (ac < 5 || ac > 6)
		return (error(1));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	res = check_arguments(av, data);
	if (!res || res == -1)
		return (error(0));
	philos = create_philos(data);
	data->start_time = current_time();
	create_process(philos);
	waitpid(-1, NULL, 0);
	ft_kill(philos);
}

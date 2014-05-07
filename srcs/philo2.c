
void	*func(void *p_data)
{
	t_data		*data;

	data = p_data;
	printf("\nPhilosopher %d is thinking ", data->n);
	pthread_mutex_lock(&chopstick[data->n]);
	pthread_mutex_lock(&chopstick[(data->n+1)%7]);
	printf("\nPhilosopher %d is eating ",data->n);
	sleep(3);
	pthread_mutex_unlock(&chopstick[data->n]);
	pthread_mutex_unlock(&chopstick[(data->n+1)%7]);
	printf("\nPhilosopher %d Finished eating ", data->n);
}

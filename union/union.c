#include <unistd.h>

int		check_doublon(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	Union(char *s1, char *s2)
{
	int i;
	int k;
	int j;
	char UNION[255];

	i = 0;
	j = 0;
	k = 0;
	UNION[0] = '\0';
	while (s1[i])
	{
		if (check_doublon(UNION, s1[i]) == 0)
			UNION[k++] = s1[i];
		i++;
	}
	while (s2[j])
	{
		if (check_doublon(UNION, s2[j]) == 0)
			UNION[k++] = s2[j];
		j++;
	}
	UNION[k] = '\0';
	ft_putstr(UNION);
}

int main(int ac, char **av)
{
	if (ac == 3)
		Union(av[1], av[2]);
	write(1, "\n", 1);
	return (1);
}

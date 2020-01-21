#include <unistd.h>

int		common_char(char *str, char c)
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
void	inter(char *s1, char *s2)
{
	int i;
	int j;
	int k;
	char INTER[255];

	INTER[0] ='\0';
	i = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && (common_char(INTER, s1[i]) == 0))
				INTER[k++] = s1[i];
			j++;
		}
		i++;
	}
	INTER[k] = '\0';
	ft_putstr(INTER);
}

int main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

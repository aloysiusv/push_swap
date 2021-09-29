#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int 	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_str_only_digits(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			;
		else if (ft_isdigit(str[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", is_str_only_digits("66843"));
	printf("%d\n", is_str_only_digits("-66843"));
	printf("%d\n", is_str_only_digits("-0000000003"));
	printf("%d\n", is_str_only_digits("-0000000"));
	printf("%d\n", is_str_only_digits("668-43"));
	printf("%d\n", is_str_only_digits("66 84 3"));
	return(0);
}
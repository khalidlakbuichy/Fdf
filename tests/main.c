#include "../inc/fdf.h"

long int	ft_atoi_hex(const char *hex);

int main (int ac, char **av)
{
    printf("%ld\n", ft_atoi_hex(av[1]));
}
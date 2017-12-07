#include "proto.h"

void	check_args(int ac, char **av)
{
  if (ac != 2){
    printf("Usage: ./mysearch [string]\n");
    exit (EXIT_FAILURE);
  }
}


int	main(int ac, char **av)
{
  check_args(ac, av);
  my_search(av[1]);
}

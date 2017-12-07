#include "proto.h"

void	check_args(int ac)
{
  if (ac != 2){
    printf("Usage: ./mysearch [string]\n");
    exit (EXIT_FAILURE);
  }
}


int	main(int ac, char **av)
{
  check_args(ac);
  my_search(av[1]);
}

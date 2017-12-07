#include "proto.h"

void		*xmalloc(size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      write(2, "Error malloc \n", 30);
      exit(0);
    }
  return (ptr);
}

#include "proto.h"

node_t	*list_file = NULL;

void	list_files(char *dir_name, char *str)
{
  DIR	*d;

  d = opendir(dir_name);
  if (!d) {
    fprintf (stderr, "Cannot open directory '%s': %s\n",
	     dir_name, strerror (errno));
    exit (EXIT_FAILURE);
  }
  while (1) {
    
    struct dirent * entry;
    
    entry = readdir (d);
    if (! entry) {
      break;
    }
    search_in_file(entry->d_name, str);
  }
  if (closedir (d)) {
    fprintf (stderr, "Could not close '%s': %s\n",
	     dir_name, strerror (errno));
    exit (EXIT_FAILURE);
  }
  return ;
}

int	search_in_file(char *fname, char *str)
{
  FILE		*fp;
  int		find_result = 0;
  char		*line = NULL;
  size_t	len = 0;
  ssize_t	read;
  bool		match = false;
  
  if((fp = fopen(fname, "r")) == NULL) {
	return(-1);
  }
  while((read = getline(&line, &len, fp)) != -1) {
    while((line = strcasestr(line, str)) != NULL) {
      line++;
      find_result++;
      match = true;
    }
  }
  if (match == true)
    append(&list_file, fname, find_result);
  if(fp) {
    fclose(fp);
  }  
  return(0);
}

void	my_search(char *string)
{
  list_files(".", string);
  merge_sort(&list_file);
  print_list(list_file, string);
}

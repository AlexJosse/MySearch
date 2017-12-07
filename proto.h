#ifndef PROTO_H_
#define	PROTO_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct	node {
  char	*filename;
  int	n;
  struct node	*next;
}		node_t;

typedef int bool;
enum { false, true };

int	search_in_file(char *fname, char *str);
void	my_search(char *string);
void	list_files(char *dir, char *str);
void	append(node_t** head_ref, char *new_data, int n);
void	print_list(node_t *node, char *string);
void	merge_sort(node_t **headref);
node_t*	sorted_merge(node_t *a, node_t *b);
void	front_back_split(node_t  *source, node_t **frontref, node_t **backref);
void*	xmalloc(size_t size);
char*	strcasestr(const char *haystack, const char *needle);

#endif	/* PROTO_H_ */

#include "proto.h"


void	append(node_t** head_ref, char *new_data, int n)
{
    node_t	*new_node = (node_t*)xmalloc(sizeof(node_t));
    node_t	*last = *head_ref;

    new_node->filename = xmalloc(sizeof(char*) * strlen(new_data));
    new_node->filename  = strcpy(new_node->filename, new_data);
    new_node->n = n;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void	print_list(node_t *node, char *string)
{
  int	cpt = 0;
  
  while (node != NULL)
  {
    printf("%s %s\t%d occurrences\n", KRED,  node->filename, node->n);
    node = node->next;
    cpt++;
  }
  printf("%s %d files with the string %s\n", KGRN, cpt, string);
}

void	merge_sort(node_t **headref)
{
  node_t	*head = *headref;
  node_t	*a;
  node_t	*b;
 
  if ((head == NULL) || (head->next == NULL))
    return;
  front_back_split(head, &a, &b);  
  merge_sort(&a);
  merge_sort(&b);
  *headref = sorted_merge(a, b);
}

node_t*	sorted_merge(node_t *a, node_t *b)
{
  node_t	*result = NULL;
 
  if (a == NULL)
     return(b);
  else if (b == NULL)
    return(a);
  if (strcmp(a->filename, b->filename) < 0)
  {
     result = a;
     result->next = sorted_merge(a->next, b);
  }
  else
  {
     result = b;
     result->next = sorted_merge(a, b->next);
  }
  return(result);
}

void	front_back_split(node_t  *source,
          node_t **frontref, node_t **backref)
{
  node_t	*fast;
  node_t	*slow;

  if (source == NULL || source->next == NULL)
  {
    *frontref = source;
    *backref = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *frontref = source;
    *backref = slow->next;
    slow->next = NULL;
  }
}


/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved. 
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <stdlib.h>

#include "data_structures/linked_list.h"

void add_node(int_llnode **tail, int value) {
  int_llnode *new_tail = malloc(sizeof(int_llnode));
  new_tail->value = value;
  new_tail->next = NULL;

  if (*tail) {
    (*tail)->next = new_tail;
  }

  *tail = new_tail;
}

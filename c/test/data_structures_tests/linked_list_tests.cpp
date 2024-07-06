
/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <stdlib.h>

#include <gtest/gtest.h>

#include "data_structures/linked_list.h"


// Tests that when there isn't any tail yet it creates one
TEST(AddTest, CreatesTail) {
  int_llnode *tail = NULL;

  add_llnode(&tail, 1);

  EXPECT_EQ(tail->value, 1);

  if (tail) {
    free(tail);
  }
}

/*
  Tests that when the tail is the head, the tail becomes a different after
  the addition
*/
TEST(AddTest, HeadTailSeparation) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;

  add_llnode(&tail, 2);

  EXPECT_EQ(tail->value, 2);
  EXPECT_EQ(head->value, 1);

  if (head) {
      free(head);
  }
  if (tail) {
    free(tail);
  }
}

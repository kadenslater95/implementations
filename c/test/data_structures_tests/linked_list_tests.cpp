
/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved. 
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <stdlib.h>

#include <gtest/gtest.h>

#include "data_structures/linked_list.h"

/*
  Tests that when there isn't any tail yet it creates one
*/
TEST(AddNodeTest, CreatesTail) {
  int_llnode *tail = NULL;

  add_node(&tail, 1);

  EXPECT_EQ(tail->value, 1);

  if (tail) {
    free(tail);
  }
}

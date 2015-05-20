#include "ifftw.h"

#ifdef CONFIG_MUTUALEXCLUSIONPLANNER

/* trivial ticket lock, with no safety net whatsoever */

/* todo: fixme: should be aligned on 32/64 (cache line)
 * boundary to make sure the two variables don't share
 * a cache line */
volatile static int next = 0;
volatile static int now = 0;

void X(grab_plan_lock)(void) {
  int cur = __sync_fetch_and_add(&next, 1);
  while (now != cur) {
  }
}
void X(release_plan_lock)(void) {
  now ++;
}

#endif

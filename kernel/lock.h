#ifdef CONFIG_MUTUALEXCLUSIONPLANNER


#include "ifftw.h"

void X(grab_plan_lock)(void);
void X(release_plan_lock)(void);

#endif

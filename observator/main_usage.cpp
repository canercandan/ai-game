#include <unistd.h>
#include <stdlib.h>
#include "observator.h"

void	main_usage()
{
  write(1, OBS_USAGE, sizeof(OBS_USAGE));
  exit (0);
}

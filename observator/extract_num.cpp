#include <irrlicht.h>
#include "observator.h"

int	extract_num(char *buf, int num)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < num)
    {
      while (buf[i] != '\n' && (buf[i] < '0' || buf[i] > '9'))
	i++;
      j++;
      if (j < num)
	{
	  while (buf[i] != '\n' && buf[i] >= '0' && buf[i] <= '9')
	    i++;
	}
    }
  num = 0;
  while (buf[i] != '\n' && buf[i] >= '0' && buf[i] <= '9')
    {
      num = num * 10 + (buf[i] - 48);
      i++;
    }
  return (num);
}

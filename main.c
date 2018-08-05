#include <stdio.h>

#include "translateLib.h"
#include "inputHandler.h"


int
main (int   argc,
      char *argv[])
{

  // the struct which will store reference to the required widgets
  if (argc != 4){
    printf("usage %s %s %s %s",argv[0],"<input language code>","<output language code>","<input text>");
  }
  return 0;
}



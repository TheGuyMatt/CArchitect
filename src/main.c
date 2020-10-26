#include "log.h"

int main(int argc, char **argv)
{
  loge("%s", "testing");
  logi("%s, %d, %f", "test2", 4, 2.2f);

  return 0;
}

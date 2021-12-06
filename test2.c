#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

int main(int argc, char *argv[]) {
  for(int i=0; i<100;i++){
    mkdir("pasta");
    unlink("pasta");
  }
  exit();
}

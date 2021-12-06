#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

int main(int argc, char *argv[]) {
   char *music =
      "Ai, amor será que tu divide a dor do teu peito cansado com alguém que "
      "não vai te sarar meu amor eu vivo no aguardo de ver você voltando "
      "cruzando a porta, parararara\n";
    long int number=0;
    for(int i=0; i<999999;i++){
      number +=strlen(music);
    }
    for(int i=0; i<5;i++){
      mkdir("pasta");
      unlink("pasta");
    }
    exit();
}

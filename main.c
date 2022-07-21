#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){ 

    srand(time(NULL));
    //access -> Retorna 0 caso o arquivo exista (F_OK indica o modo de acesso {checagem})
    int pid = fork();

    FILE *lock;
    FILE *buffer;

    fopen("buffer.txt", "w+");

    //pid 0 = produtor
    if (pid == 0){
        while (1){
            if (access("buffer.txt.lock", F_OK) != 0){
                lock = fopen("buffer.txt.lock", "w");
                
                char value[3];

                sprintf(value, "%d", rand()%100);

                printf("%s\n", value);
                // Problema no fwrite!
                fwrite(value, 2, sizeof(value), buffer);

                fclose(lock);
                remove("buffer.txt.lock");
                sleep((rand()%3)+1);
            }
        }

    //pid !0 = consumidor
    } else {
        while (1){
            if (access("buffer.txt.lock", F_OK) == 0){
                lock = fopen("buffer.txt.lock", "w");
                // apagar buffer.txt
                // printar o valor removido
                fclose(lock);
                remove("buffer.txt.lock");
                sleep((rand()%3)+1);
            }   
        }
    } 

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


pid_t hijo (char* program, char** arg_list){
    pid_t hijo_pid;

    hijo_pid = fork ();

    if (hijo_pid != 0)
        return hijo_pid;
    else {

        execvp (program, arg_list);

        fprintf (stderr, "an error occurred in execvp\n");
        abort ();
    }
}

int main (){

    char* arg_list[] = {
        "firefox",
        NULL
    };

    hijo ("firefox", arg_list);

    printf ("done with main program\n");

    return EXIT_SUCCESS;

}

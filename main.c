#define RL_BUFSIZE 1024
char *my_read_line(void){
    int bufsize = RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if(!buffer){
        fprintf(stderr, "E: Allocation Error\n");
        exit(EXIT_FAILURE);
    }
    while(1){
        c = getchar();

        if(c == EOF || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        }else{
            buffer[position] = c;
        }
        position++;

        if(position >= bufsize){
            bufsize += RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if(!buffer){
                frpintf(stderr, "E: Allocation Error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void my_loop(void){
    char *line;
    char **args;
    int status;

    do{
        printf(">> ");
        line = my_read_line();
        args = my_split_line(line);
        status = my_execute(args);

        free(line);
        free(args);
    }while(status);
}

int main(int argc, char **argv){
    //load config files, if any.
    
    //Run command Loop
    
    my_loop();

    //Perform any shutdown or cleanup.
    
    return EXIT_STATUS;
}


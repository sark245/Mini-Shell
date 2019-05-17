#define RL_BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
char *my_read_line(void){
    char *line = NULL;
    ssize_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}
char **split_line(char *line){
    int bufsize = TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize *sizeof(char*));
    char *token;
    if(!token){
    fprintf(stderr,"E: allocation error\n");
    exit(EXIT_FAILURE);
    }
    
    token = strtok(line,TOK_DELIM);
    while(token != NULL){
        tokens[position] = token;
        position++;

        if(position >= bufsize){
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize *sizeof(char*));
            if(!tokens){
                fprintf(stderr, "E: Allocation Error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
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


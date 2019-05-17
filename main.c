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

int launch(char **args){
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0){
        if(execvp(args[0],args) == -1){
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }elseif(pid<0){
        perror("Error");
    }else{
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

/**************************************************************************///For Builtin Commands
int my_cd(char **args);
int my_help(char **args);
int my_exit(char **args);

cahr builtin_str[] = {
    "cd",
    "help",
    "exit"
};
int (*builtin_func[])(char **) = {
    &my_cd,
    &my_help,
    &my_exit
};

int my_num_builtins(){
    return sizeof(builtin_str)/sizeof(char *);
}
int my_cd(char **args)
{
    if(args[1] == NULL){ 
        fprintf(stderr, "E: Expected argument to \"cd\"\n");
    }
    else{
        if(chdir(args[1])!=0){
            perror("Error");
        }
    }
    return 1;
}

int my_help(char **args){
    int i;
    printf("Sarthak Kathuria's Miniatur Shell\n");
     printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }
   printf("Use the man command for information on other programs.\n");
   return 1;
    }

    int lsh_exit(char **args)
    {
     return 0;
    }





/**************************************************************************/

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


#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <ctype.h>

extern char **environ;

void print_option(char *text, int num) {
    printf("[%d]: %s\n", num, text);
}

void print_line(int count) {
    for(int i=0; i<count; i++)
        printf("-");
    printf("\n");
    return;
}

void print_menu(char *text) {
    //header
    print_line(strlen(text));
    printf(text);
    print_line(strlen(text));
    return;
}

int show_options() {
    
    print_menu("Environment-List Menu\n");
	
	print_option("print environment list", 1);
    print_option("print environment entry (getenv)", 2);
    print_option("add environment entry (putenv)", 3);
    print_option("modify environment entry (setenv)", 4);
    print_option("remove environment entry (unsetenv)", 5);
    print_option("end program", 0);

    char *ans = readline("choice: ");
    int answ = atoi(ans);
    
	free(ans);
    return answ;
}


void print_env_list(char **env) {
    printf("..printing environment list...\n");
	if(*env)
		while(*env) puts(*env++);
	else{
		printf("err: Failed to show environment list..\n");
	}
}

// ask for entry and search with getenv()
void print_env_entry() {
    
	char *ans = readline("entry:\n(warning: pay attention to upper- and lowercase): ");
	char *entry = getenv(ans);
    
	if(entry) printf("%s=%s\n", ans, entry);
    else printf("err: Failed to show requested entry!\n");
	
	free(ans);
} // print_env_entry()

// ask for entry and add in list with putenv()
void add_env_entry() {
    char *ans = readline("'name=value' (note: if the entry does exist, the value will be overwritten!): ");

    if( putenv(ans) )
        perror("Failed to save a new entry!\n");
    free(ans);
}

void mod_env_entry() {
    char *ans = readline("'name': ");
    char *ans2 = readline("'value': ");
    int overwrite;
    char ans3;

    printf("overwrite? (y/n): ");
    scanf("%c", &ans3);
	
	//buffer from https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }

    if(ans3 == 'y')
        overwrite = 1;
    else if(ans3 == 'n')
        overwrite = 0;
    else {
        perror("Overwrite Value was not given correctly!\n");
        return;
    }
    setenv(ans, ans2, overwrite);

    free(ans);
    free(ans2);
}

void remov_env_entry() {
    char *ans = readline("'name': ");
    unsetenv(ans);
    free(ans);
}


int main() {
    int breaker = 0;
    //show options
    do {
        switch( show_options() ) {
        case 1:
            print_env_list(environ);
            break;
        case 2:
            print_env_entry();
            break;
        case 3:
            add_env_entry();
            break;
        case 4:
            mod_env_entry();
            break;
        case 5:
            remov_env_entry();
            break;
        case 0:
            breaker = 1;
            break;
        default:
            printf("\n\nPlease make sure to enter a valid number!\n");
			//perror("Please enter a valid number!\n");
            //return EXIT_FAILURE;
        }
    } while(!breaker);
    return EXIT_SUCCESS;
}

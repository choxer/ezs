#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <ctype.h>


#define DEBUG

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

    print_line( strlen("Environment-List Menu"));

	char *ans = readline("Enter a number:\n>> ");
	int answ = atoi(ans);
    
	print_line( strlen("Environment-List Menu"));

	free(ans);
    return answ;
} // show_ooptions()

// p
void print_env_list(char **env) {

    if( !(*env))
        printf(">> ERROR: Failed to show environment list\n");
    else 
        while(*env) puts(*env++);
}


// lower and uppercase
void to_upper(char *ans){
    int i = 0;
    while(ans[i]) {
        ans[i] = toupper(ans[i]);
        i++;
    }
} // to_upper()


// ask for entry and search with getenv()
void print_env_entry() {

    char *ans = readline("entry: ");
	to_upper(ans);

    char *entry = getenv(ans);

    if(entry) printf("%s=%s\n", ans, entry);
    else printf(">> ERROR: Failed to show requested entry!\n");

} // print_env_entry()


char *parse_equalsign(char *ans){
	if(!ans)
		return NULL;
	
	while(*ans){
	
		if (*ans == '='){
			printf("%s\n", ans);

			return ++ans;
		}
		ans++;
	}
	return NULL;
}

char *parse_to_equalsign(char *ans){
	if(!ans)
		return NULL;

	while(*ans){
		if(*ans++ == '='){
			
		}
	}
	return NULL;
}

// ask for entry and add in list with putenv()
void add_env_entry() {

    char *ans = readline("usage: entry=value\n(note: if the entry does exist, the value will be overwritten!): ");
	to_upper(ans);
	printf("STORED IN ANS: %s\n", ans);    
	
	// putenv(ans) -> stores "enter a number..."-prompt to envlist
	if( putenv(ans) != 0)
        perror(">> ERROR: Failed to save a new entry!\n");
	
    //free(ans);
} // add_env_entry()


// ask for entry and modify with setenv()
void mod_env_entry() {

    char *ans = readline("usage: entry=value\n>> ");
	to_upper(ans);

	char *parse[2];
		parse[0] = strtok(ans, "=");
		parse[1] = strtok(NULL, "=");
	printf("%s %s\n", parse[0], parse[1]);

	int overwrite;
    char ans3;

    printf("overwrite? (Y/n): ");
    scanf("%1c", &ans3);

    //free buffer from https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    if(ans3 == 'Y')
        overwrite = 1;
    else if(ans3 == 'n')
        overwrite = 0;
	else if( ans3 == '\n')
		overwrite = 1;
    else {
        fprintf(stderr, "Overwrite Value was not given correctly!\n");
        return;
    }
	
    setenv(parse[0], parse[1], overwrite);

} // mod_env_entry()


// ask for entry and remove it form list
void remov_env_entry() {

    char *ans = readline("entry: ");
	to_upper(ans);

	unsetenv(ans);

    free(ans);
} // remov_env_entry()


int main() {

    int breaker = 0;

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
            printf("\n>> ERROR: Please make sure to enter a valid number!\n");
            break;
        }
    } while(!breaker);
    return EXIT_SUCCESS;
}

#include "shell.h"

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char **tokenize(char *line)
{
    char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
    long unsigned int i, tokenIndex = 0, tokenNo = 0;

    for (i = 0; i < strlen(line); i++)
    {
        char readChar = line[i];
        if (readChar == ' ' || readChar == '\n' || readChar == '\t')
        {
            token[tokenIndex] = '\0';
            if (tokenIndex != 0)
            {
                tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
                strcpy(tokens[tokenNo++], token);
                tokenIndex = 0;
            }
        }
        else
        {
            token[tokenIndex++] = readChar;
        }
    }
    token[tokenIndex] = '\0';
    tokens[tokenNo] = NULL;
    free(token);
    return (tokens);
}

int main(void)
{
    char input[MAX_INPUT_SIZE];
    char **tokens;
    pid_t child_pid;
    int status;
	int i;
    while (1)
    {
        printf("$ ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }
        input[strcspn(input, "\n")] = '\0';
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            tokens = tokenize(input);
            if (execvp(tokens[0], tokens) == -1)
            {
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }
            for (i = 0; tokens[i] != NULL; i++)
            {
                free(tokens[i]);
            }
            free(tokens);
        }
        else
        {
            if (waitpid(child_pid, &status, 0) == -1)
            {
                perror("Wait failed");
                exit(EXIT_FAILURE);
            }
        }
    }
    return (0);
}



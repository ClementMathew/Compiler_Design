#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_TOKEN_LENGTH 100
enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    DELIMITER,
};
struct Token
{
    enum TokenType type;
    char lexeme[MAX_TOKEN_LENGTH];
};
int isKeyword(char *str)
{
    char *keywords[] = {"int", "float", "if", "else", "while", "for", "return"};
    int numKeywords = 7;
    for (int i = 0; i < numKeywords; i++)
    {
        if (strcmp(keywords[i], str) == 0)
        {
            return 1; // It's a keyword
        }
    }
    return 0;
}
void tokenize(char *program)
{
    int i = 0;
    struct Token token;
    int programLength = strlen(program);
    while (i < programLength)
    { // Skip whitespace
        while (isspace(program[i]))
        {
            i++;
        } // Check for keywords, identifiers, and numbers
        if (isalpha(program[i]))
        {
            int j = 0;
            while (isalnum(program[i]) || program[i] == '_')
            {
                if (j < MAX_TOKEN_LENGTH - 1)
                {
                    token.lexeme[j] = program[i];
                    j++;
                }
                i++;
            }
            token.lexeme[j] = '\0';
            if (isKeyword(token.lexeme))
            {
                token.type = KEYWORD;
            }
            else
            {
                token.type = IDENTIFIER;
            }
        }
        else if (isdigit(program[i]))
        {
            int j = 0;
            while (isdigit(program[i]) || program[i] == '.')
            {
                if (j < MAX_TOKEN_LENGTH - 1)
                {
                    token.lexeme[j] = program[i];
                    j++;
                }
                i++;
            }
            token.lexeme[j] = '\0';
            token.type = NUMBER;
        } // Check for operators and delimiters
        else if (strchr("+-*/=<>", program[i]) != NULL)
        {
            token.lexeme[0] = program[i];
            token.lexeme[1] = '\0';
            token.type = OPERATOR;
            i++;
        }
        else if (strchr("();{},[]", program[i]) != NULL)
        {
            token.lexeme[0] = program[i];
            token.lexeme[1] = '\0';
            token.type = DELIMITER;
            i++;
        }
        else
        { // Handle unsupported characters or tokens
            printf("Error: Invalid character: %c\n", program[i]);
            i++;
        } // Print the recognized token
        printf("Type: %d, Lexeme: %s\n", token.type, token.lexeme);
    }
}
int main()
{
    char program[] = "int main() {\n int x = 5;\n return x;\n}";
    struct Token token;
    printf("Type 0 - KEYWORD \nType 1 - IDENTIFIER \nType 2 - NUMBER \
nType 3 - OPERATOR \nType 4 - DELIMITER\n");
    printf("\n");
    tokenize(program);
    return 0;
}
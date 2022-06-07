

#define BACKSPACE '\b'
#define ENTER '\n'
#define TAB '\t'
#define SPACE ' '
#define PIPE '|'
#define DOUBLE_TAB "     "

/*
 * Devuelve la string ingresada como un entero
 */
int atoi_(char * str);

/*
 * Devuelve el tamanño de una string
 */
int strlen_(const char * s);

/*
 * Devuelve el indice donde substr es una subtring de str, -1 sino existe
 */
int substring(char *str, char *substr);

/*
 * Recibe un texto donde busca el primer indice donde aparece la string patron
 * como una substring. 
 */
int KMP(const char *text, const char *pattern, int textLen, int patternLen);

/*
 * Recibe dos strings y las compara
 */
int strcmp_(const char * str1, const char * str2);

/*
 * Recibe una string y devuelve el indice de la primer letra y
 * despues de la ultima letra. OJO QUE TIENE QUE PODER MODIFICAR A LA STRING
 * NO PUEDE SER UNA STRING LITERAL
 */
int removeTrailingSpaces(char * str);

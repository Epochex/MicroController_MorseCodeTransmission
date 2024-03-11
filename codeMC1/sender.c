#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* Function to convert a character to Morse code */
char * string_to_morse(char c)
{
    /* Morse code for letters A-Z */
    const char* morse_letters[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    /* Morse code for digits 0-9 */
    const char* morse_digits[] = {
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
    };

    if (isalpha(c)) {
        /* Print Morse code for letters (case insensitive) */
        return (char *)morse_letters[toupper(c) - 'A'];
    } else if (isdigit(c)) {
        /* Print Morse code for digits */
        return (char *)morse_digits[c - '0'];
    } else if (c == ' ') {
        /* Print a space to separate words; you might adjust this to your needs */
        return "/ ";
    }
    /* For unsupported characters */
    return "?";
}

int main()
{
    char text[] = "Hello World 123";

    /* FOR DEBUG USAGE */
    printf("Original : %s\n", text);
    printf("Morse Code : ");

    /* Convert and print each character in the text to Morse code */
    for (int i = 0; i < strlen(text); i++) {
        char * morse_code = string_to_morse(text[i]);
        for(int j = 0; j < strlen(morse_code); j++){
            /* FOR DEBUG USAGE */
            printf("%c", morse_code[j]);
            if(morse_code[j] == '.'){
                /* send a short sound */
                sleep(1);
                /* mico controler code here */
            } else if(morse_code[j] == '-'){
                /* send a long sound */
                sleep(1);
                /* mico controler code here */
            } else if(morse_code[j] == ' '){
                /* sleep for 3 second */
                sleep(3);
            } else if(morse_code[j] == '/'){
                /* sleep for 5 second */
                sleep(5);
            } 
        }
        /* FOR DEBUG USAGE */
        printf(" ");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

/* Structure to asign a Morse code to its character */
typedef struct {
    const char* morse;
    char character;
} MorseMap;

/* Function to convert a Morse code to a character */
char morse_code_to_character(const char* morse, MorseMap* map, int size)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(morse, map[i].morse) == 0) {
            return map[i].character;
        }
    }
    /* For unsupported characters */
    return '?';
}

int main()
{
    MorseMap morse_map[] = {
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'},
        {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
        {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
        {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
        {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
        {"--..", 'Z'}, {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
        {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},
        {"----.", '9'}, {"/", ' '}
    };
    int map_size = sizeof(morse_map) / sizeof(morse_map[0]);

    char morse_code[] = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";
    /* We suppose the message will be less than 100 characters */
    char decoded_message[100];

    char* token = strtok(morse_code, " ");
    int i = 0;
    while (token != NULL) {
        decoded_message[i++] = morse_code_to_character(token, morse_map, map_size);
        token = strtok(NULL, " ");
    }
    decoded_message[i] = '\0';

    printf("Morse Code : %s\n", morse_code);
    printf("Decoded message : %s\n", decoded_message);

    return 0;
}
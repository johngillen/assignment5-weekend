/*
 * Name: John Gillen
 * Assignment: Assignment5-weekend
 */

#include <stdio.h>
#include <stdlib.h>

char *cipher(char *string, char key)
{
    char k = (key - 'a') % 26;
    char* s = malloc(sizeof(string) + 1);
    s = string;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        if ('a' <= s[i] && s[i] <= 'z')  
        {
            if (s[i] + k > (int)'z')
            {
                s[i] = ((s[i] - 'a') + k) % 26 + 'a';
            } else {
                s[i] += k;
            }
            
        }
    }

    return s;
}

char smallcipher(char cleartext, char key)
{
    char k = (key - 'a') % 26;
    if ('a' <= cleartext && cleartext <= 'z')
    {
        if (cleartext + k > 'z')
        {
            return ((cleartext - 'a') + k) % 26 + 'a';
        } else {
            return cleartext + k;
        }
        
    }
    return cleartext;
}

char *vigenere(char *string, char *phrase)
{
    char* s = malloc(sizeof(string) + 1);
    s = string;

    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (phrase[n] == '\0') { n = 0; }
        s[i] = smallcipher(s[i], phrase[n]);
        n++;
    }
    
    return s;
}

char *invert(char *string)
{
    char* s = malloc(sizeof(string) + 1);
    s = string;

    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = (('a' - s[i]) + 26) % 26 + 'a';
    }
    
    return s;
}

int main(int argc, char const *argv[])
{

    char plaintext[420];
    printf("Enter cleartext: ");
    scanf("%s", plaintext);

    char phrase[420];
    printf("Encryption phrase: ");
    scanf("%s", phrase);

    printf("Decryption phrase: %s\n", invert(phrase));

    printf("Ciphertext: %s\n", vigenere(plaintext, phrase));

    return 0;
}

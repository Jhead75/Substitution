#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string encrypt(string key);

int main(int argc, string argv[])
{
    if (argc == 2) // check that user has passed only one additionaly argument
    {
        if (strlen(argv[1]) == 26) // check that argument length is exactly 26 characheters
        {
            for (int i = 0; i < 26; i++)
            {
                if (isalpha(argv[1][i]) == false) // check that key only contains alphabetical characters
                {
                    printf("key can only contain alpha charachter. \n");
                    return 1;
                }

                for (int j = 0; j < 26; j++) // check that each alphabetical charachter is only used once
                {
                    if (j != i)
                    {
                        if (argv[1][i] == argv[1][j])
                        {
                            printf("Key must contain every alphabetical character only once. \n");
                            return 1;
                        }
                    }
                }
            }
        }
        else
        {
            printf("key must be exactly 26 charachters in length. \n");
            return 1;
        }
    }
    else
    {
        printf("usage: ./substitution key \n");
        return 1;
    }

    //create array to represent letter shift
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string key = argv[1];
    int shift [26];

    for (int k = 0; k < 26; k++)
    {
        int one = tolower(key[k]);
        int two = alpha[k];
        shift[k] = one - two; //calculate difference between key ascii value and alphabet ascii value
    }


    //Convert plain text to cypher text
    string ptext = get_string("plaintext: "); // prompt user for "Plain text" that is too be encrypted
    string ctext = ptext;

    for (int l = 0; l < strlen(ptext); l++)
    {
        if (isalpha(ptext[l]))
        {
            if (isupper(ptext[l]))
            {
                ctext[l] += shift[ptext[l] - 65]; //set cipher text equal to plain text plus shift value.
            }                                     //Subtract 65 to account for upper case ascii value offset.
            else
            {
                ctext[l] += shift[ptext[l] - 97]; //set cipher text equal to plain text plus shift value.
            }                                     //Subtract 97 to account for lower case ascii value offset.
        }
    }
    printf("ciphertext: %s\n", ctext);
    return 0;
}

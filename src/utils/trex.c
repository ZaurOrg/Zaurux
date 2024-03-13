#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct 
{ 
    char text[65536]; 
    int length;
} text_line;

text_line read_line();
void display_text(text_line lines[65536]);
void save_text(text_line lines[65536], char *name);
int main(int argc, char **argv);

// Function to read a line of text from the user
text_line
read_line() 
{ 
    char buffer[1024];
    fgets(buffer, 1023, stdin);
    text_line line;
    strcpy(line.text, buffer);
    line.length = strlen(buffer);
    return line;
}

// Function to display the contents of the text file on the screen
void 
display_text(text_line lines[65536]) 
{ 
    for (int i = 0; i < 100; i++) 
        {   
            if (lines[i].length > 0)
                printf("%d: %s\n", i, lines[i].text); 
            else
                break;
        }
}
// Function to save the text file to disk
void save_text(text_line lines[65536], char *name) 
{ 
    FILE *fp = fopen(name, "w"); 
    if (fp == NULL) 
        {
            perror("Error opening file");
            return;
        }
    for (int i = 0; i < 65536; i++) 
        { 
            fprintf(fp, "%s\n", lines[i].text); 
        } 
    fclose(fp);
}
int main(int argc, char **argv) 
{
    if (argc != 2)
        {
            return -1;
        }
    else
        {
            FILE *f = fopen(argv[1], "w");
            fclose (f);
            f = fopen(argv[1], "r");
            if (!f)
                {
                    fprintf(stderr, "File wasn't created properly\n");
                    return -1;
                }
            else
                fclose (f);
        }
    text_line lines[65536]; 
    
    // Read lines of text from the user 
    for (int i = 0; i < 65536; i++) 
        { 
            lines[i] = read_line(); 
        } 
    // Display the contents of the text file on the screen 
    display_text(lines);
    // Save the text file to disk 
    save_text(lines, argv[1]); 
    return 0;
}
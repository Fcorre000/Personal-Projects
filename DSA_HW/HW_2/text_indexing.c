/*
 * Starter code
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000//define maximum number of words

//reads the file and combines it into a string
char * read_file_to_string(const char *file_path){
    //opens file for reading
    FILE *file = fopen(file_path, "r");

    //makes sure file isnt empty
    if(file == NULL){
        perror("error opening file");
        return NULL;
    }

    //Find the file size
    fseek(file, 0,SEEK_END);//moves file pointer to end of file

    long file_size = ftell(file);//uses the file pointer to find size of file and stores
    //value in file_size
    fseek(file, 0, SEEK_SET);//move file pointer back to beginning of file

    //Allocate buffer to read the file content
    char *buffer = (char *)malloc(file_size + 1);
    if(buffer == NULL){//error checking
        perror("error allocating memory for buffer");
        fclose(file);
        return NULL;
    }

    //read the file and put into buffer
    fread(buffer, 1, file_size, file);

    buffer[file_size] = '\0';//Null terminate the buffer
    //this makes it a valid C-string

    fclose(file);
    return buffer;
}

//tokenizes string stored in buffer
int tokenize_buffer(char *buffer, char *words[], int max_words){
    int word_count = 0;
    char *token = strtok(buffer, " \t\n\r");//splits it up by space, tab, newline and carraige return
    while(token != NULL && word_count < max_words){
        words[word_count++] = token;
        token = strtok(NULL, " \t\n\r");
    }
    return word_count;
}

int main(int argc, char** argv) {
    char *fname = NULL;
    int mode = 0; // 0 - normal, 1 - verbose

    if (argc < 3 ) {
        printf("Not enough arguments. Need mode and filename, e.g.: 0 caps.txt\n");
        return 0;
    }
    else {
        fname = argv[2];
        mode = atoi(argv[1]);
    }

    printf("mode: %d  file: %s\n", mode, fname);  // KEEP THIS LINE

    //read file to string
    char *file_content = read_file_to_string(fname);

    //error check then tokenize string
    if(file_content != NULL){
        char *words[MAX_WORDS];
        int word_count = tokenize_buffer(file_content, words, MAX_WORDS);
    }
    
    return 0;
}

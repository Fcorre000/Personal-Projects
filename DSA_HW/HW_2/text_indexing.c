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

//sorts words
void insertion_sort(char *words[], int word_count){
    for(int i = 1; i < word_count; i++){//i=1 because we need to start at the 2nd word
        char *key = words[i];
        int j = i - 1;//j used to traverse the sorted portion right to left
        while(j >= 0 && strcmp(words[j], key) > 0){
            words[j + 1] = words[j];//shifts j one position to the right
            j = j - 1;//decreases j to check the previous elements in the sorted portion
        }
        words[j + 1] = key;//inserts key into the right place in the sorted portion
    }
}


int binary_search(char *words[], int word_count, char *target) {
    int left = 0;
    int right = word_count - 1;
    int iterations = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        iterations++;
        printf("Middle index: %d\n", mid);

        int cmp = strcmp(words[mid], target);
        if (cmp == 0) {
            printf("Total iterations: %d\n", iterations);
            printf("Found\n");
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Total iterations: %d\n", iterations);
    printf("Not found\n");
    return -1;
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

    //MAIN ACTIONS: actually do stuff with the file now
    if(file_content != NULL){
        char *words[MAX_WORDS];
        int word_count = tokenize_buffer(file_content, words, MAX_WORDS);

        //sort words using insertion sort
        insertion_sort(words, word_count);

        // Example usage of the sorted words
        for (int i = 0; i < word_count; i++) {
            printf("Word %d: %s\n", i, words[i]);
        }

        // Read each word and use binary search to search for it in the sorted list
        for (int i = 0; i < word_count; i++) {
            printf("Searching for word: %s\n", words[i]);
            binary_search(words, word_count, words[i]);
        }

        free(file_content);
    
    }

    
    return 0;
}

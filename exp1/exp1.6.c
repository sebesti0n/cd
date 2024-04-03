#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isStopWord(const char *word, const char *stopWords) {
    char *token;
    char stopWordsCopy[1000];
    strcpy(stopWordsCopy, stopWords);
    token = strtok(stopWordsCopy, ", ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            return 1;
        }
        token = strtok(NULL, ", ");
    }
    return 0;
}

void removeStopWords(char *line, const char *stopWords, FILE *outputFilePtr) {
    char *word;
    char *delim = " \t\n";
    char *savePtr;

    word = strtok_r(line, delim, &savePtr);
    while (word != NULL) {
        char trimmedWord[100];
        strcpy(trimmedWord, word);
        char *end = trimmedWord + strlen(trimmedWord) - 1;
        while (end > trimmedWord && (*end == ' ' || *end == '\t' || *end == '\n')) {
            *end-- = '\0';
        }
        char *ptr = trimmedWord;
        while (*ptr && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')) {
            ptr++;
        }
        if (!isStopWord(ptr, stopWords)) {
            fprintf(outputFilePtr, "%s ", ptr);
        }
        word = strtok_r(NULL, delim, &savePtr);
    }
}

int main() {
    FILE *stopWordsPtr, *storyPtr, *storyWithoutStopWordsPtr;
    char line[1000];
    char stopWords[1000];

    stopWordsPtr = fopen("stop_words.txt", "r");
    storyPtr = fopen("story.txt", "r");
    storyWithoutStopWordsPtr = fopen("story_without_stopwords.txt", "w");
    if (stopWordsPtr == NULL || storyPtr == NULL || storyWithoutStopWordsPtr == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    char word[100];
    while (fscanf(stopWordsPtr, "%s", word) != EOF) {
        strcat(stopWords, word);
        strcat(stopWords, " ");
    }
    while (fgets(line, sizeof(line), storyPtr) != NULL) {
        removeStopWords(line, stopWords, storyWithoutStopWordsPtr);
    }
    fclose(stopWordsPtr);
    fclose(storyPtr);
    fclose(storyWithoutStopWordsPtr);

    printf("Stop words removed successfully. Output written to 'story_without_stopwords.txt'.\n");

    return 0;
}

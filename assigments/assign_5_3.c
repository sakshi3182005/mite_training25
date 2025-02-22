#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[256];
    struct Song *next;
} Song;

Song *createSong(const char *title) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    if (newSong == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newSong->title, title);
    newSong->next = NULL;
    return newSong;
}

Song *addSong(Song *playlist, const char *title) {
    Song *newSong = createSong(title);
    if (playlist == NULL) {
        newSong->next = newSong; // Circular link to itself for the first song
        return newSong;
    }

    Song *temp = playlist;
    while (temp->next != playlist) {
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->next = playlist; // Make the list circular
    return playlist;
}

Song *nextSong(Song *currentSong) {
    if (currentSong == NULL) {
        return NULL;
    }
    return currentSong->next;
}

void displayCurrentSong(Song *currentSong) {
    if (currentSong != NULL) {
        printf("Current Song: %s\n", currentSong->title);
    } else {
        printf("Playlist is empty.\n");
    }
}

void freePlaylist(Song *playlist) {
    if (playlist == NULL) {
        return;
    }

    Song *current = playlist;
    Song *next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != playlist);
}

int main() {
    Song *playlist = NULL;
    Song *currentSong = NULL;

    playlist = addSong(playlist, "Song A");
    playlist = addSong(playlist, "Song B");
    playlist = addSong(playlist, "Song C");

    currentSong = playlist; // Start with the first song

    displayCurrentSong(currentSong);

    currentSong = nextSong(currentSong);
    displayCurrentSong(currentSong);

    currentSong = nextSong(currentSong);
    displayCurrentSong(currentSong);

    currentSong = nextSong(currentSong);
    displayCurrentSong(currentSong); // Loop back to the first song

    currentSong = nextSong(currentSong);
    displayCurrentSong(currentSong);

    currentSong = nextSong(currentSong);
    displayCurrentSong(currentSong);

    freePlaylist(playlist);
    return 0;
}

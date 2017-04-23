#include <string.h>
#include <stdlib.h>

void reverse(char* wS, char* wE) {
    while(wS < wE) {
        char tmp = *wS;
        *wS = *wE;
        *wE = tmp;
        ++wS, --wE;
    }
}

void reverseWords(char* s) {
    if (!s) return;

    char* forwardIter = s;
    char* writeIter = s;
    char* wordStart = NULL;

    while(*forwardIter) {
        if (*forwardIter == ' ') {
            // Word ends here
            if (wordStart) {
                // We do a slow job, we first reverse the word in-place and then
                // copy it to wordStart
                reverse(wordStart, forwardIter - 1);
                while(wordStart != forwardIter) *writeIter++ = *wordStart++;

                *writeIter++ = ' ';

                wordStart = NULL;
            }
        } else {
            if (!wordStart) wordStart = forwardIter;
        }
        ++forwardIter;
    }

    if (wordStart) {
        reverse(wordStart, forwardIter - 1);
        while(wordStart != forwardIter) *writeIter++ = * wordStart++;
        *writeIter = ' ';
        writeIter++;
    }
    if (*(writeIter - 1) == ' ')
        *--writeIter = 0;
    else
        *writeIter = 0;

    // now reverse the whole reversed stripped string.
    reverse(s, writeIter - 1);
}

#include <stdio.h>
int main() {
    char words[] = " this is a test. ";
    reverseWords(words);
    printf("|%s|\n", words);
}

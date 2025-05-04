#include <stdio.h>

void main() {
    int i, j, n, fno, a[50], frame[10], k, avail, pagefault = 0;

    // Input number of frames
    printf("\nEnter the number of Frames: ");
    scanf("%d", &fno);

    // Input number of reference string
    printf("\nEnter number of reference string: ");
    scanf("%d", &n);

    // Input the reference string
    printf("\nEnter the Reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize all frames to -1 (empty)
    for (i = 0; i < fno; i++) {
        frame[i] = -1;
    }

    j = 0;  // Initialize the FIFO counter

    // Print the given reference string
    printf("\nFIFO Page Replacement Algorithm\n");
    printf("\nThe given reference string is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Process each page in the reference string
    for (i = 0; i < n; i++) {
        printf("\nReference No %d -> ", a[i]);

        avail = 0;

        // Check if the page is already in any frame
        for (k = 0; k < fno; k++) {
            if (frame[k] == a[i]) {
                avail = 1; // Page is already in memory
                break;
            }
        }

        // If page is not in memory, replace the oldest page (FIFO)
        if (avail == 0) {
            frame[j] = a[i];  // Place the new page in the frame
            j = (j + 1) % fno;  // Move to the next frame (circular FIFO)
            pagefault++;  // Increment page fault

            // Print the current state of the frames
            for (k = 0; k < fno; k++) {
                if (frame[k] != -1) { // Only print non-empty frames
                    printf("%2d ", frame[k]);
                }
            }
        }

        printf("\n");
    }

    // Output the total number of page faults
    printf("\nPage Faults: %d\n", pagefault);
}

#include <stdio.h>

int main() {
    int i, j, k, n, fno, a[50], frame[10], flag, min, pagefault = 0;

    printf("\nEnter the number of frames: ");
    scanf("%d", &fno);

    printf("\nEnter the number of reference strings: ");
    scanf("%d", &n);

    printf("\nEnter the reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize all frames to -1 (empty)
    for (i = 0; i < fno; i++) {
        frame[i] = -1;
    }

    printf("\nOptimal Page Replacement Algorithm\n");
    printf("The given reference string is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Process each reference in the reference string
    for (i = 0; i < n; i++) {
        printf("\nReference No %d -> ", a[i]);
        flag = 0;

        // Check if the page is already in the frame
        for (j = 0; j < fno; j++) {
            if (frame[j] == a[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {  // If the page is not in the frame
            int farthest = -1, replace = -1;

            // Find the page that will not be used for the longest time in the future
            for (j = 0; j < fno; j++) {
                int found = 0;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == a[k]) {
                        found = 1;
                        break;
                    }
                }

                // If the page is not found in future, replace it
                if (found == 0) {
                    replace = j;
                    break;
                }

                // If the page is used in future, find which one will be used later
                if (found == 1) {
                    if (k > farthest) {
                        farthest = k;
                        replace = j;
                    }
                }
            }

            // Replace the page at the "replace" index
            frame[replace] = a[i];
            pagefault++;  // Increment the page fault count

            // Print current state of the frames
            for (j = 0; j < fno; j++) {
                if (frame[j] != -1)
                    printf(" %2d", frame[j]);
                else
                    printf("  -");
            }
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pagefault);
    return 0;
}

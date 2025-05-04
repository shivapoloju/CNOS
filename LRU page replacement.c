#include <stdio.h>

int main() {
    int i, j, k, n, fno, a[50], frame[10], lru[10];
    int pagefault = 0, avail, max, pos = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &fno);

    printf("Enter the number of reference strings: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialize frames and LRU counters
    for (i = 0; i < fno; i++) {
        frame[i] = -1;
        lru[i] = 0;
    }

    printf("\nLRU Page Replacement Algorithm\n");
    printf("Reference string: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("\nReference %d -> ", a[i]);
        avail = 0;

        // Check if the page is already in a frame
        for (j = 0; j < fno; j++) {
            if (frame[j] == a[i]) {
                avail = 1;
                lru[j] = 0; // Reset LRU for recently used
            } else if (frame[j] != -1) {
                lru[j]++;   // Increase LRU for others
            }
        }

        // If page not found in frame, replace using LRU
        if (!avail) {
            int lru_pos = 0;

            // If there's an empty frame, use it
            for (j = 0; j < fno; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (j == fno) {
                // All frames are filled, find LRU
                for (j = 1; j < fno; j++) {
                    if (lru[j] > lru[lru_pos])
                        lru_pos = j;
                }
                pos = lru_pos;
            }

            frame[pos] = a[i];
            lru[pos] = 0;
            for (j = 0; j < fno; j++) {
                if (j != pos && frame[j] != -1)
                    lru[j]++;
            }
            pagefault++;
        }

        // Print current frame state
        for (j = 0; j < fno; j++) {
            if (frame[j] != -1)
                printf("%3d", frame[j]);
            else
                printf("  -");
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pagefault);
    return 0;
}

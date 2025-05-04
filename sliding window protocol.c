#include <stdio.h>

int main() {
    int totalFrames, windowSize, currentFrame = 0, acknowledgedFrames;

    // Input total number of frames and window size
    printf("Enter the total number of frames: ");
    scanf("%d", &totalFrames);

    printf("Enter the window size: ");
    scanf("%d", &windowSize);

    while (currentFrame < totalFrames) {
        // Sending frames within the window
        printf("\nSending frames:\n");
        for (int i = 0; i < windowSize && currentFrame + i < totalFrames; i++) {
            printf("Sent Frame: %d\n", currentFrame + i);
        }

        // Acknowledging frames
        printf("\nEnter the number of frames acknowledged: ");
        scanf("%d", &acknowledgedFrames);

        if (acknowledgedFrames == 0) {
            printf("No acknowledgment received. Resending frames...\n");
        } else {
            currentFrame += acknowledgedFrames;
            printf("%d frames acknowledged.\n", acknowledgedFrames);
        }
    }

    printf("\nAll frames sent successfully!\n");

    return 0;
}

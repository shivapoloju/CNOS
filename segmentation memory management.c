#include<stdio.h>

void main() {
    int i, j, m, size, val[10][10], badd[10], limit[10], ladd;

    // Input the size of the segment table
    printf("Enter the size of the segment table: ");
    scanf("%d", &size);

    // Input segment information (base address and limit)
    for(i = 0; i < size; i++) {
        printf("\nEnter information about segment %d", i + 1);
        printf("\nEnter base address: ");
        scanf("%d", &badd[i]);
        printf("Enter the limit: ");
        scanf("%d", &limit[i]);
        
        // Input the values for each segment based on its limit
        for(j = 0; j < limit[i]; j++) {
            printf("Enter address value at logical address %d: ", badd[i] + j);
            scanf("%d", &val[i][j]);
        }
    }

    // Display the segment table
    printf("\n\n****SEGMENT TABLE****");
    printf("\nSegment No.\tBase Address\tLimit");
    for(i = 0; i < size; i++) {
        printf("\n%d\t\t%d\t\t%d", i + 1, badd[i], limit[i]);
    }

    // Input the segment number to access
    printf("\n\nEnter segment number: ");
    scanf("%d", &i);

    // Check if the segment number is valid
    if(i < 1 || i > size) {
        printf("Invalid segment number!\n");
    } else {
        // Adjust segment number to zero-indexed for array access
        i--; 

        // Input the logical address
        printf("Enter the logical address: ");
        scanf("%d", &ladd);

        // Check if the logical address is within the segment limit
        if(ladd >= limit[i]) {
            printf("Invalid logical address!\n");
        } else {
            // Calculate the physical address (base address + logical address)
            m = badd[i] + ladd;
            
            // Display the physical address and value at the logical address
            printf("\nMapped physical address: %d", m);
            printf("\nThe value at this address is: %d\n", val[i][ladd]);
        }
    }
}

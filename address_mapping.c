#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, n;
    printf("\nEnter size of page: ");
    scanf("%d", &size);
    printf("\nEnter size of page table: ");
    scanf("%d", &n);
    int pgtable[n];
    printf("\nEnter %d entries for page table: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &pgtable[i]);
    }
    int va, ra;
    int cont;
    do{
    printf("Enter Virtual Address for Conversion: ");
    scanf("%d", &va);
    int pg = va/size;
    if(pg<n){
    ra = pgtable[pg]*size + va%size;
    printf("\nReal Address is %d", ra);
    }
    else printf("\nInvalid VA");
    printf("\n\nEnter 1 to continue or any key to exit: ");
    scanf("%d", &cont);
    }while(cont==1);

    /*
    // simulate virtual to physical address mapping
    int virtual_address = rand() % (NUM_PAGES * PAGE_SIZE);
    int page_number = virtual_address / PAGE_SIZE;
    int offset = virtual_address % PAGE_SIZE;
    int physical_address = (page_table[page_number] * PAGE_SIZE) + offset;

    // print results
    printf("Virtual address: %d\n", virtual_address);
    printf("Page number: %d\n", page_number);
    printf("Offset: %d\n", offset);
    printf("Physical address: %d\n", physical_address);
    */

    return 0;
}
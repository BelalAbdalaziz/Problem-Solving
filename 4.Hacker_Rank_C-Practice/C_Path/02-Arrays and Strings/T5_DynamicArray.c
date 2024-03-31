#include <stdio.h>
#include <stdlib.h>


 // This stores the total number of books in each shelf.

int* total_number_of_books;

int bookCounter,pageCounter;
//  This stores the total number of pages in each book of each shelf.
//  The rows represent the shelves and the columns represent the books.
 
int** total_number_of_pages;//Ptr to shelves that ptr to book 

int main()
{
    int total_number_of_shelves = 0;
    int total_number_of_requests = 0;
    
    scanf_s(" %d", &total_number_of_shelves);          //5 shelves
    scanf_s(" %d", &total_number_of_requests);         //5requests
    
    while (total_number_of_requests--) 
    {
        int type_of_request;
        scanf_s(" %d", &type_of_request);
        
        if (type_of_request == 1) {
            
            /*
            int x, y;
            scanf("%d %d", &x, &y);
            *(total_number_of_books+x)+=1;
            *(total_number_of_pages+x)=realloc(*(total_number_of_pages+x), *(total_number_of_books+x)*sizeof(int));
            *(*(total_number_of_pages+x)+*(total_number_of_books+x)-1)=y;
            */
            
        } else if (type_of_request == 2) {
            int shelveNumber, bookNumber;
            scanf_s(" %d %d", &shelveNumber, &bookNumber);
            printf("%d\n", *(*(total_number_of_pages + shelveNumber) + bookNumber));
        } else {
            int shelveNumber;
            scanf_s(" %d", &shelveNumber);
            printf("%d\n", *(total_number_of_books + shelveNumber));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
/* 
<<<<<<<<<< Task 4 => Dynamic Array in C Library search >>>>>>>>>>
----------------------------------
|       |       |       |       |
----------------------------------
|       |       |       |       |
----------------------------------
|       |       |       |       |
----------------------------------

request format : xyz
    y -> shelf Number
    z -> book Number
    x -> 1: insert Book in specified position
         2: print number of pages from specified Book and its pos
         3: print number of books from specified shelf  


Sample Input 0
5           -> No Of Shelves(رفوف)
5           -> No Of requests 
1 0 15      -> req1
1 0 20      -> req2
1 2 78      -> req3
2 2 0       -> req4
3 0         -> req5


Sample Output 0
78          
2

Explanation 0

*/
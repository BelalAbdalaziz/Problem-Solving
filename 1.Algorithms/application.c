#include "application.h"

#define KEY_1 5
#define KEY_2 55

#define ARRAY_LENGTH(LIST) (sizeof(LIST) / sizeof(LIST[0]))
#define FIRST_INDEX 0
#define LAST_INDEX(LIST) (ARRAY_LENGTH(LIST) - 1)

uint32_t List[] = {11, 22, 66, 33, 7, 12, 44, 55};
sint32_t Pos = NOT_EXIST;

int main(void)
{

    /* printf("Linear Search \n");
    Pos = linear_search(List, ARRAY_LENGTH(List), KEY_1);
    PRINT_POSITION(Pos, KEY_1)
    Pos = linear_search(List, ARRAY_LENGTH(List), KEY_2);
    PRINT_POSITION(Pos, KEY_2)
    printf("---------------------------- \n");
 */
    /* printf("Binary Search \n");
    Pos = binary_search(List, ARRAY_LENGTH(List), KEY_1);
    PRINT_POSITION(Pos, KEY_1)
    Pos = binary_search(List, ARRAY_LENGTH(List), KEY_2);
    PRINT_POSITION(Pos, KEY_2)
    printf("---------------------------- \n");*/

    /* printf("Selection Sort \n");
    print_array(List, ARRAY_LENGTH(List));
    selection_sort(List, ARRAY_LENGTH(List));
    print_array(List, ARRAY_LENGTH(List)); */

    /* printf("Bubble Sort \n");
    print_array(List, ARRAY_LENGTH(List));
    bubble_sort(List, ARRAY_LENGTH(List));
    print_array(List, ARRAY_LENGTH(List));
    print_array(List, ARRAY_LENGTH(List)); */

    /* printf("Insertion Sort \n");
    print_array(List, ARRAY_LENGTH(List));
    insertion_sort(List, ARRAY_LENGTH(List));
    print_array(List, ARRAY_LENGTH(List)); */
    enum
    {
        false,
        true
    };

    int i = 1;
    do
    {
        printf("%d\n", i);
        i++;
        if (i < 15)
            break;
    } while (true);

    return 0;
}

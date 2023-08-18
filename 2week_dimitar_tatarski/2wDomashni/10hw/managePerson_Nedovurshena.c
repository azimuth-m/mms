#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define ID_LEN 3 /* Beign odd does not requre more space than odd-1
                  * 3 has same space as 2;
                  * 5 has same space as 4;
                  */

/* Struct is padded to a size%2 Bytes == 0 */
struct Person {
        uint16_t birthYear  :  12; /* [0: 4095] */
        uint16_t birthMonth :   4; /* [0:   16] */
                /* 2 Bytes */
        char name[100];
        char id[ID_LEN];
                /* 100 + ID_LEN Bytes */

        uint8_t birthDay    :   5; /* [0:   31] */
        uint8_t gender      :   1; /* [0:    1] */
                /* 1 Byte */
};

/* Tui kato addPerson ne priema argument ukazatel kum array,
 * se predpolaaga che array-ut e globalen
 */
struct Person *PERSONS;
size_t LAST_ADDED_PERSON;
char LAST_ID[ID_LEN];

int
addPerson(char *name, uint16_t birthYear, uint8_t birthDay, uint8_t gender)
{
        PERSONS[LAST_ADDED_PERSON].name         = name;
        PERSONS[LAST_ADDED_PERSON].birthYear    = birthYear;
        PERSONS[LAST_ADDED_PERSON].birthDay     = birthDay;
        PERSONS[LAST_ADDED_PERSON].gender       = gender;

        
}

void *
initArray(size_t capacity) /* Remember to free allocated space */
{
        return (malloc(capacity * sizeof(struct Person)));
}

int
main()
{
        printf("%ld ", sizeof(struct Person));
        PERSONS = initArray(5);
        return 0;
}

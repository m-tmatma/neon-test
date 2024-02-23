#include <stdio.h>

/**
 * Performs a conditional selection operation on arrays of integers using NEON intrinsics.
 *
 * @param dest      Pointer to the destination array where the result will be stored.
 * @param src1      Pointer to the first source array.
 * @param src2      Pointer to the second source array.
 * @param size      The number of elements in the arrays.
 * @param condition The condition vector used for selecting elements.
 */
void conditional_select_int(int* dest, int* src1, int* src2, int size, unsigned int condition[4])
{
    for (int i = 0; i < size; i += 4) {
        int a[4];
        int b[4];
        int result[4];
        for (int j = 0; j < 4; j++) {
            a[j] = src1[i + j];
            b[j] = src2[i + j];
            result[j] = (condition[j] != 0) ? a[j] : b[j];
            dest[i + j] = result[j];
        }
    }
}

void conditional_select_char(char* dest, char* src1, char* src2, int size, unsigned char condition[16])
{
    for (int i = 0; i < size; i += 16) {
        char a[16];
        char b[16];
        char result[16];
        for (int j = 0; j < 16; j++) {
            a[j] = src1[i + j];
            b[j] = src2[i + j];
            result[j] = (condition[j] != 0) ? a[j] : b[j];
            dest[i + j] = result[j];
        }
    }
}

void test_select_int()
{
    int buf1[4] = { 0,1,2,3, };
    int buf2[4] = { 4,5,6,7, };
    int buf3[4] = { 0,1,2,3, };
    unsigned int condition[4] = { 0, 0xffffffff, 0, 0xffffffff };

    conditional_select_int(buf3, buf1, buf2, 4, condition);

    for( int i = 0; i < 4; i++ )
    {
        printf("%4d, %4d, %4d, %08x\n",buf1[i],buf2[i],buf3[i], condition[i]);
    }
}

void test_select_char()
{
    char buf1[16] = { 0,1,2,3,4,5,6,7 };
    char buf2[16] = { 8,9,10,11,12,13,14,15 };
    char buf3[16];
    unsigned char condition[16] = { 0, 0xff, 0, 0xff, 0, 0xff, 0, 0xff };

    conditional_select_char(buf3, buf1, buf2, 8, condition);

    for( int i = 0; i < 16; i++ )
    {
        printf("%4d, %4d, %4d, %02x\n",buf1[i],buf2[i],buf3[i], condition[i]);
    }
}

int main(int argc, char const* argv[])
{
    printf("test_select_int\n");
    test_select_int();
    printf("\n");

    printf("test_select_char\n");
    test_select_char();
    printf("\n");

    return 0;
}

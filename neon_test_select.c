#include <arm_neon.h>
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
void conditional_select_int(int* dest, int* src1, int* src2, int size, uint32x4_t condition)
{
    for (int i = 0; i < size; i += 4) {
        int32x4_t a = vld1q_s32(src1 + i);
        int32x4_t b = vld1q_s32(src2 + i);
        int32x4_t result = vbslq_s32(condition, a, b);
        vst1q_s32(dest + i, result);
    }
}

int main(int argc, char const* argv[])
{
    int buf1[4] = { 0,1,2,3, };
    int buf2[4] = { 4,5,6,7, };
    int buf3[4] = { 0,1,2,3, };
    uint32_t mask[4] = { 0, 0xffffffff, 0, 0xffffffff };
    uint32x4_t condition = vld1q_u32(mask);

    conditional_select_int(buf3, buf1, buf2, 4, condition);

    for( int i = 0; i < 4; i++ )
    {
        printf("%d, %d, %d, %08x\n",buf1[i],buf2[i],buf3[i], mask[i]);
    }

    return 0;
}

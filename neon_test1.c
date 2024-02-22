/*
    https://qiita.com/ar90n@github/items/347790d26a90f6de637b
*/
#include <arm_neon.h>
#include <stdio.h>

int main(int argc, char const* argv[])
{
    char buf1[] = { 0,1,2,3,4,5,6,7 };
    char buf2[] = { 8,9,10,11,12,13,14,15 };
    char buf3[8];
    uint8x8_t a;
    uint8x8_t b;
    uint8x8_t c;

    a = vld1_u8( buf1 );
    b = vld1_u8( buf2 );
    c = vadd_u8( a, b );
    vst1_u8( buf3, c );

    for( int i = 0; i < 8; i++ )
    {
        printf("%d\n",buf3[i]);
    }

    return 0;
}

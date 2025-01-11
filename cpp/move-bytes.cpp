#include <cstdlib>

// "number" of bytes located at the src address location should
// be at the dest address location after executing moveBytes
void moveBytes(char * src, char * dest, int number)
{
    if (src == dest) return;
    if (src == nullptr) return;
    if (dest == nullptr) return;

    int diff = dest - src;
    // no overlap, copy the bytes in any order
    if (abs(diff) >= number) {
        for (int idx = 0; idx < number; ++idx) {
            *(dest + idx) = *(src + idx);
        }
    } else if (diff > 0) {
        // copy the rear non overlapping bytes
        for (int idx = number - diff; idx < number; ++idx) {
            *(dest + idx) = *(src + idx);
        }
        // copy the overlapping bytes in the start
        for (int idx = 0; idx < (number - diff); ++idx) {
            *(dest + idx) = *(src + idx);
        }
    } else if (diff < 0) {
        diff = abs(diff);
        // copy the overlapping bytes in the start
        for (int idx = 0; idx < diff; ++idx) {
            *(dest + idx) = *(src + idx);
        }
        // copy the non-overlapping bytes
        for (int idx = diff; idx < number; ++idx) {
            *(dest + idx) = *(src + idx);
        }
    }
}

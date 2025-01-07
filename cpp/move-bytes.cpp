
// "number" of bytes located at the src address location should
// be at the dest address location after executing moveBytes
void moveBytes(char * src, char * dest, int number)
{
    if (src == dest) return;
    if (src == nullptr) return;
    if (dest == nullptr) return;

    for (int idx = 0; idx < number; ++idx) {
        *(dest + idx) = *(src + idx);
    }

    // FIXME: check for overlapping address locations
}

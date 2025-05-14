import sys

def longestSubstring(qstring: str) -> int:
    """Find the longest substring without repeating character,
    from the given string.
    This method uses the sliding window method.
    """
    parsed_char_set = set()
    leftIndex = 0
    longestLengthMatched = 0

    for rightIndex in range(len(qstring)):
        while qstring[rightIndex] in parsed_char_set:
            parsed_char_set.remove(qstring[leftIndex])
            leftIndex += 1
        parsed_char_set.add(qstring[rightIndex])
        longestLengthMatched = max(longestLengthMatched, rightIndex - leftIndex + 1)

    return longestLengthMatched

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: %s <string>" %(sys.argv[0]))
        sys.exit(1)

    print(longestSubstring(sys.argv[1]))


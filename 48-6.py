from typing import Optional, Tuple

def eqf(haystack: str, needle: str) -> Optional[Tuple[int, int]]:
    if not needle:
        return 0, 0
    elif len(needle) == 1:
        return (haystack.find(needle), 0) if needle in haystack else None
    else:
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i] == needle[0] and haystack[i+1:].find(needle[1]) != -1:
                j = i + 1 + haystack[i+1:].find(needle[1])
                dist = j - i
                if needle[2:] == haystack[i + 2 * dist:i + len(needle) * dist:dist]:
                    return i, dist
    return None

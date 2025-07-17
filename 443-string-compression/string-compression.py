class Solution(object):
    def compress(self, chars):
        point = 0
        count = 1
        key = chars[0]
        
        for char in chars[1:]:
            if char == key:
                count += 1
            else:
                chars[point] = key
                point += 1
                if count > 1:
                    for c in str(count):
                        chars[point] = c
                        point += 1
                key = char
                count = 1

        # Final group
        chars[point] = key
        point += 1
        if count > 1:
            for c in str(count):
                chars[point] = c
                point += 1

        return point

def weightedUniformStrings(s, queries):
    weights = set()
    prev = -1
    length = 0
    for c in s:
        weight = ord(c) - ord('a') + 1
        weights.add(weight)
        if prev == c:
            length += 1
            weights.add(length*weight)
        else:
            prev = c
            length = 1
     
    rval = []
    for q in queries:
        if q in weights:
            rval.append("Yes")
        else:
            rval.append("No")
    return rval

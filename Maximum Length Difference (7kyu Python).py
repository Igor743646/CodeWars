mxdiflg = lambda a1, a2: -1 if a1 == [] or a2 == [] else max(abs(len(min(a1, key = len)) - len(max(a2, key = len))), abs(len(min(a2, key = len)) - len(max(a1, key = len))))

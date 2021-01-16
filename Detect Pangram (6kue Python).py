is_pangram = lambda s: "abcdefghijklmnopqrstuvwxyz" in ''.join(sorted(set(s.lower())))

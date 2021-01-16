string_breakers = lambda n, st: '\n'.join([st.replace(" ", "")[i - n:i] for i in range(n, len(st.replace(" ", "")) + n, n)])

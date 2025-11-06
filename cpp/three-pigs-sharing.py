def solve(a):
    t = sum(a)
    if t % 3 != 0:
        return 0
    m = t//3
    n = len(a)
    c = 0
    ps = 0
    pc = {0:0}
    for i in range (n-1):
        ps += a[i]
        if ps == 2*m:
            c += pc.get(m,0)
        pc[ps] = pc.get(ps,0) + 1
    return c
			

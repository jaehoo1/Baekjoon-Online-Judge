a = input()
a_float = float(a)
a_int, a_frac = map(int, a.split('.'))
b = input()
b_float = float(b)
b_int, b_frac = map(int, b.split('.'))

cmp = (a_float > b_float) - (a_float < b_float)
int_cmp = (a_int > b_int) - (a_int < b_int)
frac_cmp = (a_frac > b_frac) - (a_frac < b_frac)

if int_cmp != 0:
    print(max(a_float, b_float))
else:
    print(max(a_float, b_float) if cmp == frac_cmp else -1)
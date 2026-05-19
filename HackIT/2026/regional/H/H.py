# authors:
# 1) Danila "akshin_" Axyonov;
# 2) Alexander "ValeevAlex" Valeev;
# 3) Nikita "rizhiy" Terebinov.

n = int(input())
a = {}
for _ in range(n):
    s = input()
    s1, s2 = s.split(' -> ')
    s3 = s2.split(', ')
    a[s1] = s3
q = []
used = set()
l = r = 0
q.append('305'); used.add('305'); r += 1
q.append('309'); used.add('309'); r += 1
while l < r:
    cur = q[l]; l += 1
    for nb in a.get(cur, []):
        if nb in used:
            continue
        q.append(nb); used.add(nb); r += 1
print('YES' if '000' in used else 'NO')

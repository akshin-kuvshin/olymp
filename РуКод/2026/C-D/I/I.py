# authors:
# 1) Danila "akshin_" Axyonov;
# 2) Alexander "Valeev_Alex" Valeev;
# 3) Nikita "benchik_228" Terebinov.

# solution for 40 points out of 60

def bin_pow(base: int, ptr: int) -> int:
    if ptr == 0:
        return 1
    if ptr % 2 == 1:
        return bin_pow(base, ptr - 1) * base
    half: int = bin_pow(base, ptr // 2)
    return half ** 2

def main() -> None:
    n: int = int(input())
    ans: int = 0
    for a in range(1, n):
        b: int = n - a

        col_min: int = (bin_pow(26, a) - 1) // 25
        col_max: int = col_min * 26
        row_min: int = bin_pow(10, b - 1)
        row_max: int = row_min * 10 - 1

        l: int = max(col_min, row_min)
        r: int = min(col_max, row_max)
        if r < l:
            continue

        ans += r - l + 1
        ans %= MOD
    print(ans)

if __name__ == '__main__':
    MOD = 998_244_353
    main()

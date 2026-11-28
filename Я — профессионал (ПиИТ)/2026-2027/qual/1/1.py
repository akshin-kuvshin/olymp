# author: Danila "akshin_" Axyonov

def main() -> None:
    b, n = map(int, input().split())

    ans, pow_b = 0, 1
    while pow_b <= n:
        ans += n // pow_b
        pow_b *= b # no overflow due to long arithmetic

    print(ans)

if __name__ == '__main__':
    main()

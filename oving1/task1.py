def is_Fibonacci_number(n):
    a = 0
    b = 1

    while b < n:
        temp = b
        b += a
        a = temp

    return b == n

if __name__ == '__main__':
    assert is_Fibonacci_number(5)

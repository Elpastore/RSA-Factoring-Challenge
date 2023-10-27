import gmpy2
def pollards_rho(n):
    def f(x):
        return (x**2 + 1) % n

    x = 2
    y = 2
    d = 1

    while d == 1:
        x = f(x)
        y = f(f(y))
        d = gmpy2.gcd(abs(x - y), n)

    return d

semiprime = 239809320265259  # Generate a 100-bit semiprime for demonstration

# Factorize the semiprime using Pollard's Rho
factor = pollards_rho(semiprime)

if factor == semiprime:
    print(f"Failed to factorize. Factor is still {semiprime}. Try a different algorithm or library.")
else:
    print(f"Factors using Pollard's Rho: {factor} and {semiprime // factor}")
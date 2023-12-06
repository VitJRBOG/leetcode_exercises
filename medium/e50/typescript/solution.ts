export function myPow(x: number, n: number): number {
    if (n == 0) {
        return 1;
    }

    if (n == -1) {
        return 1. / x;
    }

    let result: number = myPow(x, Math.floor(n / 2));
    result *= result;

    if (n % 2) {
        result *= x;
    }

    return result;
};
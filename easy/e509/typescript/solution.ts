export function fib(n: number): number {
    return calcFib(n, 0, 1);
};

function calcFib(n: number, f1: number, f2: number): number {
    if (n == 0) {
        return f1;
    }

    return calcFib(n - 1, f2, f1 + f2);
}
export function fib(n: number): number {
    let f1: number = 0;
    let f2: number = 1;

    while (0 < n) {
        let tmp: number = f2;

        f2 = f1 + f2;
        f1 = tmp;

        n--;
    }

    return f1;
};
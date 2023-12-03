export function isPalindrome(x: number): boolean {
    if (x < 0) {
        return false;
    }

    let origX = x;
    let result: number = 0;

    for (let i: number = 1; 0 < x; i = i * 10) {
        result = result * 10 + Math.trunc(x % 10);

        x = Math.trunc(x / 10);
    }

    if (result != origX) {
        return false;
    }

    return true;
};
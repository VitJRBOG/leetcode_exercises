import { isPalindrome } from "./solution"

function testIsPalindrome(): string {
    let input1: number[] = [123, 111, 101, 10, 11, -101, 12300321, 1, 0];

    let expectations: boolean[] = [false, true, true, false, true, false, true, true, true];

    if (input1.length != expectations.length) {
        return "test is invalid";
    }

    for (let i = 0; i < expectations.length; i++) {
        let result = isPalindrome(input1[i]);

        let msg = `bad result for ${input1[i]}: got ${result} expected ${expectations[i]}`;

        if (result != expectations[i]) {
            return msg;
        }
    }

    return "PASS";
}

console.log(testIsPalindrome());
import { fib } from "./solution"

function testFib(): string {
    let input1: number[] = [2, 3, 4];

    let expectations: number[] = [1, 2, 3];

    if (input1.length != expectations.length) {
        return "test is invalid";
    }

    for (let i = 0; i < expectations.length; i++) {
        let result = fib(input1[i]);

        let msg = `bad result for ${input1[i]}: got ${result} expected ${expectations[i]}`;

        if (result != expectations[i]) {
            return msg;
        }
    }

    return "PASS";
}

console.log(testFib());
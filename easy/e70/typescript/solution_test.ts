import { climbStairs } from "./solution"

function testClimbStairs(): string {
    let input1: number[] = [2, 3, 4, 5, 45];

    let expectations: number[] = [2, 3, 5, 8, 1836311903];

    if (input1.length != expectations.length) {
        return "test is invalid";
    }

    for (let i = 0; i < expectations.length; i++) {
        let result = climbStairs(input1[i]);

        let msg = `bad result for ${input1[i]}: got ${result} expected ${expectations[i]}`;

        if (result != expectations[i]) {
            return msg;
        }
    }

    return "PASS";
}

console.log(testClimbStairs());
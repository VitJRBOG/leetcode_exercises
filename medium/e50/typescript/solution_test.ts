import { myPow } from "./solution"

function testMyPow(): string {
    let input1: number[] = [2.00000, 2.10000, 2.00000, 10, -100.00000, -99.99999, 34.00515];
    let input2: number[] = [10, 3, -2, 4, -2147483648, -2147483648, -3];

    let expectations: number[] = [1024.00000, 9.26100, 0.25000, 10000.00000, 0.00000, 0.00000, 0.00003];

    if (input1.length != input2.length || input2.length != expectations.length || expectations.length != input1.length) {
        return "test is invalid";
    }

    for (let i = 0; i < expectations.length; i++) {
        let result = myPow(input1[i], input2[i]);

        let msg = `bad result for ${input1[i]} and ${input2[i]}: got ${result} expected ${expectations[i]}`;

        if (parseFloat(result.toFixed(5)) != expectations[i]) {
            return msg;
        }
    }

    return "PASS";
}

console.log(testMyPow());
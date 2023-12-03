import { twoSum } from "./solution"

function testTwoSum(): string {
    let input1: number[][] = [[0, 4, 3, 0], [2, 7, 11, 15], [3, 2, 4], [3, 3]];
    let input2: number[] = [0, 9, 6, 6];

    let expectations: number[][] = [[0, 3], [0, 1], [1, 2], [0, 1]];

    if (input1.length != input2.length || input2.length != expectations.length || expectations.length != input1.length) {
        return "test is invalid";
    }

    for (let i = 0; i < expectations.length; i++) {
        let result = twoSum(input1[i], input2[i]);

        let msg = `bad result for ${input1[i]} and ${input2[i]}: got ${result} expected ${expectations[i]}`;

        if (result.length != expectations[i].length) {
            return msg;
        }

        for (let j = 0; j < result.length; j++) {
            if (result[j] != expectations[i][j]) {
                return msg;
            }
        }
    }

    return "PASS";
}

console.log(testTwoSum());
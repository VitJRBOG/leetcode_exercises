import { sortColors } from "./solution"

function testSortColors(): string {
    let input1: number[][] = [[2, 0, 2, 1, 1, 0], [2, 0, 1]];

    let expectations: number[][] = [[0, 0, 1, 1, 2, 2], [0, 1, 2]];

    if (input1.length != expectations.length) {
        return "test is invalid";
    }

    for (let i = 0; i < expectations.length; i++) {
        const origInput: number[] = Object.assign([], input1[i])

        sortColors(input1[i]);

        let msg = `bad result for ${origInput}: got ${input1[i]} expected ${expectations[i]}`;

        if (origInput.length != input1[i].length) {
            return msg;
        }

        for (let j: number = 0; j < expectations[i].length; j++) {
            if (expectations[i][j] != input1[i][j]) {
                return msg;
            }
        }
    }

    return "PASS";
}

console.log(testSortColors());
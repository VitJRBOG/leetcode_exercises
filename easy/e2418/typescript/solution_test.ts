import { sortPeople } from "./solution"

function testSortPeople(): string {
    let input1: string[][] = [["Mary", "John", "Emma"], ["Alice", "Bob", "Bob"]]
    let input2: number[][] = [[180, 165, 170], [155, 185, 150]];

    let expectations: string[][] = [["Mary", "Emma", "John"], ["Bob", "Alice", "Bob"]];

    if (input1.length != input2.length || input2.length != expectations.length || expectations.length != input1.length) {
        return "test is invalid";
    }

    for (let i = 0; i < expectations.length; i++) {
        let result: string[] = sortPeople(input1[i], input2[i]);

        let msg = `bad result for ${input1[i]} and ${input2[i]}: got ${result} expected ${expectations[i]}`;

        if (result.length != expectations[i].length) {
            return msg;
        }

        for (let j: number = 0; j < expectations[i].length; j++) {
            if (expectations[i][j] != result[j]) {
                return msg;
            }
        }
    }

    return "PASS";
}

console.log(testSortPeople());
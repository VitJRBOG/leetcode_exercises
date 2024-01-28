export function sortPeople(names: string[], heights: number[]): string[] {
    mergeSort(names, heights);
    return names;
};

function mergeSort(names: string[], heights: number[]) {
    if (names.length <= 1) {
        return;
    }

    let mid: number = Math.floor(names.length / 2);
    let leftNames: string[] = names.slice(0, mid);
    let leftHeights: number[] = heights.slice(0, mid);
    mergeSort(leftNames, leftHeights);
    let rightNames: string[] = names.slice(mid, names.length);
    let rightHeights: number[] = heights.slice(mid, heights.length);
    mergeSort(rightNames, rightHeights);

    let i: number = 0;
    let j: number = 0;
    let n: number = 0;
    while (i < leftHeights.length && j < rightHeights.length) {
        if (rightHeights[j] < leftHeights[i]) {
            heights[n] = leftHeights[i];
            names[n] = leftNames[i];

            i++;
        } else {
            heights[n] = rightHeights[j];
            names[n] = rightNames[j];

            j++;
        }
        n++;
    }

    while (i < leftHeights.length) {
        heights[n] = leftHeights[i];
        names[n] = leftNames[i];

        i++;
        n++;
    }

    while (j < rightHeights.length) {
        heights[n] = rightHeights[j];
        names[n] = rightNames[j];

        j++;
        n++;
    }
};
/**
 Do not return anything, modify nums in-place instead.
 */
export function sortColors(nums: number[]): void {
    if (nums.length < 2) {
        return;
    }

    _hoarsSort(nums, 0, nums.length - 1);
};

function _hoarsSort(nums: number[], left: number, right: number) {

    let partition: number = 0;

    if (left < right) {
        partition = _partition(nums, left, right);

        _hoarsSort(nums, left, partition - 1);
        _hoarsSort(nums, partition + 1, right);
    }

};

function _partition(nums: number[], left: number, right: number): number {
    let tmp: number = 0;
    let i: number = left - 1;

    for (let j: number = left; j < right; j++) {
        if (nums[j] <= nums[right]) {
            i++;

            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    i++;
    tmp = nums[i];
    nums[i] = nums[right];
    nums[right] = tmp;

    return i;
};
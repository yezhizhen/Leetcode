//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
fun twoSum(numbers: IntArray, target: Int): IntArray {
    var (l, r) = listOf(0, numbers.size - 1)
    while (true) {
        (numbers[l] + numbers[r]).let {
            if (it < target)
                l++
            else if (it > target)
                r--
            else
                return intArrayOf(l + 1, r + 1)
        }
    }
}

//binary search
fun twoSum_b(numbers: IntArray, target: Int): IntArray {
    //for each numbers[l]. find its target
    for (l in 0 until numbers.size - 1) //l cannot reach the final. use until
    {
        var r = numbers.binarySearch(target - numbers[l], l + 1)
        if (r >= 0)
            return intArrayOf(l + 1, r + 1)
    }
    return intArrayOf(-1, -1)
}
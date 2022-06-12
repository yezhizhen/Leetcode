//https://leetcode.com/problems/maximum-erasure-value/
@RequiresApi(Build.VERSION_CODES.N)
fun maximumUniqueSubarray(nums: IntArray): Int {
    var (l, ans, cur_sum) = listOf(0, 0, 0)
    var last_occ = mutableMapOf<Int, Int>()
    for(r in 0 until nums.size){
        cur_sum += nums[r]
        if(last_occ.getOrDefault(nums[r],-1) >= l) {
            var last_val = last_occ.getValue(nums[r])
            while (l <= last_val)
                cur_sum -= nums[l++]
        }
        last_occ[nums[r]] = r
        ans = max(ans, cur_sum)
    }
    return ans
}
//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

@RequiresApi(Build.VERSION_CODES.N) //for getordefault. requires api 24 in android
fun lengthOfLongestSubstring(s: String): Int {
    var l = 0; var ans = 0
    var occ = mutableMapOf<Char, Int>() //char to index
    for(r in 0 until  s.length){
        //find duplicate
        occ.getOrDefault(s[r], -1).let{ last_occ ->
            if(last_occ >= l)
                l = last_occ + 1
        }
        occ[s[r]] = r
        ans = max(ans, r - l + 1)
    }
    return ans
}

fun lengthOfLongestSubstring2(s: String): Int {
    var l = 0; var ans = 0
    var occ = mutableMapOf<Char, Int>() //char to index
    for(r in 0 until s.length){
        //find duplicate
        if(occ.contains(s[r]) &&  occ[s[r]]!! >= l)
            l = occ[s[r]]!! + 1
        occ[s[r]] = r
        ans = max(ans, r - l + 1)
    }
    return ans
}
//https://leetcode.com/problems/remove-palindromic-subsequences/

//fun removePalindromeSub(s: String): Int {
//    return when (s == s.reversed()) {
//        true -> 1
//        false -> 2
//    }
//}

fun isPalind(s: String): Boolean{
    var l = 0; var r = s.length - 1
    while(l <= r && s[l] == s[r])
    {
        l++; r--
    }
    if(l > r)
        return true
    return false
}

fun removePalindromeSub(s: String): Int {
    return if (isPalind(s)) 1 else 2
}
/*
fun removePalindromeSub(s: String): Int {
    return if (s == s.reversed()) 1 else 2
}
*/
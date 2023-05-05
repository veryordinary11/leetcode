/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 * Input: s = "abciiidef", k = 3
  Output: 3
  Explanation: The substring "iii" contains 3 vowel letters.
 */

var maxVowels = function (s, k) {
  const vowels = ["a", "e", "i", "o", "u"];
  let count = 0;
  let max = 0;
  for (let i = 0; i < s.length; i++) {
    if (vowels.includes(s[i])) count++;

    if (i >= k && vowels.includes(s[i - k])) count--;

    if (i >= k - 1) max = max > count ? max : count;
  }
  return max;
};


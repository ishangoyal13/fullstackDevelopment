"""
# PREFIX AND SUFFIX SEARCH

Design a special dictionary with some words that searchs the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".
 

Constraints:

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.
"""

# THIS SOLUTION WILL RESULT IN TIME LIMIT EXCEEDED ERROR.

from typing import Collection, List

class WordFilter:

    def __init__(self, words: List[str]):
        self.root = {}
        self.endSymbol = "*"
        self.suffixIndex = "SuffixIndexes"
        self.prefixIndex = "PrefixIndexes"
        for index, word in enumerate(words):
            self.populateTrie(word, index)
        
    def populateTrie(self, word, index):
        for i in range(len(word)):
            current = self.root
        
            for j in range(i, len(word)):
                letter = word[j]
                if letter not in current:
                    current[letter] = {}
                current = current[letter]
            if self.endSymbol in current and self.suffixIndex in current:
                current[self.suffixIndex].append(index)
            else:
                current[self.endSymbol] = True
                current[self.suffixIndex] = [index]
        
        for i in range(len(word)):
            current = self.root
        
            for j in range(i + 1):
                letter = word[j]
                if letter not in current:
                    current[letter] = {}
                current = current[letter]
            if self.endSymbol in current and self.prefixIndex in current:
                current[self.prefixIndex].append(index)
            else:
                current[self.endSymbol] = True
                current[self.prefixIndex] = [index]
        

    def f(self, prefix: str, suffix: str) -> int:
        prefixIndexes = self.searchPrefixIndexes(prefix)
        suffixIndexes = self.searchSuffixIndexes(suffix)
        if prefixIndexes == -1 or suffixIndexes == -1:
            return -1
        
        prefixIndexes.sort(reverse=True)
        suffixIndexes.sort(reverse=True)
        i, j = 0, 0
        while i < len(prefixIndexes) and j < len(suffixIndexes):
            if prefixIndexes[i] == suffixIndexes[j]:
                return prefixIndexes[i]
            elif prefixIndexes[i] > suffixIndexes[j]:
                i += 1
            else:
                j += 1
        
        return -1
        
    def searchPrefixIndexes(self, prefix):
        current = self.root
        for letter in prefix:
            if letter not in current:
                return -1
            current = current[letter]
        if self.endSymbol in current:
            return current[self.prefixIndex]
        
    def searchSuffixIndexes(self, suffix):
        current = self.root
        for letter in suffix:
            if letter not in current:
                return -1
            current = current[letter]
        if self.endSymbol in current:
            return current[self.suffixIndex]
            


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)

########################################
# THIS IS THE MOST EFFICIENT SOLUTION
########################################

Trie = lambda: Collection.defaultdict(Trie)
WEIGHT = False

class WordFilter(object):
    def __init__(self, words):
        self.trie = Trie()

        for weight, word in enumerate(words):
            word += '#'
            for i in range(len(word)):
                cur = self.trie
                cur[WEIGHT] = weight
                for j in range(i, 2 * len(word) - 1):
                    cur = cur[word[j % len(word)]]
                    cur[WEIGHT] = weight

    def f(self, prefix, suffix):
        cur = self.trie
        for letter in suffix + '#' + prefix:
            if letter not in cur:
                return -1
            cur = cur[letter]
        return cur[WEIGHT]
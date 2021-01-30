#include <string>
#include <unordered_map>

// Check if a given string is palindrome
// There is no any exception. Each character should be identical.
bool IsPalindrome(std::string s)
{
    int head, tail;
    head = 0;
    tail = s.size() - 1;
    if (head == tail)
    {
        // one character
        return true;
    }

    bool isPalindrome = true;
    while (head < tail)
    {
        if (s[head] != s[tail])
        {
            isPalindrome = false;
            break;
        }
        ++head;
        --tail;
    }
    return isPalindrome;
}

// 125. Valid Palindrome - LeetCode
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// s consists only of printable ASCII characters.
bool ValidPalindrome(std::string s)
{
    // empty string
    if (s.empty())
    {
        return true;
    }

    // firstly, create lookup table for valid characters
    // [Aa, Zz] + [0, 9]
    std::unordered_map<char, char> umap;
    for (auto i = 0; i < 26; ++i)
    {
        umap[char('a' + i)] = char('A' + i);
        umap[char('A' + i)] = char('a' + i);
    }
    for (auto i = 0; i < 10; ++i)
    {
        umap[char('0' + i)] = char('0' + i);
    }

    // filter source string to temp string with only acceptable characters and numbers
    std::string temp;
    for (char c : s)
    {
        if (umap.find(c) != umap.end())
        {
            temp.push_back(c);
        }
    }

    // print lookup table
    //for (auto c : umap)
    //{
    //    cout << "c.first: " << c.first << " - c.second: " << c.second << endl;
    //}
    // print filtered source string (only letters in English Alphabet)
    //cout << temp << endl;


    int head, tail;
    head = 0;
    tail = temp.size() - 1;
    if (head == tail)
    {
        // one character
        return true;
    }

    bool isPalindrome = true;
    while (head < tail)
    {
        // compare both original values from lookup table and
        // compare by changing one of them to lower or upper case while keeping the other as same
        if (temp[head] != temp[tail] && umap[temp[head]] != temp[tail])
        {
            isPalindrome = false;
            break;
        }
        ++head;
        --tail;
    }
    return isPalindrome;
}
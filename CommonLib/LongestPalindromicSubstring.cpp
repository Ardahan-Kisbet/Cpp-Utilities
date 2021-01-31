#include <string>
#include "IsPalindrome.cpp"
#include <iostream>

std::string LongestPalindromicSubstring(std::string s) {

    int head, tail, maxLen;
    head = tail = 0;
    maxLen = 0;
    std::string maxPalindrome;

    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = i + maxLen; j < s.size(); ++j)
        {
            std::string temp = s.substr(i, j - i + 1);
            if (IsPalindrome(temp) && temp.size() > maxLen)
            {
                maxPalindrome = temp;
                maxLen = temp.size();
            }
        }
    }

    return maxPalindrome;
}

void static Print()
{
    std::string t = LongestPalindromicSubstring("kztakrekvefgchersuoiuatzlmwynzjhdqqftjcqmntoyckqfawikkdrnfgbwtdpbkymvwoumurjdzygyzsbmwzpcxcdmmpwzmeibligwiiqbecxwyxigikoewwrczkanwwqukszsbjukzumzladrvjefpegyicsgctdvldetuegxwihdtitqrdmygdrsweahfrepdcudvyvrggbkthztxwicyzazjyeztytwiyybqdsczozvtegodacdokczfmwqfmyuixbeeqluqcqwxpyrkpfcdosttzooykpvdykfxulttvvwnzftndvhsvpgrgdzsvfxdtzztdiswgwxzvbpsjlizlfrlgvlnwbjwbujafjaedivvgnbgwcdbzbdbprqrflfhahsvlcekeyqueyxjfetkxpapbeejoxwxlgepmxzowldsmqllpzeymakcshfzkvyykwljeltutdmrhxcbzizihzinywggzjctzasvefcxmhnusdvlderconvaisaetcdldeveeemhugipfzbhrwidcjpfrumshbdofchpgcsbkvaexfmenpsuodatxjavoszcitjewflejjmsuvyuyrkumednsfkbgvbqxfphfqeqozcnabmtedffvzwbgbzbfydiyaevoqtfmzxaujdydtjftapkpdhnbmrylcibzuqqynvnsihmyxdcrfftkuoymzoxpnashaderlosnkxbhamkkxfhwjsyehkmblhppbyspmcwuoguptliashefdklokjpggfiixozsrlwmeksmzdcvipgkwxwynzsvxnqtchgwwadqybkguscfyrbyxudzrxacoplmcqcsmkraimfwbauvytkxdnglwfuvehpxd");
    std::cout << "t --> " << t << std::endl;
}

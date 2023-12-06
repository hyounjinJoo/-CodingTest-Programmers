#include <string>
#include <vector>

using namespace std;

char TranslateMorse(const std::string& morseLetter)
{
    std::vector<std::string> morseCode = {".-","-...","-.-.","-.."
                                        ,".","..-.","--.","...."
                                        ,"..",".---","-.-",".-.."
                                        ,"--","-.","---",".--."
                                        ,"--.-",".-.","...","-"
                                        ,"..-","...-",".--","-..-"
                                        ,"-.--","--.."};
    std::vector<char> alphabetCode;
    for(size_t index = 0; index < 28; ++index)
    {
        alphabetCode.push_back('a' + static_cast<char>(index));
    }
    
    char translatedChar = 0;
    for(size_t codeIndex = 0; codeIndex < 28; ++codeIndex)
    {
        if(morseCode[codeIndex] == morseLetter)
        {
            translatedChar = alphabetCode[codeIndex];
        }
    }
        
    return translatedChar;
}

char alphabet = 0;
string solution(string letter) {
    string answer = "";
    string morseLetter = "";
    size_t length = letter.length();
    for(size_t index = 0; index < length; ++index)
    {
        if(letter[index] == ' ')
        {
            alphabet = TranslateMorse(morseLetter);
            morseLetter = "";
            
            answer.push_back(alphabet);
            
            continue;
        }
        else
        {
            morseLetter.push_back(letter[index]);
            
            if(index == length - 1)
            {
                alphabet = TranslateMorse(morseLetter);
                answer.push_back(alphabet);
            }
        }
        
    }
    
    return answer;
}
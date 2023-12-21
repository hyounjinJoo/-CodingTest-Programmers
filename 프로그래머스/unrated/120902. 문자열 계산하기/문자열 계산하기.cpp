#include <string>
#include <vector>

using namespace std;


int solution(string my_string) {
    // 연산 과정
    //  - 숫자를 찾는다.
    //      -> 숫자의 조건
    //          => 앞에 -가 붙거나 공백이고 자기 자신은 숫자(숫자의 시작 조건)
    //          => 뒤가 공백이거나 숫자이고 자기 자신은 숫자(숫자의 끝 조건)
    //          결론 : 자기 자신이 숫자
    //          추가 : -일때 뒤가 숫자이면 숫자에 포함된 문자
    //  - 숫자를 변환한다.
    //  - 연산자를 저장해 둔다.
    //  - 연산자가 있고 숫자가 존재하면 연산을 실행한다.
    // 단, 첫 번째 숫자는 예외로 미리 값을 저장해둔다.
    std::vector<std::string> tokenizedStr;
    std::string delim = " ";
    
    size_t pos = 0;
    while((pos = my_string.find(" ")) != std::string::npos)
    {
        tokenizedStr.push_back(my_string.substr(0, pos));
        my_string.erase(0, pos + delim.size());
    }
    tokenizedStr.push_back(my_string.substr(0, pos));
    
    int answer = std::stoi(tokenizedStr[0]);

    int tempNumber = 0;
    int count = static_cast<int>(tokenizedStr.size());
    for(int index = 1; index < count; index += 2)
    {
        if(tokenizedStr[index] == "+")
        {
            answer += std::stoi(tokenizedStr[index+1]);
        }
        else
        {
            answer -= std::stoi(tokenizedStr[index+1]);
        }
    }
    return answer;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string solution(string InitString, vector<string> command)
{
    // 커서를 문제의 조건처럼 맨 뒤에 붙입니다.
    string answer = InitString+'|';
    // 제가 기입한것과 다르게 c_str 은 const char 를 반환하기 때문에 
    // vector 를 사용해야 할것 같습니다.
    // vector 를 answer 로 초기화 합니다.
    vector<char> str_vector(answer.begin(), answer.end());
    // 커서의 현재 인덱스를 선언합니다.
    int cursor = InitString.size();
    char tmp;
    // 이제 커맨드 백터에 대해서 반복문을 수행합니다.
    for (int i=0;i<command.size();i++) {
        // 순서에 맞게 수행할 커맨드를 가져옵니다.
        auto cmd = command[i];
        // 스트링값이기 떄문에 캐랙터 타입으로 변경해줍니다.
        char prefix = cmd[0];
        switch (prefix) {
            // L 커맨드일 경우 커서 인덱스와 왼쪽의 원소화 swap 을 
            // 수행합니다.
            case 'L':
                // 임시로 커서 왼쪽의 있는 값을 저장합니다.
                // 여기서 커서가 가장 왼쪽에 있을 경우에 대비해
                // 조건을 추가해야겠습니다.
                if (!cursor) {
                    break;
                }
                tmp = str_vector[cursor-1];
                str_vector[cursor-1] = str_vector[cursor];
                str_vector[cursor] = tmp;
                // cursor 의 인덱스를 조정해줍니다. 
                cursor -= 1;
                break;
            case 'R':
                // L 과 원리적으로 같고
                // 방향이 다르기 때문에 
                // 커서가 가장 오른쪽에 있는경우에 조건을 달아 break해주고
                if (cursor == str_vector.size() - 1) {
                    break;
                }
                // 아니면 오른쪽 값과 스왑해줍니다.
                tmp = str_vector[cursor+1];
                str_vector[cursor+1] = str_vector[cursor];
                str_vector[cursor] = tmp;
                // cursor 의 인덱스를 조정해줍니다. 
                cursor += 1;
                break;
            case 'D':
                // L 과 동일하게 커서가 가장 왼쪽에 있을 경우에 대비해
                // 조건을 추가합니다.
                if (!cursor) {
                    break;
                }
                // 아닐경우 백터의 이레이즈 함수를 이용해 
                // 왼쪽 원소를 지웁니다.
                str_vector.erase(str_vector.begin()+cursor-1);
                // cursor 의 인덱스를 조정해줍니다. 
                cursor -= 1;
                break;
            case 'I':
                // ㅣ 은 커서가 가장 오른쪽에 있을 경우 P 커맨드로 작동하기 떄문에 
                // 조건부로 break 를 구성하겠습니다.
                if (!(cursor == str_vector.size() - 1)) {
                    // 가장 오른쪽에 존재하지 않을경우 break 넣어 스위치문을
                    // 빠져나가게 하고 오른쪽에 있을 경우
                    // break 를 하지않아 P 커맨드가 수행될 수 있도록 합니다.

                    // 커서 오른쪽에 있는 값을 커맨드 두번째 원소로 넣어주고
                    str_vector[cursor+1] = cmd[2];
                    // 커서와 스왑합니다.
                    tmp = str_vector[cursor+1];
                    str_vector[cursor+1] = str_vector[cursor];
                    str_vector[cursor] = tmp;
                    // cursor 의 인덱스를 조정해줍니다. 
                    cursor += 1;
                    break;
                }
            case 'P':
                // 커서 오른쪽에 있는 값을 커맨드 두번째 원소로 넣어주고
                str_vector.insert(str_vector.begin() + cursor, cmd[2]);
                // 커서의 인덱스를 조정해 줍니다.
                cursor += 1;
                break;
            default:
                break;
        }
    }
    str_vector.erase(str_vector.begin() + cursor);
    // 반복문이 끝나면 백터값을 스트링으로 변한해 줍니다.
    answer = string(str_vector.begin(), str_vector.end());
    return answer;
}


int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    

    auto ret = solution(
        "abcd",
        {"L", "P Z", "L", "D", "R", "I x"}
    );

    ret = solution(
        "",
        {"P a", "P b", "L", "I c", "I d"}
    );


    return 0;
}

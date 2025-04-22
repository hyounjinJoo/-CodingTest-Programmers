#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, map<string, int>> IDListMap;
    for (auto& data : report)
    {
        int IDXSpace = data.find(' ');
        string ReportID = data.substr(0, IDXSpace);
        string ReportedID = data.substr(IDXSpace + 1);
        IDListMap[ReportedID][ReportID] = 1;
    }

    vector<int> ReportedCounts;
    for (auto& data : id_list)
    {
        int ReportCount = 0;
        for (auto& ReportID : id_list)
        {
            if (data == ReportID)
            {
                continue;
            }
            if (1 == IDListMap[data][ReportID])
            {
                ++ReportCount;
            }
        }

        ReportedCounts.push_back(ReportCount);
    }

    map<string, int> MapNameIDX;
    for(int IDX = 0; IDX < id_list.size(); ++IDX)
    {
        MapNameIDX[id_list[IDX]] = IDX;
    }

    answer.resize(id_list.size());

    for(int IDX = 0; IDX < ReportedCounts.size(); ++IDX)
    {
        if (ReportedCounts[IDX] >= k)
        {
            string& OverKName = id_list[IDX];

            for(auto& Reporter : id_list)
            {
	            for(auto& Reported : id_list)
	            {
		            if(OverKName == Reported && 1 == IDListMap[Reported][Reporter])
		            {
                        IDListMap[Reported][Reporter] = 0;
                        ++answer[MapNameIDX[Reporter]];
		            }
	            }
            }
        }
    }

    return answer;
}
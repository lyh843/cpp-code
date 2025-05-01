#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<set>
#include<unordered_map>

class LogAnalyzer{
    private:
        std::vector<std::string> logs;
    public:
        void loadLogs(const std::string& rawText){
            std::stringstream text(rawText);
            std::string line;
            while(std::getline(text, line)){
                if(!line.empty()){
                    logs.push_back(line);
                }
            }
        }
        int countByLevel(const std::string& level){
            int num = 0;
            for(const std::string& target : logs){
                if(target.find(level) != std::string::npos) num++;
            }
            return num;
        }
        std::vector<std::string> getIPs(){
            std::set<std::string> ipSet;

            for(const std::string& line : logs){
                size_t pos = line.find("IP ");
                if(pos != std::string::npos){
                    std::string ip = line.substr(pos + 3);
                    if(!ip.empty()){
                        ipSet.insert(ip);
                    }
                }
            }

            return std::vector<std::string>(ipSet.begin(), ipSet.end());
        }
        std::vector<std::string> filterByKeyword(const std::string& keyword){
            std::vector<std::string> result;
            for(const std::string& line : logs){
                if(line.find(keyword) != std::string::npos){
                    result.push_back(line);
                }
            }
            return result;
        }
        std::string mostFrequentWord(){
            std::unordered_map<std::string, int>freq;

            for(const std::string& line : logs){
                std::string word;
                for(char ch : line){
                    if(std::isalpha(ch)){
                        word += std::tolower(ch);
                    }
                    else if(!word.empty()){
                        freq[word]++;
                        word.clear();
                    }
                }
                if(!word.empty()){
                    freq[word]++;
                }
            }
            
            std::string mostCommon;
            int maxCount = 0;
            for(const auto& pair : freq){
                if(pair.second > maxCount){
                    maxCount = pair.second;
                    mostCommon = pair.first;
                }
            }

            return mostCommon;
        }
};
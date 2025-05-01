#include "LogAnalyzer.hpp"
#include <string>
#include <vector>

int main(){
    std::string logData = R"(
        [2025-04-21 13:45:12] INFO: User alice logged in from IP 192.168.1.12
        [2025-04-21 13:46:33] ERROR: Failed to connect to database
        [2025-04-21 13:47:05] WARN: Disk usage at 90%
        [2025-04-21 13:48:02] INFO: User bob logged in from IP 10.0.0.1
        )";
        
        LogAnalyzer analyzer;
        analyzer.loadLogs(logData);
        
        std::cout << analyzer.countByLevel("INFO") << std::endl; // 输出 2
        std::vector<std::string> ips = analyzer.getIPs();        // 输出 192.168.1.12, 10.0.0.1
        std::string topWord = analyzer.mostFrequentWord();       // 输出 "User"（或别的）
        return 0;
}
#include <fstream>
#include <string>
#include <format>
#include <cassert>
#include <mutex>

enum Log_Level{
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Logger{
public:
    Logger(const std::string& _path){
        path = _path;
        ofs.open(_path, std::ios::app);
        assert(ofs.is_open());
        ofs << "===============================================\n";
        ofs << "===============================================\n";
        ofs << "===============================================\n";
    }
    ~Logger(){
        ofs.close();
    }
    void basic_log(const std::string& _file, const int _line){
        ofs << "FILE:" << _file <<" LINE:" << _line << ":\n";   
    }
    void msg_log(const Log_Level& lev, const std::string& msg){
        std::string lev_str;
        switch(lev){
            case TRACE:
                lev_str = "TRACE";
                break;
            case DEBUG:
                lev_str = "DEBUG";
                break;
            case INFO:
                lev_str = "INFO";
                break;
            case WARN:
                lev_str = "WARN";
                break;
            case ERROR:
                lev_str = "ERROR";
                break; 
        }
        ofs << "    [" << lev_str << "]:";
        ofs << msg << '\n'; 
    }

    template<typename... Args>
    void all_log(const std::string& _file, const int _line, const Log_Level& lev, std::string_view fmt, Args&&... args){
        //std::string msg = std::vformat(fmt, std::make_format_args(args...));
        std::string msg = std::vformat(fmt, std::make_format_args(args...));
        mtx.lock();
        basic_log(_file, _line);
        msg_log(lev, msg);
        mtx.unlock();
    }
private:
    std::ofstream ofs;
    std::string path;
    std::mutex mtx;
};

extern Logger logger;

#define Log(lev, fmt, ...) \
    logger.all_log(__FILE__, __LINE__, lev, fmt, ##__VA_ARGS__)

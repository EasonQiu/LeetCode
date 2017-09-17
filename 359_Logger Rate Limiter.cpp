// Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

// Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

// It is possible that several messages arrive roughly at the same time.

// 注意如果没有输出则不用更新上次输出的结果
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto pos = records.find(message);
        if (pos != records.end() && (timestamp - pos->second < 10)) {
            return false;
        }
        records[message] = timestamp;
        return true;
    }
    
private:
    unordered_map<string, int> records; // <message, last timestamp>
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
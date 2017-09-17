// ["Twitter","postTweet","getNewsFeed","follow","getNewsFeed","unfollow","getNewsFeed"]
// [[],[1,1],[1],[2,1],[2],[2,1],[2]]

// 上述corner case就是可能存在follow一个不存在的人，所以其实user里面的id是没用的

class Tweet {
public:
    int id;
    int timestamp;
    Tweet* prev;
    Tweet(int id_, int timestamp_, Tweet* prev_ = NULL) : id(id_), timestamp(timestamp_), prev(prev_) {}
};
class TweetCompare {
public:
    bool operator() (const Tweet* lhs, const Tweet* rhs) {
        return lhs->timestamp < rhs->timestamp;
    }
};

class User {
public:
    unordered_set<int> follows;
    Tweet* tweets_head;
    User() : tweets_head(NULL) {}
    
    void addTweet(int tweetId, int timestamp) {
        Tweet *node = new Tweet(tweetId, timestamp, tweets_head);
        tweets_head = node;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users[userId].addTweet(tweetId, ++timestamp);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<Tweet*, vector<Tweet*>, TweetCompare> pq;
        if (users[userId].tweets_head)  pq.push(users[userId].tweets_head);
        for (int followsId : users[userId].follows) {
            if (users[followsId].tweets_head)  pq.push(users[followsId].tweets_head);
        }
        for (int k = 0; k < 10; ++k) {
            if (pq.empty())  break;
            ans.push_back(pq.top()->id);
            if (pq.top()->prev)  pq.push(pq.top()->prev);
            pq.pop();
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)  return;
        users[followerId].follows.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].follows.erase(followeeId);
    }
    
private:
    unordered_map<int, User> users; // <userId, User>
    int timestamp = 0;
};
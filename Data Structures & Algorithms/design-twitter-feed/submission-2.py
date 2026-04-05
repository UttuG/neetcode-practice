import heapq
from collections import defaultdict
from typing import List

class Twitter:

    def __init__(self):
        self.user_follow_dict = defaultdict(set)
        self.user_tweet_dict = defaultdict(list)
        self.timestamp = 0  # decreasing, so newer tweets have smaller (more negative) timestamps

    def postTweet(self, userId: int, tweetId: int) -> None:
        # Ensure user follows themselves
        self.user_follow_dict[userId].add(userId)
        # Use max heap behavior by keeping timestamp negative
        heapq.heappush(self.user_tweet_dict[userId], (self.timestamp, tweetId))
        self.timestamp -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        tweets = []

        # Get all tweet lists of followed users
        for followee in self.user_follow_dict.get(userId, {userId}):
            tweets.extend(self.user_tweet_dict[followee])  # last 10 tweets (may not be in order)

        heapq.heapify(tweets)
        # Get the 10 most recent tweets (by timestamp)
        top_10 = heapq.nsmallest(10, tweets)

        # Return tweet IDs in order from most recent to least recent
        return [tweetId for _, tweetId in sorted(top_10)]

    def follow(self, followerId: int, followeeId: int) -> None:
        self.user_follow_dict[followerId].add(followeeId)
        self.user_follow_dict[followerId].add(followerId)  # Ensure self-follow

    def unfollow(self, followerId: int, followeeId: int) -> None:
        # Cannot unfollow self
        if followeeId != followerId:
            self.user_follow_dict[followerId].discard(followeeId)

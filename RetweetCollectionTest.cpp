#include "gmock/gmock.h"
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace ::testing;

class ARetweetCollection: public Test {
public:
   RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
   ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded) {
   collection.add(Tweet());
   
   ASSERT_THAT(collection.isEmpty(), Eq(false));
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
   ASSERT_THAT(collection.size(), Eq(0));
}

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded) {
   collection.add(Tweet());

   ASSERT_THAT(collection.size(), Eq(1));
}

// START:twoTests
TEST_F(ARetweetCollection, DecreasesSizeAfterRemovingTweet) {
   collection.add(Tweet());
   
   collection.remove(Tweet());

   ASSERT_THAT(collection.size(), Eq(0));
}

// AVOID doing this
TEST_F(ARetweetCollection, IsEmptyAfterRemovingTweet) {
   collection.add(Tweet());
   
   collection.remove(Tweet());

   ASSERT_THAT(collection.isEmpty(), Eq(true)); 
}
// END:twoTests

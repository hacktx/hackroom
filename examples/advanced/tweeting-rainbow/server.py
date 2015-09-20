from apscheduler.schedulers.blocking import BlockingScheduler
from random import randint
import logging
import requests
import twitter

logging.basicConfig()

# A server that periodically searches for a new tweet 
# and sends a command to update the LCD display.

# Spark
spark_endpoint = 'https://api.spark.io/v1/devices/<SPARK_CORE_ID_HERE>/setTweet'
spark_token = '<SPARK_ACCESS_TOKEN_HERE>'

# Config
sched = BlockingScheduler()
tags = ['hacktx', 'hackathon', 'hackers', 'mlhacks']
seen = []

@sched.scheduled_job('interval', minutes=1)
def timed_job():
    api = twitter.Api(consumer_key='<TWITTER_CONSUMER_KEY_HERE>',
                      consumer_secret='<TWITTER_CONSUMER_SECRET_HERE>',
                      access_token_key='<TWITTER_ATK_HERE>',
                      access_token_secret='<TWITTER_ATS_HERE>')

    # Get a random tag to search for
    tag = tags[randint(0,len(tags) - 1)]
    results = api.GetSearch(term=tag,
                            count=15,
                            lang='en',
                            include_entities=True)
    
    # Filter out results with images or links, or that have already been seen
    text_results = [result for result in results 
                    if not result.media and not result.urls and result.id not in seen]

    if text_results:
        # Get a good tweet to show
        result = text_results[randint(0, len(text_results) - 1)]
        tweet = result.text

        # Send tweet in batches to avoid hard-coded Spark API payload limit

        # Number of segments
        total = 1 + (len(tweet) / 59)

        for i in xrange(total):
            msg = ('%s %s %s' % (i+1, total, tweet[59*i:59*(i+1)]));
            print msg
            requests.post(spark_endpoint, data={'access_token': spark_token,
                                                'args':msg})

        seen.append(result.id)
        print tweet

# Start the scheduler    
sched.start()

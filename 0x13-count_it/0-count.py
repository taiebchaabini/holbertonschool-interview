#!/usr/bin/python3
"""
    Parses the title of all hot articles, and prints a sorted
    count of given keywords (case-insensitive, delimited by spaces.
"""
import json
import re
import time
import urllib.request


def count_elements(request, word_list, results):
    """ Counts number of elements """
    for title in request['data']['children']:
        datas = title['data']['title'].split(" ")
        for i in range(len(datas)):
            datas[i] = datas[i].lower()
            if (datas[i] in word_list):
                if (datas[i] in results.keys()):
                    results[datas[i]] += word_list.count(datas[i])
                else:
                    results[datas[i]] = word_list.count(datas[i])
    return results


def count_words(subreddit, word_list, count=0, results={}):
    """ Main function to count and print the words """
    baseLink = 'https://api.reddit.com/r/%s/search/' % subreddit
    link = ""

    if (link == ""):
        for i in range(len(word_list)):
            word_list[i] = word_list[i].lower()

    link = baseLink + "?q=%s&sort=hot" % word_list[count]
    req = urllib.request.Request(link)
    req.add_header('User-agent', 'HolbertonSchoolTask')
    with urllib.request.urlopen(req) as response:
        data = response.read()

    data = json.loads(data.decode('utf-8'))
    if (count < len(word_list) - 1):
        results = count_elements(data, word_list, results)
        count_words(subreddit, word_list, count + 1, results)
    else:
        results = sorted(
            results.items(), key=lambda x: (x[1], x[0]), reverse=True
            )
        print(results)

# url to get -> https://a2oj.netlify.app/dsa_interview

import requests
from bs4 import BeautifulSoup
import pandas as pd

r = requests.get('https://a2oj.netlify.app/dsa_interview')

soup = BeautifulSoup(r.content, 'html.parser')

required_table = soup.find('table')

tr_list = required_table.find_all('tr')[1:]

TOPIC = []
QUES = []
QUES_LINK = []


for item in tr_list:
    td_list = item.find_all('td')
    
    try:
        ques_link = td_list[1].find('a').get('href')
        QUES_LINK.append(ques_link)

        topic = td_list[0].text
        TOPIC.append(topic)

        ques = td_list[1].text
        QUES.append(ques)        
    except:
        pass


df = pd.DataFrame()

df['TOPIC'] = pd.Series(TOPIC)
df['QUESTION TITLE'] = pd.Series(QUES)
df['QUESTION LINK'] = pd.Series(QUES_LINK)

# now we need the unique topics from the given list
topic_list = TOPIC.copy()

unique_topics = set(topic_list)
unique_topic_list = list(unique_topics)

# list to count the number of problems in each unique topic
count_ques = []

for topic in unique_topic_list:
    topic_count = 0
    for ques in TOPIC:
        if topic == ques:
            topic_count = topic_count + 1
    count_ques.append(topic_count)

# data frame containing the number of questions in each topic
df2 = pd.DataFrame()

df2['TOPIC'] = pd.Series(unique_topic_list)
df2['NUMBER OF QUESTIONS'] = pd.Series(count_ques)

# writing the data frame into an excel sheet
with pd.ExcelWriter('A2OJ_DSA_Questions.xlsx') as writer:
    df.to_excel(writer, sheet_name='A2OJ DSA', index=False)
    df2.to_excel(writer, sheet_name='Number of Questions', index=False)



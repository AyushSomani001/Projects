import pandas as pd
import numpy as np
import matplotlib as plt
import openpyxl as op
from bs4 import BeautifulSoup
from urllib import request
%matplotlib inline
from bs4 import BeautifulSoup
from urllib import request
import csv   

def extract_score(my_url, *id_kargs):
    try:
        resp = request.urlopen(my_url).read()
        soup = BeautifulSoup(resp, "html.parser")
        score = soup.find_all("div", class_=id_kargs[0])
        return score
    except Exception as e:
        print(str(e))
        return "Network Error"
    
def extract_score_(my_url, *id_kargs):
    try:
        resp = request.urlopen(my_url).read()
        soup = BeautifulSoup(resp, "html.parser")
        score = soup.find_all("p", class_=id_kargs[0])
        return score
    except Exception as e:
        print(str(e))
        return "Network Error"

def bowlers(data):
    res = []
    for test in data:
        for test_ in test:        
            for test__ in test_:
                for test___ in test__:
                    for each in test___:
                        try:
                            if(each.get_text() == ''):
                                continue
                            res.append(each.get_text())
                            if(each.get_text() == 'Bowling'):
                                res.append('Style')
                        except Exception as e:
                            res.append(each)
                        try:
                            if(each.find("a") != None):
                                my_data = extract_score_(each.find("a")["href"], "ciPlayerinformationtxt")
                                res.append(my_data[6].get_text()[14:])
                        except:
                            pass
    return res

def prettify(data):
    res = []
    for each in data:
        for i, each_next in enumerate(each):
            if i is 0: 
                continue
            try:
                res.append(each_next.get_text())
            except Exception as e:
                res.append(each_next)
    return res

def inform(data):
    res = []
    res.append(data[0].get_text())
    res.append(data[1].get_text())
    return res
workload=op.load_workbook(r'C:\Users\Insprion\Downloads\Test Matches.xlsx')
ws=workload.active
for i in range(90, 291):
    link=ws.cell(column=8,row=i).hyperlink.target
    info = inform(extract_score(link, "match-detail--right"))
    scores = prettify(extract_score(link, "total"))
    bowling = bowlers(extract_score(link, "scorecard-section bowling"))
    row = [i, ] + info + scores + bowling
    with open(r'C:\Users\Insprion\Downloads\msi_data.csv', 'a') as f:
        writer = csv.writer(f)
        writer.writerow(row)

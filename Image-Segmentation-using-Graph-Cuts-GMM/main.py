#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 21 21:48:50 2018
@author: Ayush Somani
"""


from scipy.misc import imread, imshow
from sklearn.mixture import GaussianMixture as GMM


def iread():
    X=imread('robot.jpg')
    imshow(X)
    global old
    old=X.shape
    print(old)
    X=X.reshape(-1,3)
    gmm=GMM(covariance_type='full', n_components=2)
    gmm.fit(X)
    clusters=gmm.predict_proba(X)
    clusters=clusters.reshape(old[0],old[1],2)
    #clusters = clusters.reshape(old[0], old[1])
    #imshow(clusters)
    return clusters

def cur(i,j):
    return i*old[0]+j+2

def norm(l1,l2):
    ans=0
    for i in range(len(l1)):
        ans+=(l1[i]-l2[i])**2
    return ans


def gcut(clusters):
    import graph_tool.all as gt
    import numpy as np
    g=gt.Graph()
    wt=g.new_edge_property("long double")
    g.add_vertex(old[0]*old[1]+2)
    s=g.vertex(0)
    t=g.vertex(1)
    beta=5
    for i in range(old[0]):
        print(i)
        for j in range(old[1]):
            e=g.add_edge(s,cur(i,j))
            wt[e]=-np.log(clusters[i][j][1])
            e=g.add_edge(cur(i,j),t)
            wt[e]=-np.log(clusters[i][j][0])
            if i>0:
                e=g.add_edge(cur(i-1,j),cur(i,j))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i-1][j]))
                e=g.add_edge(cur(i,j),cur(i-1,j))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i-1][j]))
            if j!=old[1]-1:
                e=g.add_edge(cur(i,j),cur(i,j+1))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i][j+1]))
                e=g.add_edge(cur(i,j+1),cur(i,j))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i][j+1]))
            if i!=old[0]-1:
                e=g.add_edge(cur(i,j),cur(i+1,j))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i+1][j]))
                e=g.add_edge(cur(i+1,j),cur(i,j))
                wt[e]=np.exp(-beta*norm(clusters[i+1][j], clusters[i][j]))
            if j!=0:
                e=g.add_edge(cur(i,j),cur(i,j-1))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i][j-1]))
                e=g.add_edge(cur(i,j-1), cur(i,j))
                wt[e]=np.exp(-beta*norm(clusters[i][j], clusters[i][j-1]))
    res = gt.push_relabel_max_flow(g, s, t, wt)
    part = gt.min_st_cut(g, s, wt, res)
    print("Graph cut done.")
    ans=np.ndarray((old[0],old[1]), dtype=bool)
    print(ans.shape)
    for i in range(old[0]):
        for j in range(old[1]):
            ans[i][j]=part[g.vertex(cur(i,j))]
    imshow(ans)
    return
    
if __name__=="__main__":
    op=iread()
    gcut(op)

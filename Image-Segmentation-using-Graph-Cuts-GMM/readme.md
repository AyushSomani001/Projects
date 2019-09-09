# Automatic Image Segmentation using Graph Cuts

### Abstract

This project aims to segment image into forground and background using automated process and thus requiring no user participation. Probability of a pixel fitting to background and foreground is calculated using Gaussian Mixture Model. This model first uses k-means clustering to cluster closely related pixels to initialise the weights and means of the gaussians of two Gaussian Mixture Model and then ”fits” the needed gaussian mixture model according to training data i.e. image itself. Segmentation is binary into foreground and background but remain unclassified to either category, based on the probability of the pixel fitting to either gaussians. The probabilities were used to construct edge weights in the graph to which graph cut was done and the overall error function is minimised. The labelling as output from graph cut is the final classification of foreground and background.

##### NOTE

Detailed description is provided in report provided in the link below. Presentation is also provided to provide intuitive understanding of the concepts used in the project.

### Results

As mentioned the segmentation is automatic and depending on the GMM the foreground and background may interchange but the classification is correctly done. Images from various domain is taken and classfication is studied. All the images belong to their repective owners.

![Female Portrait](https://github.com/madhur4127/project/blob/master/Image-Segmentation-Graph-Cuts-GMM/girl-port.jpg)
![Male Portrait](https://github.com/madhur4127/project/blob/master/Image-Segmentation-Graph-Cuts-GMM/insaan.jpg)
![Wildlife](https://github.com/madhur4127/project/blob/master/Image-Segmentation-Graph-Cuts-GMM/wild.jpg)
![Objects](https://github.com/madhur4127/project/blob/master/Image-Segmentation-Graph-Cuts-GMM/rob.jpg)

### Resources

1. **Report**: [`Download Report`](https://github.com/madhur4127/project/blob/master/Image-Segmentation-Graph-Cuts-GMM/report.pdf)
2. **Presentation**: [`Download Presentation`](https://github.com/madhur4127/project/blob/master/Image-Segmentation-Graph-Cuts-GMM/presentation.pdf)

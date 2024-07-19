import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# Load Data
education = pd.read_csv("education.csv")

# Data Information
education.info()

# Exploratory Data Analysis (EDA)
# Measures of Central Tendency
print("Mean:", education.workex.mean())
print("Median:", education.workex.median())
print("Mode:", education.workex.mode())

# Measures of Dispersion
print("Variance:", education.workex.var())
print("Standard Deviation:", education.workex.std())
print("Range:", max(education.workex) - min(education.workex))

# Skewness
print("Skewness (workex):", education.workex.skew())
print("Skewness (gmat):", education.gmat.skew())

# Kurtosis
print("Kurtosis (workex):", education.workex.kurt())

# Data Visualization
# Barplot
plt.figure()
plt.bar(height=education.gmat, x=np.arange(1, len(education.gmat) + 1))
plt.title("Barplot of GMAT Scores")
plt.show()

# Histograms
plt.figure()
plt.hist(education.gmat, color='blue', edgecolor='red', bins=[600, 680, 710, 740, 780])
plt.title("Histogram of GMAT Scores")
plt.show()

plt.figure()
plt.hist(education.workex, color='red', edgecolor='black', bins=6)
plt.title("Histogram of Work Experience")
plt.show()

# Histograms using Seaborn
sns.displot(education.gmat)
plt.title("Seaborn Histogram of GMAT Scores")
plt.show()

# Boxplot
plt.figure()
plt.boxplot(education.gmat)
plt.title("Boxplot of GMAT Scores")
plt.show()

# Density Plot
sns.kdeplot(education.gmat, bw_adjust=0.5, fill=True)
plt.title("Density Plot of GMAT Scores")
plt.show()

# Descriptive Statistics
print(education.describe())
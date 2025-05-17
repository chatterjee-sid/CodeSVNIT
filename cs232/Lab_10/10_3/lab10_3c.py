import pandas as pd
import numpy as np

df = pd.read_csv("LAB_10_student.csv", header=None)

hw = df[3]
project = df[5]

cov_matrix = np.cov(hw, project, ddof=0)

cov_hw_project = cov_matrix[0, 1]

print("Covariance between HW and Project:", cov_hw_project)

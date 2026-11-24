import pandas as pd
import matplotlib.pyplot as plt

sel = pd.read_csv("selection_sort.csv")
ins = pd.read_csv("insertion_sort.csv")

# Columns are named differently in the two files, so use them by position:
# first column = input size (x), second column = comparisons (y)
plt.figure(figsize=(8, 5))
plt.plot(sel.iloc[:, 0], sel.iloc[:, 1], marker="o", markersize=3, label="Selection sort")
plt.plot(ins.iloc[:, 0], ins.iloc[:, 1], marker="s", markersize=3, label="Insertion sort")

plt.xlabel("Input size (n)")
plt.ylabel("Number of comparisons")
plt.title("Selection sort vs Insertion sort")
plt.grid(True, alpha=0.3)
plt.legend()
plt.tight_layout()
plt.savefig("sort_comparison.png", dpi=150)
plt.show()
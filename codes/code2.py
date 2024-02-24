import matplotlib.pyplot as plt

# Read coordinates from data1.txt
with open("data1.txt", "r") as file:
    data = [line.split() for line in file.readlines()]
    x = [float(entry[0]) for entry in data]
    y = [float(entry[1]) for entry in data]

# Plotting the stem plot
plt.stem(x, y, basefmt='r', linefmt='b', markerfmt='ro')  # Red coordinates, blue lines, and red base axes
plt.axhline(0, color='r', linestyle='--')  # Red horizontal base axis
plt.axvline(0, color='r', linestyle='--')  # Red vertical base axis

# Adding grid and labels
plt.grid(True)
plt.xlabel('Term Number')
plt.ylabel('Value of GP Term')

# Setting y-axis step to 0.1
plt.yticks([i * 0.1 for i in range(int(min(y) * 10), int(max(y) * 10) + 1)])

# Show the plot
plt.show()

